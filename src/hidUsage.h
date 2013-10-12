#ifndef HIDUSAGE_H_
#define HIDUSAGE_H_

#include <IOKit/hid/IOHIDKeys.h>
#include <IOKit/hid/IOHIDUsageTables.h>

const char * hidUsageString(long usagePage, long usage);
const char * hidGenericUsageString(long usage);
const char * hidKeyboardUsageString(long usage);
;const char * hidUsagePageString(long usagePage);
const char *hidTypeString(IOHIDElementType type);


#endif /* HIDUSAGE_H_ */
