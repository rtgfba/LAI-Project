#ifndef USER_H
#define USER_H

#include <string>
#include <map>




class User {

public:
	std::string name;

	int dopamineLevel;
	int happinessLevel;
	int harmLevel;
	int motivationLevel;
	int angerLevel;
	int fearLevel;
	int generosityLevel;
	int emotionalLevel;


	std::map<std::string, int> activityLog;


	User(std::string name);


	void updateActivityLog(std::string activityName, int duration);
	void updateDopamineLevel(int change);
	void updateHappinessLevel(int change);
	void updateHarmLevel(int change);
	void updateEmotionLevel(Emotion emotion, int change);


};


#endif
