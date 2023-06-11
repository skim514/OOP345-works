/***********************************************************************
// OOP345 Workshop #4
//
// File    Reservation.cpp
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

#include <iostream>
#include <string>
#include <iomanip>
#include "Reservation.h"

using namespace std;

namespace sdds {
	Reservation::Reservation() { }
	void Reservation::update(int day, int time)
	{
		m_day = day;
		m_hour = time;
	}

	string Reservation::trim(const string& str, const string& whitespace)
	{
		const auto strBegin = str.find_first_not_of(whitespace);
		if (strBegin == std::string::npos)
			return "";

		const auto strEnd = str.find_last_not_of(whitespace);
		const auto strRange = strEnd - strBegin + 1;

		return str.substr(strBegin, strRange);
	}

	Reservation::Reservation(const std::string& res)
	{
		string needFind = ",";
		string tmpNum;
		string tmpDay;
		string tmpHour;

		size_t foundID = res.find(":");
		size_t foundName{};
		size_t foundEmail{};
		size_t foundNum{};
		size_t foundDay{};
		size_t foundHour{};

		if (foundID != string::npos)
		{
			m_reservationID = res.substr(0, foundID);
			m_reservationID = trim(m_reservationID, " ");			
		}

		foundName = res.find(needFind, foundID +1);
		if (foundName != string::npos)
		{
			m_reservationName = res.substr(foundID + 1, foundName - foundID - 1);
			m_reservationName = trim(m_reservationName, " ");
		}

		foundEmail = res.find(needFind, foundName + 1);
		if (foundEmail != string::npos)
		{
			m_customerEmail = res.substr(foundName + 1, foundEmail - foundName - 1);
			m_customerEmail = trim(m_customerEmail, " ");			
		}

		foundNum = res.find(needFind, foundEmail + 1);
		if (foundNum != string::npos)
		{
			tmpNum = res.substr(foundEmail + 1, foundNum - foundEmail - 1);
			m_numOfPeople = stoi(tmpNum);			
		}

		foundDay = res.find(needFind, foundNum + 1);
		if (foundDay != string::npos)
		{
			tmpDay = res.substr(foundNum + 1, foundDay - foundNum- 1);
			m_day = stoi(tmpDay);
		}

		foundHour = res.find(needFind, foundDay + 1);
		if (foundHour == string::npos)
		{
			tmpHour = res.substr(foundDay + 1, res.length());
			m_hour = stoi(tmpHour);			
		}
	}

	ostream& operator<<(ostream& ostr, const Reservation& res)
	{
		ostr << "Reservation ";
		ostr.setf(ios::right); ostr.fill(' '); ostr.width(10);
		ostr << res.m_reservationID << ": "; ostr.unsetf(ios::right);

		ostr.setf(ios::right); ostr.fill(' '); ostr.width(20);
		ostr << res.m_reservationName; ostr.unsetf(ios::right);

		ostr << "  ";
		ostr.setf(ios::left); ostr.fill(' '); ostr.width(20);
		ostr << "<" + res.m_customerEmail + ">"; ostr.unsetf(ios::left);

		if (res.m_hour >= 6 && res.m_hour <= 9)
		{
			ostr << "    Breakfast on day " << res.m_day << " @ " << res.m_hour << ":00";
		}
		else if (res.m_hour >= 11 && res.m_hour <= 15)
		{
			ostr << "    Lunch on day " << res.m_day << " @ " << res.m_hour << ":00";
		}
		else if (res.m_hour >= 17 && res.m_hour <= 21)
		{
			ostr << "    Dinner on day " << res.m_day << " @ " << res.m_hour << ":00";
		}
		else
		{
			ostr << "    Drinks on day " << res.m_day << " @ " << res.m_hour << ":00";
		}
		ostr << " for " << res.m_numOfPeople;
		if (res.m_numOfPeople == 1)
		{
			ostr << " person.";
		}
		else
		{
			ostr << " people.";
		}
		ostr << std::endl;
		return ostr;
	}
}