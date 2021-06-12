#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "type.hpp"
//#include "GameQuestion.hpp"
#include "question.hpp"
#include "option.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <stdlib.h>

class Type; // forward declaration of Type class

using namespace std;

class Game {
	private:
		// holds all the objects of questions for the current game
		vector<GameQuestion*> questions;
		// holds the correct answers for each question in above vector
		vector<string> answers;
		// holds bool values of if the question hasbeen printed or not
		//vector<bool> printed;
		Type* type = nullptr;

		void LoadFillQuestions(string topic) {
			ifstream qFile; // use this to go thorugh questions file
			fstream aFile; // use this to go thorugh questions file
			string question;
			string answer;

			vector<int> nums; // nums of which questions are already in the questions vector

			vector<string> all_q;
			vector<string> all_a;

			// specify path to file from directory where executable is called
			qFile.open("notes/" + topic + "_fill.txt");
			aFile.open("notes/" + topic + "_answers_fill.txt");

			if (!qFile.is_open()) {
				cout << topic << " FILL QUESTIONS FILE NOT OPEN" << endl;
				exit(1);
			}
			if (!aFile.is_open()) {
				cout << topic << " FILL ANSWERS FILE NOT OPEN" << endl;
				exit(1);
			}

			// count total lines and ppulate vectors with all questions and answers
			int totalLines = 0;
			while (getline(qFile, question) && getline(aFile,answer)) {
				totalLines++;
				all_q.push_back(question);
				all_a.push_back(answer);
			}
			
			srand(time(0));
			int randNum = 0;
			while (nums.size() != 2) {
				randNum = rand() % totalLines;
				// add it to vector only if not found
				if (find(nums.begin(), nums.end(), randNum) == nums.end())
					nums.push_back(randNum);
			}

			srand(time(0));
			for (int i = 0; i < nums.size(); i++) {
				GameQuestion* new_q = new Question(all_q.at(nums.at(i)), 5);
				new_q->AddOption(new Option(all_a.at(nums.at(i)), true));
				questions.push_back(new_q);
			}
			
			qFile.close();
			aFile.close();
			nums.clear(); 
		}
		
		void LoadTFQuestions(string topic) {
			ifstream qFile; // use this to go thorugh questions file
			ifstream aFile; // use this to go thorugh questions file
			string question;
			string answer;

			vector<int> nums; // nums of which questions are already in the questions vector

			vector<string> all_q;
			vector<string> all_a;

			// specify path to file from directory where executable is called
			qFile.open("notes/" + topic + "_tf.txt");
			aFile.open("notes/" + topic + "_answers_tf.txt");
			
			if (!qFile.is_open()) {
				cout << topic << " TF QUESTIONS FILE NOT OPEN" << endl;
				exit(1);
			}
			if (!aFile.is_open()) {
				cout << topic << " TF ANSWERS FILE NOT OPEN" << endl;
				exit(1);
			}
			
			// count total lines and ppulate vectors with all questions and answers
			int totalLines = 0;
			while (getline(qFile, question) && getline(aFile,answer)) {
				totalLines++;
				all_q.push_back(question);
				all_a.push_back(answer);
			}
			
			srand(time(0));
			int randNum = 0;
			while (nums.size() != 2) {
				randNum = rand() % totalLines;
				// add it to vector only if not found
				if (find(nums.begin(), nums.end(), randNum) == nums.end())
					nums.push_back(randNum);
			}
			
			srand(time(0));
			for (int i = 0; i < nums.size(); i++) {
				GameQuestion* new_q = new Question(all_q.at(nums.at(i)), 3);
				if (all_a.at(nums.at(i)) == "true" || all_a.at(nums.at(i)) == "True") {
					new_q->AddOption(new Option("true", true));
					new_q->AddOption(new Option("false", false));
				}
				else {
					new_q->AddOption(new Option("true", false));
					new_q->AddOption(new Option("false", true));
				}
				questions.push_back(new_q);
			}
			
			qFile.close();
			aFile.close();
			nums.clear();
		}
		
