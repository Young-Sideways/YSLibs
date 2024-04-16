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
    UCH_DECL_REF(*collection, shifted);
    if (shifted->_dtor)
        shifted->_dtor(*collection);
    free(*collection);
    *collection = NULL;
}

#pragma endregion
