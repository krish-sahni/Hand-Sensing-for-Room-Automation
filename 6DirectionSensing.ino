#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>  
  
  //RF24 radio(3,4); // CE, CSN
  const byte address[10] = "ADDRESS01";
  char txt1[] = "B1", txt2[] = "B2", txt3[] = "B3";

  #include <Servo.h> 
// Declare the Servo pin 
  int servoPin = 3; 
// Create a servo object 
  Servo Servo1; 
  
  const int trigPin = 9;
  const int echoPin = 10;
  const int trigPin2 = 7;
  const int echoPin2 = 8;
  const int trigPin3 = 5;
  const int echoPin3 = 6;
  //const int ledPin = 13;
 // const int ledPin2 = 12;

  signed long previousMillis;
  signed long currentMillis;


  long duration;
  int distance;
  long duration2;
  int distance2;
  long duration3;
  int distance3;

  bool ltr = false;
  bool rtl = false;
  bool btf = false;
  bool ftb = false;

  bool btfActive = false;

  bool rightClose = false;
  bool leftClose = false;
  bool rightAndLeft = false;
  bool rightToLeftStart = false;
  bool leftToRightStart = false;
  bool rightToLeftCompleted = false;
  bool leftToRightCompleted = false;
  bool frontToBackStart = false;
  bool frontToBackCompleted = false;
  bool start2 = false;


  bool x1_10 = false;
  bool backActive = false;
  
  void findDist () {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
    // Prints the distance on the Serial Monitor


    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration2 = pulseIn(echoPin2, HIGH);
    // Calculating the distance
    distance2 = duration2 * 0.034 / 2;
    // Prints the distance on the Serial Monitor

    digitalWrite(trigPin3, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin3, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin3, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration3 = pulseIn(echoPin3, HIGH);
    // Calculating the distance
    distance3 = duration3 * 0.034 / 2;
    // Prints the distance on the Serial Monitor
  }
  void start () {
  rightClose = false;
  leftClose = false;
  rightAndLeft = false;
  rightToLeftStart = false;
  leftToRightStart = false;
  rightToLeftCompleted = false;
  leftToRightCompleted = false;
  frontToBackStart = false;
  frontToBackCompleted = false;
  }










  void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  //pinMode(ledPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
  //pinMode(ledPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin3, INPUT); // Sets the echoPin as an Input
  Servo1.attach(servoPin); 
  Serial.begin(9600); // Starts the serial communication
  /*radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();*/
  }


  void loop() {


  findDist();

  //int ledVal = digitalRead(ledPin);
  //int ledVal2 = digitalRead(ledPin2);

  start2 = true;
  start();

  if ((distance2 < 10) && (backActive == false)){
    x1_10 = true;
    Serial.println("right sensor 10");
    currentMillis = millis();
    //Serial.println(distance2);
    //previousMillis = currentMillis;
    while (millis() <= currentMillis + 1000){
      findDist();
      //Serial.println(distance2);
      if ((distance2 < 13) && (distance2 > 10)){
        Serial.println("front to back 1");
        while (millis() <= currentMillis + 1000){
          findDist();
          //Serial.println(distance2);
          if ((distance2 < 16) && (distance2 > 13)){
            Serial.println("front to back 2");
            while (millis() <= currentMillis + 1000){
              findDist();
              //Serial.println(distance2);
              if ((distance2 < 20) && (distance2 > 16)){
                Serial.println("front to back done");
                //digitalWrite(ledPin2, LOW);
              }
            }
          }
        }
      }
      else if ((distance < 20) && (distance2 > 60)){
        Serial.println("right to left 1");
        while (millis() <= currentMillis + 1000){
          findDist();
          if ((distance > 60) && ( distance2 > 60)){
            Serial.println("right to left done");
            //digitalWrite(ledPin, HIGH);
            while (millis() <= currentMillis + 1000){
              findDist();
              //Serial.println(distance2);
              if ((distance < 25) && (distance > 20)){
                Serial.println("front to back done 2");
                //digitalWrite(ledPin2, LOW);
              }
            }
          }
        }
      }
      else if ((distance3 < 20) && (distance2 > 60)){
        Serial.println("bottom to top 1");
        while (millis() <= currentMillis + 1000){
          findDist();
          if ((distance3 > 60) && ( distance2 > 60)){
            Serial.println("bottom to top done");
            //digitalWrite(ledPin, HIGH);
            
            while (millis() <= currentMillis + 1000){
              findDist();
              //Serial.println(distance2);
              if ((distance < 25) && (distance > 20)){
                Serial.println("front to back done 2");
                //digitalWrite(ledPin2, LOW);
              }
            }
          }
        }
      }
    }
  }


  if ((distance < 10) && (backActive == false)){
    //x1_10 = true;
    Serial.println("left sensor 10");
    currentMillis = millis();
    //Serial.println(distance);
    //previousMillis = currentMillis;
    while (millis() <= currentMillis + 1000){
      findDist();
      //Serial.println(distance);
      if ((distance < 13) && (distance > 10)){
        Serial.println("front to back 1");
        while (millis() <= currentMillis + 1000){
          findDist();
          //Serial.println(distance);
          if ((distance < 16) && (distance > 13)){
            Serial.println("front to back 2");
            while (millis() <= currentMillis + 1000){
              findDist();
              //Serial.println(distance);
              if ((distance < 20) && (distance > 16)){
                Serial.println("front to back done");
               //digitalWrite(ledPin2, LOW);
              }
            }
          }
        }
      }
      else if ((distance2 < 20) && (distance > 60)){
        Serial.println("left to right 1");
        while (millis() <= currentMillis + 1000){
          findDist();
          if ((distance2 > 60) && ( distance > 60)){
            Serial.println("left to right done");
            //digitalWrite(ledPin, LOW);
            while (millis() <= currentMillis + 1000){
              findDist();
              //Serial.println(distance2);
              if ((distance2 < 25) && (distance2 > 20)){
                Serial.println("front to back done 2");
                //digitalWrite(ledPin2, LOW);
              }
            }
          }
        }
      }
    }
  }

  if (((distance > 30) && (distance < 40)) || ((distance2 > 30) && (distance2 < 40))){
    Serial.println("back");
    backActive = true;
    currentMillis = millis();
    //Serial.println(distance);
    //previousMillis = currentMillis;
    while (millis() <= currentMillis + 1000){
      findDist();
      if (((distance > 25) && (distance < 30)) || ((distance2 > 25) && (distance2 < 30))){
        Serial.println("back to front 1");
        while (millis() <= currentMillis + 1000){
          findDist();
          if (((distance > 20) && (distance < 25)) || ((distance2 > 20) && (distance2 < 25))){
            Serial.println("back to front done");
            Servo1.write(40);
            //digitalWrite(ledPin2, HIGH);
            backActive = false;
          } else {
            backActive = false;
          }
        }
      } else {
        backActive = false;
      }
    }
  }

  if (distance3<20){
    Serial.println("top sensor 10");
    currentMillis = millis();
    while (millis() <= currentMillis + 1000){
      findDist();
      if (distance2<20 && distance3>60){
        Serial.println("top to bottom 1");
        while (millis() <= currentMillis + 1000){
          findDist();
          if (distance2>60 && distance3>60){
            Serial.println("top to bottom done");
            Servo1.write(130);
          }
        }
      }
    }
  }

  


  /*if ((distance < 15) && (distance2 < 15)){
    Serial.println("right and left");
    
  }*/

  /*if ((start2 == true) && (distance < 20) && (distance2 > 60) && (rightClose == false)){
    leftClose = true;
    Serial.println("left close");
    currentMillis = millis();
    previousMillis = currentMillis;
    start2 = false;
  }
  */

  }





