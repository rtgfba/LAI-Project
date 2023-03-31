//LifeAI class header file

#ifndef LIFEAI_H
#define LIFEAI_H

#include <vector>
#include<string>
#include <map>
#include "activity.h" //Include the activity header
#include "user.h"	  //Include the user header

//Life AI Class

class LifeAI {

public:
	std::vector<Activity> activities;
	User user;


	//Constructor
	LifeAI(std::string userName);



	//Life AI declrations 

	bool addActivity(const Activity& activity);
	void recommendActivities();
	void trackEmotions();
	void trackHarm();
	void provideFeedback();
	void customizeApproach();
	bool validateActivity(const Activity& activity);
	bool updateUserActivity(const Activity& activity, int duration);
	bool activityExists(const std::string& activityName);
	void updateEmotionalLevels(const Activity& activity);

	//Save user data
	void saveUserData(const std::string& filename);

	//Load user data
	void loadUserData(const std::string& filename);


};















#endif
