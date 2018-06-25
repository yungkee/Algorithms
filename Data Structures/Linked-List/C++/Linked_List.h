#include <exception>
#include <iostream>

template<typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void PushBack(T data);
	void PushFront(T data);

	void PopFront();
	void Clear();

	int GetSize() { return m_size; }
	void Insert(T data, int index);
	T& operator[](const int index);

	void DeleteNodeAtPos(int index);
	void PopBack();

private:
	template<typename T>
	class Node
	{
	public:
		Node * m_next;
		T m_data;

		Node(T p_data = T(), Node * p_next = nullptr)
		{
			m_data = p_data;
			m_next = p_next;
		}
	};
	int m_size;
	Node<T> *m_head;
};


template<typename T>
LinkedList<T>::LinkedList()
{
	m_size = 0;
	m_head = nullptr;
}


template<typename T>
LinkedList<T>::~LinkedList()
{
	Clear();
}


template<typename T>
void LinkedList<T>::PopFront()
{
	Node<T> *temp = m_head;

	m_head = m_head->m_next;
	delete temp;
	m_size--;
}

template<typename T>
void LinkedList<T>::PushBack(T data)
{
	if (m_head == nullptr)
	{
		m_head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = m_head;

		while (current->m_ext != nullptr)
		{
			current = current->m_next;
		}
		current->m_next = new Node<T>(data);

	}

	m_size++;
}

template<typename T>
void LinkedList<T>::Clear()
{
	while (m_size)
	{
		PopFront();
	}
}


template<typename T>
T& LinkedList<T>::operator[](const int index)
{
	int counter = 0;
	Node<T> *current = m_head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->m_data;
		}
		current = current->m_next;
		counter++;
	}
}

template<typename T>
void LinkedList<T>::PushFront(T data)
{
	m_head = new Node<T>(data, m_head);
	m_size++;
}

template<typename T>
void LinkedList<T>::Insert(T data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T> *previous = m_head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->m_next;
		}

		Node<T> *new_node = new Node<T>(data, previous->m_next);

		previous->m_next = new_node;

		m_size++;
	}
}


template<typename T>
void LinkedList<T>::DeleteNodeAtPos(int index)
{
	if (index == 0)
	{
		PopFront();
	}
	else
	{
		Node<T> *previous = m_head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->m_next;
		}

		Node<T> *to_delete = previous->m_next;

		previous->m_next = to_delete->m_next;

		delete to_delete;

		m_size--;
	}
}

template<typename T>
void LinkedList<T>::PopBack()
{
	DeleteNodeAtPos(m_size - 1);
}

int main()
{
	LinkedList<int> lst;
	lst.PushFront(5);
	lst.PushFront(7);
	lst.PushFront(101);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		std::cout << lst[i] << std::endl;
	}

	std::cout << std::endl << "pop_back " << std::endl << std::endl;

	lst.PopBack();

	for (int i = 0; i < lst.GetSize(); i++)
	{
		std::cout << lst[i] << std::endl;
	}

	system("pause");
	return 0;
}