#include <stdlib.h>
#include "LIFO_Buffer.h"

/**
 * @brief This function initializes the LIFO buffer
 * @param LIFO_Buffer_t *lbuf: Pointer to the LIFO buffer
 * @return LIFO_Status_e: Status of the function
 */
LIFO_Status_e LIFO_Init(LIFO_Buffer_t *lbuf)
{
    if (lbuf == NULL)
    {
        return LIFO_NULL;
    }
    lbuf->base = (uint8_t *)malloc(LIFO_BUFFER_SIZE);
    if (lbuf->base == NULL)
    {
        return LIFO_NULL;
    }
    lbuf->head = lbuf->base;
    lbuf->length = 0;
    return LIFO_NO_ERROR;
}

/**
 * @brief This function pushes data to the LIFO buffer
 * @param LIFO_Buffer_t *lbuf: Pointer to the LIFO buffer
 * @param uint8_t data: Data to be pushed to the LIFO buffer
 * @return LIFO_Status_e: Status of the function
 */
LIFO_Status_e LIFO_Push(LIFO_Buffer_t *lbuf, uint8_t data)
{
    if (lbuf == NULL)
    {
        return LIFO_NULL;
    }
    if (lbuf->length == LIFO_BUFFER_SIZE)
    {
        return LIFO_FULL;
    }
    *(lbuf->head) = data;
    lbuf->head++;
    lbuf->length++;
    return LIFO_NO_ERROR;
}

/**
 * @brief This function pops data from the LIFO buffer
 * @param LIFO_Buffer_t *lbuf: Pointer to the LIFO buffer
 * @param uint8_t *data: Pointer to the data to be popped from the LIFO buffer
 * @return LIFO_Status_e: Status of the function
 */
LIFO_Status_e LIFO_Pop(LIFO_Buffer_t *lbuf, uint8_t *data)
{
    if (lbuf == NULL)
    {
        return LIFO_NULL;
    }
    if (lbuf->length == 0)
    {
        return LIFO_EMPTY;
    }
    lbuf->head--;
    *data = *(lbuf->head);
    lbuf->length--;
    return LIFO_NO_ERROR;
}

/**
 * @brief This function checks if the LIFO buffer is full
 * @param LIFO_Buffer_t *lbuf: Pointer to the LIFO buffer
 * @return LIFO_Status_e: Status of the function
 */
LIFO_Status_e LIFO_IsFull(LIFO_Buffer_t *lbuf)
{
    if (lbuf == NULL)
    {
        return LIFO_NULL;
    }
    if (lbuf->length == LIFO_BUFFER_SIZE)
    {
        return LIFO_FULL;
    }
    return LIFO_NOT_FULL;
}

/**
 * @brief This function checks if the LIFO buffer is empty
 * @param LIFO_Buffer_t *lbuf: Pointer to the LIFO buffer
 * @return LIFO_Status_e: Status of the function
 */
LIFO_Status_e LIFO_IsEmpty(LIFO_Buffer_t *lbuf)
{
    if (lbuf == NULL)
    {
        return LIFO_NULL;
    }
    if (lbuf->length == 0)
    {
        return LIFO_EMPTY;
    }
    return LIFO_NOT_EMPTY;
}

