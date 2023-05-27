/***********************************************************************
// OOP345 Workshop #2
//
// File    TennisLog.h
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

#ifndef TENNISLOG_H
#define TENNISLOG_H
#include <iostream>

namespace sdds {
	struct TennisMatch {
		std::string tournamentID {};
		std::string tournamentName {};
		unsigned int matchID {0};
		std::string winner {};
		std::string loser {};
	};

	class TennisLog {
		TennisMatch* m_tennisMatch {};
		unsigned int m_count {0};

	public:
		TennisLog();
		TennisLog(const char* fileName);
		~TennisLog();
		void addMatch(TennisMatch& match);
		TennisLog findMatches(const std::string name) const;
		TennisMatch operator[] (size_t index) const;
		operator size_t();
	};
	std::ostream& operator<<(std::ostream& ostr, const TennisMatch& match);
}

#endif