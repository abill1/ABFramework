// © 2022 Anthony Bill. All rights reserved.

//********************************************************************************
// A base object class that allows for memory tracking during debugging and 
// stores some commonly used attributes in the future.
// Example: name, hash. 
//********************************************************************************

#ifndef AB_OBJECT_H
#define AB_OBJECT_H

class Object
{
public:
	Object();
	Object(const Object&);
	Object(Object&&) noexcept;
	virtual ~Object();
	Object& operator=(const Object&) = default;
	Object& operator=(Object&&) noexcept = default;

};

#endif // !AB_OBJECT_H

