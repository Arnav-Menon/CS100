#ifndef __GAMEQUESTION_HPP__
#define __GAMEQUESTION_HPP__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GameQuestion {
	protected:
		int totalPoints = 0; // how many points all questions are worth together
		int qPoints; // how much each question is worth
		int score = 0; // user score
	public:
		GameQuestion() { }
		virtual ~GameQuestion() = default;
		virtual string GetAnswer() const = 0;
		virtual bool CorrectAnswer() { }

		virtual string GetQuestion() const { return "garbage. need this for Question class"; }
		
		// only need this for Question class but need to define in all subclasses
		virtual int HowManyOptions() const { return 11; }

		virtual void AddOption(GameQuestion* gq) { }
//		virtual vector<GameQuestion*> GetOptions() { }
		virtual vector<GameQuestion*> AllOptions() { }
		virtual string GetSingleOption() { }
		virtual int GetScore() const { }
		virtual int GetTotalPoints() const { }
		virtual void UpdateUserScore(int) { }
		virtual int QPoints() { } // how much is that question worth
};


#endif // __GAMEQUESTION_HPP__
