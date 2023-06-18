/***********************************************************************
// OOP345 Workshop #5
//
// File    SpellChecker.cpp
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

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"

namespace sdds {
	size_t SpellChecker::CNT[6] = {0,0,0,0,0,0};

	sdds::SpellChecker::SpellChecker() {}
	std::string SpellChecker::trim(const std::string& str, const std::string& whitespace) //quoted
	{
		const auto strBegin = str.find_first_not_of(whitespace);
		if (strBegin == std::string::npos)
			return "";

		const auto strEnd = str.find_last_not_of(whitespace);
		const auto strRange = strEnd - strBegin + 1;

		return str.substr(strBegin, strRange);
	}

	SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream file(filename);
		if (!file)
		{
			throw "Bad file name!";
		}
		else
		{
			size_t i = 0;
			std::string strChk {};
			do
			{
				std::getline(file, strChk);

				size_t foundBad = strChk.find(" ");
				size_t foundGood = 0;
				if(strChk != "")
				{
					if (foundBad != std::string::npos)
					{
						m_badWords[i] = strChk.substr(0, foundBad);
						m_badWords[i] = trim(m_badWords[i], " ");
					}

					foundGood = strChk.find(" ", foundBad + 1);
					if (foundGood)
					{
						m_goodWords[i] = strChk.substr(foundGood + 1, strChk.length());
						m_goodWords[i] = trim(m_goodWords[i], " ");
					}
					i++;
				}
			} while (file);
		}
	}
	void SpellChecker::operator()(std::string& text)
	{
		for (size_t i = 0; i < 6; i++)
		{
			size_t findEnd = 0;
			for (size_t start = 0; start < text.size(); start += findEnd)
			{
				findEnd = text.find(m_badWords[i], start);
				if (findEnd != std::string::npos)
				{
					text.replace(findEnd, m_badWords[i].size(), m_goodWords[i]);
					CNT[i]++;
				}
			}
		}
	}
	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics" << std::endl;
		for (size_t i = 0; i < 6; i++)
		{
			out.setf(std::ios::right); out.fill(' '); out.width(15);
			out << m_badWords[i]; out.unsetf(std::ios::right);
			out << ": " << CNT[i] << " replacements" << std::endl;
		}
	}
}