#include <robot_info/agv_robot_info_class.hpp>
#include <robot_info/hydraulic_system_monitor.hpp>

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle &nh,
                           const std::string &robot_description,
                           const std::string &serial_number,
                           const std::string &ip_address,
                           const std::string &firmware_version,
                           const std::string &maximum_payload,
                           const HydraulicSystemMonitor &hsm)
    : RobotInfo(nh, robot_description, serial_number, ip_address,
                firmware_version),
      maximum_payload(maximum_payload), hsm(hsm) {}

void AGVRobotInfo::publish_data() {
  set_data_fields();
  robot_info_msg.data_field_05 = "maximum_payload: " + maximum_payload;
  robot_info_msg.data_field_06 =
      "hydraulic_oil_temperature: " + hsm.get_oil_temp();
  robot_info_msg.data_field_07 =
      "hydraulic_oil_tank_fill_level: " + hsm.get_oil_level();
  robot_info_msg.data_field_08 =
      "hydraulic_oil_pressue: " + hsm.get_oil_pressure();

  robot_info_pub.publish(robot_info_msg);
}