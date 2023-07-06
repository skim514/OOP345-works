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
// I got help for the function "std::string trim(const std::string& str, const std::string& whitespace);"
//Found from "https://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds {
    Vehicle* createInstance(std::istream& in)
    {
        std::string oneLine{};
        char tmpTag{};
        char delimiter{};
        Vehicle* result = nullptr;
        
        getline(in, oneLine);
        oneLine = trim(oneLine, " ");
        std::stringstream trimedLine(oneLine);
        trimedLine >> tmpTag >> delimiter;

        if (trimedLine)
        {
            if (tmpTag == 'c' || tmpTag == 'C')
            {
                Car* car = new Car(trimedLine);
                result = car;
            }
            else if (tmpTag == 'r' || tmpTag == 'R')
            {
                Racecar* raceCar = new Racecar(trimedLine);
                result = raceCar;
            }
            else
            {
                std::string tagStr{};
                tagStr = tmpTag;
                throw "Unrecognized record type: [" + tagStr + "]";
            }
        }
        return result;
    }

    std::string trim(const std::string& str, const std::string& whitespace) //quoted
    {
        const auto strBegin = str.find_first_not_of(whitespace);
        if (strBegin == std::string::npos)
            return "";

        const auto strEnd = str.find_last_not_of(whitespace);
        const auto strRange = strEnd - strBegin + 1;

        return str.substr(strBegin, strRange);
    }
}