#include <stdio.h>
#include "linked_list.h"

int main()
{
    LinkedList list;
    LINKED_LIST_Status_e status;

    status = LINKED_LIST_Init(&list);

    if (status == LINKED_LIST_NO_ERROR)
    {
        printf("Linked List Initialized\n");
    }
    else
    {
        printf("Linked List Initialization Failed\n");
    }

    status = LINKED_LIST_Insert(&list, 10, 0);

    if (status == LINKED_LIST_NO_ERROR)
    {
        printf("Data Inserted\n");
    }
    else
    {
        printf("Data Insert Failed\n");
    }

    status = LINKED_LIST_Insert(&list, 20, 1);
    status = LINKED_LIST_Insert(&list, 30, 2);
    status = LINKED_LIST_Insert(&list, 40, 3);
    if (status == LINKED_LIST_NO_ERROR)
    {
        printf("Data Inserted\n");
    }
    else
    {
        printf("Data Insert Failed\n");
    }
    status = LINKED_LIST_Insert(&list, 50, 4);
    if (status == LINKED_LIST_NO_ERROR)
    {
        printf("Data Inserted\n");
    }
    else
    {
        printf("Data Insert Failed\n");
    }
    status = LINKED_LIST_Insert(&list, 60, 5);
    if (status == LINKED_LIST_NO_ERROR)
    {
        printf("Data Inserted\n");
    }
    else
    {
        printf("Data Insert Failed\n");
        printf("Error : %d\n", status);
    }
    return 0;
}