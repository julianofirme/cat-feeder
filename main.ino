#include <Servo.h>

Servo myservo;

unsigned long startTime = 0;

unsigned long seconds = 0;
unsigned long minutes = 0;
unsigned long hours = 0;

void setup() {
  Serial.begin(9600); 
  myservo.attach(9);
}

void loop() {

    if (startTime == 0) {
      startTime = millis();
    }

    unsigned long elapsedTime = millis() - startTime;

    seconds = elapsedTime / 1000;
    minutes = seconds / 60;
    hours = minutes / 60;

    seconds = seconds % 60;
    minutes = minutes % 60;
    hours = hours;

    if (seconds > 3){
          myservo.write(0);
          delay(200);

          myservo.write(100);
          startTime = 0;
    }

    Serial.print("seconds: ");
    Serial.println(seconds);
    Serial.println("");

    delay(1000);
}