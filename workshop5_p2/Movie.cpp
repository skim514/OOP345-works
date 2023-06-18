/***********************************************************************
// OOP345 Workshop #5
//
// File    Movie.cpp
// Version    1.0
// Date     June 11, 2023
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
#include <iomanip>
#include "Movie.h"

namespace sdds {
	sdds::Movie::Movie() {}
	const std::string& Movie::title() const
	{
		return m_title;
	}

	std::string Movie::trim(const std::string& str, const std::string& whitespace) //quoted
	{
		const auto strBegin = str.find_first_not_of(whitespace);
		if (strBegin == std::string::npos)
			return "";

		const auto strEnd = str.find_last_not_of(whitespace);
		const auto strRange = strEnd - strBegin + 1;

		return str.substr(strBegin, strRange);
	}

	Movie::Movie(const std::string& strMovie)
	{
		std::string tmpTitle;
		std::string tmpYear;
		std::string tmpDesc;

		size_t foundTitle = strMovie.find(",");
		size_t foundYear = 0;
		size_t foundDesc = 0;

		if (foundTitle != std::string::npos)
		{
			m_title = strMovie.substr(0, foundTitle);
			m_title = trim(m_title, " ");
		}

		foundYear = strMovie.find(",", foundTitle + 1);
		if (foundYear != std::string::npos)
		{
			tmpYear = strMovie.substr(foundTitle + 1, foundYear - foundTitle - 1);
			m_year = stoi(tmpYear);
		}

		foundDesc = strMovie.find(",", foundYear + 1);
		if (foundDesc)
		{
			m_description = strMovie.substr(foundYear + 1, strMovie.length());
			m_description = trim(m_description, " ");
		}
	}

	std::ostream& operator<<(std::ostream& ostr, const Movie& src)
	{
		ostr.width(40);
		ostr << src.m_title;
		ostr << " | ";

		
		ostr.width(4);
		ostr << src.m_year;
		ostr << " | ";

		ostr << src.m_description << std::endl;
		return ostr;
	}
}