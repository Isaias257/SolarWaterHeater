#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
uint16_t t;

#include <OneWire.h>
#include <DallasTemperature.h>
 
#define ONE_WIRE_BUS 8 // Data wire is plugged into port 8 on the Arduino
#define precision 12 // OneWire precision Dallas Sensor
int sen_number = 0; // Counter of Dallas sensors
 
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire); // Pass our oneWire reference to Dallas Temperature.
DeviceAddress T1, T2, T3, T4, T5; // arrays to hold device addresses
void setup(void)
{
lcd.begin(16,2);
Serial.begin(9600); //Start serial port

// Start up the library
sensors.begin();
// locate devices on the bus
// report parasite power requirements
// Search for devices on the bus and assign based on an index.
// show the addresses we found on the bus

// set the resolution to 12 bit per device
sensors.setResolution(T1, precision);
sensors.setResolution(T2, precision);
sensors.setResolution(T3, precision);
sensors.setResolution(T4, precision);
sensors.setResolution(T5, precision);

Serial.print("t T1 T2 T3 T4 T5");
Serial.println();
}
// function to print a device address
// function to print the temperature for a device
void printTemperature(DeviceAddress deviceAddress)
{
float tempC = sensors.getTempC(deviceAddress);
Serial.print(tempC);
// Serial.print(" Temp F: ");
// Serial.print(DallasTemperature::toFahrenheit(tempC));
}
// function to print a device's resolution
void printResolution(DeviceAddress deviceAddress)
{
}
 
void printData(DeviceAddress deviceAddress)
{
printTemperature(deviceAddress);
Serial.print(" ");
}
 
void loop(void)
{
// call sensors.requestTemperatures() to issue a global temperature request to all devices on the bus
sensors.requestTemperatures();

// print the device information
Serial.print(t);
Serial.print(" ");
printData(T1); 
printData(T2); 
printData(T3); 
printData(T4); 
printData(T5); 
Serial.println();

if (sen_number == sensors.getDeviceCount()) {
sen_number = 0; // reset counter
// lcd.clear(); // clear screen on LCD
}
lcd.setCursor(0,0);
lcd.print("Sensor Number ");
lcd.print(sen_number+1);
lcd.setCursor(0,1);
lcd.print(" Temp: ");
if (sen_number == 0) { lcd.print(sensors.getTempC(T1)); lcd.write((char)223); lcd.print("C ");
} else if (sen_number == 1) { lcd.print(sensors.getTempC(T2)); lcd.write((char)223); lcd.print("C ");
} else if (sen_number == 2) { lcd.print(sensors.getTempC(T3)); lcd.write((char)223); lcd.print("C ");
} else if (sen_number == 3) { lcd.print(sensors.getTempC(T4)); lcd.write((char)223); lcd.print("C ");
} else if (sen_number == 4) { lcd.print(sensors.getTempC(T5)); lcd.write((char)223); lcd.print("C ");
}

t++;
sen_number++ ;
}
