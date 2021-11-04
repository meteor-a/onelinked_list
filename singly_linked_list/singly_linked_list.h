#ifndef ONELINKED_LIST_H__
#define ONELINKED_LIST_H__

/*------------------------------------------------------------------------------------------------------------------*/

typedef int SINGLY_LINKED_LIST; // type of elems in list

/*------------------------------------------------------------------------------------------------------------------*/
/**
 * @brief Struct elems in list's array
 * 
 */
struct ElemSinglyLinkedList {
    SINGLY_LINKED_LIST elem = 0;
    int index = -1;
};

/**
 * @brief Struct one linked list(Short: oLinkList)
 * 
 */
struct SinglyLinkedList {
    int size     = -1;
    int capacity = -1;

    ElemSinglyLinkedList* list = nullptr;

    ElemSinglyLinkedList* head = nullptr;
    ElemSinglyLinkedList* tail = nullptr;
};

/*------------------------------------------------------------------------------------------------------------------*/

const char* ERROR_BAD_POINTER__   = "Programm has detected bad pointer";
const char* ERROR_CANT_CALLOC_MEM = "Programm can't calloc more memory";
const char* ERROR_PUSH_AFTER_TAIL = "Programm detected pushing elem after index, which is more that size of the list";
const char* ERROR_POP_AFTER_TAIL  = "Programm detected pop elem after index, which is more that size of the list";

/*------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Prototype of constructor singly linked list
 * 
 * @param sLinkList 
 * @return int (0 - if all is OK; 1 -if was errors) 
 */
int SinglyLinkedListConstructor(SinglyLinkedList* sLinkList);

/**
 * @brief Prototype of destructor singly linked list
 * 
 * @param sLinkList 
 * @return int (0 - if all is OK; 1 -if was errors) 
 */
int SinglyLinkedListDestructor  (SinglyLinkedList* sLinkList);

/**
 * @brief Prototype of push elem after tail in singly link list
 * 
 * @param sLinkList - pointer to the singly link list
 * @param val_push  - value pushing in singly link list
 * @return int (0 - if all is OK; 1 -if was errors) 
 */
int SinglyLinkedListPushTail(SinglyLinkedList* sLinkList, SINGLY_LINKED_LIST val_push);

/**
 * @brief Prototype of push elem after head in singly link list
 * 
 * @param sLinkList - pointer to the singly link list
 * @param val_push  - value pushing in singly link list
 * @return int (0 - if all is OK; 1 -if was errors) 
 */
int SinglyLinkedListPushHead(SinglyLinkedList* sLinkList, SINGLY_LINKED_LIST val_push);

/**
 * @brief Prototype of push elem after current elem in singly link list
 * 
 * @param sLinkList - pointer to the singly link list
 * @param val_push  - value pushing in singly link list
 * @param ind_push_after - index of elem in list to push after 
 * @return int (0 - if all is OK; 1 -if was errors) 
 */
int SinglyLinkedListPushAfterInd(SinglyLinkedList* sLinkList, SINGLY_LINKED_LIST val_push, int ind_push_after);

/**
 * @brief Prototype of pop elem on head in singly link list
 * 
 * @param sLinkList - pointer to the singly link list
 * @return int (0 - if all is OK; 1 -if was errors) 
 */
int SinglyLinkedListPopHead(SinglyLinkedList* sLinkList);

/**
 * @brief Prototype of pop elem on tail in singly link list
 * 
 * @param sLinkList - pointer to the singly link list
 * @return int (0 - if all is OK; 1 -if was errors) 
 */
int SinglyLinkedListPopTail(SinglyLinkedList* sLinkList);

/**
 * @brief Prototype of pop elem on index in singly link list
 * 
 * @param sLinkList - pointer to the singly link list
 * @param ind_push_after - index of elem in list to pop 
 * @return int (0 - if all is OK; 1 -if was errors) 
 */
int SinglyLinkedListPopInd(SinglyLinkedList* sLinkList, int ind_pop_after);

#endif
