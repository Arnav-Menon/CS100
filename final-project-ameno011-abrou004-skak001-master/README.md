 # Trivia Quiz Maker

 > Authors: [Arnav Menon](https://github.com/Arnav-Menon) [Alexus Broussard](https://github.com/alexthelionnnn) [Shwena Kak](https://github.com/shwenakak)
 
 ## Expectations
 > * Incorporate **at least two** distinct design patterns. You need to include at least *one* design pattern that we will teach this session:
 >   * Composite, Strategy, Abstract Factory, Visitor, or Decorator
 > * All design patterns need to be linked together (it can't be two distinct projects)
 > * Your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group.

## Project Description
 > The trivia quiz will allow the user to play a trivia game. The user will be able to choose between a genre-specific quiz. Based on their selection the quiz will contain multiple-choice, true/false, and fill-in-the-blank questions.
 > * Games are a fun way to destress and relax, especially in these current times, learning how to relax and take care of yourself is equally as important as staying on top of your stuff.
 > * We will be using C++, Valgrind, and CMake.
 > * C++: an object-oriented programming language 
 > * Valgrind: an instrumentation framework for building dynamic analysis tools
 > * CMake: a software for build automation, testing, packaging, and installation
 > * Input: What topic questions user wants: Sports, Science, or Music
 > * Output: Quiz Questions and Total Score at the End
 
> ### Composite: 
> We picked this pattern because we felt that a quiz allows us to nicely and cleanly divide the project into separate components. Our composite design is getting the answer choices for each question. We have Question objects with each object holding a vector of Option objects. We use this when we are comparing user input to see if they answered the question correctly. One problem this pattern will help us solve is getting the correct answers. Without this structure, we would probably create the Questions and Option objects as usual, but we ould have no way of associating the proper Option objects to the correct Question object. With the composite pattern, we will have a vector of Option object pointers which will allow us to keep track of the corrcet options for each question. With all our quiz components, Composite Design Pattern will give us flexibility in our class structure.

> ### Strategy: 
> We picked this pattern because we want to be able to display the different types of questions, T/F, MC, Fill-in-the-Blank, differently. We will have a SetStrategy() function which will have our pointer point to the right class so we can call the appropriate display function. If we weren't using the Strategy pattern, we would still need to implement the Display() functions independently, but then calling the correct function would become really challenging. With the strategy pattern, we can easily call the correct functions with one single pointer, having it point to the correct class whenever we need. Using a pointer can help lower the runtime and also memory allocation as we constantly delete the pointer before pointing it to a new object. All these factors ensure the user can take the quiz as soon as possible.

 > ## Phase II
## Class Diagram
 > ![newQuizOMTdiagram (2)](https://user-images.githubusercontent.com/70414572/120258696-618c8e00-c247-11eb-93ac-1db37513125b.png)
 
 > We have a Game class which holds a reference to the GameQuestion class in the form of a vector of pointers as well as a Type* pointer, which is part of our strategy pattern. For our Composite pattern we have the GameQuestion, Question, and Option classes. GameQuestion is the abstract class, and Question and Option are the derived classes. A Question object holds a vector of pointers to Option objects, where each possible answer choice is an Option object. We call the GetAnswer() function on a Question object, and it calls the GetAnswer() function of each Option object in the vector and return the correct answer choice, determined by the "isCorrect" bool flag passed in to each Option constructor. We call the GetAnswer() function when we are checking user input and seeing if they answered the question correct. But before we can check if the user's input is correct, we must first display the question, which brings us to the Strategy pattern. Our base abstract class is Type, and classes TF, MC, and Fill are the derived classes. These classes are only responsible for one function, Display(GameQuestion*). We have a Type* type pointer in the Game class, and the function SetStrategy(Type*) takes the Type* pointer and points it to instances of the correct class. For example, if we want to display a Fill-in-the-Blank question, we call the SetStrategy function, and pass in "new Fill()" as the parameter. Then we call the print() function in the Game class, which internally calls "type->Display(GameQuestion*, ostream&) function for the appropraite derived class of Type. We also have other helper functions within the Question class which help with all the other functions of the class. 

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ![image](https://user-images.githubusercontent.com/81598652/120259586-183d3e00-c249-11eb-9b4c-d4a2d9b0fe40.png)
 ![image](https://user-images.githubusercontent.com/81598652/120259720-4c186380-c249-11eb-9c57-37c4935af7dd.png)
 ![image](https://user-images.githubusercontent.com/81598652/120259820-7c600200-c249-11eb-858e-ff5b245943ef.png)
 ![image](https://user-images.githubusercontent.com/81598652/120260854-8be04a80-c24b-11eb-835b-c98ac009844e.png)

 
 ## Installation/Usage
 > No additional installation is required to operate or play the game. 
 > 
 > To initialize the game run cmake3 . then make the file. Once the file is made it will generate a game executable. Run the game executable using ./game. Then enjoy!

## Testing
 > Each individual subject (Science, Sports, Music) was tested with googletest, developer unit tests, and valgrind. 
 > 
 > Each test was completed and passed with no memory leaks or errors.
 
