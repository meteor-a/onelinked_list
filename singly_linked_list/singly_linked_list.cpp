#include "singly_linked_list.h"
#include "../bin/_mtLib/base_lib/base_lib.h"
#include "../bin/_mtLib/logger/logger.h"

/*------------------------------------------------------------------------------------------------------------------*/

#include <stdlib.h>

/*------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Constant name of module SINGLY_LINKED_LIST
 * 
 */
const char* NAME_MODULE_SINGLY_LINKED_LIST = "SINGLY_LINKED_LIST";

/**
 * @brief Constant log file name
 * 
 */
const char* LOG_FILENAME = "log_singly_link_list";

const int DEFAULT_START_CAPACITY      = 16;
const int DEFAULT_DIFFERENCE_CAPACITY = 16;

/*------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Prototype of dump singly linked list
 * 
 * @param sLinkList - pointer to the singly link list
 * @return int (0 - if all is OK; 1 -if was errors) 
 */
int DumpSinglyLinkList(SinglyLinkedList* sLinkList);

/**
 * @brief Prototype of inizialize data after constructor
 * 
 * @param sLinkList - pointer to the singly link list
 * @return int (0 - if all is OK; 1 -if was errors) 
 */
int InizializeData(SinglyLinkedList* sLinkList);

/**
 * @brief Prototype of calloc more memory for list
 * 
 * @param sLinkList - pointer to the singly link list
 * @return int (0 - if all is OK; 1 -if was errors) 
 */
int AllocateIncreaseMemoryList(SinglyLinkedList* sLinkList);

/**
 * @brief Prototype of low memory for list
 * 
 * @param sLinkList - pointer to the singly link list
 * @return int (0 - if all is OK; 1 -if was errors) 
 */
int AllocateLeaseMemoryList(SinglyLinkedList* sLinkList);

/**
 * @brief Prototype of finding preious to index index of elem
 * 
 * @param sLinkList - pointer to the singly link list
 * @param index - index, before which need to find index
 * @return int - omdex of previous elem
 */
int FindPreviousIndex(SinglyLinkedList* sLinkList, int index);

/*------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Define assert of incorrect pointers
 * 
 */
#define _ASSERT__(var, err_text)                                                                         \
    if (_IsBadReadPtr(var)) {                                                                            \
        CreateLog(LOG_FILENAME, NAME_MODULE_SINGLY_LINKED_LIST, err_text, LOCATION_VAR__(var));          \
        DumpSinglyLinkList(sLinkList);                                                                   \
        return EXIT_FAILURE;                                                                             \
    }

/**
 * @brief Define assert of incorrect pointers
 * 
 */
#define _ASSERT_C_(var, err_text, call_place)                                                                 \
    if (_IsBadReadPtr(var)) {                                                                                \
        CreateLog(LOG_FILENAME, NAME_MODULE_SINGLY_LINKED_LIST, err_text, call_place, LOCATION_VAR__(var));  \
        DumpSinglyLinkList(sLinkList);                                                                       \
        return EXIT_FAILURE;                                                                                 \
    }

#define SinglyLinkListOK(sLinkList) _SinglyLinkListOK__(sLinkList,  LOCATION_STRUCT_CALL__{LOCATION__})
int _SinglyLinkListOK__(SinglyLinkedList* sLinkList, LOCATION_STRUCT_CALL__ call_place) {
    _ASSERT_C_(sLinkList,       ERROR_BAD_POINTER__, call_place)
    _ASSERT_C_(sLinkList->head, ERROR_BAD_POINTER__, call_place)
    _ASSERT_C_(sLinkList->tail, ERROR_BAD_POINTER__, call_place)
    _ASSERT_C_(sLinkList->list, ERROR_BAD_POINTER__, call_place)

    return EXIT_SUCCESS;
}

/*------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Constructor of type: singly linked list
 * 
 * @param sLinkList - pointer to the singly link list
 * @return int(0 - if all is OK; 1 -if was errors) 
 */
