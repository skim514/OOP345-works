/***********************************************************************
// OOP345 Workshop #5
//
// File    Book.cpp
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
#include <iomanip> 
#include "Book.h"

namespace sdds {
	Book::Book(){}
	const std::string& Book::title() const
	{
		return m_title;
	}
	const std::string& Book::country() const
	{
		return m_contryOfPub;
	}
	const size_t& Book::year() const
	{
		return m_year;
	}
	double& Book::price()
	{
		return this->m_price;
	}
	std::string Book::trim(const std::string& str, const std::string& whitespace) //quoted
	{
		const auto strBegin = str.find_first_not_of(whitespace);
		if (strBegin == std::string::npos)
			return "";

		const auto strEnd = str.find_last_not_of(whitespace);
		const auto strRange = strEnd - strBegin + 1;

		return str.substr(strBegin, strRange);
	}
	Book::Book(const std::string& strBook)
	{
		std::string needFind = ",";
		std::string tmpPrice;
		std::string tmpYear;
		std::string tmpDesc;

		size_t foundAuthor = strBook.find(needFind);
		size_t foundTitle = 0;
		size_t foundCon = 0;
		size_t foundPrice = 0;
		size_t foundYear = 0;
		size_t foundDesc = 0;

		if (foundAuthor != std::string::npos)
		{
			m_author = strBook.substr(0, foundAuthor);
		}

		foundTitle = strBook.find(needFind, foundAuthor + 1);
		if (foundTitle != std::string::npos)
		{
			m_title = strBook.substr(foundAuthor + 1, foundTitle - foundAuthor - 1);
			m_title = trim(m_title, " ");
		}

		foundCon = strBook.find(needFind, foundTitle + 1);
		if (foundCon != std::string::npos)
		{
			m_contryOfPub = strBook.substr(foundTitle + 1, foundCon - foundTitle - 1);
			m_contryOfPub = trim(m_contryOfPub, " ");
		}

		foundPrice = strBook.find(needFind, foundCon + 1);
		if (foundPrice != std::string::npos)
		{
			tmpPrice = strBook.substr(foundCon + 1, foundPrice - foundCon - 1);
			m_price = stod(tmpPrice);
		}

		foundYear = strBook.find(needFind, foundPrice + 1);
		if (foundPrice != std::string::npos)
		{
			tmpYear = strBook.substr(foundPrice + 1, foundYear - foundPrice - 1);
			m_year = stoi(tmpYear);
		}

		foundDesc = strBook.find(needFind, foundYear + 1);
		if (foundDesc)
		{
			m_description = strBook.substr(foundYear + 1, strBook.length());
			m_description = trim(m_description, " ");
		}
	}
	std::ostream& operator<<(std::ostream& ostr, const Book& src)
	{
		ostr.width(20);
		ostr << src.m_author;
		ostr << " | ";

		ostr.width(22);
		ostr << src.m_title;
		ostr << " | ";

		ostr.width(5);
		ostr << src.m_contryOfPub;
		ostr << " | ";

		ostr.width(4);
		ostr << src.m_year;
		ostr << " | ";

		ostr.width(6);
		ostr << std::fixed << std::setprecision(2) << src.m_price;
		ostr << " | ";

		ostr << src.m_description << std::endl;
		return ostr;
	}
}