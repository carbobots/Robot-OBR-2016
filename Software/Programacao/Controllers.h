#include <Arduino.h>
#include <QTRSensors.h>
/*
  FUNÇÕES de Controles DO ROBÔ
*/

// CONTROLE DE SEGUIDOR DE LINHA DO SALÃO PRINCIPAL E RAMPA
void SeguidorLinha (boolean condicao, int situacao){
  if (condicao == true) {
    
    // SE FOR A RAMPA
    if(situacao == ST_RAMPA) {

      PID(KP, 0, 0, forca_Rampa, setPoint);
      if(verificaGap() == true){
        Gap();
      }
    }
    
    // SE FOR O SALÃO PRINCIPAL
    if (situacao == ST_PRINCIPAL){
      
        // SEGUIDOR DE LINHA P.I.D.
        PID(KP, KI, KD, forca_Normal, setPoint);

        // SE VERIFICAR GAP, ELE EXECUTA A FUNÇÃO
        if(verificaGap() == true){
          Gap();
        } 
        
        if(verificaVerde(ESQUERDA) == true){
          Verde(ESQUERDA);
        }
 
        if(verificaVerde(DIREITA) == true){
          Verde(DIREITA);
        }
        
        if(verificaEncruzilhada() == true) {
          Encruzilhada();
        }
        
        if(verificaObstaculo() == true) {
          Obstaculo();    
        }
      
       if (verifica90graus() == DIREITA) {
            
            // AÇÃO SE ENCONTRAR A 90 GRAUS DIREITA

            AndarParaVerificar90graus(DIREITA); // anda até todos os sensores dos extremos serem brancos
            if (lerTodosQTR() == 7000 || lerTodosQTR() == 0) { // compara se todos os sensores são brancos
                VoltarParaLinha(); // se forem brancos, ele anda para atrás até não serem mais brancos
                delay(600);
                mover(forca_Curva, forca_Curva * -1);
                delay(500);
                /*mover(forca_Curva, 0);
                delay(1900);
                pararMotores();
                delay(600);
                mover((forca_Normal + 5) * -1, forca_Normal * -1);
                delay(1300);
                pararMotores();
                delay(600);*/
            }
    
        }
        
      if (verifica90graus() == ESQUERDA) {
        
            // AÇÃO SE ENCONTRAR A 90 GRAUS ESQUERDA
            
            AndarParaVerificar90graus(ESQUERDA); // anda até todos os sensores dos extremos serem brancos
            if (lerTodosQTR() == 7000 || lerTodosQTR() == 0) { // compara se todos os sensores são brancos
                //VoltarParaLinha(); // se forem brancos, ele anda para atrás até não serem mais brancos
                //delay(600);
                mover(forca_Media, forca_Media);
                delay(300);
                mover(forca_Curva * -1, forca_Curva);
                delay(700);
                /*mover(0, forca_Curva);
                delay(1600);
                pararMotores();
                delay(600);
                mover((forca_Normal + 5) * -1, forca_Normal * -1);
                delay(1300);
                pararMotores();
                delay(600);*/
            }
      }
     

      
      

    }
  }
}

void Resgate() {
  while(verificaGap() == false) {
    mover(forca_Media, forca_Media);
  }
  pararMotores();
  delay(600);
  mover(-30, 30);
}
