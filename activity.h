#ifndef ACTIVITY_H
#define ACTIVITY_H


#include <string>
#include <map>



//Enum through the differnt typ of emotions to be used in the Activity class
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
	std::string name;
	std::map<Emotion, int> emotionLevels;
	int harmLevel;
	int duration;




	//constructor
	Activity(std::string name, std::map<Emotion, int> emotionLevels, int harmLevel, int duration);


};























#endif