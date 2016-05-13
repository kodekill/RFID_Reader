#include <SoftwareSerial.h>
SoftwareSerial RFID(2, 3); // RX and TX
const int LED = 13;


int myCode[14] = {2, 48, 67, 48, 48, 53, 52, 54, 55, 69, 55, 68, 56, 3};
int myTag[14] = {0};
int value = 0; 

void setup()
{
  RFID.begin(9600);    // start serial to RFID reader
  Serial.begin(9600);  // start serial to PC 
  pinMode(LED, OUTPUT);
}

void loop()
{
  digitalWrite(LED, LOW);
  value = 0; 
  while (RFID.available() > 0) 
  {
    
     int i = RFID.read();

     for(int j = 0; j<=13; j++)
       {
        myTag[j]= i; 
       }
     
     for(int k = 0; k<1; k++)
       {
        Serial.print(myTag[k], DEC);
        Serial.print(" ");
        delay(100);
        value += myTag[k];
       }
       
     
  }
Serial.println(value);
  
  
  if (value == 678)
        {
          Serial.println("Same");
          digitalWrite(LED, HIGH);
          delay(1500);
          digitalWrite(LED, LOW);
        }
  
  delay(100);
}
