/***********************************************************************
// OOP345 Workshop #3
//
// File    Dictionary.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Dictionary.h"
#include "Queue.h"

using namespace std;

namespace sdds {
		std::ostream& operator<<(std::ostream& ostr, const Dictionary& dic)
	{
		ostr.setf(ios::right); ostr.fill(' '); ostr.width(20);
		cout << dic.getTerm() << ": " << dic.getDefinition();
		ostr.unsetf(ios::right);
		return ostr;
	}
}