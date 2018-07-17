#pragma once
#include "Iterator.h"

namespace STL
{
	template<typename T, typename UnaryPredicate>
	void ForEach(RandomAccessIterator<T> pBegin, RandomAccessIterator<T> pEnd, UnaryPredicate functor)
	{
		while (pBegin != pEnd)
		{
			functor(*pBegin);
			++pBegin;
		}
	}

	template<typename T, typename UnaryPredicate>
	void ForEach(RandomAccessConstIterator<T> pBegin, RandomAccessConstIterator<T> pEnd, UnaryPredicate functor)
	{
		while (pBegin != pEnd)
		{
			functor(*pBegin);
			++pBegin;
		}
	}

	template<typename T, typename Generator>
	void Generate(RandomAccessIterator<T> pBegin, RandomAccessIterator<T> pEnd, Generator generator)
	{
		while (pBegin != pEnd)
		{
			*pBegin = generator();
			++pBegin;
		}
	}

	template<typename T>
	void Fill(RandomAccessIterator<T> pBegin, RandomAccessIterator<T> pEnd, const T& value)
	{
		while (pBegin != pEnd)
		{
			*pBegin = value;
			++pBegin;
		}
	}

#pragma region Search

	template<typename T>
	RandomAccessIterator<T> Find(RandomAccessIterator<T> pBegin, RandomAccessIterator<T> pEnd, const T& value)
	{
		while (pBegin != pEnd)
		{
			if (*pBegin == value)
				return pBegin;
			++pBegin;
		}
		return pEnd;
	}

	template<typename T>
	RandomAccessConstIterator<T> Find(RandomAccessConstIterator<T> pBegin, RandomAccessConstIterator<T> pEnd, const T& value)
	{
		while (pBegin != pEnd)
		{
			if (*pBegin == value)
				return pBegin;
			++pBegin;
		}
		return pEnd;
	}

	template<typename T, typename UnaryPredicate>
	RandomAccessIterator<T> FindIf(RandomAccessIterator<T> pBegin, RandomAccessIterator<T> pEnd, UnaryPredicate functor)
	{
		while (pBegin != pEnd)
		{
			if (functor(*pBegin))
				return pBegin;
			++pBegin;
		}
		return pEnd;
	}

	template<typename T, typename UnaryPredicate>
	RandomAccessConstIterator<T> FindIf(RandomAccessConstIterator<T> pBegin, RandomAccessConstIterator<T> pEnd, UnaryPredicate functor)
	{
		while (pBegin != pEnd)
		{
			if (functor(*pBegin))
				return pBegin;
			++pBegin;
		}
		return pEnd;
	}

#pragma region Search

	template<class T>
	void Reverse(RandomAccessIterator<T> pBegin, RandomAccessIterator<T> pEnd)
	{
		while (pBegin != pEnd && pBegin != --pEnd)
		{
			Swap(*pBegin, *pEnd);
			++pBegin;
		}
	}

	template<class T>
	void Replace(RandomAccessIterator<T> pBegin, RandomAccessIterator<T> pEnd, const T& oldValue, const T& newValue)
	{
		while (pBegin != pEnd)
		{
			if (*pBegin == oldValue)
				*pBegin = newValue;
			++pBegin;

			
		}
	}

	template<class T, typename UnaryPredicate>
	void ReplaceIf(RandomAccessIterator<T> pBegin, RandomAccessIterator<T> pEnd, UnaryPredicate predicate, const T& newValue)
	{
		while (pBegin != pEnd)
		{
			if (predicate(*pBegin))
				*pBegin = newValue;
			++pBegin;
		}
	}

}