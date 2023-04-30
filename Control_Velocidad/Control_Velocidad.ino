#include <Servo.h>

Servo miServo; // Objeto de la clase Servo
int potPin = A0; // define el pin del potenciómetro
int motorPin = 3; // define el pin del servo
int speed;  // variable para almacenar la velocidad

void setup() {
  Serial.begin(9600);
  miServo.attach(motorPin); // se utiliza el pin digital 3
  miServo.write(0); // el servo comienza en 0 grados
}

void moverIzquierda() {
  miServo.write(180); // se establece el ángulo en 180 grados
  Serial.println("Moviendo a la IZQUIERDA");
}

void moverDerecha() {
  miServo.write(0); // se establece el ángulo en 0 grados
  Serial.println("Moviendo a la DERECHA");
}

void readSpeed() {
  speed = analogRead(potPin); // lee el valor del potenciómetro
  speed = map(speed, 0, 1023, 0, 180); // convierte el valor leído a un rango de 0 a 180 grados
}

void sendSpeed() {
  miServo.write(speed); // envía la velocidad al servo
  delay(15); // espera un breve lapso de tiempo antes de continuar
}

void loop() {
  if (Serial.available() > 0) {
    char entrada = Serial.read();
    if (entrada == 'I') { // si se recibe "I"
      moverIzquierda();
    } else if (entrada == 'D') { // si se recibe "D"
      moverDerecha();
    }
  } else {
    readSpeed(); // lee el valor del potenciómetro y convierte el valor leído a un rango de 0 a 180 grados
    sendSpeed(); // envía la velocidad al servo
  }
}


