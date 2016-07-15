#include <Arduino.h>
#include <Servo.h>
#include <QTRSensors.h>
/*
  FUNÇÕES de Ação DO ROBÔ
*/

void pararMotores() {
  analogWrite(MotorEsquerdoFrente, 0);
  analogWrite(MotorEsquerdoTras, 0);            
  analogWrite(MotorDireitoFrente, 0);
  analogWrite(MotorDireitoTras, 0);
}

void mover(int a, int b){
  if (a>0){
    a=a*2.55;
    a=a+compensacao;
    analogWrite(MotorEsquerdoFrente,a);
    analogWrite(MotorEsquerdoTras,0);
  }
  else if(a==0){
    analogWrite(MotorEsquerdoFrente,0);
    analogWrite(MotorEsquerdoTras,0);
  }
  else{
    a=a*-2.55;
    analogWrite(MotorEsquerdoFrente,0);
    analogWrite(MotorEsquerdoTras,a);
  }
    if (b>0){
    b=b*2.55;
    
    analogWrite(MotorDireitoFrente,b);
    analogWrite(MotorDireitoTras,0);
  }
  else if(b==0){
    analogWrite(MotorDireitoFrente,0);
    analogWrite(MotorDireitoTras,0);
  }
  else{
    b=b*-2.55;
    analogWrite(MotorDireitoFrente,0);
    analogWrite(MotorDireitoTras,b);
  }  
};


void calibracao (boolean condition) {
  if(condition == true) {
    for (int i = 0; i < 15; i++){
        mover(forca_Curva * -1, forca_Curva);
        qtra.calibrate();       // reads all sensors 10 times at 2.5 ms per six sensors (i.e. ~25 ms per call)
    }
    for (int i = 0; i < 30; i++){
        mover(forca_Curva, forca_Curva * -1);
        qtra.calibrate();       // reads all sensors 10 times at 2.5 ms per six sensors (i.e. ~25 ms per call)
    }
    do{
      mover(forca_Curva * -1, forca_Curva);
    }while(lerQTR(4) <= branco);
    pararMotores();
  }/*
  for (int i = 0; i < 400; i++)  // make the calibration take about 10 seconds
  {
    qtra.calibrate();       // reads all sensors 10 times at 2.5 ms per six sensors (i.e. ~25 ms per call)
  }
  }*/
};







/*
float Andar(String motor_escolhido, int forca_escolhida) {
  
  int compensacao = 17.64;

  int forca = forca_escolhida * 2.55;
  
  if (motor_escolhido == "Esquerdo") { // verifica se o motor informado no parametro for Esquerdo

    if (forca_escolhida > 0) { // ele verifica se é positivo ou negativo
      analogWrite(MotorEsquerdoFrente, forca + compensacao); // motor esquerdo pra frente
      analogWrite(MotorEsquerdoTras, 0);
    } else {
      analogWrite(MotorEsquerdoFrente, 0);
      analogWrite(MotorEsquerdoTras, abs(forca) + compensacao); // se for um valor negativo ele vai para trás, só que não existe tensão negativa por isso multiplicado por -1
    }
    
  }

  if(motor_escolhido == "Direito") { // verifica se o motor informado no parametro for Direito

    if (forca_escolhida > 0) { // ele verifica se é positivo ou negativo
      analogWrite(MotorDireitoFrente, forca); // motor direito para frente
      analogWrite(MotorDireitoTras, 0);
    } else {
      analogWrite(MotorDireitoFrente, 0);
      analogWrite(MotorDireitoTras, abs(forca)); // se for um valor negativo ele vai para trás, só que não existe tensão negativa por isso multiplicado por -1
    }
    
  }

  if(motor_escolhido == "Ambos") { // verifica se o motor informado no parametro for Ambos

    if (forca_escolhida > 0) {
      analogWrite(MotorDireitoFrente, forca); // anda com os dois motores pra frente
      analogWrite(MotorEsquerdoFrente, forca + compensacao); // anda com os dois motores pra frente
      analogWrite(MotorDireitoTras, 0);
      analogWrite(MotorEsquerdoTras, 0);
      
    } else {
      
      analogWrite(MotorDireitoFrente, 0);
      analogWrite(MotorEsquerdoFrente, 0);
      analogWrite(MotorDireitoTras, abs(forca)); // se for um valor negativo ele vai para trás, só que não existe tensão negativa por isso multiplicado por -1
      analogWrite(MotorEsquerdoTras, abs(forca) + compensacao);// se for um valor negativo ele vai para trás, só que não existe tensão negativa por isso multiplicado por -1
      
    }
   
  }
  
}


float curva(String lado_da_curva, int forca_escolhida_curva) {

    if(lado_da_curva == "Esquerda") { // verifica se o motor informado no parametro for Direito
  
      if (forca_escolhida_curva > 0) { // ele verifica se é positivo ou negativo
        analogWrite(MotorDireitoFrente, forca_escolhida_curva); // motor direito para frente
        analogWrite(MotorEsquerdoTras, forca_escolhida_curva); // motor esquerdo tras
      } else {
        analogWrite(MotorDireitoFrente, forca_escolhida_curva * -1); // motor direito para frente
        analogWrite(MotorEsquerdoTras, forca_escolhida_curva * -1); // motor esquerdo tras
      }
      
    }

  
   if (lado_da_curva == "Direita") { // verifica se o motor informado no parametro for Esquerdo

    if (forca_escolhida_curva > 0) { // ele verifica se é positivo ou negativo
      analogWrite(MotorEsquerdoFrente, forca_escolhida_curva); // motor esquerdo pra frente
      analogWrite(MotorDireitoTras, forca_escolhida_curva); // motor direito para trás
    } else {
      analogWrite(MotorEsquerdoFrente, forca_escolhida_curva * -1); // motor esquerdo pra frente
      analogWrite(MotorDireitoTras, forca_escolhida_curva * -1); // motor direito para trás
    }
    
  }

}

*/


