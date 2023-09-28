#pragma once

#include <robotinfo_msgs/RobotInfo10Fields.h>
#include <ros/ros.h>

class RobotInfo {

public:
  RobotInfo(ros::NodeHandle &nh, const std::string &robot_description,
            const std::string &serial_number, const std::string &ip_address,
            const std::string &firmware_version);

  virtual void publish_data();

protected:
  std::string robot_description;
  std::string serial_number;
  std::string ip_address;
  std::string firmware_version;

  robotinfo_msgs::RobotInfo10Fields robot_info_msg;

  ros::Publisher robot_info_pub;

  void set_data_fields();
};