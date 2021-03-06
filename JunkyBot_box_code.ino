/* Licenced by pineapplem3 Inc. This program is used for junkybot any reproduction of this code is strictly prohibited.
    compiled and developed by : Nirmal Ram

*/

#include <Servo.h>
Servo servo1;  // any name can be choosen in case of " myservo"
Servo servo2;
int internallimit = 12 , externallimit = 5;
void setup() {
  pinMode(12, OUTPUT);    // buzzer alert
  pinMode(6, OUTPUT);     // Redlight
  pinMode(7, OUTPUT);     //greenlight
  pinMode(5, OUTPUT);     //bluelight
  pinMode(3, OUTPUT);      // triggger is output of external sensor
  pinMode(4, INPUT);           // echo is input of external sensor
  pinMode(8, OUTPUT);      // triggger is output of internal sensor
  pinMode(9, INPUT);           // echo is input of internal sensor
  servo1.attach(10);
  servo2.attach(2);
  Serial.begin(9600);
  
}

void servoup()
{
  servo1.write(45);    // initial down stage
  servo2.write(65);  //initial down stage
  Serial.println("\n\n Access Granted . Pickup your items from cart . Happy shopping !");
}
void servodown()
{
  servo1.write(110);  //fixed up stage
  servo2.write(0);     //fixed up stage
  Serial.println("\n\n The Door is Locked . Scan QRcode to Proceed . ");

}
void internalsensor()
{
  delay(1000);
  digitalWrite(8, LOW);
  delayMicroseconds(2);
  digitalWrite(8, HIGH);
  delayMicroseconds(5);               // will send waves of 2 ms low wave & 5 ms high wave
  long x1 = pulseIn(9, HIGH);
  int internalsensor = x1 / (29 * 2);
  Serial.print(" \nInternal sensor detected = ");
  Serial.println(internalsensor);

}
void externalsensor()
{
  //delay(1000);
  digitalWrite(3, LOW);
  delayMicroseconds(2);
  digitalWrite(3, HIGH);
  delayMicroseconds(5);               // will send waves of 2 ms low wave & 5 ms high wave
  long x2 = pulseIn(4, HIGH);
  int externalsensor = x2 / (29 * 2);
  //Serial.print(" \nExternal sensor detected = ");
  Serial.println(externalsensor);


}
void redlighton()
{
  digitalWrite(6, HIGH); // turn on red Light
  Serial.print(" \n\n Red Light is activated");
}
void redlightoff()
{
  digitalWrite(6, LOW);   // turn off red light
  Serial.print(" \n\n Red Light is deactivated");
}

void bluelighton()
{
  digitalWrite(5, HIGH); // turn on blue Light
  Serial.print(" \n\n Blue Light is activated");
}
void bluelightoff()
{
  digitalWrite(5, LOW);   // turn off blue light
  Serial.print("\n\n Blue Light is deactivated");
}

void greenlighton()
{
  digitalWrite(7, HIGH); // turn on green Light
  Serial.print("\n\n Green Light is activated");
}
void greenlightoff()
{
  digitalWrite(7, LOW);   // turn off green light
  Serial.print("\n\n Green Light is deactivated");
}

void alert()      // Turn On Buzzer & LEDS Blink Circuit
{
  Serial.print("\n\n Warning...Something Wrong. Securing Vault . Doors Locked");
  digitalWrite(12, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  delay(50);
  digitalWrite(12, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  delay(50);
}
void buzzer()       // barcode reading sound
{
  digitalWrite(12, HIGH);
  delay(50);
  digitalWrite(12, LOW);
  delay(50);
  Serial.print("\n\n BarCode Detected. Authentication Success. Database Updated......(100%)");
}

void loop() {

  servodown();
  externalsensor();
  internalsensor();
  delay(1000);
  redlighton();
  digitalWrite(3, LOW);
  delayMicroseconds(2);
  digitalWrite(3, HIGH);
  delayMicroseconds(5);               // will send waves of 2 ms low wave & 5 ms high wave
  long x2 = pulseIn(4, HIGH);
  int externalsensor = x2 / (29 * 2);
  //Serial.print(" \nExternal sensor detected = ");
  Serial.println(externalsensor);


  if (externalsensor <= externallimit)
  {
    redlightoff();
    buzzer();
    greenlighton();
    servoup();
    int count = 4;
    int i=0;
    while(i<=count)
    {
      internalsensor();
      delay(1000);
      digitalWrite(8, LOW);
      delayMicroseconds(2);
      digitalWrite(8, HIGH);
      delayMicroseconds(5);               // will send waves of 2 ms low wave & 5 ms high wave
      long x1 = pulseIn(9, HIGH);
      int internalsensor = x1 / (29 * 2);
      Serial.print(" \nInternal sensor detected = ");
      Serial.println(internalsensor);
      bluelighton();
      if (internalsensor <= internallimit)
      {
        count--;
        buzzer();
      }  
    } 
    bluelightoff();
    delay(1500);
    servodown();
    greenlightoff();
    delay(1000);
  }
  else {

    digitalWrite(8, LOW);
    delayMicroseconds(2);
    digitalWrite(8, HIGH);
    delayMicroseconds(5);               // will send waves of 2 ms low wave & 5 ms high wave
    long x1 = pulseIn(9, HIGH);
    int internalsensor = x1 / (29 * 2);
    Serial.print(" \nInternal sensor detected = ");
    Serial.println(internalsensor);
    if (internalsensor <= internallimit)
    {
      while(1){
         alert();
      }
     
    }
  }
}
