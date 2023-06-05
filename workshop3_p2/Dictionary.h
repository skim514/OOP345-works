/***********************************************************************
// OOP345 Workshop #3
//
// File    Dictionary.h
// Version    1.0
// Date     June 1, 2023
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
//I have done all the coding by myself and 
//only copied the code that my professor provided to complete my workshops and assignments.

#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <string>

namespace sdds {
	class Dictionary
	{
		std::string m_term{};
		std::string m_definition{};

	public:
		const std::string& getTerm() const { return m_term; }
		const std::string& getDefinition() const { return m_definition; }
		Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition } {}

		// TODO: Code the missing prototype functions and operators
		//       that the class needs in order to work with the Queue class.
		//       Implement them in the Dictionary.cpp file.

		Dictionary() : m_term{ }, m_definition{ } { }

		// Comparison operator
		bool operator==(const Dictionary& dic) const;

	};
	std::ostream& operator<<(std::ostream& ostr, const Dictionary& dic);
}

#endif
