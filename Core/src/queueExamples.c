/*
 * queueExamples.c
 *
 *  Created on: 31-Oct-2023
 *      Author: LENOVO
 */
#include "Appinterface.h"
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "stdio.h"
#include "queue.h"

#define QUEUE_LENGTH    5
#define ITEM_SIZE       sizeof(uint32_t)

QueueHandle_t qHandle = NULL;

uint32_t Data[] = {10, 15, 19, 21, 9};

uint32_t uxBuffer[QUEUE_LENGTH];

void qCreate(void);
void qSendToBack();
void qSendToFront();
void qReceive(void);
void qDelete(void);


void queueExamples()
{
    qCreate();

//    qSendToBack();

    qSendToFront();

    qReceive();

    qDelete();

    while(1);
}

void qCreate()
{

    puts("Queue starts \n");
    fflush(stdout);

    qHandle = xQueueCreate(QUEUE_LENGTH, ITEM_SIZE);
    configASSERT(qHandle);
}

void qSendToBack()
{
    int i;

    for(i=0; i<QUEUE_LENGTH; i++)
    {
        if (xQueueSendToBack(qHandle, &Data[i], (TickType_t) 0) == pdPASS)
        {
            puts("Data sent successfully to Queue \n");
            fflush(stdout);
        }
    }
}

void qSendToFront()
{
    int i;

    for(i=0; i<QUEUE_LENGTH; i++)
    {
        if (xQueueSendToFront(qHandle, &Data[i], (TickType_t) 0) == pdPASS)
        {
            puts("Data sent successfully to Queue \n");
            fflush(stdout);
        }
    }
}

void qReceive(void)
{
    int i;

    for(i=0; i<QUEUE_LENGTH; i++)
    {
        if (xQueueReceive(qHandle, &uxBuffer[i], (TickType_t)10)  == pdPASS)
        {
            puts("Data received successfully from Queue \n");
            fflush(stdout);
        }
    }
}

void qDelete()
{
    if(qHandle != NULL)
    {
       vQueueDelete(qHandle);
    }
}


