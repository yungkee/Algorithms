#pragma once
#include "Utility.h"

namespace STL
{
	template<typename T, typename U>
	struct KeyValuePair
	{
		KeyValuePair(const T& key) :
			m_key(key)
		{}

		KeyValuePair(T&& key, const U& value) :
			m_key(Forward<T>(key)), m_value(value)
		{}

		KeyValuePair(const T& key, U&& value) :
			m_key(key), Value(Forward<V>(value))
		{}

		KeyValuePair(T&& key, U&& value) :
			m_key(Forward<T>(key)), Value(Forward<U>(value))
		{}

		KeyValuePair(const T& key, const U& value) :
			m_key(key), m_value(value)
		{}

		KeyValuePair(const KeyValuePair& other) :
			m_key(other.m_key), m_value(other.m_value)
		{}

		KeyValuePair& operator=(const KeyValuePair& other)
		{
			m_key = other.m_key;
			m_value = other.m_value;
			return *this;
		}

		KeyValuePair& operator=(KeyValuePair&& other)
		{
			m_key = Move(other.m_key);
			m_value = Move(other.m_value);
			return *this;
		}

		bool operator==(const KeyValuePair& other) const { return m_key == other.m_key && m_value == other.m_value; }
		bool operator!=(const KeyValuePair& other) const { return m_key != other.m_key || m_value != other.m_value; }

		T m_key;
		U m_value;
	};
}