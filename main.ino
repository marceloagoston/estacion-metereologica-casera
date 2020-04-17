const long A = 1000;     //Resistencia en oscuridad en KΩ
const int B = 15;        //Resistencia a la luz (10 Lux) en KΩ
const int Rc = 10;       //Resistencia calibracion en KΩ
const int LDRPin = A0;   //Pin del LDR	
const int ledPIN = 13;    // Pin 13
 
int V;
int ilum;
 
void setup() 
{
   Serial.begin(115200);
  pinMode(ledPIN , OUTPUT);  //definir pin como salida
}
 
void loop()
{
   V = analogRead(LDRPin);         
 
   //ilum = ((long)(1024-V)*A*10)/((long)B*Rc*V);  //usar si LDR entre GND y A0 
   ilum = ((long)V*A*10)/((long)B*Rc*(1024-V));    //usar si LDR entre A0 y Vcc (como en el esquema anterior)
  if(ilum<60){
  	Serial.println("Led Prendido");
    digitalWrite(ledPIN , HIGH);
  } else {
  	Serial.println("Led Apagado");
    digitalWrite(ledPIN , LOW);
  }
   Serial.println(ilum);   
   delay(1000);
}