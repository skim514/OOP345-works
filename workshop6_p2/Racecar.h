/***********************************************************************
// OOP345 Workshop #6
//
// File    Racecar.h
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
#ifndef RACECAR_H
#define RACECAR_H
#include <iostream>
#include <string>
#include <vector>
#include "Car.h"

namespace sdds {
	class Racecar : public Car {
		double m_booster{};

	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}

#endif
