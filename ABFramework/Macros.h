// © 2022 Anthony Bill. All rights reserved.

//********************************************************************************
// A header to include personal macro definitions. 
//********************************************************************************

#include <assert.h>

#ifndef ABMACROS_H
#define ABMACROS_H

#define UNUSED_VAR(x) (void(x))
#define IS_NULL(x) x == nullptr;
#define CHECK_NULL(x) assert(x != nullptr);

#endif // !ABMACROS_H

