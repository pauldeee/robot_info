#include <robot_info/robot_info_class.hpp>

RobotInfo::RobotInfo(ros::NodeHandle &nh, const std::string &robot_description,
                     const std::string &serial_number,
                     const std::string &ip_address,
                     const std::string &firmware_version)
    : robot_description(robot_description), serial_number(serial_number),
      ip_address(ip_address), firmware_version(firmware_version) {

  robot_info_pub =
      nh.advertise<robotinfo_msgs::RobotInfo10Fields>("/robot_info", 1);
}

void RobotInfo::publish_data() {
  set_data_fields();

  robot_info_pub.publish(robot_info_msg);
}

void RobotInfo::set_data_fields() {
  robot_info_msg.data_field_01 = "robot_description: " + robot_description;
  robot_info_msg.data_field_02 = "serial_number: " + serial_number;
  robot_info_msg.data_field_03 = "ip_address: " + ip_address;
  robot_info_msg.data_field_04 = "firmware_version: " + firmware_version;
}
