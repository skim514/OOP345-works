/***********************************************************************
// OOP345 Workshop #6
//
// File    Autoshop.h
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
#ifndef AUTOSHOP_H
#define AUTOSHOP_H
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicle;
	
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();
		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) //T test는 펑션이 들어오는 자리
		{
			//auto i = Vehicle* 타입이고, m_vehicle 시작인덱스가 i의 값.
			//m_vehicle의 마지막 인덱스까지 for문 돌아라.
			for (auto i = m_vehicle.begin(); i != m_vehicle.end(); i++) //설명 필요
			{
				//test(메인에서는 람다 fastVehicles, brokenVehicles)의 *i가 가리키는 곳에 받아온 vehicles을 한개씩 넣어라
				if (test(*i))
					vehicles.push_back(*i);
			}
		}
	};
}

#endif