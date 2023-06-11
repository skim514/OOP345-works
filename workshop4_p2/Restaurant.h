/***********************************************************************
// OOP345 Workshop #4
//
// File    Restaurant.h
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


#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <iostream>
#include <string>
#include "Reservation.h"

namespace sdds {
	class Restaurant { //Composition
		Reservation** m_res = nullptr;
		size_t m_numOfRes = 0;

	public:
		Restaurant();
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& src);//copy constructor
		Restaurant& operator=(const Restaurant& src);//copy assign (Composition)

		Restaurant(Restaurant&& src) noexcept;//move constructor
		Restaurant& operator=(Restaurant&& src) noexcept;//move assign (Composition)
		~Restaurant(); //Composition

		size_t size() const;
		friend std::ostream& operator<<(std::ostream& ostr, const Restaurant& res);
	};
}

#endif
