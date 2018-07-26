#pragma once
#include <assert.h>
#include <iostream>
#include "Iterator.h"

namespace STL
{
	class String
	{
	public:
		using Iterator = RandomAccessIterator<char>;
		using ConstIterator = RandomAccessConstIterator<char>;
	public:
		//Empty string, no buffer
		String() :
			m_pBuffer(nullptr), m_size(0), m_capacity(0)
		{}

		//Create string filled with defined value
		String(const size_t size, const char value = '\0') :
			m_pBuffer(new char[size + 1]), m_size(size), m_capacity(size)
		{
			memset(m_pBuffer, value, m_size);
			m_pBuffer[size] = '\0';
		}

		//Create string from c-string
		String(const char* pData) :
			m_pBuffer(nullptr), m_size(0), m_capacity(0)
		{
			Append(pData);
		}

		//Create string from unicode c-string
		explicit String(const wchar_t* pData) :
			m_pBuffer(nullptr), m_size(0)
		{
			Append(pData);
		}

		//Create string from begin and end iterator
		explicit String(const char* pBegin, const char* pEnd)
		{
			if (pBegin == nullptr || pEnd == nullptr)
			{
				m_pBuffer = nullptr;
				m_capacity = 0;
				m_size = 0;
			}
			else
			{
				m_size = pEnd - pBegin;
				m_capacity = m_size;
				m_pBuffer = new char[m_size + 1];
				memcpy(m_pBuffer, pBegin, m_size);
				m_pBuffer[m_size] = '\0';
			}
		}

		~String()
		{
			if (m_pBuffer)
			{
				delete[] m_pBuffer;
				m_pBuffer = nullptr;
			}
		}

		void Resize(const size_t size)
		{
			size_t copyWidth = 0;
			if (m_pBuffer)
			{
				char* pNewBuffer = new char[size + 1];
				copyWidth = size > m_size ? m_size : size;
				memcpy(pNewBuffer, m_pBuffer, copyWidth);
				delete[] m_pBuffer;
				m_pBuffer = pNewBuffer;
			}
			else
			{
				m_pBuffer = new char[size + 1];
			}
			memset(m_pBuffer + copyWidth, 0, (size - copyWidth));
			m_size = size;
			m_capacity = size;
			m_pBuffer[m_size] = '\0';
		}

		void Reserve(const size_t size)
		{
			if (size <= m_capacity)
				return;

			if (m_pBuffer != nullptr)
			{
				char* pNewBuffer = new char[size + 1];
				size_t copyWidth = size > m_size ? m_size: size;
				memcpy(pNewBuffer, m_pBuffer, copyWidth + 1);
				delete[] m_pBuffer;
				m_pBuffer = pNewBuffer;
			}
			else
			{
				m_pBuffer = new char[size + 1];
			}
			m_capacity = size;
		}

		void ShrinkToFit()
		{
			Resize(m_size);
		}

		char Pop()
		{
			assert(m_size > 0);
			char value = Back();
			--m_size;
			m_pBuffer[m_size] = '\0';
			return value;
		}

		void Swap(String& other)
		{
			STL::Swap(m_pBuffer, other.m_pBuffer);
			STL::Swap(m_size, other.m_size);
			STL::Swap(m_capacity, other.m_capacity);
		}

		void Assign(const size_t amount, const char value)
		{
			if (m_size + amount > m_capacity)
				Reserve(m_size + amount);
			for (size_t i = 0; i < amount; ++i)
			{
				memcpy(m_pBuffer + m_size + i, &value, sizeof(char));
			}
			m_size += amount;
			m_pBuffer[m_size] = '\0';
		}


		void Append(const char* pData)
		{
			if (pData)
			{
				const size_t dataSize = StrLen(pData);			
				char* pNewBuffer = new char[m_size + dataSize + 1];
				memcpy(pNewBuffer + m_size, pData, dataSize);
				if (m_pBuffer)
				{
					memcpy(pNewBuffer, m_pBuffer, m_size);
					delete[] m_pBuffer;
				}
				m_size += dataSize;
				m_capacity = m_size;
				m_pBuffer = pNewBuffer;
				m_pBuffer[m_size] = '\0';
			}
		}

		void Append(const wchar_t* pData)
		{
			const size_t dataSize = StrLen(pData);
			char* pNewBuffer = new char[m_size + dataSize + 1];
			for (size_t i = 0; i < dataSize; ++i)
			{
				pNewBuffer[i + m_size] = (char)pData[i];
			}
			if (m_pBuffer)
			{
				memcpy(pNewBuffer, m_pBuffer, m_size);
				delete[] m_pBuffer;
			}
			m_size += dataSize;
			m_capacity = m_size;
			m_pBuffer = pNewBuffer;
			m_pBuffer[m_size] = '\0';
		}

	private:

		char* m_pBuffer;
		size_t m_size;
		size_t m_capacity;

}