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

}