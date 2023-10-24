//CÓDIGO SOLAR TRACKER - PROJETO CASA SUSTENTÁVEL
//AUTOR: LUCAS EDUARDO DIAS DE OLIVEIRA
//DATA: 22/10/2023

#include <Servo.h>

//SENSORES
#define sensorQuadr1 A4
#define sensorQuadr2 A3 
#define sensorQuadr3 A2 
#define sensorQuadr4 A1

int valSensorQuadr1 = 0;
int valSensorQuadr2 = 0;
int valSensorQuadr3 = 0;
int valSensorQuadr4 = 0;

int returnSensor(int sensor);


//SERVOS
byte angServoSup = 90;
byte angServoInf = 90;

Servo servoSup;
Servo servoInf;

void atualizaAngServo();
void controlAngServoSup();
void controlAngServoInf();


byte limiteSupAngServoSup=130;
byte limiteInfAngServoSup=50;

byte limiteSupAngServoInf=130;
byte limiteInfAngServoInf=50;



void setup() {
  pinMode(sensorQuadr1, INPUT);
  pinMode(sensorQuadr2, INPUT);
  pinMode(sensorQuadr3, INPUT);
  pinMode(sensorQuadr4, INPUT);

  Serial.begin(57600);

  servoSup.attach(5);
  servoInf.attach(6);

  servoSup.write(90);
  servoInf.write(90);
  
  
}

void loop() {

  
  Serial.println("Sensor quadrante 1: " + String(returnSensor(sensorQuadr1)));
  Serial.println("Sensor quadrante 2: " + String(returnSensor(sensorQuadr2)));
  Serial.println("Sensor quadrante 3: " + String(returnSensor(sensorQuadr3)));
  Serial.println("Sensor quadrante 4: " + String(returnSensor(sensorQuadr4)));



  delay(50);

  controlAngServoInf();
  controlAngServoSup();
  atualizaAngServo();

  


}

int returnSensor(int sensor){
  int geralValueSensor=0;
  geralValueSensor=analogRead(sensor);
  delay(15);
  return geralValueSensor;
}

void atualizaAngServo(){
  servoSup.write(angServoSup);
  servoInf.write(angServoInf);
}

void controlAngServoSup(){
  if(returnSensor(sensorQuadr2) + returnSensor(sensorQuadr3)>returnSensor(sensorQuadr1) + returnSensor(sensorQuadr4)){
    angServoSup++;
  }else{
    angServoSup--;
  }
  if(angServoSup>=limiteSupAngServoSup){
    angServoSup=limiteSupAngServoSup;
  }
  if(angServoSup<=limiteInfAngServoSup){
    angServoSup=limiteInfAngServoSup;
  }
}

void controlAngServoInf(){
  if(returnSensor(sensorQuadr1) + returnSensor(sensorQuadr2)>returnSensor(sensorQuadr3) + returnSensor(sensorQuadr4)){
    angServoInf++;
  }else{
    angServoInf--;
  }
  if(angServoInf>=limiteSupAngServoInf){
    angServoInf=limiteSupAngServoInf;
  }
  if(angServoInf<=limiteInfAngServoInf){
    angServoInf=limiteInfAngServoInf;
  }
}
