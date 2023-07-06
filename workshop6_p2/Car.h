/***********************************************************************
// OOP345 Workshop #6
//
// File    Car.h
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
#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds {
	class Car : public Vehicle{
		std::string m_maker{};
		std::string m_condition{};
		double m_topSpeed{};
		
	public:
		Car(std::istream& istr);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		std::string trim(const std::string& str, const std::string& whitespace); //quoted
	};
}

#endif
