#pragma once

#include <string>

class HydraulicSystemMonitor {

public:
  HydraulicSystemMonitor(const std::string oilTemp, const std::string oilLevel,
                         const std::string oilPressure);

  std::string get_oil_temp();
  std::string get_oil_level();
  std::string get_oil_pressure();

private:
  std::string hydraulic_oil_temperature;
  std::string hydraulic_oil_tank_fill_level;
  std::string hydraulic_oil_pressure;
};