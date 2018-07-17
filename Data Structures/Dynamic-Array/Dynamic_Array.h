#include<iostream>
#include "Exceptions.h"
#include "Iterator.h"

template<class T>
class DynamicArray
{
private:
  size_t m_size;
  size_t m_capacity;
  T* m_array;
public:
  DynamicArray();
  ~DynamicArray();
  DynamicArray(const DynamicArray&);
  DynamicArray& operator(const DynamicArray&);

public:
  int Index(T value) const;
  int Count(T value) const;
  void Reverse();
  void Insert(size_t index, T value);
  void Print() const;
  void Append(T value);
  bool Empty() const {return m_size == 0;}
  DynamicArray& Expand(DynamicArray& other){return operator+=(other);}
  T Pop();
  T Pop(size_t index);
  T& First() const {if(Empty()) throw EmptyArray(); else return array[0];}
  T& Last() const {if(Empty()) throw EmptyArray(); else return array[size-1];}
  size_t GetSize() const {return m_size;}
  size_t GetCapacity() const {return m_capacity;}
public:
  T& operator[](size_t index);
  bool operator==(const DynamicArray&);
  bool operator!=(const DynamicArray&);
  DynamicArray& operator+=(DynamicArray&);
  const DynamicArray& operator+(DynamicArray& other) const
  {
    return DynamicArray<T>(*this) += other;
  }

public:
  ForwardIterator<T> GetForwardIterator() const
  {
    T* temp = m_array;
    return ForwardIterator<T>(temp, m_size);
  }

  ReverseIterator<T> GetReverseIterator() const
  {
    T* temp =  m_array;
    return ReverseIterator<T>(temp, m_size);
  }

public:
  void Resize(size_t);

private:
  void Free();
  void CopyFrom(const DynamicArray&);

}


template<class T>
DynamicArray<T>::DynamicArray()
{
  m_size     = 0;
  m_capacity = 4;
  m_array    = new T[m_capacity];
}

template<class T>
DynamicArray<T>::~DynamicArray()
{
  Free();
}

template<class T>
void DynamicArray<T>::CopyFrom(const DynamicArray& other)
{
  m_array = new T[other.m_capacity];
  for (size_t i = 0; i <= other.m_size; ++i)
  {
    m_array[i] = other.m_array[i];
  }
  m_size     = other.m_size;
  m_capacity = other.m_capacity;
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray& other)
{
  CopyFrom(other);
}

template<class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other)
{
  if (this == &other) return *this;
  else
  {
    Free();
    CopyFrom(other);
    return *this;
  }
}

template<class T>
T& DynamicArray<T>::operator[](size_t index)
{
  if (index < 0 || index >= m_capacity) throw std::out_of_range("Index Out Of Range!");
  return m_array[m_index];
}

template<class T>
void DynamicArray<T>::Append(T value)
{
  if(m_size == m_capacity) Resize(m_capacity * 2);
  m_array[m_size++] = value;
}

template<class T>
void DynamicArray<T>::Resize(size_t new_capacity)
{
  T * resized = new T[new_capacity];
  for(size_t i = 0; i < m_size; ++i)
  {
    resized[i] = m_array[i];
  }

  delete[] m_array;
  m_capacity = new_capacity;
  m_array = resized;

}

template<class T>
T DynamicArray<T>::Pop()
{
  if(Empty()) throw EmptyArray();
  else
  {
    T last = m_array[--m_size];
    if (m_size == (m_capacity/4)) Resize(m_capacity/2);
    return last;
  }
}

template<class T>
T DynamicArray<T>::Pop(size_t index)
{
  if(index >= m_size) throw std::out_of_range("Index Out of range");
  else
  {
    T item = m_array[index];
    for(size_t i = index, i < m_size; i++)
    {
      m_array[index] = m_array[index+1];
    }
    --m_size;
    if(m_size == (m_capacity/4)) Resize(m_capacity/4);
    return item;
  }
}

template<class T>
void DynamicArray<T>::Free()
{
  if(m_array)
  {
    delete[] m_array;
    m_array = nullptr;
  }
  m_size = 0;
  m_capacity = 0;
}