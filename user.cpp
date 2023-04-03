#include "user.h"
#include "activity.h"
#include "lifeai.h"


//User.cpp contains the implementation of the User class methods in user.h


//User class constructor initializes the User object with the provided userName. It also sets the initial values for
//dopamineLevel, happinessLevel, motivationLevel, etc.. to 0
User::User(std::string userName) : name(userName), dopamineLevel(0), happinessLevel(0), harmLevel(0), motivationLevel(0), angerLevel(0)
, fearLevel(0), generosityLevel(0), emotionalLevel(0)
{

	//constructor implementation


}


//method for updating user's activity log with the specified activity name and duration
void User::updateActivityLog(std::string activityName, int duration) {

	activityLog[activityName] += duration;

}


//Updates user's dopamine level by adding the provided change value
void User::updateDopamineLevel(int change) {
	dopamineLevel += change;

}

//Updates user's happiness level by adding the provided change value
void User::updateHappinessLevel(int change) {
	happinessLevel += change;
}

//Updates user's harm level by adding the provided change value
void User::updateHarmLevel(int change) {
	harmLevel += change;

}

//updateEmotionLevel method updates the user's emotion level ofr the specified emotion by adding the provided
//change value. It checks the emotion parameter and updates the corresponding emotion level accordingly
void User::updateEmotionLevel(Emotion emotion, int change) {
	if (emotion == HAPPINESS) {
		happinessLevel += change;
	}
	else if (emotion == MOTIVATION) {
		motivationLevel += change;
	}
	else if (emotion == ANGER) {
		angerLevel += change;
	}
	else if (emotion == FEAR) {
		fearLevel += change;
	}
	else if (emotion == GENEROSITY) {
		generosityLevel += change;
	}
	else if (emotion == EMOTIONAL) {
		emotionalLevel += change;
	}
}

//Implement getters
const int User::getDopamineLevel() { return dopamineLevel;}
const int User::getHappinessLevel() { return happinessLevel; }
const int User::getHarmLevel() { return harmLevel; }
const int User::getMotivationLevel() { return motivationLevel; }
const int User::getAngerLevel() { return angerLevel; }
const int User::getFearLevel() { return fearLevel; }
const int User::getGenerosityLevel() { return generosityLevel; }
const int User::getEmotionalLevel() { return emotionalLevel; }


//Reset emotions
void User::resetEmotionLevels() {
	dopamineLevel = 0;
	happinessLevel = 0;
	harmLevel = 0;
	motivationLevel = 0;
	angerLevel = 0;
	fearLevel = 0;
	generosityLevel = 0;
	emotionalLevel = 0;

}

const std::string User::getBestFeelingState() {
	return bestFeelingState;
}



void User::setBestFeelingState(const std::string &state) {
	bestFeelingState = state;
}


const std::vector<std::string> User::getRelatedActivities() {
	return relatedActivities;
	;
}

void User::addRelatedActivity(const std::string &activity) {
	relatedActivities.push_back(activity);
}