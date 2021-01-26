#ifndef _NINJALAMP_CORE_H_
#define _NINJALAMP_CORE_H_

#include "Arduino.h"
#include <PID_v1.h>

#define TARGET_TEMP 63 /* Typical temp for LAMP */

#define THERMISTOR_LOW_SIDE 1
#define THERMISTOR_HIGH_SIDE 2

#define MAX_OUTPUT_THRESHOLD 5

struct ThermistorRange {
  double tempLowerLimit;
  int bConst;
  double voltageLimit;
};

/* Thermistor config */
struct Thermistor {
  // Thermistor config
  int bConstRangeCount;
  ThermistorRange *bConstRanges;
  double r0;
  double baseTemp;
  
  // Thermistor & resistor circuit
  int place;
  bool useSwitching;
  double r;
  
  // Resistor switching (for well)
  double rLow;
  double rHigh;
  double switchingTemp;
  int switchingPin;
};

class ADCCustom {
  public:
    virtual void initADC() = 0;
    virtual double getWellADCValue() = 0;
    virtual double getAirADCValue() = 0;
};

class NinjaLAMPCore {
  public:
    NinjaLAMPCore(Thermistor *wellThermistorConf, Thermistor *airThermistorConf, 
      ADCCustom *adc, double wellKP, double wellKI, double wellKD, int heaterPWM);
    // Called from Arduino's setup & loop functions
    void setup();
    void enableSampleTempSimulation (double heatResistanceRatio, double sampleHeatCapacity);
    void disableSampleTempSimulation ();
    void loop();
    void loopWithoutBlocking();
    // Called by interfaces
    void start(double temp);
    void setTargetTemp(double temp);
    void stop();
    
    void debug();
    
    // Getters
    double getWellTemp(); /* Well temperature (Celsius) */
    double getAirTemp(); /* Air temperature (Celsius) */
    double getEstimatedSampleTemp(); /* Estimated temperature (Celsius) */
    double getTargetTemp(); /* Target temperature (Celsius) */
    double getTempSetpoint(); /* Setpoint of well temperature (Celsius) */
    unsigned long getTotalElapsedTime(); /* Total elapsed time from the start of the device (msec) */
    unsigned long getStageElapsedTime(); /* Elapsed time since the temperature reached the target (msec) */
    bool isHolding;
  private:
    Thermistor *wellThermistor;
    Thermistor *airThermistor;
    ADCCustom *adc;
    bool started;
    PID *pid;
    int heaterPWMPin;
    double wellTemp;
    double airTemp;
    bool isSampleTempSimulationEnabled;
    double sampleHeatCapacity;
    double heatResistanceRatio;
    double estimatedSampleTemp;
    
    unsigned long lastTimestamp;
    unsigned long lastWellTimestamp;
    unsigned long lastAirTimestamp;
    unsigned long totalElapsedTime; /* msec */
    unsigned long stageElapsedTime; /* msec */
    
    void loopWell();
    void loopAir();
    void controlTemp();
    void setupPID();
    double readWellTemp ();
    double readAirTemp ();
    double bConstantForVoltage (int rangeCount, ThermistorRange *ranges, double voltageRatio);
    void calcVoltageLimits (Thermistor *thermistor);
    void switchWellR (double temp);
    double voltageToTemp (double voltageRatio, float resistance, 
      float b_constant, float r0, double baseTemp);
    double tempToVoltageRatio (double tempCelsius, double resistance, 
      double bConst, double r0, double baseTemp);
    double averageTemp ();
};

#endif _NINJALAMP_CORE_H_
