#include <stdio.h>
#include "LIFO_Buffer.h"

int main()
{
    LIFO_Buffer_t lbuf;
    LIFO_Status_e status;
    status = LIFO_Init(&lbuf);
    if (status == LIFO_NO_ERROR)
    {
        printf("LIFO_Init: OK\n");
    }
    else
    {
        printf("LIFO_Init: Error\n");
    }
}