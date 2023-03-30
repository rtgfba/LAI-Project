//Include headers

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "lifeai.h"







//Activity Class

class Activity {

public:
	//name of the activity
	std::string name;

	//Assign a value to the specific emotion and store it
	std::map<Emotion, int> emotionLevels;

	//Create variable for harm level
	int harmLevel;

	//Create variable for the duration of the activity
	int duration;

	
	//Constructor 
	Activity(std::string name, std::map<Emotion,int> emotionLevels, int harmLevel, int duration)
		:name(name), emotionLevels(emotionLevels), harmLevel(harmLevel), duration(duration){}


};





int main()
{
	LifeAI.loadUserData("userData.txt");

	std::string userName;
	std::cout << "Please enter your name: ";
	std::cin >> userName;

	LifeAI lifeAI(userName);

	//Add activities and ohter setup tasks here

	//Main loop for user interaction


	std::string userInput;
	bool running = true;
	while (running) {
		std::cout << "Enter command (add, recommend, quit): ";
		std::cin >> userInput;

		if (userInput == "add") {
			//get user input to add an activity
		}
		else if (userInput == "recommend") {
			//Call the recommendActivities() function
		}
		else if (userInput == "quit") {
			running = false;
		}
		else {
			std::cout << "Invalid command. Please try again." << std::endl;
		}


	}


	LifeAI.saveUserData("userData.txt");

	return 0;
}