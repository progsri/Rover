#include<AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

// defines pins numbers
const int trigPin = 42;
const int echoPin = 43;
// defines variables
long duration;
int distance;
int lastDistance;


void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

 motor1.setSpeed(255);
 motor2.setSpeed(255);
 motor3.setSpeed(255);  
 motor4.setSpeed(255);

 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output 
 pinMode(echoPin, INPUT); // Sets the echoPin as an Inputd
}

void loop() {
    int presentDistance = sonar();
    Serial.println(distance);
    
    if(lastDistance == presentDistance){
      Serial.println("SAME DISTANCE");
       backward();
    }

    lastDistance = presentDistance;
    
    if (distance > 20 ){
       forward();
    }else{
       stop();
       backward();
       turn();
    }
}

void stop(){
    Serial.println("STOP");
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
   
}

void forward(){
    Serial.println("Forward");
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
}

void backward(){
   Serial.println("BACKWARD");
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}


void turn(){
   Serial.println("TURN");
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
}



int sonar(){
    Serial.println("sonar");
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    Serial.print("duration: ");
    Serial.println(duration);
    
    // Calculating the distance
    distance= duration*0.034/2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
    return distance;

}
