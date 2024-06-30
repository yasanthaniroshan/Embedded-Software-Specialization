#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdint.h>

/*
    * @brief Node Structure
    * @details This structure is used to define the node of the linked list
*/
typedef struct Node
{
    uint8_t data;
    struct Node *next;
    struct Node *prev;
} Node;

/*
    * @brief Linked List Structure
    * @details This structure is used to define the linked list
*/
typedef struct 
{
    Node *head;
    Node *tail;
    uint8_t count;
} LinkedList;

/*
* @brief Status of Linked List Operation
*/
typedef enum
{
    LINKED_LIST_ERROR = -1,
    LINKED_LIST_NO_ERROR = 0,
    LINKED_LIST_FULL,
    LINKED_LIST_NOT_FULL,
    LINKED_LIST_EMPTY,
    LINKED_LIST_NOT_EMPTY,
    LINKED_LIST_NULL,
    LINKED_LIST_ELEMENT_NOT_FOUND,
    LINKED_LIST_ELEMENT_FOUND,
    LINKED_LIST_ELEMENT_INSERTED,
    LINKED_LIST_ELEMENT_REMOVED,
    LINKED_LIST_ELEMENT_UPDATED,

} LINKED_LIST_Status_e;

/*
* @brief Initialize Linked List
* @details This function is used to initialize the linked list
* @param list Linked List Pointer
* @return Status of the operation
*/
LINKED_LIST_Status_e LINKED_LIST_Init(LinkedList *list);
/*
* @brief Insert Data to Linked List
* @details This function is used to insert data to the linked list
* @param list Linked List Pointer
* @param data Data to be inserted
* @param position Position to insert the data
* @return Status of the operation
*/
LINKED_LIST_Status_e LINKED_LIST_Insert(LinkedList *list, uint8_t data, uint8_t position);

/*
* @brief Append Data to Linked List
* @details This function is used to append data to the linked list
* @param list Linked List Pointer
* @param data Data to be appended
* @return Status of the operation
*/
LINKED_LIST_Status_e LINKED_LIST_Append(LinkedList *list, uint8_t data);
/*
* @brief Remove Data from Linked List
* @details This function is used to remove data from the linked list
* @param list Linked List Pointer
* @param data Data to be removed
* @param position Position to remove the data
* @return Status of the operation
*/
LINKED_LIST_Status_e LINKED_LIST_Remove(LinkedList *list, uint8_t position);

/*
* @brief Delete Data from Linked List
* @details This function is used to delete data from the linked list
* @param list Linked List Pointer
* @param data Data to be deleted
* @return Status of the operation
*/
LINKED_LIST_Status_e LINKED_LIST_Delete(LinkedList *list, uint8_t data);

/*
* @brief Search Data in Linked List
* @details This function is used to search data in the linked list
* @param list Linked List Pointer
* @param data Data to be searched
* @return Status of the operation
*/
LINKED_LIST_Status_e LINKED_LIST_Search(LinkedList *list, uint8_t data);

/*
* @brief Update Data in Linked List
* @details This function is used to update data in the linked list
* @param list Linked List Pointer
* @param data Data to be updated
* @param position Position to update the data
* @return Status of the operation
*/
LINKED_LIST_Status_e LINKED_LIST_Update(LinkedList *list, uint8_t data, uint8_t position);

/*
* @brief Get Data from Linked List
* @details This function is used to get data from the linked list
* @param list Linked List Pointer
* @param data Data to be get
* @param position Position to get the data
* @return Status of the operation
*/
LINKED_LIST_Status_e LINKED_LIST_Get(LinkedList *list, uint8_t *data, uint8_t position);



#endif // __LINKED_LIST_H__