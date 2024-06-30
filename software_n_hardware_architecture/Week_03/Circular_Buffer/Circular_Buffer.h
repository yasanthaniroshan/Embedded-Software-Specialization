#ifndef __CIRCULAR_BUFFER_H__
#define __CIRCULAR_BUFFER_H__

#include <stdint.h>
/*
    * Buffer size for circular buffer
*/
#define CIRCULAR_BUFFER_SIZE 5

/*
* @brief Status of Circular Buffer Operation
* @details This enum is used to define the status of the circular buffer operation
*/
typedef enum
{
    CIRCULAR_ERROR = -1,
    CIRCULAR_NO_ERROR = 0,
    CIRCULAR_FULL,
    CIRCULAR_NOT_FULL,
    CIRCULAR_EMPTY,
    CIRCULAR_NOT_EMPTY,
    CIRCULAR_NULL
} CIRCULAR_Status_e;

/*
* @brief Circular Buffer Structure
* @details This structure is used to define the circular buffer
*/
typedef struct
{
    uint8_t count;
    uint8_t length;
    uint8_t *base;
    uint8_t *head;
    uint8_t *tail;

} CIRCULAR_Buffer_t;

/*
* @brief Initialize Circular Buffer
* @details This function is used to initialize the circular buffer
* @param cbuf Circular Buffer Pointer
* @return Status of the operation
*/
CIRCULAR_Status_e CIRCULAR_Init(CIRCULAR_Buffer_t *cbuf);

/*
* @brief Enqueue Data to Circular Buffer
* @details This function is used to enqueue data to the circular buffer
* @param cbuf Circular Buffer Pointer
* @param data Data to be enqueued
* @return Status of the operation
*/
CIRCULAR_Status_e CIRCULAR_Enqueue(CIRCULAR_Buffer_t *cbuf, uint8_t data);

/*
* @brief Dequeue Data from Circular Buffer
* @details This function is used to dequeue data from the circular buffer
* @param cbuf Circular Buffer Pointer
* @param data Data to be dequeued
* @return Status of the operation
*/
CIRCULAR_Status_e CIRCULAR_Dequeue(CIRCULAR_Buffer_t *cbuf, uint8_t *data);

/*
* @brief Check if Circular Buffer is Full
* @details This function is used to check if the circular buffer is full
* @param cbuf Circular Buffer Pointer
* @return Status of the operation
*/
CIRCULAR_Status_e CIRCULAR_IsFull(CIRCULAR_Buffer_t *cbuf);

/*
* @brief Check if Circular Buffer is Empty
* @details This function is used to check if the circular buffer is empty
* @param cbuf Circular Buffer Pointer
* @return Status of the operation
*/
CIRCULAR_Status_e CIRCULAR_IsEmpty(CIRCULAR_Buffer_t *cbuf);


#endif // __CIRCULAR_BUFFER_H__