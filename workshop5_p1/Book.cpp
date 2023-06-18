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

using namespace std;

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
	string Book::trim(const string& str, const string& whitespace) //quoted
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
		string needFind = ",";
		string tmpPrice;
		string tmpYear;
		string tmpDesc;

		size_t foundAuthor = strBook.find(needFind);
		size_t foundTitle = 0;
		size_t foundCon = 0;
		size_t foundPrice = 0;
		size_t foundYear = 0;
		size_t foundDesc = 0;

		if (foundAuthor != string::npos)
		{
			m_author = strBook.substr(0, foundAuthor);
		}

		foundTitle = strBook.find(needFind, foundAuthor + 1);
		if (foundTitle != string::npos)
		{
			m_title = strBook.substr(foundAuthor + 1, foundTitle - foundAuthor - 1);
			m_title = trim(m_title, " ");
		}

		foundCon = strBook.find(needFind, foundTitle + 1);
		if (foundCon != string::npos)
		{
			m_contryOfPub = strBook.substr(foundTitle + 1, foundCon - foundTitle - 1);
			m_contryOfPub = trim(m_contryOfPub, " ");
		}

		foundPrice = strBook.find(needFind, foundCon + 1);
		if (foundPrice != string::npos)
		{
			tmpPrice = strBook.substr(foundCon + 1, foundPrice - foundCon - 1);
			m_price = stod(tmpPrice);
		}

		foundYear = strBook.find(needFind, foundPrice + 1);
		if (foundPrice != string::npos)
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
		ostr << ostr.fill(' '); ostr.width(20);
		ostr << src.m_author;
		ostr << " | ";

		ostr.setf(ios::right); ostr.fill(' '); ostr.width(22);
		ostr << src.m_title; ostr.unsetf(ios::right);
		ostr << " |";

		ostr << ostr.fill(' '); ostr.width(5);
		ostr << src.m_contryOfPub;
		ostr << " |";

		ostr << ostr.fill(' '); ostr.width(4);
		ostr << src.m_year;
		ostr << " |";

		ostr << ostr.fill(' '); ostr.width(6);
		ostr << fixed << setprecision(2) << src.m_price;
		ostr << " | ";

		ostr << src.m_description << endl;
		return ostr;
	}
}