// C++ code


#include <Servo.h>

#define BUFFER_SIZE 8 // Tamaño del búfer para almacenar el mensaje

char receivedMessage[BUFFER_SIZE]; // Búfer para almacenar el mensaje recibido
int messageIndex = 0; // Índice para rastrear la posición actual en el búfer
int buzzer = 7;
// Definir los objetos servo para los dos servomotores
Servo servo1;
Servo servo2;

// Pines a los que están conectados los servomotores
int pinServo1 = 10;
int pinServo2 = 11;
int numericValue;

void setup() {
  Serial.begin(9600); // Iniciar comunicación serial a 9600 bps
 servo1.attach(pinServo1);
  servo1.write(0);
  servo2.attach(pinServo2);
  servo2.write(0);
  pinMode(buzzer,OUTPUT);
  
}

void loop() {
  // Si hay datos disponibles en el puerto serial
  while (Serial.available() > 0) {
    char receivedChar = Serial.read(); // Leer el carácter recibido
    
    // Verificar si se ha recibido el carácter de finalización
    if (receivedChar == '\n' || messageIndex >= BUFFER_SIZE - 1) {
      // Agregar el carácter nulo al final del mensaje
      receivedMessage[messageIndex] = '\0';
      
      // Imprimir el mensaje recibido
      Serial.print("Mensaje recibido: ");
      Serial.println(receivedMessage);
      
      char tipo = receivedMessage[0];
      Serial.println(tipo);
      
      receivedMessage[0] = '0';
      numericValue = atoi(receivedMessage); // Convertir la cadena en un valor numérico entero

      Serial.println(numericValue);
      
      
      if (tipo == 'B'){
       
        //servos
         if (numericValue == 0){
          servo1.write(45); // Angulo de 90 grados
         
  
         
        }if (numericValue == 1){
          servo1.write(90);
          
         }if (numericValue == 3){
          
           servo1.write(135);
         }if (numericValue == 5){
          
         servo1.write(180);
         }
        
        
      }else if(tipo == 'T'){
        
 if (numericValue <= 34){
    Serial.println("menos de 34"); 
    servo2.write (45);
    digitalWrite(buzzer, HIGH); 
    delay(500);
    digitalWrite(buzzer, LOW);   

      }if (numericValue >=35 & numericValue <= 38){
   Serial.println("normalito normalito");
   servo2.write (135);
    digitalWrite(buzzer, LOW);     

          }if (numericValue >= 39){
    servo2.write (180);
   
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
      
      }
      break;
        
        
      }else if (tipo == 'P'){

         if (numericValue <= 60){
    servo2.write (45);
     digitalWrite(buzzer, HIGH); 
    delay(500);
    digitalWrite(buzzer, LOW);   

      }if (numericValue >=61 & numericValue <= 100){
    servo2.write (135);
    digitalWrite(buzzer, LOW);          
        Serial.println("alarmas");

          }if (numericValue >= 101){
    servo2.write (180);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
      
      }
      break;
      
      }else if (tipo == 'O'){
         if (numericValue <= 95){
    servo2.write (45);
    digitalWrite(buzzer, HIGH); 
    delay(500);
    digitalWrite(buzzer, LOW);   

      }if (numericValue >=96 & numericValue <= 98){
    servo2.write (135);
    digitalWrite(buzzer, LOW);          
        Serial.println("alarmas");

          }if (numericValue >= 99){
    servo2.write (180);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
      
      }
      break;
        
      }
      
      
      // Reiniciar el índice y búfer del mensaje
      messageIndex = 0;
      memset(receivedMessage, 0, sizeof(receivedMessage));
    } else {
      // Almacenar el carácter en el búfer del mensaje
      receivedMessage[messageIndex++] = receivedChar;
    }
  }
  


  
}