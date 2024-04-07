#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include "general.h"

#define VECTOR_SIZE_MIN 0u
#define VECTOR_SIZE_MAX INT_MAX

typedef struct vector {
    size_t
        size,
        element_size,
        capacity;
} *vector_t;

//---------------------------------------------------------------------------------------------//
vector_t vec_create(size_t size, size_t element_size) {
    assert(element_size);
    if (size > VECTOR_SIZE_MAX)
        return NULL;
    vector_t result = (vector_t)malloc(size * element_size + sizeof(struct vector));
    if (result)
        *(result++) = (struct vector){ size, element_size, size };
    return result;
}
void vec_delete(vector_t container) {
    free(container - 1); // C standard. 7.20.3.2/2 from ISO-IEC 9899
}
//---------------------------------------------------------------------------------------------//
#define vec_size(container) (container - 1)->size
#define vec_element_size(container) (container - 1)->element_size
#define vec_capacity(container) (container - 1)->capacity
//---------------------------------------------------------------------------------------------//
void vec_move(vector_t* destination, vector_t* source) {
    assert(source);
    assert(*source);
    if (destination)
        vec_delete(*destination);
    *destination = *source;
    *source = NULL;
}
void vec_swap(vector_t* destination, vector_t* source) {
    assert(destination);
    assert(source);
    vector_t temp = *destination;
    *destination = *source;
    *source = temp;
}
void vec_shadow(vector_t* destination, vector_t* source) {
    assert(source);
    assert(*source);
    if (*destination)
        vec_delete(destination);
    vec_create(vec_capacity(*source), vec_element_size(*source));
}
void vec_copy(vector_t* destination, vector_t* source) {
    vec_shadow(destination, source);
    if (*destination) {
        vec_size(*destination) = vec_size(*source);
        memcpy(*destination, *source, vec_size(*destination) * vec_element_size(*destination));
    }
}
//---------------------------------------------------------------------------------------------//
void* vec_at(vector_t container, int index) {
    assert(container);
    assert((size_t)index < vec_size(container));
    return (byte*)container + index * vec_element_size(container);
}
void* vec_front(vector_t container) {
    assert(container);
    assert(vec_size(container));
    return container;
}
void* vec_back(vector_t container) {
    assert(container);
    assert(vec_size(container));
    return (byte*)container + (vec_size(container) - 1) * vec_element_size(container);
}
const void* vec_end(vector_t container) {
    assert(container);
    return (byte*)container + vec_size(container) * vec_element_size(container);
}
//---------------------------------------------------------------------------------------------//
void vec_insert(vector_t container, int index, void* value) {
    assert(container);
    assert(value);
    assert((size_t)index <= vec_size(container));
    if (vec_size(container) >= vec_capacity(container)) {
        size_t new_capacity = GROWTH(vec_capacity(container));
        if (new_capacity > VECTOR_SIZE_MAX)
            return;
        void* new_block = realloc(container, new_capacity * vec_element_size(container) + sizeof(struct vector));
        if (!new_block)
            return;
        vec_capacity(container) = new_capacity;
        container = new_block;
    }
    byte* ptr = (byte*)container + index * element_size(container);
    memmove(ptr + vec_element_size(container), ptr, (vec_size(container)++ - index) * vec_element_size(container));
    memcpy(ptr, value, vec_element_size(container));
}
void vec_insert_range(vector_t container, int index, void* range, size_t range_size) {
    if (index < 0)
        index += (int)(container->size + 1);
    assert(
        container
        && range
        && range_size <= CONTAINER_MAX_SIZE
        && (size_t)index <= container->size
    );
    if (container->size + range_size > container->capacity) {
        size_t new_capacity = GROWTH(container->capacity);
        for (; new_capacity < container->size + range_size;)
            new_capacity = GROWTH(new_capacity);
        return_if(new_capacity > CONTAINER_MAX_SIZE, return_failure);
        if (new_capacity > CONTAINER_MAX_SIZE)
            return return_failure;
        void* new_block = realloc(container->data, new_capacity * container->element_size);
        return_if(!new_block, return_failure);
        if (!new_block)
            return return_failure;
        container->capacity = new_capacity;
        container->data = new_block;
    }
    byte* ptr = (byte*)container->data + index * container->element_size;
    memmove(ptr + range_size * container->element_size, ptr, (container->size - index) * container->element_size);
    container->size += range_size;
    memcpy(ptr, range, range_size * container->element_size);
    return_(return_success);
}

