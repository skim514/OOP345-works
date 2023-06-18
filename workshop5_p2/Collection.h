/***********************************************************************
// OOP345 Workshop #5
//
// File    Collection.h
// Version    1.0
// Date     June 11, 2023
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

#ifndef COLLECTION_H
#define COLLECTION_H
#include <iostream>
#include <string>
#include "Book.h"

namespace sdds {
	template <typename T>
	class Collection {
		std::string m_name;
		T* m_items;
		size_t m_size;
		void (*ptr) (const Collection<T>& items, const T& src); //function pointer

	public:
		Collection()
		{
			m_name  = 0;
			m_items = nullptr;
			m_size = 0;
			ptr = nullptr;
		}

		Collection(const Collection& src) = delete;
		Collection& operator=(const Collection& src) = delete;

		Collection(const std::string& name)
		{
			m_name = name;
			m_items = nullptr;
			m_size = 0;
			ptr = nullptr;
		}

		~Collection()
		{
			delete[] m_items;
		}

		const std::string& name() const
		{
			return m_name;
		}

		size_t size() const
		{
			return m_size;
		}

		void setObserver(void (*observer)(const Collection<T>& items, const T& src))
		{
			ptr = observer;
		}

		Collection<T>& operator+=(const T& item)
		{
			bool found = true;
			
			if (m_items != nullptr)
			{
				for (size_t i = 0; i < m_size; i++)
				{
					if (m_items[i].title() == item.title())
					{
						found = false;
					}
				}
				if (found)
				{
					T* tmp = new T[m_size + 1];
					for (size_t i = 0; i < m_size; i++)
						tmp[i] = m_items[i];

					tmp[m_size] = item;
					m_size++;
					delete[] m_items;
					m_items = new T[m_size];

					for(size_t i = 0; i < m_size; i++)
						m_items[i] = tmp[i];

					delete[] tmp;					
				}
				if (ptr != nullptr && found)
				{
					ptr(*this, item);
				}
			}
			else
			{
				m_items = new T[1];
				m_items[0] = item;
				m_size++;	
			}
			return *this;
		}

		T& operator[](size_t idx) const
		{
			if (idx >= m_size)
			{
				std::string temp = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.";
				throw std::out_of_range(temp);
			}
			return m_items[idx];
		}

		T* operator[](const std::string& title) const
		{
			T* res = nullptr;
			for (size_t i = 0; i < m_size; i++)
			{
				if (m_items[i].title() == title)
				{
					res = &m_items[i];
				}
			}
			return res;
		}
	};

	template <typename T>
	std::ostream& operator<<(std::ostream& ostr, const Collection<T>& src)
	{
		for (size_t i = 0; i < src.size(); i++)
		{
			ostr << src[i];
		}
		return ostr;
	}
}

#endif
