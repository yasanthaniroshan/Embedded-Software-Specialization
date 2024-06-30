#include "Circular_Buffer.h"
#include <stdlib.h>

CIRCULAR_Status_e CIRCULAR_Init(CIRCULAR_Buffer_t *cbuf)
{
    if (cbuf == NULL)
    {
        return CIRCULAR_NULL;
    }
    cbuf->base = (uint8_t *)malloc(CIRCULAR_BUFFER_SIZE * sizeof(uint8_t));
    if (cbuf->base == NULL)
    {
        return CIRCULAR_ERROR;
    }

    cbuf->length = CIRCULAR_BUFFER_SIZE;
    cbuf->count = 0;
    cbuf->head = cbuf->base;
    cbuf->tail = cbuf->base;

    return CIRCULAR_NO_ERROR;
}

CIRCULAR_Status_e CIRCULAR_Enqueue(CIRCULAR_Buffer_t *cbuf, uint8_t data)
{
    if (cbuf == NULL)
        return CIRCULAR_NULL;
    if (cbuf->count == cbuf->length)
        return CIRCULAR_FULL;

    cbuf->count++;
    *cbuf->head = data;
    cbuf->head++;

    if (cbuf->head == cbuf->base + cbuf->length)
    {
        cbuf->head = cbuf->base;
    }

    return CIRCULAR_NO_ERROR;
}

CIRCULAR_Status_e CIRCULAR_Dequeue(CIRCULAR_Buffer_t *cbuf, uint8_t *data)
{
    if (cbuf == NULL)
        return CIRCULAR_NULL;
    if (cbuf->count == 0)
        return CIRCULAR_EMPTY;

    cbuf->count--;
    *data = *cbuf->tail;
    cbuf->tail++;

    if (cbuf->tail == cbuf->base + cbuf->length)
    {
        cbuf->tail = cbuf->base;
    }

    return CIRCULAR_NO_ERROR;
}

CIRCULAR_Status_e CIRCULAR_IsFull(CIRCULAR_Buffer_t *cbuf)
{
    if (cbuf == NULL)
        return CIRCULAR_NULL;
    if (cbuf->count == cbuf->length)
        return CIRCULAR_FULL;
    else
        return CIRCULAR_NOT_FULL;
}

CIRCULAR_Status_e CIRCULAR_IsEmpty(CIRCULAR_Buffer_t *cbuf)
{
    if (cbuf == NULL)
        return CIRCULAR_NULL;
    if (cbuf->count == 0)
        return CIRCULAR_EMPTY;
    else
        return CIRCULAR_NOT_EMPTY;
}

