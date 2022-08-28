// © 2022 Anthony Bill. All rights reserved.

//********************************************************************************
// An enumeration defining the possible sizes of ABString.
//********************************************************************************

#ifndef AB_STRING_SIZES_H
#define AB_STRING_SIZES_H

enum class StringSize : int
{
	UNINITIZED = 0,
	SIZE16 = 16,
	SIZE32 = 32,
	SIZE64 = 64,
	SIZE128 = 128,
	SIZE256 = 256,
	SIZE512 = 512,
	SIZE1024 = 1024,
	SIZE2048 = 2048,
	SIZE4096 = 4096
};

#endif // !AB_STRING_SIZES_H

