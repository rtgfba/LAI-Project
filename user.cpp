#include "user.h"
#include "activity.h"
#include "lifeai.h"


User::User(std::string userName) : name(userName), dopamineLevel(0), happinessLevel(0), harmLevel(0), motivationLevel(0), angerLevel(0)
, fearLevel(0), generosityLevel(0), emotionalLevel(0)
{

	//constructor implementation


}


void User::updateActivityLog(std::string activityName, int duration) {

	//implementation

}



void User::updateDopamineLevel(int change) {
	dopamineLevel += change;

}


void User::updateHappinessLevel(int change) {
	happinessLevel += change;
}


void User::updateHarmLevel(int change) {
	harmLevel += change;

}


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