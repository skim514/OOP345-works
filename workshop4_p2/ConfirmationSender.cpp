/***********************************************************************
// OOP345 Workshop #4
//
// File    ConfirmationSender.cpp
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

#include <iostream>
#include <string>
#include "ConfirmationSender.h"

using namespace std;

namespace sdds {
	ConfirmationSender::ConfirmationSender() {}
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src)
	{
		*this = src;
	}
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src) //Aggregation
	{
		if (this != &src) {
			delete[] m_reservation;
			m_reservation = nullptr;
			m_numOfConfirmation = 0;

			if (src.m_reservation != nullptr)
			{
				m_reservation = new const sdds::Reservation* [src.m_numOfConfirmation];

				for (size_t i = 0; i < src.m_numOfConfirmation; i++)
					m_reservation[i] = src.m_reservation[i];
			}
			m_numOfConfirmation = src.m_numOfConfirmation;
		}
		return *this;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) noexcept
	{
		*this = std::move(src);
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) noexcept //Aggregation
	{
		if (this != &src)
		{
			delete[] m_reservation;
			m_reservation = src.m_reservation;
			src.m_reservation = nullptr;
			m_numOfConfirmation = src.m_numOfConfirmation;
			src.m_numOfConfirmation = 0;
		}
		return *this;
	}
	ConfirmationSender::~ConfirmationSender() //Aggregation
	{
		delete[] m_reservation;
	}
	
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool found = true;
		for (size_t i = 0; i < m_numOfConfirmation; ++i)
		{
			if (m_reservation[i] == &res)
			{
				found = false;
			}
		}
		if (found) {
			const sdds::Reservation** temp = new const Reservation* [m_numOfConfirmation+1];
			for (size_t i = 0; i < m_numOfConfirmation; i++)
				temp[i] = m_reservation[i];

			temp[m_numOfConfirmation] = &res;
			delete[] m_reservation;
			m_reservation = temp;
			m_numOfConfirmation++;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		bool found = false;
		size_t i = 0;
		for (; i < m_numOfConfirmation && !found; ++i)
		{
			if (m_reservation[i] == &res) {
				found = true;
			}
		}
		if (found)
		{
			for (; i < m_numOfConfirmation; ++i)
			{
				m_reservation[i-1] = m_reservation[i];
			}
			if (m_numOfConfirmation > 0)
			{
				m_reservation[m_numOfConfirmation - 1] = nullptr; // set the last one to nullptr
				m_numOfConfirmation--;
			}
		}
		return *this;
	}
	ostream& operator<<(ostream& ostr, const ConfirmationSender& res)
	{
		ostr << "--------------------------" << endl << "Confirmations to Send" << endl;
		ostr << "--------------------------" << endl;
		if (res.m_numOfConfirmation == 0)
		{
			ostr << "There are no confirmations to send!" << endl;
		}
		else
		{
			for (size_t i = 0; i < res.m_numOfConfirmation; i++)
			{
				ostr << *res.m_reservation[i];
			}
		}
		ostr << "--------------------------" << endl;

		return ostr;
	}
}