#include <SpinTimer.h>
#include <UptimeInfo.h>

*/
#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"
MAX30105 particleSensor;
const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
byte rates [RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occurred
float beatsPerMinute;
int beatAvg:
#define echoPin 6
#define triggerPin 7
#include <SpinTimer.h>
#include <UptimeInfo.h>
#include <Adafruit DotStarMatrix.h>
#include <gamma.h>
#include <LcdKeypad.h>
#include <LiquidCrystal_I2C.h>
#include <wire.h>
//12C address 0x27
LiquidCrystal_I2C Icd(0x27,16.2); //16x2 display
void setup()
{
Serial.begin(115200);
Serial.println("Initializing...");
lcd.init();// initialize the Icd
lcd.backlight();// Backlight ON
// Initialize sensor
if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) //Use default 12C port, 400kHz
speed
{
Serial.println("MAX30105 was not found. Please check wiring/power."); 
while (1);
}
Serial.println("Place your index finger on the sensor with steady pressure.");
pinMode(triggerPin, OUTPUT); // Sets the trigPin as an OUTPUT
pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT

// Serial.begin(9600); baudrate speed // Serial Communication is starting with 9600 of

Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor

Serial.println("with Arduino UNO");

void loop() 
{
//lcd.clear(): 
//delay(500);
long high PulseDuration:
int calculatedDistanceCm;
//Set the trigPin to low, before setting it to high for the pulse 
digitalWrite(triggerPin, LOW); 
delayMicroseconds(5);
// Create the 10 seconds pulse on the trig pin 
digitalWrite(triggerPin, HIGH); 
delayMicroseconds(10);
// Set the pin to low to end the pulse
digitalWrite(triggerPin, LOW);

// Read the duration of the high pulse on the echo pin 
highPulse Duration pulseln(echoPin, HIGH);

// Calculating the distance
calculatedDistanceCm = highPulseDuration 0.034/2: // Speed of
// Displays the distance on the Serial Monitor Serial.print("Calculated Distance: "); Serial.print(calculated DistanceCm); Serial.println("cm");
lcd.setCursor(2,1);// 1st column, 2nd row
Icd.print("Dist: 7: lcd.print(calculatedDistanceCm);
lcd.setCursor(10,1);// Ist column, 2nd row lcd.print("cm");
long irValue particleSensor.getIR();
if (checkForBeat(irValue) == true)
{
//We sensed a beat! 
long delta millis() - lastBeat; 
lastBeat millis():
beats Per Minute=60/(delta/1000.0);
if (beatsPerMinute < 255 && beatsPerMinute>20)
{
rates[rateSpot++] (byte) beatsPerMinute; //Store this reading in the array rateSpot % RATE_SIZE; //Wrap variable
//Take average of readings
beatAvg = 0;
for (byte x = 0; x < RATE_SIZE; x++)
beatAvg += rates[x]:
beatAvg/= RATE_SIZE;
 }
}
Serial.print("IR-");
Serial.print(irValue);
Serial.print(", BPM=");
Serial.print(beatsPerMinute); 
Serial.print(", Avg BPM="); 
Serial.print(beatAvg);

lcd.setCursor(0,0);// 2nd column, Ist row 
lcd.print("Avg BPM:"); 
lcd.setCursor(9,0);// 2nd column, Ist row 
lcd.print(beatAvg);
if (irValue 50000)
Serial.print(" No finger?");

Serial.println();

serial.println();

}
