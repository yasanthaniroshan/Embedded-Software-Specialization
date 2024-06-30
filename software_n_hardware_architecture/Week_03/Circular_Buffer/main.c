#include <stdio.h>
#include "Circular_Buffer.h"

int main()
{
    CIRCULAR_Buffer_t cbuf;
    CIRCULAR_Status_e status;

    status = CIRCULAR_Init(&cbuf);

    if (status == CIRCULAR_NO_ERROR)
    {
        printf("Circular Buffer Initialized\n");
    }
    else
    {
        printf("Circular Buffer Initialization Failed\n");
    }

    status = CIRCULAR_Enqueue(&cbuf, 10);

    if (status == CIRCULAR_NO_ERROR)
    {
        printf("Data Enqueued\n");
    }
    else
    {
        printf("Data Enqueue Failed\n");
    }

    status = CIRCULAR_Enqueue(&cbuf, 20);
    status = CIRCULAR_Enqueue(&cbuf, 30);
    status = CIRCULAR_Enqueue(&cbuf, 40);
    if (status == CIRCULAR_NO_ERROR)
    {
        printf("Data Enqueued\n");
    }
    else
    {
        printf("Data Enqueue Failed\n");
    }
    status = CIRCULAR_Enqueue(&cbuf, 50);
    if (status == CIRCULAR_NO_ERROR)
    {
        printf("Data Enqueued\n");
    }
    else
    {
        printf("Data Enqueue Failed\n");
    }
    status = CIRCULAR_Enqueue(&cbuf, 60);
    if (status == CIRCULAR_NO_ERROR)
    {
        printf("Data Enqueued\n");
    }
    else
    {
        printf("Data Enqueue Failed\n");
        printf("Error : %d\n", status);
    }
    uint8_t data;
    status = CIRCULAR_Dequeue(&cbuf, &data);

    if (status == CIRCULAR_NO_ERROR)
    {
        printf("Data Dequeued: %d\n", data);
    }
    else
    {
        printf("Data Dequeue Failed\n");
    }
}