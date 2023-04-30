#include <Servo.h>

Servo miServo;
int angulo = 0;

void setup() {
  Serial.begin(9600);
  miServo.attach(3); // se utiliza el pin digital 3
  miServo.write(angulo); // el servo comienza en 0 grados
}

void moverIzquierda() {
  angulo = 180; // se establece el ángulo en 180 grados
  miServo.write(angulo); // se mueve el servo
  Serial.println("Moviendo a la IZQUIERDA");
}

void moverDerecha() {
  angulo = 0; // se establece el ángulo en 0 grados
  miServo.write(angulo); // se mueve el servo
  Serial.println("Moviendo a la DERECHA");
}

void loop() {
  if (Serial.available() > 0) {
    char entrada = Serial.read();
    if (entrada == 'I') { // si se recibe "I"
      moverIzquierda();
    } else if (entrada == 'D') { // si se recibe "D"
      moverDerecha();
    }
  }
}



