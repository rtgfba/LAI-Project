#include "user.h"
#include "activity.h"
#include "lifeai.h"


User::User(std::string userName) : name(userName), dopamineLevel(0), happinessLevel(0), harmLevel(0) {

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