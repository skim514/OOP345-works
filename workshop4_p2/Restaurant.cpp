/***********************************************************************
// OOP345 Workshop #4
//
// File    Restaurant.cpp
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
#include "Restaurant.h"

using namespace std;

namespace sdds {
    Restaurant::Restaurant() { }
    Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
    {
        m_numOfRes = cnt;
        m_res = new Reservation*[cnt];
        for (size_t i = 0; i < cnt; i++)
        {
            m_res[i] = new Reservation(*reservations[i]);
        }
    }
    Restaurant::Restaurant(const Restaurant& src)
    {
        *this = src;
    }
    Restaurant& Restaurant::operator=(const Restaurant& src) //Composition
    {
        if (this != &src) {
            for (size_t i = 0; i < m_numOfRes; i++)
                delete m_res[i];

            delete[] m_res;
            m_res = nullptr;
            m_numOfRes = 0;

            if (src.m_res != nullptr)
            {
                m_res = new Reservation*[src.m_numOfRes];

                for (size_t i = 0; i < src.m_numOfRes; i++)
                    m_res[i] = new Reservation(*src.m_res[i]);
            }
            m_numOfRes = src.m_numOfRes;
        }
        return *this;
    }
    Restaurant::Restaurant(Restaurant&& src) noexcept
    {
        *this = std::move(src);
    }
    Restaurant& Restaurant::operator=(Restaurant&& src) noexcept //Composition
    {
        if (this != &src)
        {
            for (size_t i = 0; i < m_numOfRes; i++)
            {
                delete m_res[i];
            }
            delete[] m_res;
            m_res = src.m_res;
            src.m_res = nullptr;
            m_numOfRes = src.m_numOfRes;
            src.m_numOfRes = 0;
        }
        return *this;
    }
    Restaurant::~Restaurant() //Composition
    {
        for (size_t i = 0; i < m_numOfRes; i++)
        {
            delete m_res[i];
        }
        delete[] m_res;
    }
    size_t Restaurant::size() const
    {
        return m_numOfRes;
    }
    std::ostream& operator<<(std::ostream& ostr, const Restaurant& res)
    {
        static int countCalled = 1;

        ostr << "--------------------------" << endl << "Fancy Restaurant (" << countCalled << ")" << endl;
        ostr << "--------------------------" << endl;
        if (res.m_numOfRes == 0)
        {
            ostr << "This restaurant is empty!" << endl;
        }
        else
        {
            for (size_t i = 0; i < res.m_numOfRes; i++)
            {
                ostr << *res.m_res[i];
            }
        }
        ostr << "--------------------------" << endl;
        countCalled++;
        
        return ostr;
    }
}