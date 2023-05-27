/***********************************************************************
// OOP345 Workshop #2
//
// File    Timer.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Timer.h"
#include "TennisLog.h"

using namespace std;
using namespace chrono;

namespace sdds {
	void Timer::start()
	{
		m_startTime = steady_clock::now();
	}
	long long Timer::stop()
	{
		steady_clock::time_point end_time;
		end_time = steady_clock::now();
		auto timetook = duration_cast<nanoseconds>(end_time - m_startTime);

		return timetook.count();
	}
}
