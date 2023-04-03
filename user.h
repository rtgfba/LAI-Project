#ifndef USER_H
#define USER_H

//Contains the user class definitions

#include <string>
#include <map>




class User {

public:

	//------------User class variables ------------------

	//Name of the user
	std::string name;


	//Current dopamine level
	int dopamineLevel;
	
	//Current happiness level
	int happinessLevel;

	//Current harm level
	int harmLevel;

	//Current motivation level
	int motivationLevel;

	//Current anger lever
	int angerLevel;

	//Current fear level
	int fearLevel;

	//Current generosity level
	int generosityLevel;

	//Current emotional level
	int emotionalLevel;



	//Map storing the user's activities and their corresponding durations
	std::map<std::string, int> activityLog;

	//------------User class methods ------------------

	//User constructor that initializes the user object with a name
	User(std::string name);

	//Updates the user's activityLog by adding the duration for the given activity
	void updateActivityLog(std::string activityName, int duration);

	//Updates the user's dopamine level by adding the provided change value
	void updateDopamineLevel(int change);

	//Updates the user's happiness level by adding the provided change value
	void updateHappinessLevel(int change);

	//Updates the user's harm level by adding the provided change value
	void updateHarmLevel(int change);

	//Updates the user's emotion level by adding the provided change value
	void updateEmotionLevel(Emotion emotion, int change);


};


#endif
