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

	void addActivity(Activity activity);
	void recommendActivities();
	void trackEmotions();
	void trackHarm();
	void provideFeedback();
	void customizeApproach();

	//Save user data
	void saveUserData(const std::string& filename);

	//Load user data
	void loadUserData(const std::string& filename);


};















#endif