int SinglyLinkedListConstructor(SinglyLinkedList* sLinkList) {
    sLinkList->size     = 0;
    sLinkList->capacity = DEFAULT_START_CAPACITY;

    sLinkList->list = (ElemSinglyLinkedList*) calloc(sLinkList->capacity, sizeof(ElemSinglyLinkedList));
    _ASSERT__(sLinkList->list, ERROR_CANT_CALLOC_MEM);

    sLinkList->head = sLinkList->list;
    sLinkList->tail = sLinkList->list;

    SinglyLinkListOK(sLinkList);

    InizializeData(sLinkList);

    sLinkList->head->index = 0;

    return EXIT_SUCCESS;
}

int InizializeData(SinglyLinkedList* sLinkList) {
    SinglyLinkListOK(sLinkList);



    return EXIT_SUCCESS;
}

/**
 * @brief Destructor of type: singly linked list
 * 
 * @param sLinkList - pointer to the singly link list
 * @return int(0 - if all is OK; 1 -if was errors) 
 */
int SinglyLinkedListDestructor(SinglyLinkedList* sLinkList) {
    SinglyLinkListOK(sLinkList);

    sLinkList->size     = -1;
    sLinkList->capacity = -1;

    sLinkList->head = (ElemSinglyLinkedList*) POISON_POINTERS__::pNullData;
    sLinkList->tail = (ElemSinglyLinkedList*) POISON_POINTERS__::pNullData;
    free(sLinkList->list);

    sLinkList->list = (ElemSinglyLinkedList*) POISON_POINTERS__::pNullData;

    return EXIT_SUCCESS;
}

/**
 * @brief Function to push elem after tail in singly link list
 * 
 * @param sLinkList - pointer to the singly link list
 * @param val_push  - value pushing in singly link list
 * @return int (0 - if all is OK; 1 -if was errors) 
 */
int SinglyLinkedListPushTail(SinglyLinkedList* sLinkList, SINGLY_LINKED_LIST val_push) {
    SinglyLinkListOK(sLinkList);

    SINGLY_LINKED_LIST index_find_empty = 0;
    while(sLinkList->list[index_find_empty].index != -1) ++index_find_empty;

    sLinkList->list[sLinkList->tail->index].index = index_find_empty;

    sLinkList->list[index_find_empty].elem  = val_push;
    sLinkList->list[index_find_empty].index = 0;

    ++sLinkList->size;

    if (sLinkList->size == sLinkList->capacity) {
        AllocateIncreaseMemoryList(sLinkList);
    }

    SinglyLinkListOK(sLinkList);

    return EXIT_SUCCESS;
}

/**
 * @brief Function to push elem after head in singly link list
 * 
 * @param sLinkList - pointer to the singly link list
 * @param val_push  - value pushing in singly link list
 * @return int (0 - if all is OK; 1 -if was errors) 
 */
int SinglyLinkedListPushHead(SinglyLinkedList* sLinkList, SINGLY_LINKED_LIST val_push) {
    SinglyLinkListOK(sLinkList);

    SINGLY_LINKED_LIST index_find_empty = 0;
    while(sLinkList->list[index_find_empty].index != -1) ++index_find_empty;

    sLinkList->list[index_find_empty].index       = sLinkList->head->index;
    sLinkList->list[sLinkList->head->index].index = index_find_empty;

    sLinkList->list[index_find_empty].elem  = val_push;
    sLinkList->list[index_find_empty].index = 0;

    ++sLinkList->size;

    if (sLinkList->size == sLinkList->capacity) {
        AllocateIncreaseMemoryList(sLinkList);
    }

    SinglyLinkListOK(sLinkList);

    return EXIT_SUCCESS;
}

/**
 * @brief Calloc more memory for the list
 * 
 * @param sLinkList - pointer to the singly link list
 * @return int (0 - if all is OK; 1 -if was errors) 
 */
