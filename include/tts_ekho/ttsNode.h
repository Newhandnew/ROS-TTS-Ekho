
#include <ros/ros.h>
#include <string>
#include <std_msgs/String.h>
#include <stdio.h>
#include "config.h" // this file is generated when building Ekho
#include "ekho.h"

// using namespace ekho;

class ttsNode {
public:
	ttsNode(int argc, char** argv);
	void setLanguage(std::string &language);
	void tts(const std::string &text);
	void quit();



private:
  	ros::Subscriber ttsSubscriber;
  	void ttsCB(const std_msgs::String text);
  	ekho::Ekho *ekhoNode;
};