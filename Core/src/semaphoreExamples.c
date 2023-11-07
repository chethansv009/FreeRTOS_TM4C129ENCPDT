
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"

uint32_t rd_wr_Data = 0;

SemaphoreHandle_t semHandle;

TaskHandle_t handle1 = NULL, handle2 = NULL;

void task1Function();
void task2Function();

void semaphoreExamples(void)
{

    BaseType_t tskSt;

    tskSt = xTaskCreate(task1Function, "task1", configMINIMAL_STACK_SIZE, NULL, (UBaseType_t)1, &handle1);
    configASSERT(tskSt);

    tskSt = xTaskCreate(task2Function, "task2", configMINIMAL_STACK_SIZE, NULL, (UBaseType_t)1, &handle2);
    configASSERT(tskSt);

    semHandle = xSemaphoreCreateMutex();
    configASSERT(semHandle);


    vTaskStartScheduler();

    while(1);
}

void task1Function()
{
    int i;
    for(i=0; i<0xFFFF; i++)
    {
        if(semHandle != NULL)
        {
            if(xSemaphoreTake(semHandle, 10) == pdPASS)
            {
                rd_wr_Data += 1;
                printf("Write the data: %u\n", rd_wr_Data);
                xSemaphoreGive(semHandle);
            }
            else
            {
                puts("Failed to get the semaphore \n");
                fflush(stdout);
            }
        }
        vTaskDelay(100);
    }
}

void task2Function()
{
    while(1)
    {
        if(semHandle != NULL)
        {
            if(xSemaphoreTake(semHandle, 10) == pdPASS)
            {
                printf("data read from critical section: %u\n ", rd_wr_Data);
                xSemaphoreGive(semHandle);
            }
            else
            {
                puts("Failed to get the semaphore \n");
                fflush(stdout);
            }
        }
        vTaskDelay(100);
    }
}
