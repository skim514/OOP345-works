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

#ifndef carads_h
#define carads_h
#include <iostream>

extern double g_taxrate;//뼈대
extern double g_discount;

namespace sdds {
    void listArgs(int argc, char** argv);
    
    class Cars{
        char m_brand[11] {};
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
    };
}

#endif /* carads_h */
