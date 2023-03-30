#include "activity.h"



Activity::Activity(std::string activityName, std::map<Emotion,int> activityEmotion, int activityHarmLevel, int activityDuration)
	: name(activityName), emotionLevels(activityEmotion), harmLevel(activityHarmLevel), duration(activityDuration){


	//constructor implementation
}