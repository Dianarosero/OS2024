//Developer:Diana Rosero
/* Script description:
Temperature 1
*/

int ledPin = 13;
int motorPin = 12;
int sensorPin = A0;
float temperature = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Lee el valor del sensor de temperatura
  int sensorValue = analogRead(sensorPin);
  Serial.print("sensorValue: ");
  Serial.println(sensorValue);

  // Convierte el valor del sensor a temperatura en grados Celsius
  temperature = 50.0;

  Serial.print("Temperature (C): ");
  Serial.println(temperature);

 // Controla el LED y el motor en función de la temperatura
  if (temperature <= 5.0) { // Cambié < a <= para incluir exactamente 5.0
    // Temperatura igual o inferior a 5 °C: Enciende el LED en intermitencia y el motor
    digitalWrite(ledPin, HIGH);
    Serial.println("LED encendido"); // Mensaje de depuración
    digitalWrite(motorPin, HIGH);
    delay(500);  // Encendido durante 0.5 segundos
    digitalWrite(ledPin, LOW);
    digitalWrite(motorPin, LOW);
    delay(500);  // Apagado durante 0.5 segundos
  } else if (temperature > 5.0 && temperature <= 25.0) { // Asegurarse de excluir 5.0 de esta condición
    // Temperatura entre 6 °C y 25 °C: Apaga el LED y el motor
    digitalWrite(ledPin, LOW);
    digitalWrite(motorPin, LOW);
  } else {
    // Temperatura mayor a 25 °C: Enciende el LED y el motor
    digitalWrite(ledPin, HIGH);
    Serial.println("LED encendido"); // Mensaje de depuración
    digitalWrite(motorPin, HIGH);
  }
  delay(2000);
}
