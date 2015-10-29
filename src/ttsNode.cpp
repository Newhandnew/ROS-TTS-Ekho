#include "../include/tts_ekho/ttsNode.h"

using namespace ekho;

ttsNode::ttsNode(int argc, char** argv) {
	ros::init(argc, argv, "mqtt_drive_base");
	if ( ! ros::master::check() ) {
    	ROS_DEBUG("ROS master is not ready!");
    	quit();
	}
	//ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
	ttsSubscriber = n.subscribe("ttsText", 10, &ttsNode::ttsCB, this);
	//set default language as Mandarin
	ekhoNode = new Ekho("Mandarin");
}

void ttsNode::setLanguage(std::string &language) {
	if (language == "Mandarin");
	// haven't defined yet
	else
		printf("set a wrong language");
}


void ttsNode::tts(const std::string &text) {
	//ekhoNode=new ("Mandarin");
	if (text != "")
		ekhoNode->blockSpeak(text);
	else
		printf("nothing to speak");
}


void ttsNode::quit() {
	ros::shutdown();
	exit(0);
}


void ttsNode::ttsCB(const std_msgs::String text) {
  // ROS_DEBUG(msg.key);
  // ROS_DEBUG(msg.value);
	tts(text.data);
}
