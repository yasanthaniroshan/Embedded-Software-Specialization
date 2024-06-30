#ifndef __LIFO_BUFFER_H__
#define __LIFO_BUFFER_H__

#include <stdint.h>

/*Defined Buffer Size*/
#define LIFO_BUFFER_SIZE 10
/**
 * @brief This enum defines the possible status codes for operations on a LIFO (Last In, First Out) buffer.
 * @enum LIFO_Status_e
 */
typedef enum
{
    LIFO_NO_ERROR,    /**< No error, operation successful */
    LIFO_FULL,        /**< The LIFO buffer is full */
    LIFO_NOT_FULL,    /**< The LIFO buffer is not full */
    LIFO_EMPTY,       /**< The LIFO buffer is empty */
    LIFO_NOT_EMPTY,   /**< The LIFO buffer is not empty */
    LIFO_NULL         /**< The LIFO buffer is NULL (uninitialized or invalid) */
} LIFO_Status_e;

/** 
    * @brief This struct defines a LIFO (Last In, First Out) buffer.
    * @struct LIFO_Buffer_t
    * @param uint8_t length: The length of the LIFO buffer
    * @param uint8_t *base: Pointer to the base of the LIFO buffer
    * @param uint8_t *head: Pointer to the head of the LIFO buffer
*/
typedef struct
{
    uint8_t length;
    uint8_t *base;
    uint8_t *head;
} LIFO_Buffer_t;

LIFO_Status_e LIFO_Init(LIFO_Buffer_t *lbuf);
LIFO_Status_e LIFO_Push(LIFO_Buffer_t *lbuf, uint8_t data);
LIFO_Status_e LIFO_Pop(LIFO_Buffer_t *lbuf, uint8_t *data);
LIFO_Status_e LIFO_IsFull(LIFO_Buffer_t *lbuf);
LIFO_Status_e LIFO_IsEmpty(LIFO_Buffer_t *lbuf);


#endif // __LIFO_BUFFER_H__