int AllocateIncreaseMemoryList(SinglyLinkedList* sLinkList) {
    SinglyLinkListOK(sLinkList);

    sLinkList->list = (ElemSinglyLinkedList*) realloc(sLinkList->list, sLinkList->capacity + DEFAULT_DIFFERENCE_CAPACITY);
    SinglyLinkListOK(sLinkList);

    sLinkList->capacity += DEFAULT_DIFFERENCE_CAPACITY;

    return EXIT_SUCCESS;
}

/**
 * @brief Calloc lease memory for the list
 * 
 * @param sLinkList - pointer to the singly link list
 * @return int (0 - if all is OK; 1 -if was errors) 
 */
int AllocateLeaseMemoryList(SinglyLinkedList* sLinkList) {
    SinglyLinkListOK(sLinkList);



    SinglyLinkListOK(sLinkList);

    return EXIT_SUCCESS;
}

/**
 * @brief Function to push elem after current elem in singly link list
 * 
 * @param sLinkList - pointer to the singly link list
 * @param val_push  - value pushing in singly link list
 * @param ind_push_after - index of elem in list to push after 
 * @return int (0 - if all is OK; 1 -if was errors) 
 */
int SinglyLinkedListPushAfterInd(SinglyLinkedList* sLinkList, SINGLY_LINKED_LIST val_push, int ind_push_after) {
    SinglyLinkListOK(sLinkList);

    if (ind_push_after > sLinkList->size) {
        CreateLog(LOG_FILENAME, NAME_MODULE_SINGLY_LINKED_LIST, ERROR_PUSH_AFTER_TAIL, LOCATION_VAR__(ind_push_after));          
        DumpSinglyLinkList(sLinkList);                                                                   
        return EXIT_FAILURE;
    } else if (sLinkList->head->index == ind_push_after) {
        return SinglyLinkedListPushHead(sLinkList, val_push);
    } else if (sLinkList->tail->index == ind_push_after) {
        return SinglyLinkedListPushTail(sLinkList, val_push);
    } else {
        SINGLY_LINKED_LIST index_find_empty = 0;
        while(sLinkList->list[index_find_empty].index != -1) ++index_find_empty;

        sLinkList->list[index_find_empty].index = sLinkList->list[ind_push_after].index;
        sLinkList->list[index_find_empty].elem  = val_push;

        sLinkList->list[ind_push_after].index = index_find_empty;

        ++sLinkList->size;

        if (sLinkList->size == sLinkList->capacity) {
            return AllocateIncreaseMemoryList(sLinkList);
        }

        SinglyLinkListOK(sLinkList);
    }

     return EXIT_SUCCESS;
}

/**
 * @brief Function to pop elem in head in singly link list
 * 
 * @param sLinkList - pointer to the singly link list
 * @return int (0 - if all is OK; 1 - if was errors) 
 */
int SinglyLinkedListPopHead(SinglyLinkedList* sLinkList) {
    SinglyLinkListOK(sLinkList);

    if (sLinkList->size == 0) {
        CreateLog(LOG_FILENAME, NAME_MODULE_SINGLY_LINKED_LIST, ERROR_POP_AFTER_TAIL, LOCATION_VAR__(ind_push_after));          
        DumpSinglyLinkList(sLinkList);                                                                   
        return EXIT_FAILURE;
    }

    int prev_head_ind = sLinkList->head->index;
    sLinkList->head   = (sLinkList->list + sLinkList->head->index);
    sLinkList->list[prev_head_ind].elem  = 0;
    sLinkList->list[prev_head_ind].index = -1;

    --sLinkList->size;

    if (sLinkList->capacity - (DEFAULT_DIFFERENCE_CAPACITY * 2) >= sLinkList->size) {
        return AllocateLeaseMemoryList(sLinkList);
    }

    SinglyLinkListOK(sLinkList);

    return EXIT_SUCCESS;
}

