/***********************************************************************
// OOP345 Workshop #3
//
// File    UniqueQueue.h
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

#ifndef UNIQUEQUEUE_H
#define UNIQUEQUEUE_H
#include <iostream>
#include <cmath>
#include "Queue.h"

namespace sdds {
	template <typename T>
	class UniqueQueue : public Queue<T, 100u> {

	public:
		bool push(const T& item)
		{
			bool tmpResult = false;
			bool result = false;
		
			for (unsigned int i = 0; i < Queue<T, 100u>::size(); i++) {
				if (item == (*this)[i])
				{
					tmpResult = true;
				}
			}
			if (tmpResult == false)
			{
				result = Queue<T, 100u>::push(item);
			}
			return result;			
		}
	};	

	template<>
	bool UniqueQueue<double>::push(const double& value)
	{		
		bool tmpResult = false;
		bool result = false;

		for (unsigned int i = 0; i < Queue<double, 100u>::size(); i++) {
			if (std::fabs((*this)[i] - value) <= 0.005)
			{
				tmpResult = true;
			}
		}
		if (tmpResult == false)
		{
			result = Queue<double, 100u>::push(value);
		}		
		return result;
	}
}

#endif
