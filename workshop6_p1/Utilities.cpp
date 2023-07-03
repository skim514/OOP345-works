/***********************************************************************
// OOP345 Workshop #6
//
// File    Utilities.cpp
// Version    1.0
// Date     June 26, 2023
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
#include <fstream>
#include "Utilities.h"
#include "Car.h"

namespace sdds {
    Vehicle* createInstance(std::istream& in)
    {
        char tmpTag = '\0';
        Vehicle* result = nullptr;

        in.get(tmpTag);

        if (tmpTag == 'c' || tmpTag == 'C')
        {
            Car* car = new Car(in);
            result = car;
        }
        return result;
    }
}