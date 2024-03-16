//Developer:Diana Rosero
/* Script description:
Turn led on with Arduino and c++
*/

// Definir los pines para las luces
const int ledVerde = 11;
const int ledRojo = 12;
const int ledAmarillo = 13;

// Variables para almacenar el estado de los LEDs
bool estadoVerde = false;
bool estadoRojo = false;
bool estadoAmarillo = false;

void setup() {
  // Configurar los pines de las luces como salidas
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);

  // Iniciar la comunicación serial
  Serial.begin(9600);
  Serial.println("Ingrese un numero para controlar las luces:");
  Serial.println("1. Encender/Apagar luz verde");
  Serial.println("2. Encender/Apagar luz roja");
  Serial.println("3. Encender/Apagar luz amarilla");
  Serial.println("4. Encender/Apagar todas las luces");
  Serial.println("5. Modo intermitente");  
}

void loop() {
  // Verificar si hay datos disponibles en el puerto serial
  if (Serial.available() > 0) {
    int opcion = Serial.read() - '0'; // Leer el número ingresado

    switch (opcion) {
      case 1:
        estadoVerde = !estadoVerde; // Cambiar el estado de la luz verde
        digitalWrite(ledVerde, estadoVerde);
        Serial.print("Luz verde ");
        Serial.println(estadoVerde ? "encendida" : "apagada");
        break;
      case 2:
        estadoRojo = !estadoRojo; // Cambiar el estado de la luz roja
        digitalWrite(ledRojo, estadoRojo);
        Serial.print("Luz roja ");
        Serial.println(estadoRojo ? "encendida" : "apagada");
        break;
      case 3:
        estadoAmarillo = !estadoAmarillo; // Cambiar el estado de la luz amarilla
        digitalWrite(ledAmarillo, estadoAmarillo);
        Serial.print("Luz amarilla ");
        Serial.println(estadoAmarillo ? "encendida" : "apagada");
        break;
      case 4:
      	// Si todos los bombillos están apagados, encenderlos
		// Si alguno está encendido, apagarlos todos
		if (!estadoVerde && !estadoRojo && !estadoAmarillo) {
		// Encender todos los bombillos
		estadoVerde = HIGH;
		estadoRojo = HIGH;
		estadoAmarillo = HIGH;
		digitalWrite(ledVerde, estadoVerde);
		digitalWrite(ledRojo, estadoRojo);
		digitalWrite(ledAmarillo, estadoAmarillo);
		Serial.println("Todos los bombillos encendidos");
		} else {
		// Apagar todos los bombillos
		estadoVerde = LOW;
		estadoRojo = LOW;
		estadoAmarillo = LOW;
		digitalWrite(ledVerde, estadoVerde);
		digitalWrite(ledRojo, estadoRojo);
		digitalWrite(ledAmarillo, estadoAmarillo);
		Serial.println("Todos los bombillos apagados");
		}
		break;
      
      case 5:
        modoIntermitente();
        break;
      default:
        Serial.println("Opcion invalida");
        break;
    }
  }
}

void modoIntermitente() {
  Serial.println("Modo intermitente activado");
  while (true) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledAmarillo, HIGH);
    delay(500);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledAmarillo, LOW);
    delay(500);
    
    // Verificar si se ingresa otro número para salir del modo intermitente
    if (Serial.available() > 0) {
      int opcion = Serial.read();
      if (opcion != '\n') {
        break;
      }
    }
  }
  	digitalWrite(ledVerde, LOW);
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledAmarillo, LOW);
}




