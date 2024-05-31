// primero se ponen las librerías que vas a utilizar 

#include <LiquidCrystal_I2C.h>

// RENAP, declaración de mis hijos (variables)

//analógico
int pot = A0;
int temp = A1;
int oxi = A2;
int pul = A3;


// digital 
int menu = 6;
int contador = 0;
int edad = 0;
int valorPot;
int bandera = 0;
int valoredad = 0;
int Temperatura = 0;
int nuevopulso;
int oximetro = 0;
int valorTemperatura = 0;
int valorPulso = 0;
int pulso = 0;
int valorOxigenacion = 0;

int temporaledad = 0;
int temporaloxigeno = 0;


LiquidCrystal_I2C lcd (0x27,16,2); //RENAP de mi LCD

//void setup es cuando a mis variables les asigno la carrera y su propósito en la vida
void setup()
{
lcd.init();
lcd.backlight();
Serial.begin(9600);

 pinMode(pot,INPUT);
 pinMode(pul, INPUT);
 pinMode(menu,INPUT_PULLUP); //configuracion interna 
 pinMode(temp,INPUT);
 pinMode(oxi,INPUT);

  
  //lcd.begin(16, 2); // Set up the number of columns and rows on the LCD.

}

void loop() 
{
    //lcd.clear();

  
  //lee el valor en analogRead, mapea en valorPot y lo guarda en edad (edad es un hijo)
  valorPot = analogRead(pot);
  edad = map(valorPot,0,1023,1,100);

  //lee el valor en analogRead, mapea en temporalTemp y lo guarda en temperatura (edad es un hijo)
  int temporaltemp = analogRead(temp);
  Temperatura = map(temporaltemp,20,358,15,40); //apuntar valor de tarea aqui 

    //lee el valor en analogRead, mapea en valorPot y lo guarda en pulso (pulso es un hijo)
  int temporalPulso = analogRead(pul);
  pulso = map(temporalPulso,0,1023,1,200);

  
  //lee el valor en analogRead, mapea en temporalOxi y lo guarda en oxigenación (edad es un hijo)
  int temporaloxi = analogRead(oxi);
  oximetro = map(temporaloxi,0,560,0,100);
  
  //cambiar opciones del menu
   if(digitalRead(menu)==LOW){ //cuando apacho cambia el valor de la bandera para hacer otras cosas en el menu
     bandera++; 
     lcd.clear();
     delay(200);
  }
  
  //es para que cambie en el menu
    switch(bandera){
    
    //si no apacho el boton, bandera es 0 y está en edad 
    case 0:
    
    //lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Menu");
    lcd.setCursor(0,1);
    lcd.print("Edad?"); 
      if (temporaledad != edad){
	    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Menu");
    lcd.setCursor(0,1);
    lcd.print("Edad?"); 

  	lcd.setCursor(7,1); 
      
      temporaledad=edad;
      lcd.print(edad);

    }
  //lcd.print(edad);
          Serial.print("B");
      Serial.println(bandera);


    valoredad = edad;
    

    //Serial.println(valorPot);
    
    delay(500);
    break;
    
    case 1:


    lcd.setCursor(0,0);
    lcd.print("Menu");
    lcd.setCursor(0,1);
    lcd.print("Temperatura:"); 
    lcd.setCursor(12,1);
    lcd.print(Temperatura); 

    valorTemperatura = Temperatura; //se queda grabada la temperatura
     //Serial.println(temporaltemp);
     Serial.print("B");
     Serial.println(bandera);

    delay(500);
  	
    break;
      
    case 2:
  	  //delay(1000); // Esperar 1 segundo
    lcd.setCursor(0,0);
    lcd.print("Menu");
    lcd.setCursor(0,1);
    lcd.print("Temperatura:"); 
    lcd.setCursor(12,1);
    lcd.print(valorTemperatura); 
         Serial.print("T");
      Serial.println(valorTemperatura);


      break;
      
      
    
    case 3:
      
    
    lcd.setCursor(0,0);
    lcd.print("Menu");
    lcd.setCursor(0,1);
    lcd.print("Pulso");
      
            Serial.print("B");
      Serial.println(bandera);

      
    if (temporalPulso != pulso){
	    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Menu");
    lcd.setCursor(0,1);
    lcd.print("Pulso");
    
    lcd.setCursor(12,1);

    
    temporalPulso = pulso;
    lcd.print(pulso);
    }
    lcd.setCursor(12,1);
    lcd.print(pulso);
        valorPulso = pulso;

  	//delay(500);
    break;
    
    
    case 4:
      
          lcd.setCursor(0,0);
    lcd.print("Menu");
    lcd.setCursor(0,1);
    lcd.print("Pulso"); 
	  lcd.setCursor(7,1);
    lcd.print(valorPulso);
            Serial.print("P");
      Serial.println(valorPulso);


      
      break;
      
      
    case 5:

    lcd.setCursor(0,0);
    lcd.print("Menu");
    lcd.setCursor(0,1);
    lcd.print("Oxigenacion");
      
            Serial.print("B");
      Serial.println(bandera);

      
    if (temporaloxigeno != oximetro){
	    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Menu");
    lcd.setCursor(0,1);
    lcd.print("Oxigenacion");
    
    lcd.setCursor(12,1);

    
    temporaloxigeno = oximetro;
    lcd.print(oximetro);
    }
    lcd.setCursor(12,1);
    lcd.print(oximetro);
    
    valorOxigenacion = oximetro;
    //Serial.println(temporaloxi);

  	//   delay(500);
    break;
      
      case 6:
      
            lcd.setCursor(0,0);
    lcd.print("Menu");
    lcd.setCursor(0,1);
    lcd.print("Oxigenacion");
       lcd.setCursor(12,1);
    lcd.print(valorOxigenacion);
      
            Serial.print("O");
      Serial.println(valorOxigenacion);
 
      break;
      
    
    //regresa a la primera opcion del menu
    case 7:
    bandera = 0;
      Serial.print("B");
      Serial.println(bandera);

    break;
    
  }
  
}

