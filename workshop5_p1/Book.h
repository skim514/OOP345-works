/***********************************************************************
// OOP345 Workshop #5
//
// File    Book.h
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

#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>

namespace sdds {
	class Book {
		std::string m_author{};
		std::string m_title{};
		std::string m_contryOfPub{};
		size_t m_year = 0;
		double m_price = 0.0;
		std::string m_description{};

	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		std::string trim(const std::string& str, const std::string& whitespace); //quoted
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& ostr, const Book& src);
	};
}

#endif
