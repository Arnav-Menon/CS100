#include "../header/game.hpp"
#include "../header/fill.hpp"
#include "../header/TF.hpp"
#include "../header/mc.hpp"
#include "../header/GameQuestion.hpp"

#include <iostream>
#include <string>

using namespace std;

int main() {
	
	Game g;

	string topic = g.PickTopic(); // user will pick either Sports, Science, or Music as a topic

//	g.SetStrategy(new Fill());	
	g.LoadQuestions(topic, "fill"); // load 2 fill-in-blank questions
	g.LoadQuestions(topic, "tf"); // load 2 tf questions
	g.LoadQuestions(topic, "mc"); // load 2 mc questions

	int size = g.HowManyQuestions();	

	string userInput;
	int userScore = 0;
	int totalPoints = 0;

	for (int i = 0; i < size; i++) {
		GameQuestion* q = g.GetQuestion(i);
		if (q->HowManyOptions() == 4)
			g.SetStrategy(new MC());
		else if (q->HowManyOptions() == 2)
			g.SetStrategy(new TF());
		else
			g.SetStrategy(new Fill());

		g.print(q, std::cout);
		std::cout;
		getline(cin, userInput);
		// make sure user input is not empty	
		while (userInput.empty())
			getline(cin, userInput);
//		cout << "USER INPUT: " << userInput << endl;
		// void function but it will appropriately update user score within
		g.CheckUserAnswer(userInput, q);
		// update userScore and totalPoints available so far
		userScore += q->GetScore();
		totalPoints += q->GetTotalPoints();
	}	
	
	cout << "YOUR SCORE: " << userScore << endl;
	cout << "TOTAL POSSIBLE SCORE: " << totalPoints << endl;

	//if (q.RunGame())
	//	cout << "CONGRATS! YOU WON!" << endl;
	//else
	//	cout << "Ouch, better luck next time loser" << endl;	

	return 0;
}
