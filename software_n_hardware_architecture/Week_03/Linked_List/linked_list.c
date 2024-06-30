#include <stdlib.h>  // Add this line to include the standard library
#include "linked_list.h"

LINKED_LIST_Status_e LINKED_LIST_Init(LinkedList *list)
{
    if (list == NULL)
        return LINKED_LIST_NULL;

    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    return LINKED_LIST_NO_ERROR;
}

LINKED_LIST_Status_e LINKED_LIST_Insert(LinkedList *list, uint8_t data, uint8_t position)
{
    if (list == NULL)
        return LINKED_LIST_NULL;
    if (position > list->count)
    {
        return LINKED_LIST_ERROR;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return LINKED_LIST_ERROR;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        Node *temp = list->head;
        for (uint8_t i = 0; i < position; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        if (newNode->next != NULL)
        {
            newNode->next->prev = newNode;
        }
        if (position == list->count)
        {
            list->tail = newNode;
        }
    }
    list->count++;
    return LINKED_LIST_NO_ERROR;
}

LINKED_LIST_Status_e LINKED_LIST_Remove(LinkedList *list, uint8_t position)
{
    if (list == NULL)
        return LINKED_LIST_NULL;
    if (position >= list->count)
    {
        return LINKED_LIST_ERROR;
    }
    Node *temp = list->head;
    for (uint8_t i = 0; i < position; i++)
    {
        temp = temp->next;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    if (position == 0)
    {
        list->head = temp->next;
    }
    if (position == list->count - 1)
    {
        list->tail = temp->prev;
    }
    free(temp);
    list->count--;
    return LINKED_LIST_NO_ERROR;
}

LINKED_LIST_Status_e LINKED_LIST_Delete(LinkedList *list, uint8_t data)
{
    if (list == NULL)
        return LINKED_LIST_NULL;
    Node *temp = list->head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            if (temp->prev != NULL)
            {
                temp->prev->next = temp->next;
            }
            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }
            if (temp == list->head)
            {
                list->head = temp->next;
            }
            if (temp == list->tail)
            {
                list->tail = temp->prev;
            }
            free(temp);
            list->count--;
            return LINKED_LIST_ELEMENT_REMOVED;
        }
        temp = temp->next;
    }
    return LINKED_LIST_ELEMENT_NOT_FOUND;
}

LINKED_LIST_Status_e LINKED_LIST_Search(LinkedList *list, uint8_t data)
{
    if (list == NULL)
        return LINKED_LIST_NULL;
    Node *temp = list->head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return LINKED_LIST_ELEMENT_FOUND;
        }
        temp = temp->next;
    }
    return LINKED_LIST_ELEMENT_NOT_FOUND;
}


LINKED_LIST_Status_e LINKED_LIST_Update(LinkedList *list, uint8_t data, uint8_t position)
{
    if (list == NULL)
        return LINKED_LIST_NULL;
    if (position >= list->count)
    {
        return LINKED_LIST_ERROR;
    }
    Node *temp = list->head;
    for (uint8_t i = 0; i < position; i++)
    {
        temp = temp->next;
    }
    temp->data = data;
    return LINKED_LIST_ELEMENT_UPDATED;
}

LINKED_LIST_Status_e LINKED_LIST_Get(LinkedList *list, uint8_t *data, uint8_t position)
{
    if (list == NULL)
        return LINKED_LIST_NULL;
    if (position >= list->count)
    {
        return LINKED_LIST_ERROR;
    }
    Node *temp = list->head;
    for (uint8_t i = 0; i < position; i++)
    {
        temp = temp->next;
    }
    *data = temp->data;
    return LINKED_LIST_NO_ERROR;
}
