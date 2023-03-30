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





//Enum through the differnt typ of emotions to be used in the Activity class
enum Emotion {
	HAPPINESS,
	MOTIVATION,
	ANGER,
	FEAR,
	GENEROSITY,
	EMOTIONAL,
};

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



//User Class

class User {
public: 
	//name of the user
	std::string name;

	//Dopamine level
	int dopamineLevel;

	//Happiness level
	int happinessLevel;

	//Harm level
	int harmLevel;


	//Log the activities
	std::map<std::string, int> activityLog;


	//Constructor
	User(std::string name) : name(name), dopamineLevel(0), happinessLevel(0), harmLevel(0){}

	








	//Declaration 
	void updateActivityLog(std::string activityName, int duration);
	void updateDopamineLevel(int change);
	void updateHappinessLevel(int change);
	void updateHarmLevel(int change);






	//Implementation

	void updateDopamineLevel(int change) {
		dopamineLevel += change;
	}


	void updateHappinessLevel(int change) {
		happinessLevel += change;
	}


	void updateHarmLevel(int change) {
		harmLevel += change;
	}


};


//Life AI Class

class LifeAI {
public:
	std::vector<Activity> activities;
	User user;


	//Constructor
	LifeAI(std::string userName) : user(userName){
	
	}

	void addActivity(Activity activity) {
		activities.push_back(activity);
	}


	void recommendActivities();
	void trackEmotions();
	void trackHarm();
	void provideFeedback();
	void customizeApproach();

	//Save user data
	void saveUserData(const std::string &filename);
	
	//Load user data
	void loadUserData(const std::string &filename);


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