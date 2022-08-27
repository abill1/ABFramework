// © 2022 Anthony Bill. All rights reserved.

//********************************************************************************
// A header object attached to all objects being track in memory to contain 
// debugging information. 
//********************************************************************************

#ifndef MEMORY_HEADER_H
#define MEMORY_HEADER_H

namespace ABFramework
{
	class MemoryHeader
	{
	public:
		MemoryHeader();
		MemoryHeader(const MemoryHeader& src);
		MemoryHeader(MemoryHeader&& src) noexcept;
		~MemoryHeader();

		MemoryHeader(const char* file, size_t addr, size_t size, int line);

		MemoryHeader& operator=(const MemoryHeader& src);
		MemoryHeader& operator=(MemoryHeader&& src) noexcept;

	public:

		// ----- Getters ----- //

		const char* GetFile() const { return m_pFile; }
		size_t GetAddr() const { return m_addr; }
		size_t GetSize() const { return m_size; }
		int GetLine() const { return m_line; }
		
		// ----- Setters ----- //

		void SetFile(const char* file);
		void SetAddr(const size_t addr);
		void SetSize(const size_t size);
		void SetLine(const int line);

		// ----- Utility ------//

		void Dump() const;

	private:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="file">A C-string of the entire file path to be parsed.</param>
		/// <returns>A pointer to the beginning of the cpp file name.</returns>
		char* privParseFileName(const char* file);

	private:
		static const int FILE_LEN = 64;
		char m_pFile[FILE_LEN];
		size_t m_addr;
		size_t m_size;
		int m_line;
		size_t pad0;	
	};
}

#endif // !MEMORY_HEADER_H


