
#include "hidUsage.h"

const char * hidUsageString(long usagePage, long usage)
{
    switch(usagePage)
    {
    case kHIDPage_GenericDesktop:
        return hidGenericUsageString(usage);
    case kHIDPage_KeyboardOrKeypad:
        return hidKeyboardUsageString(usage);
    case kHIDPage_Button:
    case kHIDPage_Undefined:
    case kHIDPage_Simulation:
    case kHIDPage_VR:
    case kHIDPage_Sport:
    case kHIDPage_Game:
    case kHIDPage_LEDs:
    case kHIDPage_Ordinal:
    case kHIDPage_Telephony:
    case kHIDPage_Consumer:
    case kHIDPage_Digitizer:
    case kHIDPage_PID:
    case kHIDPage_Unicode:
    case kHIDPage_AlphanumericDisplay:
    case kHIDPage_PowerDevice:
    case kHIDPage_BatterySystem:
    case kHIDPage_BarCodeScanner:
    case kHIDPage_WeighingDevice:
    case kHIDPage_MagneticStripeReader:
    case kHIDPage_CameraControl:
    case kHIDPage_Arcade:
    case kHIDPage_VendorDefinedStart:
    default:
        return "Unknown";
    }
};

const char * hidGenericUsageString(long usage)
{
    switch(usage)
    {
    case kHIDUsage_GD_Pointer:
            return "GD_Pointer"; /* Physical Collection */
    case kHIDUsage_GD_Mouse:
            return "GD_Mouse"; /* Application Collection */
    /* 0x03 Reserved */
    case kHIDUsage_GD_Joystick:
            return "GD_Joystick"; /* Application Collection */
    case kHIDUsage_GD_GamePad:
            return "GD_GamePad"; /* Application Collection */
    case kHIDUsage_GD_Keyboard:
            return "GD_Keyboard"; /* Application Collection */
    case kHIDUsage_GD_Keypad:
            return "GD_Keypad"; /* Application Collection */
    case kHIDUsage_GD_MultiAxisController:
            return "GD_MultiAxisController"; /* Application Collection */
    /* 0x09 - 0x2F Reserved */
    case kHIDUsage_GD_X:
            return "GD_X"; /* Dynamic Value */
    case kHIDUsage_GD_Y:
            return "GD_Y"; /* Dynamic Value */
    case kHIDUsage_GD_Z:
            return "GD_Z"; /* Dynamic Value */
    case kHIDUsage_GD_Rx:
            return "GD_Rx"; /* Dynamic Value */
    case kHIDUsage_GD_Ry:
            return "GD_Ry"; /* Dynamic Value */
    case kHIDUsage_GD_Rz:
            return "GD_Rz"; /* Dynamic Value */
    case kHIDUsage_GD_Slider:
            return "GD_Slider"; /* Dynamic Value */
    case kHIDUsage_GD_Dial:
            return "GD_Dial"; /* Dynamic Value */
    case kHIDUsage_GD_Wheel:
            return "GD_Wheel"; /* Dynamic Value */
    case kHIDUsage_GD_Hatswitch:
            return "GD_Hatswitch"; /* Dynamic Value */
    case kHIDUsage_GD_CountedBuffer:
            return "GD_CountedBuffer"; /* Logical Collection */
    case kHIDUsage_GD_ByteCount:
            return "GD_ByteCount"; /* Dynamic Value */
    case kHIDUsage_GD_MotionWakeup:
            return "GD_MotionWakeup"; /* One-Shot Control */
    case kHIDUsage_GD_Start:
            return "GD_Start"; /* On/Off Control */
    case kHIDUsage_GD_Select:
            return "GD_Select"; /* On/Off Control */
    /* 0x3F Reserved */
    case kHIDUsage_GD_Vx:
            return "GD_Vx"; /* Dynamic Value */
    case kHIDUsage_GD_Vy:
            return "GD_Vy"; /* Dynamic Value */
    case kHIDUsage_GD_Vz:
            return "GD_Vz"; /* Dynamic Value */
    case kHIDUsage_GD_Vbrx:
            return "GD_Vbrx"; /* Dynamic Value */
    case kHIDUsage_GD_Vbry:
            return "GD_Vbry"; /* Dynamic Value */
    case kHIDUsage_GD_Vbrz:
            return "GD_Vbrz"; /* Dynamic Value */
    case kHIDUsage_GD_Vno:
            return "GD_Vno"; /* Dynamic Value */
    /* 0x47 - 0x7F Reserved */
    case kHIDUsage_GD_SystemControl:
            return "GD_SystemControl"; /* Application Collection */
    case kHIDUsage_GD_SystemPowerDown:
            return "GD_SystemPowerDown"; /* One-Shot Control */
    case kHIDUsage_GD_SystemSleep:
            return "GD_SystemSleep"; /* One-Shot Control */
    case kHIDUsage_GD_SystemWakeUp:
            return "GD_SystemWakeUp"; /* One-Shot Control */
    case kHIDUsage_GD_SystemContextMenu:
            return "GD_SystemContextMenu"; /* One-Shot Control */
    case kHIDUsage_GD_SystemMainMenu:
            return "GD_SystemMainMenu"; /* One-Shot Control */
    case kHIDUsage_GD_SystemAppMenu:
            return "GD_SystemAppMenu"; /* One-Shot Control */
    case kHIDUsage_GD_SystemMenuHelp:
            return "GD_SystemMenuHelp"; /* One-Shot Control */
    case kHIDUsage_GD_SystemMenuExit:
            return "GD_SystemMenuExit"; /* One-Shot Control */
    case kHIDUsage_GD_SystemMenu:
            return "GD_SystemMenu"; /* Selector */
    case kHIDUsage_GD_SystemMenuRight:
            return "GD_SystemMenuRight"; /* Re-Trigger Control */
    case kHIDUsage_GD_SystemMenuLeft:
            return "GD_SystemMenuLeft"; /* Re-Trigger Control */
    case kHIDUsage_GD_SystemMenuUp:
            return "GD_SystemMenuUp"; /* Re-Trigger Control */
    case kHIDUsage_GD_SystemMenuDown:
            return "GD_SystemMenuDown"; /* Re-Trigger Control */
    /* 0x8E - 0x8F Reserved */
    case kHIDUsage_GD_DPadUp:
            return "GD_DPadUp"; /* On/Off Control */
    case kHIDUsage_GD_DPadDown:
            return "GD_DPadDown"; /* On/Off Control */
    case kHIDUsage_GD_DPadRight:
            return "GD_DPadRight"; /* On/Off Control */
    case kHIDUsage_GD_DPadLeft:
            return "GD_DPadLeft"; /* On/Off Control */
    default:
        return "Unknown";
}

}
const char * hidKeyboardUsageString(long usage)
{
    switch (usage)
    {
        case kHIDUsage_KeyboardErrorRollOver:
            return "KeyboardErrorRollOver"; /* ErrorRollOver */
        case kHIDUsage_KeyboardPOSTFail:
            return "KeyboardPOSTFail"; /* POSTFail */
        case kHIDUsage_KeyboardErrorUndefined:
            return "KeyboardErrorUndefined"; /* ErrorUndefined */
        case kHIDUsage_KeyboardA:
            return "KeyboardA"; /* a or A */
        case kHIDUsage_KeyboardB:
            return "KeyboardB"; /* b or B */
        case kHIDUsage_KeyboardC:
            return "KeyboardC"; /* c or C */
        case kHIDUsage_KeyboardD:
            return "KeyboardD"; /* d or D */
        case kHIDUsage_KeyboardE:
            return "KeyboardE"; /* e or E */
        case kHIDUsage_KeyboardF:
            return "KeyboardF"; /* f or F */
        case kHIDUsage_KeyboardG:
            return "KeyboardG"; /* g or G */
        case kHIDUsage_KeyboardH:
            return "KeyboardH"; /* h or H */
        case kHIDUsage_KeyboardI:
            return "KeyboardI"; /* i or I */
        case kHIDUsage_KeyboardJ:
            return "KeyboardJ"; /* j or J */
        case kHIDUsage_KeyboardK:
            return "KeyboardK"; /* k or K */
        case kHIDUsage_KeyboardL:
            return "KeyboardL"; /* l or L */
        case kHIDUsage_KeyboardM:
            return "KeyboardM"; /* m or M */
        case kHIDUsage_KeyboardN:
            return "KeyboardN"; /* n or N */
        case kHIDUsage_KeyboardO:
            return "KeyboardO"; /* o or O */
        case kHIDUsage_KeyboardP:
            return "KeyboardP"; /* p or P */
        case kHIDUsage_KeyboardQ:
            return "KeyboardQ"; /* q or Q */
        case kHIDUsage_KeyboardR:
            return "KeyboardR"; /* r or R */
        case kHIDUsage_KeyboardS:
            return "KeyboardS"; /* s or S */
        case kHIDUsage_KeyboardT:
            return "KeyboardT"; /* t or T */
        case kHIDUsage_KeyboardU:
            return "KeyboardU"; /* u or U */
        case kHIDUsage_KeyboardV:
            return "KeyboardV"; /* v or V */
        case kHIDUsage_KeyboardW:
            return "KeyboardW"; /* w or W */
        case kHIDUsage_KeyboardX:
            return "KeyboardX"; /* x or X */
        case kHIDUsage_KeyboardY:
            return "KeyboardY"; /* y or Y */
        case kHIDUsage_KeyboardZ:
            return "KeyboardZ"; /* z or Z */
        case kHIDUsage_Keyboard1:
            return "Keyboard1"; /* 1 or ! */
        case kHIDUsage_Keyboard2:
            return "Keyboard2"; /* 2 or @ */
        case kHIDUsage_Keyboard3:
            return "Keyboard3"; /* 3 or # */
        case kHIDUsage_Keyboard4:
            return "Keyboard4"; /* 4 or $ */
        case kHIDUsage_Keyboard5:
            return "Keyboard5"; /* 5 or % */
        case kHIDUsage_Keyboard6:
            return "Keyboard6"; /* 6 or ^ */
        case kHIDUsage_Keyboard7:
            return "Keyboard7"; /* 7 or & */
        case kHIDUsage_Keyboard8:
            return "Keyboard8"; /* 8 or * */
        case kHIDUsage_Keyboard9:
            return "Keyboard9"; /* 9 or ( */
        case kHIDUsage_Keyboard0:
            return "Keyboard0"; /* 0 or ) */
        case kHIDUsage_KeyboardReturnOrEnter:
            return "KeyboardReturnOrEnter"; /* Return (Enter) */
        case kHIDUsage_KeyboardEscape:
            return "KeyboardEscape"; /* Escape */
        case kHIDUsage_KeyboardDeleteOrBackspace:
            return "KeyboardDeleteOrBackspace"; /* Delete (Backspace) */
        case kHIDUsage_KeyboardTab:
            return "KeyboardTab"; /* Tab */
        case kHIDUsage_KeyboardSpacebar:
            return "KeyboardSpacebar"; /* Spacebar */
        case kHIDUsage_KeyboardHyphen:
            return "KeyboardHyphen"; /* - or _ */
        case kHIDUsage_KeyboardEqualSign:
            return "KeyboardEqualSign"; /* = or + */
        case kHIDUsage_KeyboardOpenBracket:
            return "KeyboardOpenBracket"; /* [ or { */
        case kHIDUsage_KeyboardCloseBracket:
            return "KeyboardCloseBracket"; /* ] or } */
        case kHIDUsage_KeyboardBackslash:
            return "KeyboardBackslash"; /* \ or | */
        case kHIDUsage_KeyboardNonUSPound:
            return "KeyboardNonUSPound"; /* Non-US # or _ */
        case kHIDUsage_KeyboardSemicolon:
            return "KeyboardSemicolon"; /* ; or : */
        case kHIDUsage_KeyboardQuote:
            return "KeyboardQuote"; /* ' or " */
        case kHIDUsage_KeyboardGraveAccentAndTilde:
            return "KeyboardGraveAccentAndTilde"; /* Grave Accent and Tilde */
        case kHIDUsage_KeyboardComma:
            return "KeyboardComma"; /* , or < */
        case kHIDUsage_KeyboardPeriod:
            return "KeyboardPeriod"; /* . or > */
        case kHIDUsage_KeyboardSlash:
            return "KeyboardSlash"; /* / or ? */
        case kHIDUsage_KeyboardCapsLock:
            return "KeyboardCapsLock"; /* Caps Lock */
        case kHIDUsage_KeyboardF1:
            return "KeyboardF1"; /* F1 */
        case kHIDUsage_KeyboardF2:
            return "KeyboardF2"; /* F2 */
        case kHIDUsage_KeyboardF3:
            return "KeyboardF3"; /* F3 */
        case kHIDUsage_KeyboardF4:
            return "KeyboardF4"; /* F4 */
        case kHIDUsage_KeyboardF5:
            return "KeyboardF5"; /* F5 */
        case kHIDUsage_KeyboardF6:
            return "KeyboardF6"; /* F6 */
        case kHIDUsage_KeyboardF7:
            return "KeyboardF7"; /* F7 */
        case kHIDUsage_KeyboardF8:
            return "KeyboardF8"; /* F8 */
        case kHIDUsage_KeyboardF9:
            return "KeyboardF9"; /* F9 */
        case kHIDUsage_KeyboardF10:
            return "KeyboardF10"; /* F10 */
        case kHIDUsage_KeyboardF11:
            return "KeyboardF11"; /* F11 */
        case kHIDUsage_KeyboardF12:
            return "KeyboardF12"; /* F12 */
        case kHIDUsage_KeyboardPrintScreen:
            return "KeyboardPrintScreen"; /* Print Screen */
        case kHIDUsage_KeyboardScrollLock:
            return "KeyboardScrollLock"; /* Scroll Lock */
        case kHIDUsage_KeyboardPause:
            return "KeyboardPause"; /* Pause */
        case kHIDUsage_KeyboardInsert:
            return "KeyboardInsert"; /* Insert */
        case kHIDUsage_KeyboardHome:
            return "KeyboardHome"; /* Home */
        case kHIDUsage_KeyboardPageUp:
            return "KeyboardPageUp"; /* Page Up */
        case kHIDUsage_KeyboardDeleteForward:
            return "KeyboardDeleteForward"; /* Delete Forward */
        case kHIDUsage_KeyboardEnd:
            return "KeyboardEnd"; /* End */
        case kHIDUsage_KeyboardPageDown:
            return "KeyboardPageDown"; /* Page Down */
        case kHIDUsage_KeyboardRightArrow:
            return "KeyboardRightArrow"; /* Right Arrow */
        case kHIDUsage_KeyboardLeftArrow:
            return "KeyboardLeftArrow"; /* Left Arrow */
        case kHIDUsage_KeyboardDownArrow:
            return "KeyboardDownArrow"; /* Down Arrow */
        case kHIDUsage_KeyboardUpArrow:
            return "KeyboardUpArrow"; /* Up Arrow */
        case kHIDUsage_KeypadNumLock:
            return "KeypadNumLock"; /* Keypad NumLock or Clear */
        case kHIDUsage_KeypadSlash:
            return "KeypadSlash"; /* Keypad / */
        case kHIDUsage_KeypadAsterisk:
            return "KeypadAsterisk"; /* Keypad * */
        case kHIDUsage_KeypadHyphen:
            return "KeypadHyphen"; /* Keypad - */
        case kHIDUsage_KeypadPlus:
            return "KeypadPlus"; /* Keypad + */
        case kHIDUsage_KeypadEnter:
            return "KeypadEnter"; /* Keypad Enter */
        case kHIDUsage_Keypad1:
            return "Keypad1"; /* Keypad 1 or End */
        case kHIDUsage_Keypad2:
            return "Keypad2"; /* Keypad 2 or Down Arrow */
        case kHIDUsage_Keypad3:
            return "Keypad3"; /* Keypad 3 or Page Down */
        case kHIDUsage_Keypad4:
            return "Keypad4"; /* Keypad 4 or Left Arrow */
        case kHIDUsage_Keypad5:
            return "Keypad5"; /* Keypad 5 */
        case kHIDUsage_Keypad6:
            return "Keypad6"; /* Keypad 6 or Right Arrow */
        case kHIDUsage_Keypad7:
            return "Keypad7"; /* Keypad 7 or Home */
        case kHIDUsage_Keypad8:
            return "Keypad8"; /* Keypad 8 or Up Arrow */
        case kHIDUsage_Keypad9:
            return "Keypad9"; /* Keypad 9 or Page Up */
        case kHIDUsage_Keypad0:
            return "Keypad0"; /* Keypad 0 or Insert */
        case kHIDUsage_KeypadPeriod:
            return "KeypadPeriod"; /* Keypad . or Delete */
        case kHIDUsage_KeyboardNonUSBackslash:
            return "KeyboardNonUSBackslash"; /* Non-US \ or | */
        case kHIDUsage_KeyboardApplication:
            return "KeyboardApplication"; /* Application */
        case kHIDUsage_KeyboardPower:
            return "KeyboardPower"; /* Power */
        case kHIDUsage_KeypadEqualSign:
            return "KeypadEqualSign"; /* Keypad = */
        case kHIDUsage_KeyboardF13:
            return "KeyboardF13"; /* F13 */
        case kHIDUsage_KeyboardF14:
            return "KeyboardF14"; /* F14 */
        case kHIDUsage_KeyboardF15:
            return "KeyboardF15"; /* F15 */
        case kHIDUsage_KeyboardF16:
            return "KeyboardF16"; /* F16 */
        case kHIDUsage_KeyboardF17:
            return "KeyboardF17"; /* F17 */
        case kHIDUsage_KeyboardF18:
            return "KeyboardF18"; /* F18 */
        case kHIDUsage_KeyboardF19:
            return "KeyboardF19"; /* F19 */
        case kHIDUsage_KeyboardF20:
            return "KeyboardF20"; /* F20 */
        case kHIDUsage_KeyboardF21:
            return "KeyboardF21"; /* F21 */
        case kHIDUsage_KeyboardF22:
            return "KeyboardF22"; /* F22 */
        case kHIDUsage_KeyboardF23:
            return "KeyboardF23"; /* F23 */
        case kHIDUsage_KeyboardF24:
            return "KeyboardF24"; /* F24 */
        case kHIDUsage_KeyboardExecute:
            return "KeyboardExecute"; /* Execute */
        case kHIDUsage_KeyboardHelp:
            return "KeyboardHelp"; /* Help */
        case kHIDUsage_KeyboardMenu:
            return "KeyboardMenu"; /* Menu */
        case kHIDUsage_KeyboardSelect:
            return "KeyboardSelect"; /* Select */
        case kHIDUsage_KeyboardStop:
            return "KeyboardStop"; /* Stop */
        case kHIDUsage_KeyboardAgain:
            return "KeyboardAgain"; /* Again */
        case kHIDUsage_KeyboardUndo:
            return "KeyboardUndo"; /* Undo */
        case kHIDUsage_KeyboardCut:
            return "KeyboardCut"; /* Cut */
        case kHIDUsage_KeyboardCopy:
            return "KeyboardCopy"; /* Copy */
        case kHIDUsage_KeyboardPaste:
            return "KeyboardPaste"; /* Paste */
        case kHIDUsage_KeyboardFind:
            return "KeyboardFind"; /* Find */
        case kHIDUsage_KeyboardMute:
            return "KeyboardMute"; /* Mute */
        case kHIDUsage_KeyboardVolumeUp:
            return "KeyboardVolumeUp"; /* Volume Up */
        case kHIDUsage_KeyboardVolumeDown:
            return "KeyboardVolumeDown"; /* Volume Down */
        case kHIDUsage_KeyboardLockingCapsLock:
            return "KeyboardLockingCapsLock"; /* Locking Caps Lock */
        case kHIDUsage_KeyboardLockingNumLock:
            return "KeyboardLockingNumLock"; /* Locking Num Lock */
        case kHIDUsage_KeyboardLockingScrollLock:
            return "KeyboardLockingScrollLock"; /* Locking Scroll Lock */
        case kHIDUsage_KeypadComma:
            return "KeypadComma"; /* Keypad Comma */
        case kHIDUsage_KeypadEqualSignAS400:
            return "KeypadEqualSignAS400"; /* Keypad Equal Sign for AS/400 */
        case kHIDUsage_KeyboardInternational1:
            return "KeyboardInternational1"; /* International1 */
        case kHIDUsage_KeyboardInternational2:
            return "KeyboardInternational2"; /* International2 */
        case kHIDUsage_KeyboardInternational3:
            return "KeyboardInternational3"; /* International3 */
        case kHIDUsage_KeyboardInternational4:
            return "KeyboardInternational4"; /* International4 */
        case kHIDUsage_KeyboardInternational5:
            return "KeyboardInternational5"; /* International5 */
        case kHIDUsage_KeyboardInternational6:
            return "KeyboardInternational6"; /* International6 */
        case kHIDUsage_KeyboardInternational7:
            return "KeyboardInternational7"; /* International7 */
        case kHIDUsage_KeyboardInternational8:
            return "KeyboardInternational8"; /* International8 */
        case kHIDUsage_KeyboardInternational9:
            return "KeyboardInternational9"; /* International9 */
        case kHIDUsage_KeyboardLANG1:
            return "KeyboardLANG1"; /* LANG1 */
        case kHIDUsage_KeyboardLANG2:
            return "KeyboardLANG2"; /* LANG2 */
        case kHIDUsage_KeyboardLANG3:
            return "KeyboardLANG3"; /* LANG3 */
        case kHIDUsage_KeyboardLANG4:
            return "KeyboardLANG4"; /* LANG4 */
        case kHIDUsage_KeyboardLANG5:
            return "KeyboardLANG5"; /* LANG5 */
        case kHIDUsage_KeyboardLANG6:
            return "KeyboardLANG6"; /* LANG6 */
        case kHIDUsage_KeyboardLANG7:
            return "KeyboardLANG7"; /* LANG7 */
        case kHIDUsage_KeyboardLANG8:
            return "KeyboardLANG8"; /* LANG8 */
        case kHIDUsage_KeyboardLANG9:
            return "KeyboardLANG9"; /* LANG9 */
        case kHIDUsage_KeyboardAlternateErase:
            return "KeyboardAlternateErase"; /* AlternateErase */
        case kHIDUsage_KeyboardSysReqOrAttention:
            return "KeyboardSysReqOrAttention"; /* SysReq/Attention */
        case kHIDUsage_KeyboardCancel:
            return "KeyboardCancel"; /* Cancel */
        case kHIDUsage_KeyboardClear:
            return "KeyboardClear"; /* Clear */
        case kHIDUsage_KeyboardPrior:
            return "KeyboardPrior"; /* Prior */
        case kHIDUsage_KeyboardReturn:
            return "KeyboardReturn"; /* Return */
        case kHIDUsage_KeyboardSeparator:
            return "KeyboardSeparator"; /* Separator */
        case kHIDUsage_KeyboardOut:
            return "KeyboardOut"; /* Out */
        case kHIDUsage_KeyboardOper:
            return "KeyboardOper"; /* Oper */
        case kHIDUsage_KeyboardClearOrAgain:
            return "KeyboardClearOrAgain"; /* Clear/Again */
        case kHIDUsage_KeyboardCrSelOrProps:
            return "KeyboardCrSelOrProps"; /* CrSel/Props */
        case kHIDUsage_KeyboardExSel:
            return "KeyboardExSel"; /* ExSel */
        /* 0xA5-0xDF Reserved */
        case kHIDUsage_KeyboardLeftControl:
            return "KeyboardLeftControl"; /* Left Control */
        case kHIDUsage_KeyboardLeftShift:
            return "KeyboardLeftShift"; /* Left Shift */
        case kHIDUsage_KeyboardLeftAlt:
            return "KeyboardLeftAlt"; /* Left Alt */
        case kHIDUsage_KeyboardLeftGUI:
            return "KeyboardLeftGUI"; /* Left GUI */
        case kHIDUsage_KeyboardRightControl:
            return "KeyboardRightControl"; /* Right Control */
        case kHIDUsage_KeyboardRightShift:
            return "KeyboardRightShift"; /* Right Shift */
        case kHIDUsage_KeyboardRightAlt:
            return "KeyboardRightAlt"; /* Right Alt */
        case kHIDUsage_KeyboardRightGUI:
            return "KeyboardRightGUI"; /* Right GUI */
    }
    return "Unknown";
}

