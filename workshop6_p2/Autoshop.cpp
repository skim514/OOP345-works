/***********************************************************************
// OOP345 Workshop #6
//
// File    Autoshop.cpp
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
#include <vector>
#include "Autoshop.h"

namespace sdds {
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		m_vehicle.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(std::ostream& out) const
	{
		out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;

		for (auto i = m_vehicle.begin(); i != m_vehicle.end(); i++) {
			(*i)->display(out);
			out << std::endl;
		}
		out << "--------------------------------" << std::endl;
	}

	Autoshop::~Autoshop()
	{
		for (auto i = m_vehicle.begin(); i != m_vehicle.end(); i++)
			delete *i;
	}
}