		void LoadMCQuestions(string topic) {
			ifstream qFile; // use this to go thorugh questions file
			ifstream aFile; // use this to go thorugh questions file
			string question;
			string answer;
			string choice;

			vector<int> nums; // nums of which questions are already in the questions vector

			vector<string> all_q;
			vector<string> all_a;
			vector<vector<string> > optionChoices; // list of option choices for each question

			// specify path to file from directory where executable is called
			qFile.open("notes/" + topic + "_mc.txt");
			aFile.open("notes/" + topic + "_answers_mc.txt");
			
			if (!qFile.is_open()) {
				cout << topic << " MC QUESTIONS FILE NOT OPEN" << endl;
				exit(1);
			}
			if (!aFile.is_open()) {
				cout << topic << " MC ANSWERS FILE NOT OPEN" << endl;
				exit(1);
			}
			
			// count total lines and ppulate vectors with all questions and answers
			int totalLines = 0;
			while (getline(qFile, question) && getline(aFile,answer)) {
				totalLines++;
				int endQuestion = question.find("?"); // get the stuff before the question mark, that is the question
				string allChoices = question.substr(endQuestion + 2, question.size());
				all_q.push_back(question.substr(0, endQuestion + 1));
				all_a.push_back(answer);
				vector<string> choices;
				while (choices.size() != 4) {
					int optionIndex = allChoices.find(",");
					choices.push_back(allChoices.substr(0, optionIndex));
					// once that option is loaded into vector, chop it off the string and repeat
					allChoices = allChoices.substr(optionIndex + 2, allChoices.size());	
				}
				optionChoices.push_back(choices); // append vector of option choices for each questoin
				choices.clear(); // empty vector so future values aren't added on top of existing vals
			}
			
			srand(time(0));
			int randNum = 0;
			while (nums.size() != 2) {
				randNum = rand() % totalLines;
				// add it to vector only if not found
				if (find(nums.begin(), nums.end(), randNum) == nums.end())
					nums.push_back(randNum);
			}
			
			srand(time(0));
			for (int i = 0; i < nums.size(); i++) {
				GameQuestion* new_q = new Question(all_q.at(nums.at(i)), 4);
				// add options for each question
				for (int j = 0; j < optionChoices.at(nums.at(i)).size(); j++) {
					// correct answer, mark true
					if (optionChoices.at(nums.at(i)).at(j) == all_a.at(nums.at(i)))
						new_q->AddOption(new Option(optionChoices.at(nums.at(i)).at(j), true));
					// incorrect answer, mark false
					else
						new_q->AddOption(new Option(optionChoices.at(nums.at(i)).at(j), false));
				}
				questions.push_back(new_q);
			}
			
			qFile.close();
			aFile.close();
			nums.clear();
		}
	
	public:
		Game() {}
		~Game() {
			if (type != nullptr)
				delete type;
			for (int i = 0; i < questions.size(); i++)
				delete questions.at(i);
			questions.clear();
		}
		void SetStrategy(Type* new_strategy) {
			delete type;
			type = new_strategy;
		}
		void print(GameQuestion* gq, std::ostream& out) {
			type->Display(gq, out); 
		}
		// which topic will user choose: Music, Sports, or Scinec
		string PickTopic() {
			string topic;
			while (topic != "music" || topic != "sports" || topic != "science") {
				// doesnt work without it
				if (topic == "music" || topic == "sports" || topic == "science") {
					return topic;
				}
				//cout << "TOPIC: " << topic << endl;
				cout << "What topic would you like to test your knowledge in?" << endl;
				cout << "Music, Sports, or Science" << endl;
				cin >> topic;
				//topic = "SpoRTs";
				transform(topic.begin(), topic.end(), topic.begin(), ::tolower);
			}
		}
		// fill vectors with questions according to user topic
		void LoadQuestions(string t, string y) {
			if (y == "fill")
				LoadFillQuestions(t);
			else if (y == "tf")
				LoadTFQuestions(t);
			else if (y == "mc")
				LoadMCQuestions(t); 
		}
	
		GameQuestion* GetQuestion(int index) { return questions.at(index); }

		int HowManyQuestions() { return questions.size(); }	

		void CheckUserAnswer(string input, GameQuestion* q) {
			string correct_answer = q->GetAnswer();
			// convert user input to all lower case in case they decided to be smart and type with weird casing
			transform(input.begin(), input.end(), input.begin(), ::tolower);
			transform(correct_answer.begin(), correct_answer.end(), correct_answer.begin(), ::tolower);
			
			if (input == correct_answer) {
				// update user score with how much that uestion is qortk
				//cout << "CORRECT ANSWER" << endl;
				q->UpdateUserScore(q->QPoints());
			}
			else {
				// give them a hint
				cout << "Wrong! THe correct answer is: " << correct_answer << endl;
				cout << "";
			}
		}
};

#endif // __GAME_HPP__
