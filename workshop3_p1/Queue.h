/***********************************************************************
// OOP345 Workshop #3
//
// File    Queue.h
// Version    1.0
// Date     June 1, 2023
// Author   Suna Kim
// Email    skim514@myseneca.ca
// ID       104690227
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
//I have done all the coding by myself and 
//only copied the code that my professor provided to complete my workshops and assignments.

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

namespace sdds {
	template <typename T, int CAPACITY>
	class Queue {
		T m_queue[CAPACITY];
		unsigned int m_number;
		static T m_dummy;

	public:
		Queue()
		{
			for (unsigned int i = 0; i < CAPACITY; i++)
			{
				m_queue[i] = T();
			}
			m_number = 0u;
		}


		bool push(const T& item)
		{
			bool result = false;

			if (m_number < CAPACITY)
			{
				m_queue[m_number] = item;  // Add a copy of the item to the queue
				m_number++;
				result = true;
			}
			return result;
		}
		T pop()
		{
			T tmp;

			tmp = m_queue[0];
			m_queue[0] = 0;
			for (unsigned int i = 0; i < CAPACITY; i++)
			{
				m_queue[i] = m_queue[i + 1];
			}
			return tmp;
		}
		size_t size() const
		{
			return m_number;
		}
		std::ostream& display(std::ostream& ostr = std::cout) const
		{
			ostr << "----------------------" << std::endl << "| Dictionary Content |" << std::endl << "----------------------" << std::endl;
			for (unsigned int i = 0; i < m_number; i++)
			{
				ostr << m_queue[i] << std::endl;
			}
			ostr << "----------------------" << std::endl;
			return ostr;
		}
		const T& operator[](const unsigned i) const
		{
			return i < m_number ? m_queue[i] : m_dummy;
		}
	};
	template<typename T, int CAPACITY>
	T Queue<T, CAPACITY>::m_dummy {};

	template <typename T, int CAPACITY>
	std::ostream& operator<<(std::ostream& os, Queue<T, CAPACITY>& queue)
	{
		return queue.display(os);
	}
}

#endif