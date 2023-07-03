/***********************************************************************
// OOP345 Workshop #6
//
// File    Utilities.h
// Version    1.0
// Date     June 26, 2023
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
#ifndef UTILITIES_H
#define UTILITIES_H
#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in);
}

#endif
