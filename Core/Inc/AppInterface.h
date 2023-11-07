#ifndef __APPINTERFACE_H__
#define __APPINTERFACE_H__

#include "stdio.h"
#include <stdint.h>
#include <stdbool.h>

extern void vAssertCalled(char *FileName, uint32_t LineNum);
extern int taskExamples(void);
extern void queueExamples(void);
extern void semaphoreExamples(void);

#endif
