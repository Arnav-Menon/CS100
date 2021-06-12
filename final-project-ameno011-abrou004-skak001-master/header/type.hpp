#ifndef __QUESTIONS_HPP__
#define __QUESTIONS_HPP__

#include "GameQuestion.hpp"

#include <string>

using namespace std;

class GameQuestion;

class Type {
	public:
		// the param will be the current question object to display
		virtual void Display(GameQuestion*, std::ostream&) const = 0;
};

#endif // __QUESTIONS_HPP__
