#ifndef __QUESTION_HPP__
#define __QUESTION_HPP__

#include "GameQuestion.hpp"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Question : public GameQuestion {
	private:
		string q;
		int p;
		vector<GameQuestion*> options; 

	public:
		Question(string question, int points) : GameQuestion(), q(question), p(points) {
			qPoints = points;
			totalPoints += points;
		}
		~Question() {
			for (int i = 0; i < options.size(); i++)
				delete options.at(i);
			options.clear();
		}

		virtual string GetAnswer() const {
			for (int i = 0; i < options.size(); i++) {
				if (options.at(i)->CorrectAnswer())
					return options.at(i)->GetAnswer();
			}
			return "";
		}
		virtual bool CorrectAnswer() { return true; }

		virtual string GetQuestion() const { return q; }

		virtual int HowManyOptions() const { return options.size(); }

		virtual void AddOption(GameQuestion* gq) { options.push_back(gq); }
//		virtual vector<GameQuestion*> GetOptions() { return options
		virtual vector<GameQuestion*> AllOptions() { return options; }
		virtual string GetSingleOption() { return "not needed in this class"; }
		virtual int GetScore() const { return score; }
		virtual int GetTotalPoints() const { return totalPoints; }
		virtual void UpdateUserScore(int add) { score += add; }
		virtual int QPoints() { return qPoints; }

/*		virtual string GetAnswer() const
		{
			for(int i = 0; i < options.size(); i++)
			{
				if(options.at(i)->CorrectAnswer())
				{
					return options.at(i)->GetAnswer();
				}
				else
				{
					return "";
				}
			}
		}
*/
};

#endif
