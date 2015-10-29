#include "../include/tts_ekho/ttsNode.h"

int main(int argc, char **argv) {
   	ttsNode ttsErica(argc, argv);
   	
   	ros::Rate r(1);
   	ros::spin();
   	//boost::thread mthread(&rosSpin);
  	//mthread.join();
  	return 0;
}
