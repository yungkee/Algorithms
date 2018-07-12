#pragma once
#include "Exceptions.h"

template<class T>
class ForwardIterator
{
private:
  T * m_start;
  size_t m_index;
  size_t m_size;

public:
  ForwardIterator(T * start, size_t size)
  {
    m_start = start;
    m_size  = size;
    m_index = 0;
  }
  void Next()
  {
    if(End()) throw EmptyArray();
    else ++m_index;
  }
  T& Get() const
  {
    if(End()) throw EmptyArray();
    else return m_start[m_index];
  }
  bool End() const { return m_index >= m_size; }
};

template<class T>
class ReverseIterator
{
private:
  T * m_start;
  int m_index;

public:
  ReverseIterator(T * start, size_t size)
  {
    m_start = start;
    m_index = size-1;
  }
  void Next()
  {
    if(End()) throw EmptyArray();
    else --m_index;
  }
  T& Get() const
  {
    if(End()) throw EmptyArray();
    else return m_start[m_index];
  }
  bool End() const { return m_index < 0; }
};
