/***********************************************************************
// OOP345 Workshop #1
//
// File    carads.h
// Version    1.0
// Date     May 16, 2023
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

#ifndef CARADS_H
#define CARADS_H
#include <iostream>

extern double g_taxrate;
extern double g_discount;

namespace sdds {

    class Cars {
        char* m_brand {};
        char m_model[16] {};
        int m_year {};
        double m_price {};
        char m_status {};
        bool m_discount {};
        
    public:
        Cars();
        std::istream& read(std::istream& istr);
        void display(bool reset) const;
        char getStatus();
        Cars(const Cars& another);
        Cars& operator=(const Cars& another);
        ~Cars();
        operator bool() const;
    };

    void listArgs(int argc, char** argv);
    std::istream& operator>>(std::istream& istr, Cars& car);
    void operator>>(const Cars& car1, Cars& car2);
}

#endif /* carads_h */
