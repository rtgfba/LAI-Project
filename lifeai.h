//LifeAI class header file

#ifndef LIFEAI_H
#define LIFEAI_H

#include <vector>
#include<string>
#include <map>
#include "activity.h" //Include the activity header
#include "user.h"	  //Include the user header

//Life AI Class represents the main AI engine for the LAI project

class LifeAI {

public:

	//vector containing all available activities
	std::vector<Activity> activities;

	//A user object representing the user interacting with LAI
	User user;


	//Constructor which initializes LAI with a username
	LifeAI(std::string userName);



	//Life AI declrations (methods)

	//adds an activity to lifeai
	bool addActivity(const Activity& activity);

	//recommends activites based on user data
	void recommendActivities();

	//tracks user's emotions based on their activity log
	void trackEmotions();

	//tracks user's harm level based on their activity log
	void trackHarm();

	//provides feedback to the user based on their current emotional state and harm level
	void provideFeedback();

	//customizs the AI's recommendations based on user prefence and data
	void customizeApproach();

	//validates an activity before adding it to LAI
	bool validateActivity(const Activity& activity);

	//updates user's activity and emotional level
	bool updateUserActivity(const Activity& activity, int duration);

	//checks if an activity exists in the activities vector
	bool activityExists(const std::string& activityName);

	//updates user's emotional level based on the activity
	void updateEmotionalLevels(const Activity& activity);

	//Save user data
	void saveUserData(const std::string& filename);

	//Load user data
	void loadUserData(const std::string& filename);


};















#endif
