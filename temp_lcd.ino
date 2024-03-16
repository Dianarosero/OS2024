/*
Developer:Diana Rosero
Script description:
Temperature_lcd
*/

#include <LiquidCrystal.h>

int seconds = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pines del sensor TMP36, LED y motor
const int tmpSensorPin = A0;
const int ledPin = 6;
const int motorPin = 7;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Temperatura:"); // Mostrar un mensaje inicial en la pantalla LCD
  lcd.setCursor(0, 1); // Mover el cursor a la segunda línea
  lcd.print("Inicializando...");
  delay(2000); // Esperar 2 segundos
  lcd.clear(); // Limpiar la pantalla LCD
}

void loop() {
    // Leer el valor del sensor TMP36
    int sensorValue = analogRead(tmpSensorPin);

    // Convertir el valor analógico a temperatura (suponiendo una resolución de 10 mV/°C)
    float voltage = sensorValue * (5.0 / 1023.0);
    float temperatureC = (voltage - 0.5) * 100.0; // Temperatura en °C

    // Mostrar la temperatura en el monitor serial
    Serial.print("Temperatura: ");
    Serial.print(temperatureC);
    Serial.println(" °C");

    // Mostrar la temperatura en la pantalla LCD
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperatureC, 1); // Imprimir la temperatura con 1 decimal

    // Validaciones según la temperatura
    if (temperatureC <= 10.0) {
        // Temperatura menor o igual a 10 °C
        intermitenciaLED(0.5);
        digitalWrite(motorPin, LOW);
    } else if (temperatureC >= 11.0 && temperatureC <= 25.0) {
        // Temperatura entre 11 °C y 25 °C
        digitalWrite(ledPin, LOW);
        digitalWrite(motorPin, LOW);
    } else {
        // Temperatura mayor o igual a 26 °C
        digitalWrite(ledPin, HIGH);
        digitalWrite(motorPin, HIGH);
    }

    delay(1000); // Esperar un segundo antes de la próxima lectura
}


void intermitenciaLED(float retardo) {
 digitalWrite(ledPin, HIGH);
 delay(retardo * 1000);
 digitalWrite(ledPin, LOW);
 delay(retardo * 1000);
}
