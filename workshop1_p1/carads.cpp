/***********************************************************************
// OOP345 Workshop #1
//
// File    carads.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "carads.h"

using namespace std;

double g_taxrate;//공간을 여기에 만듬
double g_discount;

namespace sdds {
    void listArgs(int argc, char** argv){
        cout << "Command Line:" << endl;
        cout << "--------------------------" << endl;
        /*cout << "1: " << *argv << endl;
        cout << "2: " << *argv << endl;
        cout << "3: " << *argv << endl;
        cout << "4: " << *argv << endl;
        cout << "5: " << *argv << endl;*/
        
        for (int i = 0; i < argc; ++i)
            cout << i+1 << ": " << argv[i] << "\n";
    }
    Cars::Cars(){
        m_brand[0] = '\0';
        m_model[0] = '\0';
        m_year = 0;
        m_price = 0.0;
        m_status = '\0';
        m_discount = false;
    }
    std::istream& Cars::read(std::istream& istr){
        if(istr.good())
        {
            char tmpSta[11];
            char tmpBrd[11];
            char tmpModel[16];
            int year;
            double price;
            char discount[11];
            char grabage;
            
            istr.getline(tmpSta, 10, ',');
            
            istr.getline(tmpBrd, 10, ',');
            istr.getline(tmpModel, 15, ',');
            istr >> year;
            istr >> grabage;
            istr >> price;
            istr >> grabage;
            istr.getline(discount, 10, '\n');
            
            m_status = tmpSta[0];
            strcpy(m_brand, tmpBrd);
            strcpy(m_model, tmpModel);
            m_year = year;
            m_price =  price;
            if (discount[0] == 'Y') {
                m_discount = true;
            }
            else if (discount[0] == 'N'){
                m_discount = false;
            }
//            cout << "print result: " << tmpSta << endl;
//            cout << "print result: " << tmpBrd << endl;
//            cout << "print result: " << tmpModel << endl;
//            cout << "print result: " << year << endl;
//            cout << "print result: " << price << endl;
//            cout << "print result: " << discount << endl << endl;
        }
        return istr;
    }
    void Cars::display(bool reset) const{
        static int counter = 0;
        if (reset)
        {
            counter = 0;
        }
        cout << counter + 1 << " . " << m_brand << " | " << m_model << " | " << m_year << " | ";
        if (m_discount)
        {
            cout << m_price << " | " << m_price - (m_price * g_discount) << endl;
        }
        else
        {
            cout << m_price * (g_taxrate + 1) << " | " << m_price - (m_price * g_discount) << endl;
        }
        if (m_brand[0] == '\0')
        {
            cout << counter << ". No Car" << endl;
            //counter++;
        }
        counter++;
    }
    char Cars::getStatus(){
        return m_status;
    }
}
