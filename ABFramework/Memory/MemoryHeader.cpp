// © 2022 Anthony Bill. All rights reserved.

#include "MemoryHeader.h"
#include <string.h>
#include <memory>

//********************************************************************************
//	Constructor / Destructor
//********************************************************************************

ABFramework::MemoryHeader::MemoryHeader()
	:m_pFile(), m_addr(0), m_size(0), m_line(0), pad0(0u)
{
	memset(m_pFile, 0, ABFramework::MemoryHeader::FILE_LEN);
}

ABFramework::MemoryHeader::MemoryHeader(const char* file, size_t addr, size_t size, int line)
	: m_pFile(), m_addr(addr), m_size(size), m_line(line), pad0(0u)
{
	memset(m_pFile, 0, ABFramework::MemoryHeader::FILE_LEN);
	char* start = privParseFileName(file);
	size_t len = std::strlen(start);
	memcpy_s(m_pFile, ABFramework::MemoryHeader::FILE_LEN - 1, start, len);
}

ABFramework::MemoryHeader::MemoryHeader(const MemoryHeader& src)
	: m_pFile(), m_addr(src.m_addr), m_size(src.m_size), m_line(src.m_line), pad0(0u)
{
	memset(m_pFile, 0, ABFramework::MemoryHeader::FILE_LEN);
	size_t len = std::strlen(src.m_pFile);
	memcpy_s(m_pFile, ABFramework::MemoryHeader::FILE_LEN - 1, src.m_pFile, len);
}

ABFramework::MemoryHeader::MemoryHeader(MemoryHeader&& src) noexcept
	: m_pFile(), m_addr(std::move(src.m_addr)), m_size(std::move(src.m_size)), m_line(std::move(src.m_line)), pad0(0u)
{
	memset(m_pFile, 0, ABFramework::MemoryHeader::FILE_LEN);
	size_t len = std::strlen(src.m_pFile);
	memcpy_s(m_pFile, ABFramework::MemoryHeader::FILE_LEN - 1, src.m_pFile, len);
}

ABFramework::MemoryHeader::~MemoryHeader()
{
	memset(m_pFile, 0, ABFramework::MemoryHeader::FILE_LEN);
}

//********************************************************************************
// Operators
//********************************************************************************

ABFramework::MemoryHeader& ABFramework::MemoryHeader::operator=(const MemoryHeader& src)
{
	memset(m_pFile, 0, ABFramework::MemoryHeader::FILE_LEN);
	size_t len = std::strlen(src.m_pFile);
	memcpy_s(m_pFile, ABFramework::MemoryHeader::FILE_LEN - 1, src.m_pFile, len);

	this->m_addr = src.m_addr;
	this->m_size = src.m_size;
	this->m_line = src.m_line;

	return *this;
}

ABFramework::MemoryHeader& ABFramework::MemoryHeader::operator=(MemoryHeader&& src) noexcept
{
	memset(m_pFile, 0, ABFramework::MemoryHeader::FILE_LEN);
	size_t len = std::strlen(src.m_pFile);
	memcpy_s(m_pFile, ABFramework::MemoryHeader::FILE_LEN - 1, src.m_pFile, len);

	this->m_addr = std::move(src.m_addr);
	this->m_size = std::move(src.m_size);
	this->m_line = std::move(src.m_line);

	return *this;					   
}

//********************************************************************************
// Setters
//********************************************************************************

void ABFramework::MemoryHeader::SetFile(const char* file)
{
	memset(this->m_pFile, 0, ABFramework::MemoryHeader::FILE_LEN);
	char* start = privParseFileName(file);
	size_t len = std::strlen(start);
	memcpy_s(this->m_pFile, ABFramework::MemoryHeader::FILE_LEN - 1, start, len);
}

void ABFramework::MemoryHeader::SetAddr(const size_t addr)
{
	this->m_addr = addr;
}

void ABFramework::MemoryHeader::SetSize(const size_t size)
{
	this->m_size = size;
}

void ABFramework::MemoryHeader::SetLine(const int line)
{
	this->m_line = line;
}

//********************************************************************************
// Utility
//********************************************************************************

void ABFramework::MemoryHeader::Dump() const
{
	printf(" ----------------------------------------------------------------------\n");
	printf(" Addr: (0x%llx)\n", this->m_addr);
	printf(" File: %s\n", this->m_pFile);
	printf(" Line: %d\n", this->m_line);
	printf(" Size: %lld bytes\n", this->m_size);
	printf(" ----------------------------------------------------------------------\n");
}

//********************************************************************************
// Private Helpers
//********************************************************************************

char* ABFramework::MemoryHeader::privParseFileName(const char* file)
{
	char* pBeg = nullptr;
	if(file != nullptr)
	{
		size_t len = std::strlen(file);
		size_t end = (size_t)file + len;
		char* ch = (char*)end;
		while (*ch != '\\')
		{
			--ch;
		}
		pBeg = ++ch;
	}
	
	return pBeg;
}
