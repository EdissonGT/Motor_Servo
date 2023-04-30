#include <Servo.h>

Servo servoMotor;
int angulo = 0;

void setup() {
  // Inicializar comunicación serial a 9600 baudios
  Serial.begin(9600);
  
  // Conectar el servo motor al pin 3
  servoMotor.attach(3);
}

void loop() {
  // Leer el ángulo ingresado por el usuario desde el monitor serial
  if (Serial.available() > 0) {
    angulo = Serial.parseInt();
  }
  
  // Mover el servo motor al ángulo especificado
  if (angulo == 90) {
    servoMotor.write(90);
    Serial.println("El servo motor se movió a 90 grados");
  }
  else if (angulo == 180) {
    servoMotor.write(180);
    Serial.println("El servo motor se movió a 180 grados");
  }
}


