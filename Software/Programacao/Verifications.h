#include <Arduino.h>

/*
  FUNÇÕES DE VERIFICAÇÃO DO ROBÔ
*/

boolean verificaEncruzilhada() {
  if(lerQTR(1) >= preto && lerQTR(2) >= preto && lerQTR(3) >= preto && lerQTR(5) >= preto && lerQTR(7) >= preto && lerQTR(8) >= preto) {
    return true;
  } else {
    return false;
  }
}

boolean verificaGap() {
  if(lerQTR(1) <= branco && lerQTR(2) <= branco && lerQTR(3) <= branco && lerQTR(5) <= branco && lerQTR(7) <= branco && lerQTR(8) <= branco){
  //if(lerTodosQTR() == 7000 || lerTodosQTR() == 0){
    return true;
  } else {
    return false;
  }
}
boolean verificaVerde(int lado){

  // para verificar se realmente é verde
    int sensores_verde_esquerda = ((lerQTR(2) + lerQTR(3)) / 2);

    int sensores_meio = ((lerQTR(4) + lerQTR(5)) / 2);

    int sensores_verde_direita = ((lerQTR(6) + lerQTR(7)) / 2);

    int sensores_esquerda = lerQTR(1) + lerQTR(2) + lerQTR(3) + lerQTR(4);

    int sensores_direita = lerQTR(5) + lerQTR(6) + lerQTR(7) + lerQTR(8);

    int quase_todos_sensores = lerQTR(1) + lerQTR(2) + lerQTR(3) + lerQTR(4) + lerQTR(5) + lerQTR(6);
    
    int todos_sensores = lerQTR(1) + lerQTR(2) + lerQTR(3) + lerQTR(4) + lerQTR(5) + lerQTR(6) + lerQTR(7) + lerQTR(8);

    int sensores_extremo_esquerda = lerQTR(1) + lerQTR(2) + lerQTR(3);

    int sensores_extremo_direita = lerQTR(7) + lerQTR(8);
    
    if (lado == ESQUERDA) {


      if(lerQTR(9) < 500 && lerQTR(10) > 800 && lerQTR(1) > preto && lerQTR(2) > preto && lerQTR(3) > preto /*&& lerTodosQTR() > 3000 && lerTodosQTR() < 5000 && sensores_esquerda < 2500 && quase_todos_sensores < 3800 && todos_sensores < 5200*/) {       
          return true;
          } else {
            return false;
          }
   
    }
    
    if (lado == DIREITA) {

     if(lerQTR(10) < 600 && lerQTR(9) > 700 && lerQTR(6) > preto && lerQTR(7) > preto && lerQTR(8) > preto/*&& lerTodosQTR() > 3000 && lerTodosQTR() < 5000 && sensores_direita < 2500 && quase_todos_sensores < 3800 && todos_sensores < 5200*/) {       
          return true;
   
        
      } else {
          return false;
        }
        
    }
  
}

boolean verificaObstaculo() {

  if(lerSharp(1) > 480 && lerSharp(1) < 550) {
    return true;
  } else {
    return false;
  }
  
}

boolean verificaRampa() {
  if(lerSharp(2) > 200 && lerSharp(2) < 550 && lerSharp(3) > 200 && lerSharp(3) < 550) {
    return true;
  } else {
    return false;
  }
}

boolean verificaResgate() {
  if(sensorValues[0] > branco && sensorValues[1] > branco && sensorValues[2] > branco && sensorValues[3] > branco && sensorValues[4] > branco && sensorValues[5] > branco && sensorValues[6] > branco && sensorValues[7] > branco){ 
    return true;
  } else {
    return false;
  }
  
}


int verifica90graus() {
  if (lerQTR(1) >= preto && lerQTR(2) >= preto && lerQTR(3) >= preto && lerQTR(7) <= branco && lerQTR(8) <= branco) {
    return ESQUERDA;
  } else if (lerQTR(6) >= preto && lerQTR(7) >= preto && lerQTR(8) >= preto && lerQTR(1) <= branco && lerQTR(2) <= branco){
    return DIREITA;    
  } else {
    return 0;
  }
}

