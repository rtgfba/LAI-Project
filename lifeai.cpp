//Life AI class source

//Include headers
#include "lifeai.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "user.h"
#include "activity.h"



//Implementation


//Constructor
LifeAI::LifeAI(std::string userName) : user(userName) {


	//Constructor implementation
}



void LifeAI::recommendActivities() {
	std::map <std::string, double> activityScores;


	for (const auto& activity : activities) {
		double happinessScore = activity.emotionLevels.at(HAPPINESS) / (double)user.activityLog[activity.name];
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
	std::map<Emotion, int> totalEmotions;

	for (const auto& activityEntry : user.activityLog) {

		const std::string& activityName = activityEntry.first;
		int activityDuration = activityEntry.second;

		for (const auto& activity : activities) {
			if (activity.name == activityName) {
				for (const auto& emotionEntry : activity.emotionLevels) {
					Emotion emotion = emotionEntry.first;
					int emotionValue = emotionEntry.second;



					//Calculate the total emotion value based on the duration
					totalEmotions[emotion] += emotionValue * activityDuration;
				}
			}
		}
	}

	std::cout << "Emotions tracked for user " << user.name << ":" << std::endl;

	for (const auto& emotionEntry : totalEmotions) {
		Emotion emotion = emotionEntry.first;
		int totalEmotionValue = emotionEntry.second;


		std::cout << "Emotion: " << emotion << ", Value: " << totalEmotionValue << std::endl;
	}


}






//Track harm based on the user's activity log
void LifeAI::trackHarm() {

	int totalHarm = 0;

	for (const auto& activityEntry : user.activityLog) {
		const std::string& activityName = activityEntry.first;
		int activityDuration = activityEntry.second;

		for (const auto& activity : activities) {
			if (activity.name == activityName) {
				totalHarm += activity.harmLevel * activityDuration;
			}
		}
	}

	user.harmLevel = totalHarm;
	std::cout << "Total harm for user " << user.name << ": " << totalHarm << std::endl;
}




//Provide feedback based on the user's activity log and current emotion state
void LifeAI::provideFeedback() {

	std::cout << "Feedback for user " << user.name << ":" << std::endl;


	//Compute feedback based on the user's tracked meotions and harm levels
	//ML capabilities

	if (user.harmLevel > 100) {
		std::cout << "Warning: High harm level detected. Consider reducing activities with high harm levels." << std::endl;
	}


	if (user.harmLevel < 50) {
		std::cout << "You seem to be unhappy. Consider increasing activities that make you happy." << std::endl;
	}


	//etc...
}





//Customize the AI's approach based on the user's prefence and data
void LifeAI::customizeApproach() {

	//Can also use ML techniques and other algorithms to make better recommendations
	//

}


bool LifeAI::validateActivity(const Activity& activity) {
	//Validation check for activity name
	if (activity.name.empty()) {
		std::cout << "Activity name cannot be empty." << std::endl;
		return false;
	}

	//Validation check for emotion levels
	for (const auto& emotionLevel : activity.emotionLevels) {
		if (emotionLevel.second < 0) {
			std::cout << "Emotion levels must be  non-negative." << std::endl;
			return false;
		}
	}



}


bool LifeAI::addActivity(const Activity& activity) {

	if (validateActivity(activity)) {
		activities.push_back(activity);
		return true;
	}
	else {
		return false;
	}
}



//checks if an activity exists in the activities vector
bool LifeAI::activityExists(const std::string& activityName) {
	for (const auto& activity : activities) {
		if (activity.name == activityName) {
			return true;
		}
	}
	return false;
}

void LifeAI::updateEmotionalLevels(const Activity& activity) {
	for (const auto& emotionLevel : activity.emotionLevels) {
		user.updateEmotionLevel(emotionLevel.first, emotionLevel.second);
	}
}

bool LifeAI::updateUserActivity(const Activity &activity, int duration) {
	for (const auto& emotionEntry : activity.emotionLevels) {
		Emotion emotion = emotionEntry.first;
		int emotionChange = emotionEntry.second * duration;
		user.updateEmotionLevel(emotion, emotionChange);
	}
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
