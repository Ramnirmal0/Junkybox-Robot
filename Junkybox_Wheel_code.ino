int trigger = 3;
int echo = 2;
int RMP = 10, RMN = 11, LMP = 7, LMN = 6;
void setup() {
  pinMode(trigger, OUTPUT);      // triggger is output
  pinMode(echo, INPUT);           // echo is input
  pinMode(RMP, OUTPUT);
  pinMode(RMN, OUTPUT);
  pinMode(LMN, OUTPUT);
  pinMode(LMP, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}
void left() {
  Serial.println("moving left for 5 second" );
  Serial.println("bluetooth working");
  digitalWrite(RMP, HIGH);
  digitalWrite(RMN, LOW);
  digitalWrite(LMP, LOW);
  digitalWrite(LMN, HIGH);
  
}
void right() {
  Serial.println("moving Right  for 5 second" );
  Serial.println("bluetooth working");
  digitalWrite(RMP, LOW);
  digitalWrite(RMN, HIGH);
  digitalWrite(LMP, HIGH);
  digitalWrite(LMN, LOW);
  
}
void backward() {
  Serial.println("moving Backwards for 5 second" );
  //RIGHT MOTION
  digitalWrite(RMP, LOW);
  digitalWrite(RMN, HIGH);
  digitalWrite(LMP, LOW);
  digitalWrite(LMN, HIGH);
  
}
void forward()
{
  Serial.println("moving forward for 5 second" );
  Serial.println("bluetooth working");
  //LEFT MOTION
  digitalWrite(RMP, HIGH);
  digitalWrite(RMN, LOW);
  digitalWrite(LMP, HIGH);
  digitalWrite(LMN, LOW);

}
void stopme()
{
  Serial.println("stop command" );
  digitalWrite(RMP, LOW);
  digitalWrite(RMN, LOW);
  digitalWrite(LMP, LOW);
  digitalWrite(LMN, LOW);
}

void loop()
{
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(5);               // will send waves of 2 ms low wave & 5 ms high wave
  long x = pulseIn(echo, HIGH);
  int y = x / (29 * 2);
  Serial.print("  cm ");
  Serial.println(y);
  delay(1000);
  if (y < 60) {
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    stopme();

  }
  if (Serial.available())
  {
    char c = Serial.read();
    if (c == 'l' || c == 'L')
    {
      digitalWrite(trigger, LOW);
      delayMicroseconds(2);
      digitalWrite(trigger, HIGH);
      delayMicroseconds(5);               // will send waves of 2 ms low wave & 5 ms high wave
      long x = pulseIn(echo, HIGH);
      int y = x / (29 * 2);
      Serial.print("  cm ");
      Serial.println(y);
      delay(1000);
      if (y < 60) {
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        stopme();
        delay(500);
        backward();
        delay(2000);
      }
      else {
        left();
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
      }
    }

    else if (c == 'r' || c == 'R')
    {
      digitalWrite(trigger, LOW);
      delayMicroseconds(2);
      digitalWrite(trigger, HIGH);
      delayMicroseconds(5);               // will send waves of 2 ms low wave & 5 ms high wave
      long x = pulseIn(echo, HIGH);
      int y = x / (29 * 2);
      Serial.print("  cm ");
      Serial.println(y);
      delay(1000);
      if (y < 60) {
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        stopme();
        delay(500);
        backward();
        delay(2000);
      }
      else {
        right();
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
      }
    }


    else if (c == 'F' || c == 'f')
    {
      digitalWrite(trigger, LOW);
      delayMicroseconds(2);
      digitalWrite(trigger, HIGH);
      delayMicroseconds(5);               // will send waves of 2 ms low wave & 5 ms high wave
      long x = pulseIn(echo, HIGH);
      int y = x / (29 * 2);
      Serial.print("  cm ");
      Serial.println(y);
      delay(1000);
      if (y < 60) {
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        stopme();
        delay(500);
        backward();
        delay(2000);
      }
      else {
        forward();
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
      }
    }

    else if (c == 'b' || c == 'B')
    {
      digitalWrite(trigger, LOW);
      delayMicroseconds(2);
      digitalWrite(trigger, HIGH);
      delayMicroseconds(5);               // will send waves of 2 ms low wave & 5 ms high wave
      long x = pulseIn(echo, HIGH);
      int y = x / (29 * 2);
      Serial.print("  cm ");
      Serial.println(y);
      delay(1000);
      if (y < 60) {
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        stopme();
        delay(500);
        backward();
        delay(2000);
      }
      else {
        backward();
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
      }
    }

    else if (c == 'S' || c == 's')
    {
      stopme();
    }

  }

}
