

/**
 * FreeRTOS application file
 * main.c
 */

#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "sysctl.h"
#include "AppInterface.h"

void Task1Handler();
void Task2Handler();

TaskHandle_t task1Handle = NULL;
TaskHandle_t task2Handle = NULL;

int taskExamples(void)
{
    BaseType_t status;
    uint32_t ui32SysClock;

    /* To print the message on CIO console heap memory should be configured
     * build setting -> Arm linker -> basic options -> in Heap tab add 512
     */
    puts("Start of project \n");
    fflush(stdout);

    ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                        SYSCTL_OSC_MAIN |
                                        SYSCTL_USE_PLL |
                                        SYSCTL_CFG_VCO_480),
                                        120000000);

    //Created a sample task1
    status = xTaskCreate(Task1Handler, "Task1",
                configMINIMAL_STACK_SIZE, NULL, 1, &task1Handle);

    configASSERT(status == pdPASS);

    //Created a sample task2
    status = xTaskCreate(Task2Handler, "Task2",
                    configMINIMAL_STACK_SIZE, NULL, 2, &task2Handle);

    configASSERT(status == pdPASS);

    puts("Scheduler Start \n");
    fflush(stdout);

    //start the scheduler
    vTaskStartScheduler();

    if (task1Handle) { vTaskDelete(task1Handle); }

    if (task2Handle) { vTaskDelete(task2Handle); }

    //If code reaches here then it is failure
    while(1)
    {
        puts("In a while loop \n");
        fflush(stdout);
    }

    return 0;
}

void Task1Handler()
{
    for( ; ; )
    {
        printf("Task1 Priority: %u\n", uxTaskPriorityGet( task1Handle ));
        xTaskNotify(task2Handle, 0, eIncrement);
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY );
        vTaskDelay(1000);
    }
}

void Task2Handler()
{
    for( ; ; )
    {
        printf("Task2 Priority: %u\n", uxTaskPriorityGet( task2Handle ));
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY );
        xTaskNotify(task1Handle, 0, eIncrement);
        vTaskDelay(1000);
    }
}


