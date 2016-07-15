/*
 * Programacao para o torneio Regional OBR 2016 FEI II;
 * Desenvolvido por Felipe Silva e Felipe Tiozo;
 * Time Carbobots;
 * Apoio: Engenhoteca, Raos Cursos, Sianinha Corte e Costura, Porto Windows, 100% Pizza, Bem+Mais Publicidade & Design, Carpe Diem Revisões; 
 * http://facebook.com/carbobots
 */
#include <QTRSensors.h>
#include <Servo.h>

/// Basic robot definitions
#include "Config.h"

#include "Readings.h" // lê
#include "Verifications.h" // verifica
#include "Actions.h" // age
#include "Controllers.h" // controla

#include "Menu.h"


void setup() {
  Serial.begin(9600);
  acenderLED(1);
  
  ligarMotores();
  
  calibracao(true);
  acenderLED(2);
  
  //ligarServos(70);
  Servo myservo;
  Servo myservo2;
  
  myservo.attach(6);
  myservo2.attach(7);
  
  
  myservo.write(70);
  myservo2.write(70);
  /*myservo.detach();
  myservo2.detach();*/
  
}


void loop() {
    
   //initRobot();
    //SeguidorLinha(true, ST_PRINCIPAL);
  if(verificaRampa() == true) {
    situacao++;
  }

  if (situacao >= 150){
    Servo myservo;
        Servo myservo2;
        myservo.attach(6);
        myservo2.attach(7);
    myservo.write(180);
        myservo2.write(180);
    
        
    while(situacao >= 1) {
      /*if(verificaResgate() == true) {
        pararMotores(); 
        //situacao = 0;
        //Resgate();
      } else {*/
  
        
        SeguidorLinha(true, ST_RAMPA);
      //}
    }
    
  } else {
    SeguidorLinha(true, ST_PRINCIPAL);
  }
  
  //LeituraTodosQTR();
  //SeguidorLinha(true, ST_PRINCIPAL);
  //PID(KP, KI, KD, forca_Normal, setPoint);
  //delay(1000);
  /* int i=analogRead(A9);
  int val=(6762/(i-9))-4;
  Serial.println(val);
  delay(100);*/
/*
  Serial.println("todos os sensores = ");
  Serial.println(lerQTR(10));
  delay(100);
*/

}
