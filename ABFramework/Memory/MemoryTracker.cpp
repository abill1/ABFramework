// © 2022 Anthony Bill. All rights reserved.

#include "MemoryTracker.h"
#include "MemoryHeader.h"

// ----- Singleton instance -----//
ABFramework::MemoryTracker* ABFramework::MemoryTracker::sInstance = nullptr;

//********************************************************************************
//	Constructor / Destructor
//********************************************************************************

ABFramework::MemoryTracker::MemoryTracker()
	:m_MemoryMap(), m_CurrentAllocation(0u), m_PeakAllocation(0u)
{

}

ABFramework::MemoryTracker::~MemoryTracker()
{
	m_MemoryMap.clear();
	m_CurrentAllocation = 0u;
	m_PeakAllocation = 0u;
}

void ABFramework::MemoryTracker::Init()
{
	static MemoryTracker instance;
	MemoryTracker::sInstance = &instance;

}

//********************************************************************************
//	Utility
//********************************************************************************

void ABFramework::MemoryTracker::Add(void* obj)
{
	size_t key = (size_t)obj;
	size_t headSize = sizeof(ABFramework::MemoryHeader);
	size_t headAddr = key - headSize;

	ABFramework::MemoryHeader*& head = sInstance->m_MemoryMap[key];
	head = ((ABFramework::MemoryHeader*)headAddr);
	
	// ----- Update the current memory usage data
	sInstance->m_CurrentAllocation += head->GetSize();
	if (sInstance->m_PeakAllocation < sInstance->m_CurrentAllocation)
		sInstance->m_PeakAllocation = sInstance->m_CurrentAllocation;

}

void ABFramework::MemoryTracker::Remove(void* obj)
{
	size_t key = (size_t)obj;
	if (sInstance->m_MemoryMap.count(key) > 0)
	{
		sInstance->m_CurrentAllocation -= sInstance->m_MemoryMap[key]->GetSize();
		sInstance->m_MemoryMap[key] = nullptr;
	}
}

void ABFramework::MemoryTracker::Dump()
{
	printf(" ======================================================================\n");
	printf("                        Memory Tracker                                 \n");
	printf(" ======================================================================\n");
	printf(" Current Allocation: %lld bytes\n", sInstance->m_CurrentAllocation);
	printf(" Peak Allocation: %lld bytes\n", sInstance->m_PeakAllocation);
	printf("\n");
	printf(" ----------------------------------------------------------------------\n");
	printf("                     Currently Tracking                                \n");
	printf(" ----------------------------------------------------------------------\n");

	for (auto it : sInstance->m_MemoryMap)
	{
		if(it.second != nullptr)
			it.second->Dump();

	}

}

