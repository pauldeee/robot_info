#include <robot_info/hydraulic_system_monitor.hpp>

HydraulicSystemMonitor::HydraulicSystemMonitor(const std::string oilTemp,
                                               const std::string oilLevel,
                                               const std::string oilPressure)
    : hydraulic_oil_temperature(oilTemp),
      hydraulic_oil_tank_fill_level(oilLevel),
      hydraulic_oil_pressure(oilPressure) {}

std::string HydraulicSystemMonitor::get_oil_temp() {
  return hydraulic_oil_temperature;
}

std::string HydraulicSystemMonitor::get_oil_level() {
  return hydraulic_oil_tank_fill_level;
}

std::string HydraulicSystemMonitor::get_oil_pressure() {
  return hydraulic_oil_pressure;
}
