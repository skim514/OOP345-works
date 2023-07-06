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
// I got help for the function "std::string trim(const std::string& str, const std::string& whitespace);"
//Found from "https://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string"
#ifndef UTILITIES_H
#define UTILITIES_H
#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in);
	std::string trim(const std::string& str, const std::string& whitespace); //quoted
}

#endif