/**
 * @brief Function to pop elem on tail in singly link list
 * 
 * @param sLinkList - pointer to the singly link list
 * @return int (0 - if all is OK; 1 - if was errors) 
 */
int SinglyLinkedListPopTail(SinglyLinkedList* sLinkList) {
    SinglyLinkListOK(sLinkList);

    if (sLinkList->size == 0) {
        CreateLog(LOG_FILENAME, NAME_MODULE_SINGLY_LINKED_LIST, ERROR_POP_AFTER_TAIL, LOCATION_VAR__(ind_push_after));          
        DumpSinglyLinkList(sLinkList);                                                                   
        return EXIT_FAILURE;
    }

    int ind_previous_tail = FindPreviousIndex(sLinkList, sLinkList->tail->index);

    sLinkList->tail->elem  = 0;
    sLinkList->tail->index = -1;

    sLinkList->tail        = (sLinkList->tail + ind_previous_tail);
    sLinkList->tail->index = 0;

    --sLinkList->size;

    if (sLinkList->capacity - (DEFAULT_DIFFERENCE_CAPACITY * 2) >= sLinkList->size) {
        return AllocateLeaseMemoryList(sLinkList);
    }

    SinglyLinkListOK(sLinkList);

    return EXIT_SUCCESS;
}


/**
 * @brief Function to pop elem on index in singly link list
 * 
 * @param sLinkList - pointer to the singly link list
 * @param ind_push_after - index of elem in list to pop 
 * @return int (0 - if all is OK; 1 -if was errors) 
 */
int SinglyLinkedListPopInd(SinglyLinkedList* sLinkList, int ind_pop_elem) {
    SinglyLinkListOK(sLinkList);

    if (sLinkList->size < ind_pop_elem) {
        CreateLog(LOG_FILENAME, NAME_MODULE_SINGLY_LINKED_LIST, ERROR_POP_AFTER_TAIL, LOCATION_VAR__(ind_push_after));          
        DumpSinglyLinkList(sLinkList);                                                                   
        return EXIT_FAILURE;
    } else if (sLinkList->head->index == ind_pop_elem) {
        return SinglyLinkedListPopHead(sLinkList);
    } else if (sLinkList->tail->index == ind_pop_elem) {
        return SinglyLinkedListPopTail(sLinkList);
    } else {
        int ind_previous_tail = FindPreviousIndex(sLinkList, ind_pop_elem);

        sLinkList->list[ind_previous_tail].index = sLinkList->list[ind_pop_elem].index;

        sLinkList->list[ind_pop_elem].elem  = 0;
        sLinkList->list[ind_pop_elem].index = -1;
    }

    if (sLinkList->capacity - (DEFAULT_DIFFERENCE_CAPACITY * 2) >= sLinkList->size) {
        return AllocateLeaseMemoryList(sLinkList);
    }

    SinglyLinkListOK(sLinkList);

    return EXIT_SUCCESS;
}

/**
 * @brief Function to finding previous to index index of elem
 * 
 * @param sLinkList - pointer to the singly link list
 * @param index - index, before which need to find index
 * @return int - omdex of previous elem
 */
int FindPreviousIndex(SinglyLinkedList* sLinkList, int index) {
    SinglyLinkListOK(sLinkList);

    int ind_previous = 0;
    int tmp_cur_ind  = sLinkList->head->index;
    while(sLinkList->list[tmp_cur_ind].index != index) {
        ind_previous = tmp_cur_ind;
        ++tmp_cur_ind;
    }

    return ind_previous;
}

/**
 * @brief Create Dump file of singly link list
 * 
 * @param sLinkList - pointer to the singly link list
 * @return int (0 - if all is OK; 1 -if was errors) 
 */
int DumpSinglyLinkList(SinglyLinkedList* sLinkList) {

    return EXIT_SUCCESS;
}
