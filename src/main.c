#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/errno.h>
#include <sysexits.h>
#include <mach/mach.h>
#include <mach/mach_error.h>
#include <IOKit/IOKitLib.h>
#include <IOKit/IOCFPlugIn.h>
#include <IOKit/hid/IOHIDLib.h>
#include <IOKit/hid/IOHIDKeys.h>
#include "Events.h"
#include <CoreFoundation/CoreFoundation.h>
#include <CoreGraphics/CGEvent.h>
#include "hidUsage.h"

AbsoluteTime zeroTime = { 0, 0 };

#define INVALID_COOKIE 0
#define USAGE_BUTTON_1_DOWN 112
#define USAGE_BUTTON_1_UP 113
#define USAGE_BUTTON_2_DOWN 114
#define USAGE_BUTTON_2_UP 115

typedef struct
{
    io_object_t device;
    IOHIDDeviceInterface122 ** deviceInterface;
    IOHIDQueueInterface ** queue;
    CFRunLoopSourceRef eventSource;
    IOHIDElementCookie cookie_1_down;
    IOHIDElementCookie cookie_1_up;
    IOHIDElementCookie cookie_2_down;
    IOHIDElementCookie cookie_2_up;
    bool sw1isDown;
    bool sw2isDown;
} FSW;


typedef struct
{
    IOHIDElementCookie cookie;
    long usage;
    long usagePage;
} MyElement;

bool running;

void raiseKeyboardEvent(CGKeyCode virtualKey, bool keyDown)
{
    CGEventRef event;
    event = CGEventCreateKeyboardEvent(NULL, virtualKey, keyDown);
    CGEventPost(kCGHIDEventTap, event);
}


bool fswIsValid(FSW fsw)
{
    if (fsw.device == 0)
        return false;
    if (fsw.deviceInterface == NULL)
        return false;
    if (fsw.queue == NULL)
        return false;
    if (fsw.cookie_1_down == INVALID_COOKIE)
        return false;
    if (fsw.cookie_1_up == INVALID_COOKIE)
        return false;
    if (fsw.cookie_2_down == INVALID_COOKIE)
        return false;
    if (fsw.cookie_2_up == INVALID_COOKIE)
        return false;
    return true;
}

void releaseFsw(FSW *fsw) {
    if (fsw->device)
        IOObjectRelease(fsw->device);
    if (fsw->deviceInterface)
        (*fsw->deviceInterface)->Release(fsw->deviceInterface);
    if (fsw->queue) {
            (*fsw->queue)->stop(fsw->queue);
            (*fsw->queue)->dispose(fsw->queue);
            (*fsw->queue)->Release(fsw->queue);
    }
}

io_object_t findHIDDevice(const char *pathSubstring)
{

    io_iterator_t hidObjectIterator = 0;
    CFMutableDictionaryRef hidMatchDictionary = NULL;
    IOReturn ioReturnValue = kIOReturnSuccess;
    io_object_t hidDevice = 0;
    io_object_t result = 0;
    char path[512];

    // Set up a matching dictionary to search the I/O Registry by class
    // name for all HID class devices
    hidMatchDictionary = IOServiceMatching(kIOHIDDeviceKey);
    if (!hidMatchDictionary)
    {
        fputs("No HID devices found.\n", stderr);
        goto end;
    }

    // Now search I/O Registry for matching devices.
    ioReturnValue = IOServiceGetMatchingServices(kIOMasterPortDefault, hidMatchDictionary, &hidObjectIterator);

    if ((ioReturnValue != kIOReturnSuccess) | (hidObjectIterator == 0)) {
     fputs("No matching HID class devices found.\n", stderr);
     goto end;
    }

    while ((hidDevice = IOIteratorNext(hidObjectIterator)))
    {
        kern_return_t error = IORegistryEntryGetPath(hidDevice, kIOServicePlane, path);

        if (error == KERN_SUCCESS && strstr(path, pathSubstring))
        {
            result = hidDevice;
            break;
        }
    }
end:
    //Release iterator. Don't need to release iterator objects.
    if (hidObjectIterator)
        IOObjectRelease(hidObjectIterator);

    // IOServiceGetMatchingServices consumes a reference to the
    //   dictionary, so we don't need to release the dictionary ref.
    hidMatchDictionary = NULL;
    return result;
}

