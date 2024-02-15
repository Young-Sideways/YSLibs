#pragma once

#ifdef _inl_
#undef _inl_
#endif // !_inl_
#ifdef MATRIX_NO_INLINE
#define _inl_
#else
#define _inl_ inline
#endif // !MATRIX_NO_INLINE

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

typedef struct matrix_struct {
	size_t 
		rows, 
		cols, 
		size;
}* matrix;

#define _MATRIX_DATA_OFFSET sizeof(struct matrix_struct)
#define _MATRIX_ALLOCATED_SIZE(_matrix) (size_t)(_MATRIX_DATA_OFFSET + (_matrix->rows * _matrix->cols * _matrix->size))
#define _MATRIX_DATA_START(_matrix) (void*)(_matrix + 1)
#define _MATRIX_DATA_END(_matrix) (void*)(((uint8_t*)(_matrix + 1)) + (_matrix->rows * _matrix->cols * _matrix->size))


typedef enum matrix_errors_enum {
	NONE,
	MATRIX_IS_NOT_INITIALIZED,
	MATRIX_IS_ALREADY_INITIALIZED,
	MATRIX_INITIALIZATION_ERROR
} MATRIX_ERRORS;

_inl_ matrix mat_create(const size_t rows, const size_t cols, const size_t size) {
	assert(rows && cols && size);
	matrix result = (matrix)malloc(_MATRIX_DATA_OFFSET + (rows * cols * size));
	assert(result);
	result->rows = rows;
	result->cols = cols;
	result->size = size;
	return result;
}
_inl_ matrix mat_copy(const matrix _matrix) {
	matrix result = (matrix)malloc(_MATRIX_ALLOCATED_SIZE(_matrix));
	assert(result);
	memcpy(result, _matrix, _MATRIX_ALLOCATED_SIZE(_matrix));
	return result;
}
_inl_ void mat_set(const matrix _matrix, const void* value) {
	assert(_matrix && value);
	for (uint8_t* iter = (uint8_t*)_MATRIX_DATA_START(_matrix); iter < (uint8_t*)_MATRIX_DATA_END(_matrix); iter += _matrix->size)
		memcpy(iter, value, _matrix->size);
}
_inl_ void mat_delete(matrix _matrix) {
	assert(_matrix);
	free((void*)_matrix);
}
_inl_ void* at(const matrix _matrix, const size_t row, const size_t col) {
	return (((uint8_t*)_MATRIX_DATA_START(_matrix)) + (((row * _matrix->cols) + col) * _matrix->size));
}
_inl_ void* at_s(const matrix _matrix, const size_t row, const size_t col) {
	assert(_matrix && row && col);
	if ((row < _matrix->rows) && (col < _matrix->cols))
		return (((uint8_t*)_MATRIX_DATA_START(_matrix)) + (((row * _matrix->cols) + col) * _matrix->size));
	else
		return NULL;
}
char* mat_to_str(const matrix _matrix, char* buffer, const size_t(*convert)(void*, char*)) {
	assert(_matrix && buffer && convert);
	char* pointer = buffer;
	const uint8_t* last = (uint8_t*)_MATRIX_DATA_END(_matrix);
	for (uint8_t* iter = _MATRIX_DATA_START(_matrix); iter < last; iter += _matrix->size) {
		pointer += convert(iter, pointer);
		if ((last - iter + 1) % _matrix->cols)
			*(pointer++) = ' ';
		else
			*(pointer++) = '\n';
	}
	*pointer = '\0';
	return buffer;
}