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
/*------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Prototype of constructor singly linked list
 * 
 * @param sLinkList 
 * @return int 
 */
int SinglyLinkedListConstructor(SinglyLinkedList* sLinkList);

/**
 * @brief Prototype of destructor singly linked list
 * 
 * @param sLinkList 
 * @return int 
 */
int SinglyLinkedListDestructor  (SinglyLinkedList* sLinkList);

int SinglyLinkedListPush(SinglyLinkedList* sLinkList, SINGLY_LINKED_LIST val_push);

#endif
