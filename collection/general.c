/*******************************************************************************
 *  @file      general.c
 *  @brief     general structures and control functions for collections
 *  @author    Young Sideways
 *  @date      19.02.2024
 *  @copyright © young.sideways@mail.ru, 2024. All right reserved.
 ******************************************************************************/

#include "general.h"

#pragma region --- INCLUDE ---

#include "private.h"
#include <stdlib.h>

#pragma endregion

#pragma region --- CONSTRUCTORS / DESTRUCTORS ---

void delete(void** collection)
{
    assert(collection);
    assert(*collection);

    if (UCH_EXTRACT(*collection)->_dtor)
        UCH_EXTRACT(*collection)->_dtor(collection);
    free(UCH_EXTRACT(*collection));
    *collection = NULL;
}

#pragma endregion

#pragma region --- FUNCTIONS ---

size_t get_capacity(void* collection) {
    assert(collection);
    return UCH_EXTRACT(collection)->capacity;
}
size_t get_size(void* collection) {
    assert(collection);
    return UCH_EXTRACT(collection)->size;
}
size_t get_element_size(void* collection) {
    assert(collection);
    return UCH_EXTRACT(collection)->element_size;
}

void* get_comp(void* collection) {
    assert(collection);
    return UCH_EXTRACT(collection)->_comp;
}
void set_comp(void* collection, void* value) {
    assert(collection);
    UCH_EXTRACT(collection)->_comp = value;
}
void* get_swap(void* collection) {
    assert(collection);
    return UCH_EXTRACT(collection)->_swap;
}
void set_swap(void* collection, void* value) {
    assert(collection);
    UCH_EXTRACT(collection)->_swap = value;
}
void* get_search(void* collection) {
    assert(collection);
    return UCH_EXTRACT(collection)->_search;
}
void set_search(void* collection, void* value) {
    assert(collection);
    UCH_EXTRACT(collection)->_search = value;
}
void* get_sort(void* collection) {
    assert(collection);
    return UCH_EXTRACT(collection)->_sort;
}
void set_sort(void* collection, void* value) {
    assert(collection);
    UCH_EXTRACT(collection)->_sort = value;
}

#pragma endregion