float AndarParaVerificar90graus(int lado_verificar_90graus) {

    if (lado_verificar_90graus == ESQUERDA) {
      pararMotores();
      delay(800);
      while(lerQTR(1) >= preto && lerQTR(2) >= preto) {
        mover(forca_Media, forca_Media);
      }
      pararMotores();
      delay(600); 
    } 

    if (lado_verificar_90graus == DIREITA) {
      pararMotores();
      delay(800);
      while(lerQTR(7) >= preto && lerQTR(8) >= preto) {
        mover(forca_Media, forca_Media);
      }
      pararMotores();
      delay(600);
    }
    
}

float VoltarParaLinha() {
    while(lerTodosQTR() == 7000 || lerTodosQTR() == 0) {
        mover(forca_Media * -1, forca_Media * -1);
    }
    delay(100);
    pararMotores();
}



int lastError = 0;

int PID (double kP, double kI, double kD, double tP, int media) {

      int erro = lerTodosQTR() - media;

      //int error = map(media, 0, 7000, -100, 100);

      int nova_media = 0;

      //int desaceleracao = map((error - nova_media), -100, 100, 1, 0);
      
      int P = kP * erro;
      int I = I + (erro * kI);
      int D = kD * (erro - lastError);
      
      int ganho = P+I+D;
      
      lastError = erro;
      
      double motorB = tP + ganho;
      double motorC = tP - ganho;

      mover(motorB, motorC);

      //Serial.println(analogRead(A15));

};


// AÇÃO SE ENCONTRAR O GAP
void Gap() {
  mover(forca_Curva, forca_Curva);
}

// AÇÃO SE ENCONTRAR ENCRUZILHADA
void Encruzilhada() {
  mover(forca_Normal, forca_Normal);
}

// AÇÃO SE ENCONTRAR VERDE
void Verde(int lado_verde) {

  if (lado_verde == ESQUERDA) {
      pararMotores();
      delay(600);
      mover(forca_Media+5, forca_Media);
      delay(800);
      pararMotores();
      delay(600);
      
      mover(forca_Media * -1, forca_Media);
      delay(1400);
      while(lerQTR(6) < branco) {
        mover(forca_Media * -1, forca_Media);
      }
      pararMotores();
      mover(forca_Media * -1, forca_Media * -1);
      delay(400);
      pararMotores();
      delay(600);
    
  }

  if (lado_verde == DIREITA) {
      pararMotores();
      delay(600);
      mover(forca_Media+5, forca_Media);
      delay(800);
      pararMotores();
      delay(600);
      
      mover(forca_Media, forca_Media  * -1);
      delay(1400);
      while(lerQTR(3) < branco) {
        mover(forca_Media, forca_Media * -1);
      }
      pararMotores();
      mover(forca_Media * -1, forca_Media * -1);
      delay(400);
      pararMotores();
      delay(600);
         
  }
  
}



void Obstaculo () {
  pararMotores();
  delay(600);

  mover((forca_Obstaculo+5) * -1, forca_Obstaculo * -1);
  delay(300);
  pararMotores();
  delay(600);
  
  mover((forca_Curva_Obstaculo+5) * -1, forca_Curva_Obstaculo);
  delay(1500);

  pararMotores();
  delay(600);

  mover((forca_Obstaculo+10), forca_Obstaculo);
  delay(2500);

  pararMotores();
  delay(600);

  mover(forca_Curva, forca_Curva * -1);
  delay(800);

  while(lerSharp(3) < 450 || lerSharp(3) > 550) {
    mover(forca_Media+2, forca_Media);
  }
  
  while(lerSharp(3) > 350) {
    mover(forca_Media+2, forca_Media);
  }
  pararMotores();
  delay(600);

  mover(forca_Media, forca_Media);
  delay(2600);
  pararMotores();
  delay(600);
  mover(forca_Media, forca_Media * -1);
  delay(1700);
  while(lerTodosQTR() == 7000 || lerTodosQTR() == 0) {
    mover(forca_Media, forca_Media);
  }
  delay(600);
  pararMotores();
  delay(600);
  mover(forca_Media * -1, forca_Media);
  delay(1700);
  /*
  while(lerQTR(8) <= branco && lerQTR(7) <= branco){
    mover(forca_Media * -1, forca_Media * -1);
  }
  while(lerQTR(1) <= branco || lerQTR(2) <= branco || lerQTR(3) <= branco || lerQTR(4) <= branco || lerQTR(5) <= branco || lerQTR(6) <= branco || lerQTR(7) <= branco  || lerQTR(8) <= branco) {
    mover(forca_Media * -1, 0);
  }
  delay(100);
  
  pararMotores();
  delay(600);

  mover(forca_Media+2, forca_Media);
  delay(2800);
  pararMotores();
  delay(800);
  mover(forca_Media, forca_Media * -1);
  delay(1550);
  pararMotores();
  delay(600);
  while(lerSharp(3) < 450 || lerSharp(3) > 550) {
    mover(forca_Media+2, forca_Media);
  }
  
  while(lerSharp(3) > 350) {
    mover(forca_Media+2, forca_Media);
  }
  pararMotores();
  delay(600);
  mover(forca_Media+5, forca_Media);
  delay(1900);
  pararMotores();
  delay(600);
  mover(forca_Media, forca_Media * -1);
  delay(1500);
  while(lerTodosQTR() == 7000 || lerTodosQTR() == 0) {
    mover(forca_Media+2, forca_Media);
  }
  delay(200);
  mover(forca_Media * -1, forca_Media);
  delay(1800);

  */
}



