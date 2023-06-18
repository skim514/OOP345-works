/***********************************************************************
// OOP345 Workshop #5
//
// File    Movie.h
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

#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>

namespace sdds {
	class Movie {
		std::string m_title {};
		size_t m_year = 0;
		std::string m_description {};

	public:
		Movie();
		const std::string& title() const;
		std::string trim(const std::string& str, const std::string& whitespace); //quoted
		Movie(const std::string& strMovie);
		template <typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(m_title);
			spellChecker(m_description);
		}
		friend std::ostream& operator<<(std::ostream& ostr, const Movie& src);
	};
}

#endif
