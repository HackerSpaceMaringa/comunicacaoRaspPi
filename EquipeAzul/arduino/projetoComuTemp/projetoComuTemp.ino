#include <math.h>

const int ledPin = 8;     //Pino do led
const int pinoSensor = 0; //Pino do sensor
const int buttonPin = 9;  //Pino do botao

int valorSensor = 0;      //Valor do sensor
int buttonState = 0;      //Estado do botao
int io = 0;               //Ligado/Desligado

double Thermister(int RawADC) {
  double Temp;
  Temp = log(((10240000/RawADC) - 10000));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
  Temp = Temp - 273.15;            // Convert Kelvin to Celcius
  return Temp;
}

int Turn(int buttonState,int io) {
  int newIO = io;
  if (buttonState == HIGH){
    newIO = !newIO;
  }
  return newIO;
}

void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  io = Turn(buttonState,io);
  if (io == 1) {
    digitalWrite(ledPin,HIGH);
    Serial.println(int(Thermister(analogRead(pinoSensor))));
  }else{
    digitalWrite(ledPin,LOW);
  }
  delay(125);
}
