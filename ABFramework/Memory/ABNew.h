// © 2022 Anthony Bill. All rights reserved.

//********************************************************************************
// Redefining the new operator to better track memory allocations. 
//********************************************************************************

#ifndef ABNEW_H
#define ABNEW_H

#include <new>
#include "MemoryHeader.h"

#pragma warning( disable : 4291 ) // 'declaration' : no matching operator delete found; memory will not be freed if initialization throws an exception

#if _DEBUG
#undef new
void* operator new(size_t size, const char* file, int line)
{
	void* ptr = nullptr;
	if (size > 0)
	{
		size_t memHead = sizeof(ABFramework::MemoryHeader);
		size_t totSize = memHead + size;
		ptr = malloc(totSize);

		ABFramework::MemoryHeader* hdr = (ABFramework::MemoryHeader*)ptr;
		hdr->SetFile(file);
		hdr->SetSize(size);
		hdr->SetLine(line);
		size_t ret = (size_t)hdr + memHead;
		hdr->SetAddr(ret);
		ptr = (void*)ret;
	}
	return ptr;
}

void operator delete(void* ptr)
{
	size_t memHead = sizeof(ABFramework::MemoryHeader);
	size_t totSize = memHead;
	size_t head = (size_t)ptr - totSize;
	
	// TODO: Maybe too much of a hack that could cause headaches later
	ABFramework::MemoryHeader* hdr = (ABFramework::MemoryHeader*)head;
	if (hdr != nullptr && hdr->GetAddr() == (size_t)ptr)
	{
		ptr = hdr;
	}
	free(ptr);
}

#define New new(__FILE__, __LINE__)
#else
#define New new
#endif

#endif // !ABNEW_H


