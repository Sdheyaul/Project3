
#include <iostream>
#include <stdio.h>
#include<string>

#include "tinyxml.h"

int score = 0;

using namespace std;

int main() {

	TiXmlDocument doc("game.xml");//parsing the xml file game.xml
	doc.LoadFile();

	TiXmlElement* l_pRootElement = doc.RootElement();
	//geting the root element 
	if (NULL != l_pRootElement)
	{
		//parent element
		TiXmlElement* l_qQuestions = l_pRootElement->FirstChildElement("questions");

		if (NULL != l_qQuestions)
		{
			// First child
			TiXmlElement* l_qQuestion = l_qQuestions->FirstChildElement("question");

			while (l_qQuestion)
			{
				TiXmlElement* l_qQuestion1 = l_qQuestion->FirstChildElement("q_text");//geting the (first chhild)question text

				if (NULL != l_qQuestion1)
				{
					cout << l_qQuestion1->GetText();//print it
				}

				cout << endl;
				// All the answers must be Cap case . Otherwise else if (input == "A" || input == "a") or Switch statement
				TiXmlElement* optionA = l_qQuestion->FirstChildElement("A");//1st subchild

				if (NULL != optionA)
				{
					cout << " A) " << optionA->GetText();
				}

				cout << "\t";

				TiXmlElement* optionB = l_qQuestion->FirstChildElement("B");//2nd subchild

				if (NULL != optionB)
				{
					std::cout << "B) " << optionB->GetText();
				}

				cout << "\t";

				TiXmlElement* optionC = l_qQuestion->FirstChildElement("C");//3rd subchild

				if (NULL != optionC)
				{
					cout << "C) " << optionC->GetText();
				}



				cout << endl;

				string input;  //creating a variable that save input answer from user
				cout << "Please enter your answer -> ";

				cin >> input;//should be Capital Letter

				string correctAnswer;// cast the value of xml elemnt to a varible to help compare the user input to the correct answer(saved in xml elemnt)


				cout << endl;



				TiXmlElement* correctAns = l_qQuestion->FirstChildElement("correct"); 
			 string: correctAns;

				if (NULL != correctAns)
				{

					correctAnswer = correctAns->GetText();

				}
				// comparing string to string to check if user answer's is correct or incorrect


				if (correctAnswer.compare(input) == 0) {  

					// giving score of 10 to each question
					score = score + 10;
					l_qQuestion = l_qQuestion->NextSiblingElement("question");

				}

				else {

					cout << "Your answer is incorrect";
					cout << std::endl;
					cout << "Your score is :";
					cout << score;

					return 0;
				}
			}

			cout << "Final score is: ";
			cout << score;
		}
	}
}




