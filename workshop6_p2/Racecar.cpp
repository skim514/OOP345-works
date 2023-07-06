/***********************************************************************
// OOP345 Workshop #6
//
// File    Racecar.cpp
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
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip> 
#include "Car.h"
#include "Racecar.h"

namespace sdds {
	sdds::Racecar::Racecar(std::istream& in) : Car(in)
	{
		std::string tmpBoost{};
		getline(in, tmpBoost);
		m_booster = stod(tmpBoost);
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed() const
	{
		return Car::topSpeed() * (1 + m_booster);
	}
}