// © 2022 Anthony Bill. All rights reserved.

#include "Object.h"
#include "MemoryTracker.h"

//********************************************************************************
//	Constructor / Destructor
//********************************************************************************

Object::Object()
{
#if _DEBUG
	ABFramework::MemoryTracker::Add(this);
#endif
}

Object::Object(const Object& src)
{
#if _DEBUG
	ABFramework::MemoryTracker::Add(this);
#endif
}

Object::Object(Object&& src) noexcept
{
#if _DEBUG
	ABFramework::MemoryTracker::Add(this);
#endif
}

Object::~Object()
{
#if _DEBUG
	ABFramework::MemoryTracker::Remove(this);
#endif
}

