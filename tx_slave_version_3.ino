/* TX SLAVE CODE VERSION 3
 *  This code is for slave module , which reads the sensor values and sends it to the Master
 *  Connections are as follows
 *  
 *  Tx pin of bluetooth module   To   4 th pin of arduino
 *  Rx pin of bluetooth module   To   3 rd pin of arduino
 *  Rotatory sensor's Data pin   To   A0 Pin of Arduino
 *  Sound sensor's Data pin      To   A1 Pin of Arduino
 *  Power Supply  -    use 3.3V for bluetooth module and GND 
 *                -    use 5V and any GND Pin from Arduino 
 *                     make a parellel conecton using the breadboard
 *                     to connect The power supply lones of the both the Sensors
 *  
 */


#include <SoftwareSerial.h>// this header file is used to enable serial monitor for other attachments


#define BT_SERIAL_TX 4 // Conneting Tx pin of bluetooth module to 4 th pin of arduino
#define BT_SERIAL_RX 3 // Conneting Rx pin of bluetooth module to 3 rd pin of arduino

SoftwareSerial BluetoothSerial(BT_SERIAL_TX, BT_SERIAL_RX); // This line is to transmit and recieve sensor values through the 4th pin and 3rd pin of arduino respectively.

int potpin = A0; // Connecting Rotatory sensor's Data pin-- To A0 Pin of Arduino 
int micpin = A1; // Connecting Sound sensor's Data pin-- To A1 Pin of Arduino

int potval=0;    // variable to read Rotatory sensor's Data 
int micvolume=0; // variable to read Sound sensor's sensor's Data

void setup()

{

Serial.begin(9600); // Defining Baud Rate for Transmission and reception inside Arduino's Processing unit

BluetoothSerial.begin(9600); // // Defining Baud Rate for Transmission and reception for Bluetooth module's Processing unit
// We have to define baud rate for both the arduino and bluetooth module with same values
}

void loop()

{
 // the below set of code is to read the potentiometer value and send it to slave 
 potval = analogRead(potpin); //Reading the Sensor data 
 potval = map(potval, 0, 1023, 0, 500);  // maps the voltage from 2 to 255
 BluetoothSerial.print(potval);// Sending the Sensor data from Arduino to Blurooth module
 Serial.print("Potval in slave side:");
 Serial.print(potval);
 Serial.println(" ");
 delay(1000);// Delay of 1000 milliseconds(one second) to read the next sensor's data


 // the below set of code is to read the MIC VOLUME and send it to slave 
 micvolume= analogRead(micpin);//Reading the Sensor data
 micvolume = map(micvolume, 0, 1023, 0, 100); // maps the volume from 0 to 100
 BluetoothSerial.print(micvolume);// Sending the Sensor data from Arduino to Blurooth module
 Serial.print("micvolume in slave side: ");
 Serial.println(micvolume);
 Serial.println(" ");
 delay(1000);// Delay of 1000 milliseconds(one second) to read the next sensor's data

}
