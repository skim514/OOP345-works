/***********************************************************************
// OOP345 Workshop #2
//
// File    TennisLog.cpp
// Version    1.0
// Date     May 26, 2023
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
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "TennisLog.h"

using namespace std;

namespace sdds {
	TennisLog::TennisLog() {}
	TennisLog::TennisLog(const char* fileName)
	{
		ifstream file(fileName);

		if (file) //count line
		{
			string header;
			string lines;

			getline(file, header, '\n');
			while (!file.eof())
			{
				getline(file, lines, '\n');
				if (lines.length() != 0)
				{
					m_count++;
				}
			}
			file.clear();
			file.seekg(ios::beg); //move to begin of file

			m_tennisMatch = new TennisMatch[m_count];

			getline(file, header, '\n');
			for (unsigned int i = 0; i < m_count; i++) //save data
			{
				getline(file, m_tennisMatch[i].tournamentID, ',');
				getline(file, m_tennisMatch[i].tournamentName, ',');
				file >> m_tennisMatch[i].matchID;
				file.ignore();
				getline(file, m_tennisMatch[i].winner, ',');
				getline(file, m_tennisMatch[i].loser, '\n');
			}
		}
	}
	TennisLog::~TennisLog()
	{
		delete[] m_tennisMatch;
	}
	void TennisLog::addMatch(TennisMatch& match) //resizing
	{
		TennisMatch* newMatch = { 0 };
		
		newMatch = new TennisMatch[m_count + 1];
		for (unsigned int i = 0; i < m_count; ++i)
		{
			newMatch[i] = m_tennisMatch[i];
		}
		newMatch[m_count] = match;
		delete[] m_tennisMatch;
		m_tennisMatch = nullptr;
		m_tennisMatch = newMatch;		
		m_count = m_count + 1;
	}
	TennisLog TennisLog::findMatches(const string name) const
	{
		TennisLog tmp;
		for (unsigned int i = 0; i < m_count; i++)
		{
			if (!m_tennisMatch[i].winner.compare(name) || !m_tennisMatch[i].loser.compare(name))
			{
				tmp.addMatch(m_tennisMatch[i]);
			}
		}
		return tmp;
	}
	TennisMatch TennisLog::operator[](size_t index) const
	{
		TennisMatch tmp;
		if (m_tennisMatch != nullptr)
		{
			tmp = m_tennisMatch[index];
		}
		return tmp;
	}
	TennisLog::operator size_t() //positive int value class
	{
		return m_count;
	}
	ostream& operator<<(ostream& ostr, const TennisMatch& match)
	{
		if (match.matchID < 1)
		{
			ostr << "Empty Match";
		}
		else
		{
			ostr.setf(ios::right); ostr.fill('.'); ostr.width(20);
			ostr << "Tourney ID" << " : ";
			ostr.unsetf(ios::right);
			ostr.setf(ios::left); ostr.fill('.'); ostr.width(30);
			ostr << match.tournamentID;
			ostr.unsetf(ios::left); ostr << endl;

			ostr.setf(ios::right); ostr.fill('.'); ostr.width(20);
			ostr << "Match ID" << " : ";
			ostr.unsetf(ios::right);
			ostr.setf(ios::left); ostr.fill('.'); ostr.width(30);
			ostr << match.matchID;
			ostr.unsetf(ios::left); ostr << endl;

			ostr.setf(ios::right); ostr.fill('.'); ostr.width(20);
			ostr << "Tourney" << " : ";
			ostr.unsetf(ios::right);
			ostr.setf(ios::left); ostr.fill('.'); ostr.width(30);
			ostr << match.tournamentName;
			ostr.unsetf(ios::left); ostr << endl;

			ostr.setf(ios::right); ostr.fill('.'); ostr.width(20);
			ostr << "Winner" << " : ";
			ostr.unsetf(ios::right);
			ostr.setf(ios::left); ostr.fill('.'); ostr.width(30);
			ostr << match.winner;
			ostr.unsetf(ios::left); ostr << endl;

			ostr.setf(ios::right); ostr.fill('.'); ostr.width(20);
			ostr << "Loser" << " : ";
			ostr.unsetf(ios::right);
			ostr.setf(ios::left); ostr.fill('.'); ostr.width(30);
			ostr << match.loser;
			ostr.unsetf(ios::left); ostr << endl;
		}
		return ostr;
	}
}