/***********************************************************************
// OOP345 Workshop #2
//
// File    Timer.h
// Version    1.0
// Date     May 26, 2023
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

#ifndef TIMER_H
#define TIMER_H
#include <iostream>

namespace sdds {
	class Timer {
		std::chrono::steady_clock::time_point m_startTime;

	public:
		void start();
		long long stop();
	};
}

#endif
