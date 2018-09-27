
#include <ESP8266HTTPClient.h>
#include "ServerType.h"
#include "ServerInfo.h"
#include "InitialSetup.h"
#include "DecibelData.h"
#include "ClientHandler.h"
#include "SensorHandler.h"
#include "LEDHandler.h"
#include "ThingSpeak.h"
#include "Util.h"
#include "DHT_sensor_library_for_ESPx/DHTesp.h"

void setup() 
{
  ledHandler.init();                    	// initializing LED HW, sets LED color to blue
  Util::serialInit();				// starting serial channel
  
  menu.start();					// the user may change some settings here
  wifiHandler.connect();			// connects to wifi
  clientHandler.init();				// initializes client to be ready for connection

  ledHandler.start();                   	// sets LED color to black
}

void loop()
{
	//sensorHandler.hdtTester();		// HDT sensor tester
	sensorHandler.updateSensors();		// updates sensors
	sensorHandler.updateLED();		// updates LED
	Util::sendDataToSerialDefault();	// writes SPL, temperature and humiditay values to serial port
	clientHandler.uploadData();		// sends data to the server

	delay(50);
}




