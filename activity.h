#ifndef ACTIVITY_H
#define ACTIVITY_H


#include <string>
#include <map>



//Enum through the differnt types of emotions to be used in the Activity class
//
enum Emotion {
	HAPPINESS,
	MOTIVATION,
	ANGER,
	FEAR,
	GENEROSITY,
	EMOTIONAL,
};





class Activity {
public:

	//Name of the activity
	std::string name;

	//Map associating emotions with their respective levels for the activity
	std::map<Emotion, int> emotionLevels;

	//harm level of the activity
	int harmLevel;

	//duration of the activity
	int duration;




	//constructor that initializes the activity with the provided name, emotion level, harm level and duration
	Activity(std::string name, std::map<Emotion, int> emotionLevels, int harmLevel, int duration);


};























#endif