const char*hidUsagePageString(long usagePage)
{
    switch(usagePage)
    {
    case kHIDPage_Undefined:
            return "Undefined";
    case kHIDPage_GenericDesktop:
            return "GenericDesktop";
    case kHIDPage_Simulation:
            return "Simulation";
    case kHIDPage_VR:
            return "VR";
    case kHIDPage_Sport:
            return "Sport";
    case kHIDPage_Game:
            return "Game";
    /* Reserved 0x06 */
    case kHIDPage_KeyboardOrKeypad:
            return "KeyboardOrKeypad"; /* USB Device Class Definition for Human Interface Devices (HID). Note: the usage type for all key codes is Selector (Sel). */
    case kHIDPage_LEDs:
            return "LEDs";
    case kHIDPage_Button:
            return "Button";
    case kHIDPage_Ordinal:
            return "Ordinal";
    case kHIDPage_Telephony:
            return "Telephony";
    case kHIDPage_Consumer:
            return "Consumer";
    case kHIDPage_Digitizer:
            return "Digitizer";
    /* Reserved 0x0E */
    case kHIDPage_PID:
            return "PID"; /* USB Physical Interface Device definitions for force feedback and related devices. */
    case kHIDPage_Unicode:
            return "Unicode";
    /* Reserved 0x11 - 0x13 */
    case kHIDPage_AlphanumericDisplay:
            return "AlphanumericDisplay";
    /* Reserved 0x15 - 0x7F */
    /* Monitor 0x80 - 0x83   USB Device Class Definition for Monitor Devices */
    /* Power 0x84 - 0x87     USB Device Class Definition for Power Devices */
    case kHIDPage_PowerDevice:
            return "PowerDevice";                /* Power Device Page */
    case kHIDPage_BatterySystem:
            return "BatterySystem";              /* Battery System Page */
    /* Reserved 0x88 - 0x8B */
    case kHIDPage_BarCodeScanner:
            return "BarCodeScanner"; /* (Point of Sale) USB Device Class Definition for Bar Code Scanner Devices */
    case kHIDPage_WeighingDevice:
            return "WeighingDevice"; /* (Point of Sale) USB Device Class Definition for Weighing Devices */
    case kHIDPage_MagneticStripeReader:
            return "MagneticStripeReader";
    /* ReservedPointofSalepages 0x8F */
    case kHIDPage_CameraControl:
            return "CameraControl"; /* USB Device Class Definition for Image Class Devices */
    case kHIDPage_Arcade:
            return "Arcade"; /* OAAF Definitions for arcade and coinop related Devices */
    /* Reserved 0x92 - 0xFEFF */
    /* VendorDefined 0xFF00 - 0xFFFF */
    case kHIDPage_VendorDefinedStart:
        return "VendorDefinedStart";
    default:
        return "Unknown";
}
}

const char *hidTypeString(IOHIDElementType type) {
    switch(type)
    {
    case kIOHIDElementTypeInput_ScanCodes:
        return (" ScanCode  ");
        break;
    case kIOHIDElementTypeInput_Misc:
        return (" Misc      ");
        break;
    case kIOHIDElementTypeInput_Button:
        return (" Button    ");
        break;
    case kIOHIDElementTypeInput_Axis:
        return (" Axis      ");
        break;
    case kIOHIDElementTypeOutput:
        return (" Output    ");
        break;
    case kIOHIDElementTypeFeature:
        return (" Feature   ");
        break;
    case kIOHIDElementTypeCollection:
        return (" Collection");
        break;
    }
    return "Unknown";
}
