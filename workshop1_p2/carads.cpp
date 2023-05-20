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
#include <string>
#include <cstring>
#include "carads.h"

using namespace std;

double g_taxrate;
double g_discount;

namespace sdds {
    void listArgs(int argc, char** argv){
        cout << "Command Line:" << endl;
        cout << "--------------------------" << endl;
        
        for (int i = 0; i < argc; ++i)
            cout << "  " << i + 1 << ": " << argv[i] << "\n";
        cout << "--------------------------" << endl << endl;
    }
    std::istream& operator>>(std::istream& istr, Cars& car)
    {
        return car.read(istr);
    }
    void operator>>(const Cars& car1, Cars& car2)
    {
        car2 = car1;
    }
    Cars::Cars(){ }
    std::istream& Cars::read(std::istream& istr){
        if(istr.good())
        {
            std::string tmpBrand;

            char tmpSta;
            char tmpModel[16];
            int year;
            double price;
            char discount;
            
            istr.get(tmpSta);
            istr.ignore();
            getline(istr, tmpBrand, ',');
            if (m_brand)
            {
                delete[] m_brand;
            }
            m_brand = new char[tmpBrand.length() + 1];
            strcpy(m_brand, tmpBrand.c_str());
            istr.getline(tmpModel, 15, ',');
            istr >> year;
            istr.ignore();
            istr >> price;
            istr.ignore();
            istr.get(discount);
            istr.ignore(10000, '\n');
            
            m_status = tmpSta;
            strcpy(m_model, tmpModel);
            m_year = year;
            m_price = price;
            if (discount == 'Y')
            {
                m_discount = true;
            }
            else if (discount == 'N')
            {
                m_discount = false;
            }
        }
        return istr;
    }
    void Cars::display(bool reset) const{
        static int counter = 1;
        if (reset)
        {
            counter = 1;
        }
        cout.width(2); cout << left << counter; cout << ". ";
        cout.width(10); cout << left << m_brand; cout << "| ";
        cout.width(15); cout << left << m_model; cout << "| ";
        cout << m_year; cout << " |";
        if (m_discount)
        {
            cout.width(12); cout.setf(ios::fixed); cout.precision(2); cout << right << m_price * (1 + g_taxrate) << "| ";
            cout.width(11); cout.setf(ios::fixed); cout.precision(2); cout << right << m_price * (1 + g_taxrate) * (1 - g_discount) << endl;
        }
        else
        {
            cout.width(12); cout.setf(ios::fixed); cout.precision(2); cout << right << m_price * (1 + g_taxrate) << "|"; cout << right << endl;
        }
        if (m_brand[0] == '\0')
        {
            cout.width(2); cout << left << counter + 1 << ". No Car" << endl;
        }
        counter++;
    }
    char Cars::getStatus(){
        return m_status;
    }
    Cars::Cars(const Cars& another)
    {
        operator=(another);
    }
    Cars& Cars::operator=(const Cars& another)
    {
        if (this != &another)
        {
            m_model[0] = 0;
            if (m_brand)
            {
                delete [] m_brand;
            }
            m_brand = nullptr;
            m_year = 0;
            m_price = 0;
            m_status = 0;
            m_discount = false;
            if (another)
            {
                m_brand = new char[strlen(another.m_brand) + 1];
                strcpy(m_brand, another.m_brand);
                strcpy(m_model, another.m_model);
                m_year = another.m_year;
                m_price = another.m_price;
                m_status = another.m_status;
                m_discount = another.m_discount;
            }
        }
        return *this;
    }
    Cars::~Cars()
    {
        delete[] m_brand;
    }
    Cars::operator bool() const
    {
        return m_status == 'N';
    }
}