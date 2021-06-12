#ifndef __OPTION_HPP__
#define __OPTION_HPP__

#include "GameQuestion.hpp"

#include <string>
#include <iostream>

using namespace std;

class Option : public GameQuestion {
	private:
		string option;
		bool isCorrect; 

  	public:
		Option(string o, bool c) : GameQuestion(), option(o), isCorrect(c) { }
		~Option() { }
	
		virtual string GetAnswer() const {
			if (this->isCorrect) {
				return this->option;
			}
			return "";
		}
		virtual bool CorrectAnswer() { return this->isCorrect; }

		virtual string GetQuestion() const { return "not needed in this class"; }
		
		virtual int HowManyOptions() const { return -69; }

		virtual void AddOption(GameQuestion* gq) { }
		//virtual vector<GameQuestion*> GetOptions() { }
		virtual vector<GameQuestion*> AllOptions() { }
		virtual string GetSingleOption() { return option; }
		virtual int GetScore() const { return 1000; }
		virtual int GetTotalPoints() const { return 10000; }
		virtual void UpdateUserScore(int) { }
		virtual int QPoints() { return 10000; }		

};

#endif
