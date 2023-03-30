//Life AI class source

//Include headers
#include "lifeai.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>



//Implementation


//Constructor
LifeAI::LifeAI(std::string userName) : user(userName) {


	//Constructor implementation
}



void LifeAI::recommendActivities() {

}





void LifeAI::trackEmotions() {

}







void LifeAI::trackHarm() {

}





void LifeAI::provideFeedback() {

}






void LifeAI::customizeApproach() {

}






//Save user data
void LifeAI::saveUserData(const std::string &filename) {

	std::ofstream file(filename);

	if (file.is_open()) {
		file << user.name << '\n';
		file << user.dopamineLevel << '\n';
		file << user.happinessLevel << '\n';
		file << user.harmLevel << '\n';

		for (const auto& entry : user.activityLog) {
			file << entry.first << "," << entry.second << '\n';
		}
	}


	file.close();
}





//Load user data
void LifeAI::loadUserData(const std::string &filename) {

	std::ifstream file(filename);
	std::string line;

	if (file.is_open()) {
		std::getline(file, user.name);
		std::getline(file, line);
		user.dopamineLevel = std::stoi(line);
		std::getline(file, line);
		user.happinessLevel = std::stoi(line);
		std::getline(file, line);
		user.harmLevel = std::stoi(line);


		while (std::getline(file, line)) {
			std::istringstream ss(line);
			std::string activityName;
			std::string durationStr;
			std::getline(ss, activityName, ',');
			std::getline(ss, durationStr, ',');
			user.activityLog[activityName] = std::stoi(durationStr);

		}

	}


	file.close();
}
