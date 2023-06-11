/***********************************************************************
// OOP345 Workshop #4
//
// File    ConfirmationSender.h
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


#ifndef CONFIRMATIONSENDER_H
#define CONFIRMATIONSENDER_H
#include <iostream>
#include <string>
#include "Reservation.h"

namespace sdds {
	class ConfirmationSender { //Aggregation
		const sdds::Reservation** m_reservation = nullptr;
		size_t m_numOfConfirmation = 0;

	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& src);//copy constructor
		ConfirmationSender& operator=(const ConfirmationSender& src);//copy assign (Aggregation)

		ConfirmationSender(ConfirmationSender&& src) noexcept;//move constructor
		ConfirmationSender& operator=(ConfirmationSender&& src) noexcept;//move assign (Aggregation)
		~ConfirmationSender(); //Aggregation

		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream& ostr, const ConfirmationSender& res);
	};
}

#endif
