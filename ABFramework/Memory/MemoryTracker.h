// © 2022 Anthony Bill. All rights reserved.

//********************************************************************************
// Memory tracking class for debugging. 
//********************************************************************************

#ifndef ABMEMORY_TRACKER_H
#define ABMEMORY_TRACKER_H

// TODO: Find how to forward declare map so this will be inaccessible throughout
#include <unordered_map>

namespace ABFramework
{
	class MemoryHeader;

	class MemoryTracker
	{
	public:
		// ----- Constructor/Destructor -----/

		MemoryTracker();
		MemoryTracker(const MemoryTracker&) = delete;
		~MemoryTracker();
		MemoryTracker& operator=(const MemoryTracker&) = delete;

	public:
		static void Init();
		static void Add(void* obj);
		static void Remove(void* obj);
		static void Dump();

	private:
		static MemoryTracker* sInstance;

		std::unordered_map<size_t, MemoryHeader*> m_MemoryMap;
		size_t m_CurrentAllocation;
		size_t m_PeakAllocation;

	};
}

#endif // !ABMEMORY_TRACKER_H



