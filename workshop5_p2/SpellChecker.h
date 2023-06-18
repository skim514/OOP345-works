/***********************************************************************
// OOP345 Workshop #5
//
// File    SpellChecker.h
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
//I got help for the function "std::string trim(const std::string& str, const std::string& whitespace);"
//Found from "https://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string"

#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H
#include <iostream>
#include <string>

namespace sdds {

	class SpellChecker {
		std::string m_badWords[6] {};
		std::string m_goodWords[6] {};
		static size_t CNT[6];

	public:
		SpellChecker();
		std::string trim(const std::string& str, const std::string& whitespace); //quoted
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}

#endif
