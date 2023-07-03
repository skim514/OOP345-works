/***********************************************************************
// OOP345 Workshop #6
//
// File    Car.cpp
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
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip> 
#include "Car.h"

namespace sdds {
	Car::Car(std::istream& istr)
	{
		char tmpTag = '\0';
		std::string tmpMkr{};
		std::string tmpCondition{};
		size_t tmpSpeed = 0;

		if (istr.good())
		{
			istr.get(tmpTag);
			istr.ignore();
			getline(istr, tmpMkr, ',');
			getline(istr, tmpCondition, ',');
			tmpCondition = trim(tmpCondition, " ");
			istr >> tmpSpeed;

			m_maker = tmpMkr;
			m_maker = trim(m_maker, " ");
			if (tmpCondition == "n")
			{
				m_condition = "new";
			}
			else if(tmpCondition == "u")
			{
				m_condition = "used";
			}
			else if (tmpCondition == "b")
			{
				m_condition = "broken";
			}
			m_topSpeed = tmpSpeed;
		}
	}

	std::string Car::condition() const
	{
		return m_condition;
	}

	double Car::topSpeed() const
	{
		return m_topSpeed;
	}

	void Car::display(std::ostream& out) const
	{
		out << "| ";
		out.width(10);
		out << m_maker;
		out << " | ";
		out.width(6);
		out.setf(std::ios::left); out << m_condition; out.unsetf(std::ios::left);
		out << " | ";
		out.width(6);
		out << std::fixed << std::setprecision(2) << m_topSpeed;
		out << " |";
		out << std::endl;
	}

	std::string Car::trim(const std::string& str, const std::string& whitespace) //quoted
	{
		const auto strBegin = str.find_first_not_of(whitespace);
		if (strBegin == std::string::npos)
			return "";

		const auto strEnd = str.find_last_not_of(whitespace);
		const auto strRange = strEnd - strBegin + 1;

		return str.substr(strBegin, strRange);
	}
}