//Life AI class source

//Include headers
#include "lifeai.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <algorithm>



//Implementation


//Constructor
LifeAI::LifeAI(std::string userName) : user(userName) {


	//Constructor implementation
}



void LifeAI::recommendActivities() {
	std::map <std::string, double> activityScores;


	for (const auto& activity : activities) {
		double happinessScore = activity.emotionLevels[HAPPINESS] / (double)user.activityLog[activity.name];
		double harmScore = activity.harmLevel / (double)user.activityLog[activity.name];


		//score can be adjusted
		double score = happinessScore - 0.5 * harmScore;

		activityScores[activity.name] = score;

	}

	// Sort activities by scores

	std::vector<std::pair<std::string, double>> sortedActivities(activityScores.begin(), activityScores.end());
	std::sort(sortedActivities.begin(), sortedActivities.end(),
		[](const auto& a, const auto& b) {return a.second > b.second; });


	//Print the top recommended activities
	std::cout << "Top recommended activities:" << std::endl;
	for (const auto& activityScore : sortedActivities) {
		std::cout << "Activity: " << activityScore.first << ", Score: " << activityScore.second << std::endl;
	}

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
