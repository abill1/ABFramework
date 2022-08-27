// © 2022 Anthony Bill. All rights reserved.

#include "ABFramework/ABFramework.h"

class Dog : public Object
{
public:
	int x, y, z;
	Dog()
		:Object(), x(), y(), z()
	{

	}
	virtual ~Dog()
	{

	}
};

int main(int argc, char* argv[])
{	
#if _DEBUG
	ABFramework::MemoryTracker::Init();
	std::atexit(ABFramework::MemoryTracker::Dump);
#endif

	Dog* dog1 = New Dog();
	Dog* dog2 = New Dog();

	delete dog1;
	delete dog2;
	return EXIT_SUCCESS;
}