IOHIDDeviceInterface ** getHIDDeviceInterface(io_object_t hidDevice)
{
    IOHIDDeviceInterface **hidDeviceInterface = NULL;
    io_name_t className;
    IOCFPlugInInterface **plugInInterface = NULL;
    HRESULT plugInResult = S_OK;
    SInt32 score = 0;
    IOReturn ioReturnValue = kIOReturnSuccess;

    ioReturnValue = IOObjectGetClass(hidDevice, className);
    if (ioReturnValue != kIOReturnSuccess)
    {
        fputs("Couldn't determine device class\n", stderr);
        goto end;
    }

    ioReturnValue = IOCreatePlugInInterfaceForService(hidDevice,
                                        kIOHIDDeviceUserClientTypeID,
                                        kIOCFPlugInInterfaceID, &plugInInterface, &score);

    if (ioReturnValue != kIOReturnSuccess)
    {
        fputs("Couldn't create HID class device interface\n", stderr);
        goto end;
    }

    //Call a method of the intermediate plug-in to create the device interface
    plugInResult = (*plugInInterface)->QueryInterface(plugInInterface,
            CFUUIDGetUUIDBytes(kIOHIDDeviceInterfaceID), (LPVOID *) &hidDeviceInterface);
    if (plugInResult != S_OK)
    {
        hidDeviceInterface = NULL;
        fputs("Couldn't create HID class device interface\n", stderr);
        goto end;
    }

end:
    if (plugInInterface)
        (*plugInInterface)->Release(plugInInterface);
    return hidDeviceInterface;
}

MyElement getMyElement(CFDictionaryRef element)
{
    CFTypeRef object;
    long number;
    MyElement result = { -1, -1, -1 };

    //Get usage
    object = CFDictionaryGetValue(element, CFSTR(kIOHIDElementUsageKey));
    if (object == 0 || CFGetTypeID(object) != CFNumberGetTypeID())
        goto end;
    if (!CFNumberGetValue((CFNumberRef) object, kCFNumberLongType, &number))
        goto end;
    result.usage = number;

    //Get usage page
    object = CFDictionaryGetValue(element, CFSTR(kIOHIDElementUsagePageKey));
    if (object == 0 || CFGetTypeID(object) != CFNumberGetTypeID())
        goto end;
    if (!CFNumberGetValue((CFNumberRef) object, kCFNumberLongType, &number))
        goto end;
    result.usagePage = number;

    object = (CFDictionaryGetValue(element, CFSTR(kIOHIDElementCookieKey)));
    if (object == 0 || CFGetTypeID(object) != CFNumberGetTypeID())
        goto end;
    if (!CFNumberGetValue((CFNumberRef) object, kCFNumberLongType, &number))
        goto end;
    result.cookie = (IOHIDElementCookie) number;

end:
    return result;

}


void handleEvent(
                            void *    target,
                            IOReturn  result,
                            void *    refcon,
                            void *    sender)
{
    FSW * fsw = (FSW *) refcon;
    IOHIDEventStruct event;
    while (result == kIOReturnSuccess)
    {
        result = (*fsw->queue)->getNextEvent(fsw->queue, &event, zeroTime, 0);
        IOHIDElementCookie c = event.elementCookie;
        if (c == fsw->cookie_1_down && !fsw->sw1isDown)
        {
            fsw->sw1isDown = true;
            raiseKeyboardEvent(kVK_F18, true);
        }
        else if (c == fsw->cookie_1_up && fsw->sw1isDown)
        {
            fsw->sw1isDown = false;
            raiseKeyboardEvent(kVK_F18, false);
        }
        else if (c == fsw->cookie_2_down && !fsw->sw2isDown)
        {
            fsw->sw2isDown = true;
            raiseKeyboardEvent(kVK_F19, true);
        }
        else if (c == fsw->cookie_2_up && fsw->sw2isDown)
        {
            fsw->sw2isDown = false;
            raiseKeyboardEvent(kVK_F19, false);
        }


        if ( result != kIOReturnSuccess )
            continue;
    }
}

bool addQueueCallbacks(FSW *fsw)
{
    IOReturn ret;
    mach_port_t port;
    /*  We could use any data structure here. This data structure
        will be passed to the callback, and should probably
        include some information about the queue, assuming your
        program deals with more than one. */

    ret = (*fsw->queue)->createAsyncEventSource(fsw->queue, &fsw->eventSource);
    if (FAILED(ret)) goto end;
    ret = (*fsw->queue)->setEventCallout(fsw->queue, handleEvent, NULL, fsw);
    if (FAILED(ret)) goto end;
    CFRunLoopAddSource(CFRunLoopGetCurrent(), fsw->eventSource, kCFRunLoopDefaultMode);
end:
    return ret;
}