void vec_replace(vector_t container, int index, const void* value) {
    if (value)
        memcpy(vec_at(container, index), value, container->element_size);
    else
        memset(vec_at(container, index), 0, container->element_size);
}
void vec_replace_range(vector_t container, int index, void* range, size_t range_size) {
    if (index < 0)
        index += container->size;
    assert((uint64_t)index + range_size <= container->size);
    if (range)
        memcpy(vector_at(container, index), range, range_size * container->element_size);
    else
        memset(vector_at(container, index), 0, range_size * container->element_size);
}

void vec_remove(vector_t container, int index) {
    if (index < 0)
        index += (int)container->size;
    byte* pointer = vector_at(container, index);
    memmove(pointer, pointer + container->element_size, (--(container->size) - index) * container->element_size);
}
void vec_remove_range(vector_t container, int index, size_t range_size) {
    if (index < 0)
        index += container->size;
    assert((uint64_t)index + range_size <= container->size);
    byte* pointer = vector_at(container, index);
    memmove(pointer, pointer + range_size * container->element_size, ((container->size -= range_size) - index) * container->element_size);
}

void vec_set(vector_t container, void* value) {
    if (value) {
        byte* pointer = vector_front(container);
        const byte* last = vector_end(container);
        for (; pointer < last; pointer += container->element_size)
            memcpy(pointer, value, container->element_size);
    }
    else
        memset(container->data, 0, container->size * container->element_size);
}
void vec_set_range(vector_t container, int begin, int end, void* value) {
    byte* pointer = vector_at(container, begin), * last = vector_at(container, end);
    if (last < pointer) {
        byte* temp = pointer;
        pointer = last;
        last = temp;
    }
    if (value)
        for (; pointer <= last; pointer += container->element_size)
            memcpy(pointer, value, container->element_size);
    else
        memset(pointer, 0, (last - pointer) / container->element_size);
}

void vec_sort(vector_t container, comparison_t comparator) {
    assert(
        container
        && comparator
    );
    qsort(container->data, container->size, container->element_size, comparator);
}
void vec_sort_range(vector_t container, int begin, int end, comparison_t comparator) {
    if (begin < 0)
        begin += (int)container->size;
    if (end < 0)
        end += (int)container->size;
    assert(
        comparator
        && (size_t)begin < container->size
        && (size_t)end < container->size
    );
    qsort(vector_at(container, begin < end ? begin : end), abs(end - begin) + 1, container->element_size, comparator);
}
//---------------------------------------------------------------------------------------------//
vec_shrink(vector_t container) {
    assert(container);
    if (container->capacity > container->size) {
        void* new_block = realloc(container->data, container->size * container->element_size);
        return_if(!new_block, return_failure);
        if (new_block) {
            container->capacity = container->size * container->element_size;
            container->data = new_block;
        }
    }
    return_(return_success);
}
vec_resize(vector_t container, size_t size) {
    assert(container);
    if (size > container->capacity)
        return_(vector_insert_range(container, -1, NULL, size - container->size)); // ????????????
    else
        container->size = size;
    return return_success;
}
//---------------------------------------------------------------------------------------------//
bool vec_empty(vector_t container) {
    assert(container);
    return !container->size;
}
//---------------------------------------------------------------------------------------------//
void vec_internal_print(vector_t container) {
    assert(container);
    printf("__VECTOR__\n\t");
    printf("Size: [ %u ]\n\t", container->size);
    printf("Element_size: [ %u ]\n\t", container->element_size);
    printf("Capacity: [ %u ]\n\t", container->capacity);
    printf("Allocated: [ %ub | %u - %ub ]\n\r", _msize(container), _msize(container->data) / container->element_size, _msize(container->data));
}
void vec_print(vector_t container, to_string_s_t to_string) {
    assert(to_string);
    char* buffer = (char*)malloc(DEFAULT_STRING_BUFFER);
    if (buffer) {
        for (byte* ptr = container->data, *last = (byte*)vector_end(container); ptr < last; ptr += container->element_size)
            printf("%.*s ", DEFAULT_STRING_BUFFER, to_string(ptr, buffer, DEFAULT_STRING_BUFFER));
        printf("\r\n");
        free(buffer);
    }
}
void vpr(vector_t container, to_string_s_t to_string) {
    vector_internal_print(container);
    vector_print(container, to_string);
}
//---------------------------------------------------------------------------------------------//

#endif // !VECTOR_H