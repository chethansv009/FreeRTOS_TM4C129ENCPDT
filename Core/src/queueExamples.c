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

uint32_t peakElement;


//Functions that will operate on the queue
void qCreate(void);
void qSendToBack();
void qSendToFront();
void qNumMsgInBuffer();
void qReceive(void);
void qDelete(void);
void qPeakElement(void);


void queueExamples()
{
    //create a queue
    qCreate();

    //Add the elements to the queue back side
    qSendToBack();

    //Add the elemts to the queue front side
    qSendToFront();

    //Number of elements in a queue
    qNumMsgInBuffer();

    //First or peak elements on the queue
    qPeakElement();

    //Pop or recieve the elements from the queue
    qReceive();

    //Delete the queue
    qDelete();

    while(1);
}

void qPeakElement(void)
{
    if(qHandle != NULL)
    {
        if ( xQueuePeek(qHandle, &peakElement, ( TickType_t )10 ) == pdPASS )
        {
            puts("Peak elements is copied \n");
        }
    }
}

void qNumMsgInBuffer()
{
    uint32_t msgNum = uxQueueMessagesWaiting(qHandle);
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


