/***********************************************************************
// OOP345 Workshop #4
//
// File    Reservation.h
// Version    1.0
// Date     June 5, 2023
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
//I got help for the function "std::string trim(const std::string& str, const std::string& whitespace);"
//Found from "https://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string"

#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include <string>

namespace sdds {
	class Reservation {
		std::string m_reservationID {};
		std::string m_reservationName {};
		std::string m_customerEmail {};
		int m_numOfPeople = 0;
		int m_day = 0;
		int m_hour = 0;

	public:
		Reservation();
		void update(int day, int time);
		std::string trim(const std::string& str, const std::string& whitespace); //quoted
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& ostr, const Reservation& res);
	};
}

#endif
