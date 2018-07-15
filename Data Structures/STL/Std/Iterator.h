#pragma once

namespace STL
{
	template<typename T>
	struct RandomAccessIterator
	{
		RandomAccessIterator(T* pPtr) :
			m_ptr(pPtr)
		{}

		RandomAccessIterator(const RandomAccessIterator& other) :
			m_ptr(other.m_ptr)
		{}

		RandomAccessIterator& operator=(const RandomAccessIterator& other)
		{
			m_ptr = other.m_ptr;
			return *this;
		}

		RandomAccessIterator& operator++()
		{
			++m_ptr;
			return *this;
		}

		RandomAccessIterator& operator--()
		{
			--m_ptr;
			return *this;
		}

		RandomAccessIterator operator++(int)
		{
			RandomAccessIterator<T> pIt = *this;
			++m_ptr;
			return pIt;
		}

		RandomAccessIterator operator--(int)
		{
			RandomAccessIterator<T> pIt = *this;
			--m_ptr;
			return pIt;
		}

		RandomAccessIterator& operator+=(const size_t distance)
		{
			m_ptr += distance;
			return *this;
		}

		RandomAccessIterator& operator-=(const size_t distance)
		{
			m_ptr -= distance;
			return *this;
		}

		RandomAccessIterator operator+(const size_t distance) const { return RandomAccessIterator(m_ptr + distance); }
		RandomAccessIterator operator-(const size_t distance) const { return RandomAccessIterator(m_ptr - distance); }

		size_t operator+(const RandomAccessIterator& other) const { return (size_t)(m_ptr + other.m_ptr); }
		size_t operator-(const RandomAccessIterator& other) const { return (size_t)(m_ptr - other.m_ptr); }

		bool operator==(const RandomAccessIterator& other) const { return m_ptr == other.m_ptr; }
		bool operator!=(const RandomAccessIterator& other) const { return m_ptr != other.m_ptr; }
		bool operator>(const RandomAccessIterator& other) const { return m_ptr > other.m_ptr; }
		bool operator<(const RandomAccessIterator& other) const { return m_ptr < other.m_ptr; }
		bool operator>=(const RandomAccessIterator& other) const { return m_ptr >= other.m_ptr; }
		bool operator<=(const RandomAccessIterator& other) const { return m_ptr <= other.m_ptr; }

		T* operator->() const { return m_ptr; }
		T& operator*() const { return *m_ptr; }

		T* m_ptr;
	};

	template<typename T>
	inline size_t Distance(const RandomAccessIterator<T>& a, const RandomAccessIterator<T>& b)
	{
		return b - a;
	}

	template<typename T>
	struct RandomAccessConstIterator
	{
		RandomAccessConstIterator(const T* pPtr) :
			m_ptr(pPtr)
		{}

		RandomAccessConstIterator(const RandomAccessConstIterator& other) :
			m_ptr(other.m_ptr)
		{}

		RandomAccessConstIterator& operator=(const RandomAccessConstIterator& other)
		{
			m_ptr = other.m_ptr;
			return *this;
		}

		RandomAccessConstIterator& operator++()
		{
			++m_ptr;
			return *this;
		}

		RandomAccessConstIterator& operator--()
		{
			--m_ptr;
			return *this;
		}

		RandomAccessConstIterator operator++(int)
		{
			RandomAccessConstIterator<T> pIt = *this;
			++m_ptr;
			return pIt;
		}

		RandomAccessConstIterator operator--(int)
		{
			RandomAccessConstIterator<T> pIt = *this;
			--m_ptr;
			return pIt;
		}

		RandomAccessConstIterator& operator+=(const size_t distance)
		{
			m_ptr += distance;
			return *this;
		}

		RandomAccessConstIterator& operator-=(const size_t distance)
		{
			m_ptr -= distance;
			return *this;
		}

		RandomAccessConstIterator operator+(const size_t distance) const { return RandomAccessConstIterator(m_ptr + distance); }
		RandomAccessConstIterator operator-(const size_t distance) const { return RandomAccessConstIterator(m_ptr - distance); }

		size_t operator+(const RandomAccessConstIterator& other) const { return (size_t)(m_ptr + other.m_ptr); }
		size_t operator-(const RandomAccessConstIterator& other) const { return (size_t)(m_ptr - other.m_ptr); }

		bool operator==(const RandomAccessConstIterator& other) const { return m_ptr == other.m_ptr; }
		bool operator!=(const RandomAccessConstIterator& other) const { return m_ptr != other.m_ptr; }
		bool operator>(const RandomAccessConstIterator& other) const { return m_ptr > other.m_ptr; }
		bool operator<(const RandomAccessConstIterator& other) const { return m_ptr < other.m_ptr; }
		bool operator>=(const RandomAccessConstIterator& other) const { return m_ptr >= other.m_ptr; }
		bool operator<=(const RandomAccessConstIterator& other) const { return m_ptr <= other.m_ptr; }

		const T* operator->() const { return m_ptr; }
		const T& operator*() const { return *m_ptr; }

		const T* m_ptr;
	};

	template<typename T>
	inline size_t Distance(const RandomAccessConstIterator<T>& a, const RandomAccessConstIterator<T>& b)
	{
		return b - a;
	}
}