bool startQueue(FSW *fsw)
{
    HRESULT result = 0;
    fsw->queue = (*fsw->deviceInterface)->allocQueue(fsw->deviceInterface);

    if (!fsw->queue)
    {
        fputs("ERROR: couldn't create event queue\n", stderr);
        return false;
    }

    result = (*fsw->queue)->create(fsw->queue, 0, 8);
    if (FAILED(result)) goto end;
    result = (*fsw->queue)->addElement(fsw->queue, fsw->cookie_1_down, 0);
    if (FAILED(result)) goto end;
    result = (*fsw->queue)->addElement(fsw->queue, fsw->cookie_1_up, 0);
    if (FAILED(result)) goto end;
    result = (*fsw->queue)->addElement(fsw->queue, fsw->cookie_2_down, 0);
    if (FAILED(result)) goto end;
    result = (*fsw->queue)->addElement(fsw->queue, fsw->cookie_2_up, 0);
    if (FAILED(result)) goto end;
    result = addQueueCallbacks(fsw);
    if (FAILED(result)) goto end;
    result = (*fsw->queue)->start(fsw->queue);
    CFRunLoopRun();
end:
    return SUCCEEDED(result);
}

FSW getFSW()
{
    FSW result;
    CFArrayRef elements;
    IOReturn success;
    CFIndex i;
    MyElement element;
    IOReturn ioReturnValue = kIOReturnSuccess;

    memset(&result, 0, sizeof(result));
    result.device = findHIDDevice("FSW-02");
    if (!result.device)
    {
        fputs("Failed to get device.\n", stderr);
        return result;
    }
    result.deviceInterface = (IOHIDDeviceInterface122 **)getHIDDeviceInterface(result.device);
    if (!result.deviceInterface)
    {
        fputs("Failed to get device interface.\n", stderr);
        return result;
    }


    //open the device
    ioReturnValue = (*result.deviceInterface)->open(result.deviceInterface, 0);
    if (ioReturnValue != kIOReturnSuccess)
    {
        fputs("Failed to open device\n", stderr);
        return result;
    }

    // Copy all elements, since we're grabbing most of the elements
    // for this device anyway, and thus, it's faster to iterate them
    // ourselves. When grabbing only one or two elements, a matching
    // dictionary should be passed in here instead of NULL.
    success = (*result.deviceInterface)->copyMatchingElements(result.deviceInterface, NULL, &elements);
    if (success != kIOReturnSuccess)
    {
        fputs("Failed to get queue elements.\n", stderr);
        return result;
    }

    for (i = 0; i < CFArrayGetCount(elements); i++)
    {
        element = getMyElement(CFArrayGetValueAtIndex(elements, i));

        if (element.usagePage == kHIDPage_KeyboardOrKeypad)
        {
            switch (element.usage)
            {
            case USAGE_BUTTON_1_DOWN:
                result.cookie_1_down = element.cookie;
                break;
            case USAGE_BUTTON_1_UP:
                result.cookie_1_up = element.cookie;
                break;
            case USAGE_BUTTON_2_DOWN:
                result.cookie_2_down = element.cookie;
                break;
            case USAGE_BUTTON_2_UP:
                result.cookie_2_up = element.cookie;
                break;
            default:
                break;
            }
        }
    }
    startQueue(&result);

    return result;
}

bool run()
{
    HRESULT result = 0;
    IOHIDEventStruct hidEvent;
    FSW fsw;

    fsw = getFSW();
    if (!fswIsValid(fsw))
    {
        fputs("ERROR: failed to get all of the necessary parameters.\n", stderr);
        return false;
    }
    running = true;
    while(running)
    {
        sleep(1);
/*        result = (*fsw.queue)->getNextEvent(fsw.queue, &hidEvent, zeroTime, 0);
        if (SUCCEEDED(result))
        {
            IOHIDElementCookie c = hidEvent.elementCookie;
            if (c == fsw.cookie_1_down)
            {
                raiseKeyboardEvent(PAGE_DOWN, true);
            }
            else if (c == fsw.cookie_1_up)
            {
                raiseKeyboardEvent(PAGE_DOWN, false);
            }
            else if (c == fsw.cookie_2_down)
            {
                raiseKeyboardEvent(PAGE_UP, true);
            }
            else if (c == fsw.cookie_2_up)
            {
                raiseKeyboardEvent(PAGE_UP, false);
            }
        }*/
    }
    releaseFsw(&fsw);
    return true;
}
void handleSignal(int number)
{
    running = false;
}

void initSignals()
{
    if (signal(handleSignal, SIGTERM) == SIG_ERR)
        fputs("WARNING: failed to handle SIGTERM\n", stderr);
    if (signal(handleSignal, SIGKILL) == SIG_ERR)
        fputs("WARNING: failed to handle SIGKILL\n", stderr);
    if (signal(handleSignal, SIGHUP) == SIG_ERR)
        fputs("WARNING: failed to handle SIGHUP\n", stderr);
}
int main(int argc, const char * argv[])
{
    bool success;
    initSignals();
    success = run();
    return (success ? 0 : 1);
}
