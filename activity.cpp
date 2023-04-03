#include "activity.h"
#include "user.h"
#include "lifeai.h"


//constructor activity which initializes the activity with the provided values
Activity::Activity(std::string activityName, std::map<Emotion,int> activityEmotion, int activityHarmLevel, int activityDuration)
	: name(activityName), emotionLevels(activityEmotion), harmLevel(activityHarmLevel), duration(activityDuration){


	//constructor implementation
}