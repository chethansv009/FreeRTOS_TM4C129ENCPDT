/*
 * main.c
 *
 *  Created on: 31-Oct-2023
 *      Author: LENOVO
 */

#include "Appinterface.h"

int main()
{

    // Comment taskExample to check other functionalities because it's running in infinite loop
//    taskExamples();

    queueExamples();

    return 0;
}

void vAssertCalled(char *FileName, uint32_t LineNum)
{
   puts("Fault Handler");
   fflush(stdout);

   puts(FileName);
   fflush(stdout);

   while(1);
}


