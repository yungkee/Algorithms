#pragma once
#include <initializer_list>
#include <assert.h>
#include "Iterator.h"
#include "Utility.h"

namespace STL
{
	template<typename T>
	class Vector
	{
	public:
		using Iterator = RandomAccessIterator<T>;
		using ConstIterator = RandomAccessConstIterator<T>;
	public:
		Vector() :
			m_pBuffer(nullptr), m_size(0), m_capacity(0)
		{}

		Vector(const size_t size) :
			m_pBuffer(Allocate(size)), m_size(size), m_capacity(size)
		{
			ConstructElements(Buffer(), size);
		}

		Vector(const size_t size, const T& value) :
			m_pBuffer(Allocate(size)), m_size(size), m_capacity(size)
		{
			ConstructElements(Buffer(), size);
			for(size_t i = 0; i < size; ++i)
			{
				Buffer()[i] = value;
			}
		}

		Vector(T* pData, const size_t size) :
			m_pBuffer(Allocate(size)), m_size(size), m_capacity(size)
		{
			ConstructElements(Buffer(), pData, size);
		}

		Vector(std::initializer_list<T> list) :
			m_pBuffer(Allocate(list.size())), m_size(list.size()), m_capacity(list.size())
		{
			ConstructElements(Buffer(), list.begin(), list.size());
		}

		//move semantics
		Vector(Vector<T>&& other)
			m_pBuffer(other.m_pBuffer), m_size(other.m_size), m_capacity(other.m_capacity)
		{
			other.m_size = 0;
			other.m_capacity = 0;
			other.m_pBuffer = nullptr;
		}

		//Deep Copy
		Vector(const Vector<T>& other)
			m_size(other.m_size), m_capacity(other.m_capacity)
		{
			m_pBuffer = Allocate(other.m_size);
			ConstructElements(Buffer(), other.Buffer(), other.m_size);
		}

		~Vector()
		{
			if (m_pBuffer)
			{
				DestructElements(Buffer(), m_size);
				Free(m_pBuffer);
			}
		}

		Vector& operator=(const Vector<T>& other)
		{
			if(m_buffer)
			{
				DestructElements(Buffer(), m_capacity);
				if(m_capacity != other.m_capacity)
				{
					Free(m_pBuffer)
					m_pBuffer = nullptr;
				}
			}

			if(m_pBuffer == nullptr && other.m_capacity > 0)
			{
				m_pBuffer = Allocate(other.m_size);
			}

			m_capacity = other.m_capacity;
			m_size = other.m_size;

			ConstructElements(Buffer(), other.Buffer(), other.Size());
			return *this;
		}

		const T* Data() const { return Buffer(); }
		T* Data() { return Buffer(); }
		size_t Size() const { return m_size; }
		size_t Capacity() const { return m_capacity; }
		bool Empty() const { return m_size == 0; }

	private:
		inline T* Buffer() const {return reinterpret_cast<T*>(m_pBuffer);}

		inline unsigned char* Allocate(const size_t size)
		{
			return new unsigned char[sizeof(T) * size];
		}

		inline void Free(unsigned char* pBuffer)
		{
			delete[] pBuffer;
		}

		//Call empty constructor on elements
		inline void ConstructElements(T* pDestination, const size_t count)
		{
			for(unsigned i = 0;  i <count; i++)
				new(pDestination + i) T();
		}

		void DestructElements(T* pDestination, size_t count)
		{
			while(count--)
			{
				pDestination->~T();
				++pDestination;
			}
		}


		unsigned char* m_pBuffer;
		size_t m_size;
		size_t m_capacity;
	};

	template<typename T>
	inline void Swap(Vector<T>& a, Vector<T>& b)
	{
		a.Swap(b);
	}
}