#include "robot_info/hydraulic_system_monitor.hpp"
#include <robot_info/agv_robot_info_class.hpp>

int main(int argc, char **argv) {
  ros::init(argc, argv, "agv_robot_info");
  ros::NodeHandle nh;
  HydraulicSystemMonitor hms = HydraulicSystemMonitor("45C", "100%", "250");
  AGVRobotInfo agv_ri = AGVRobotInfo(nh, "Mir100", "567A359", "169.254.5.180",
                                     "3.5.8", "100 Kg", hms);

  ros::Rate rate(1);

  while (ros::ok()) {
    agv_ri.publish_data();
    rate.sleep();
  }
}