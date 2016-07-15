#include <Arduino.h>

/*
  ROBOT GENERAL CONFIGURATION
*/

/************************ MOTORES ************************/
// Motores: Pololu 75:1 Metal Gearmotor 25Dx54L mm MP 12V 2.1A
// Motor ESQUERDO
#define MotorEsquerdoFrente 8
#define MotorEsquerdoTras 9

// Motor DIREITO
#define MotorDireitoFrente 11
#define MotorDireitoTras 10

float ligarMotores() {
    // MOTOR ESQUERDO
  pinMode(MotorEsquerdoFrente, OUTPUT);
  pinMode(MotorEsquerdoTras, OUTPUT);


  // MOTOR DIREITO
  pinMode(MotorDireitoFrente, OUTPUT);
  pinMode(MotorDireitoTras, OUTPUT);

}


/************************ SENSORES ************************/
// Sensores: Pololu QTR-8A reflectance sensor, Sharp 4-30cm e Divisor de Tensão
// PORTAS ANÁLOGICAS

// SENSORES ARRAY QTR-8-A
#define sensor_linha1     A0 // SENSOR Esquerda
#define sensor_linha2     A1
#define sensor_linha3     A2
#define sensor_linha4     A3
#define sensor_linha5     A4
#define sensor_linha6     A5
#define sensor_linha7     A6
#define sensor_linha8     A7 // SENSOR Direita
#define sensor_linha9     A12 // SENSOR Direita
#define sensor_linha10     A15 // SENSOR Direita

int Sensores_Array[] = {
  0,
  sensor_linha1,
  sensor_linha2,
  sensor_linha3,
  sensor_linha4,
  sensor_linha5,
  sensor_linha6,
  sensor_linha7,
  sensor_linha8,
  sensor_linha9,
  sensor_linha10,
};

#define NUM_SENSORS             8  // number of sensors used


// SENSORES SHARP
#define sensor_sharp1     A10 // SENSOR DA FRENTE CIMA
#define sensor_sharp2     A9 // SENSOR DA FRENTE BAIXO
#define sensor_sharp3     A8 // SENSOR DA FRENTE ESQUERDA
#define sensor_sharp4     A11 // SENSOR DA FRENTE DIREITA

int Sensores_Sharp[] {
  0,
  sensor_sharp1,
  sensor_sharp2,
  sensor_sharp3,
  sensor_sharp4
};

// Tensão Bateria
#define sensor_bateria    A12 // SENSOR DE TENSÃO DA BATERIA
#define VOLTAGE_LOW   11.1 // Tensão mínima
#define VOLTAGE_HIGH  12.1 // Tensão maxima


/************************ SERVOS ************************/
// SERVO MOTORES PARA A GARRA - 180 graus - Servo 9g
// PORTAS PWM
#define servo_esquerdo 6 // PORTA PWM
#define servo_direito 7 // PORTA PWM
/*
  Servo myservo;
  Servo myservo2;

  myservo.attach(servo_esquerdo);
  myservo2.attach(servo_direito);

  void ligarServos(int forca_servo) {
    myservo.write(forca_servo);
    myservo2.write(forca_servo);
  };
  */
/************************ BOTÕES ************************/
// Botões para iniciar ações 
// PORTAS DIGITAIS
#define btn1 43 // LED Robô ligado
#define btn2 44 // LED Tensão bateria
#define btn3 45 // LED Teste do robô
#define btn4 47 // LED Calibração

#define btn5 42 // LED Calibração

int Botoes[] {
  0,
  btn1,
  btn2,
  btn3,
  btn4,
  btn5
};

/************************ LEDS ************************/
// LEDs para identificação de ações 
// PORTAS DIGITAIS
#define led1  30 // LED Robô ligado
#define led2  32 // LED Tensão bateria - correto
#define led3  33 // LED Teste do robô - correto
#define led4  31 // LED Calibração - correto
#define led5  34 // LED Salão principal - correto
#define led6  35 // LED Resgate - correto

int LEDS[] {
  0,
  led1,
  led2,
  led3,
  led4,
  led5,
  led6
};

/************************ ESTADOS *********************/
#define ESQUERDA -1
#define DIREITA   1
#define ST_PRINCIPAL 2
#define ST_RAMPA     4


/************************ VARIÁVEIS DO ROBÔ ************************/
int situacao;
int compensacao = 10;
int forca_Baixa = 23.5; // forca baixa para andar distâncias pequenas
int forca_Obstaculo = 25; // forca baixa para andar distâncias pequenas
int forca_Curva_Obstaculo = 35; // forca baixa para andar distâncias pequenas
int forca_Media = 31.3;
int forca_Normal = 48; // Força normal para seguir linha
int forca_Rampa = 50; // Força para rampa

int forca_Curva = 55;

//float KP = 0.03; // Constante do Proporcional
float KP = 0.04; // Constante do Proporcional
float KI = 0.1;
float KD = 0.7; // Constante do Proporcional
//float KD = 0.5; // Constante do Proporcional


int branco = 100; // Força normal para seguir linha
int preto = 650; // Força para rampa


int offset = ((branco + preto) / 2); // media seguidor

int setPoint = 3500;


