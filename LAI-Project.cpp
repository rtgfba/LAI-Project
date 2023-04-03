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
#include "user.h"
#include "activity.h"











int main()
{
	/*LifeAI.loadUserData("userData.txt");*/

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


	/*LifeAI.saveUserData("userData.txt");*/

	return 0;
}