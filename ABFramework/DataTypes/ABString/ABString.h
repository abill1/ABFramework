// © 2022 Anthony Bill. All rights reserved.

//********************************************************************************
// A fixed size string class to improve performance and memory optimization.
//********************************************************************************

#ifndef AB_STRING_H
#define AB_STRING_H

#include <string>
#include "ABStringSizes.h"

namespace ABFramework
{
	class String
	{
	public:
		String();
		String(const char* src);
		String(const std::string& src);
		String(const String& src);
		String(String&& src);
		String(std::string&& src);
		~String();

		String& operator=(const String& src);
		String& operator=(const std::string& src);
		String& operator=(String&& src);
		String& operator=(std::string&& src);

	public:
		// ----- Getters ----- //

		char* c_str() const { return m_pStr; }
		size_t GetCapacity() const { return m_capacity; }
		size_t GetLength() const { return m_size; }
		size_t GetHash() const { return m_hash; }

		// ----- Setters ----- //

		void Copy(const char* str);
		void Copy(const String& str);
		void Copy(const std::string& str);

	private:
		StringSize privFindSize(size_t len) const;

	private:
		char* m_pStr;
		size_t m_capacity;
		size_t m_size;
		size_t m_hash;
	};
}


#endif // !AB_STRING_H


