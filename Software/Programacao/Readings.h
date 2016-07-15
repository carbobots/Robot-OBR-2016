#include <Arduino.h>
/*
  FUNÇÕES de leitura DO ROBÔ
*/

// sensors 0 through 5 are connected to analog inputs 0 through 5, respectively
QTRSensorsAnalog qtra((unsigned char[]) {0, 1, 2, 3, 4, 5, 6, 7}, 
  NUM_SENSORS);
unsigned int sensorValues[NUM_SENSORS];


int lerTodosQTR() {
  return qtra.readLine(sensorValues);
}

int lerQTR(int numero_sensor) {
  //return sensorValues[numero_sensor-1];
  return analogRead(Sensores_Array[numero_sensor]);  
}

int lerSharp(int numero_sensor) {
  return analogRead(Sensores_Sharp[numero_sensor]);  
}

int lerBotao(int numero_sensor) {
  return digitalRead(Botoes[numero_sensor]);  
}

void acenderLED(int numero_led) {
  digitalWrite(LEDS[numero_led], HIGH);
}

void LeituraTodosQTR() {
  // read raw sensor values
  qtra.read(sensorValues);
  
  // print the sensor values as numbers from 0 to 1023, where 0 means maximum reflectance and
  // 1023 means minimum reflectance
  for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t'); // tab to format the raw data into columns in the Serial monitor
  }
  Serial.println();
  
  delay(250);
}
