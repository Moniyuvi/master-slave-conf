/* TX MASTER CODE VERSION 3
 *  This code is for Master module , which reads the sensor values and sent by the
 *  Slave and prints The sensor values in the Serial monitor.
 *  
 *  Connections are as follows
 *  Tx pin of bluetooth module   To   4 th pin of arduino
 *  Rx pin of bluetooth module   To   3 rd pin of arduino
 *  IMPORTANT NOTE: SELECT THE PORT OF THE MASTER MODULE CAREFULLY
 *  
 */


#include <SoftwareSerial.h> // this header file is used to enable serial monitor for other attachments


#define BT_SERIAL_TX 4  //Conneting Tx pin of bluetooth module to 4 th pin of arduino 
#define BT_SERIAL_RX 3  //Conneting Rx pin of bluetooth module to 3 rd pin of arduino

SoftwareSerial BluetoothSerial(BT_SERIAL_TX, BT_SERIAL_RX);
/* This line is to transmit and recieve sensor values through 
the 4th pin and 3rd pin of arduino respectively.*/

int potval=0; // variable to read Rotatory sensor's Data which is sent by bluetooth module
int micvolume=0;// variable to read Sound sensor's sensor's Data which is sent by bluetooth module

void setup()

{

Serial.begin(9600);// Defining Baud Rate for Transmission and reception inside Arduino's Processing unit

BluetoothSerial.begin(9600); // Defining Baud Rate for Transmission and reception for Bluetooth module's Processing unit

/* We have to define baud rate for both the arduino and bluetooth module with same values
so that there is synchronisation between the arduino and the bluetooth modue*/ 
}

void loop()

{

if (BluetoothSerial.available()>0)

{
  // the below set of code is to read the potentiometer value sent by the slave node and display in serial monitor
  potval = BluetoothSerial.read(); //  this line will Read the bluetooth module for Potentiometer data
  Serial.print("Rotary sensor Value =  " );// the set of 3 lines print the data in serial monitor
  Serial.print(potval);
  Serial.println(" ");
  Serial.println(" ");
  delay(1000); // Delay of 1000 milliseconds(one second) to read the next sensor's data


  // the below set of code is to read the Mic volume sent by  the slave node and display in serial monitor
  micvolume = BluetoothSerial.read();//this line will Read the bluetooth module for Potentiometer data
  Serial.print("Mic Volume level =  " );// the set of 3 lines print the data in serial monitor
  Serial.print(micvolume);
  Serial.println(" ");
  Serial.println(" ");
  delay(1000);// Delay of 1000 milliseconds(one second) to read the next sensor's data
}

}
