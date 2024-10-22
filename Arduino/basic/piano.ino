
#define T_A 262
#define T_B 294
#define T_C 330
#define T_D 349
#define T_E 392
#define T_F 440
#define T_G 493


const int A = 4;
const int B = 5;
const int C = 6;
const int D = 7;
const int E = 8;
const int F = 9;
const int G = 10;

const int Buzz = 11;
const int LED = 13;

void setup()
{
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  pinMode(D, INPUT);
  pinMode(E, INPUT);
  pinMode(F, INPUT);
  pinMode(G, INPUT);
  
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}


void loop()
{ 

  while(digitalRead(A) == HIGH)
  {
    tone(Buzz,T_A);
    digitalWrite(LED,HIGH);

  }

  while(digitalRead(B) == HIGH)
  {
    tone(Buzz,T_B);
    digitalWrite(LED,HIGH);

  }

  
  while(digitalRead(C) == HIGH)
  {
    tone(Buzz,T_C);
    digitalWrite(LED,HIGH);
  }


  while(digitalRead(D) == HIGH)
  {
    tone(Buzz,T_D);
    digitalWrite(LED,HIGH);

  }

  while(digitalRead(E) == HIGH)
  {
    tone(Buzz,T_E);
    digitalWrite(LED,HIGH);

  }

  while(digitalRead(F) == HIGH)
  {
    tone(Buzz,T_F);
    digitalWrite(LED,HIGH);

  }

  while(digitalRead(G) == HIGH)
  {
    tone(Buzz,T_G);
    digitalWrite(LED,HIGH);

  }


  noTone(Buzz);
  digitalWrite(LED,LOW);

}
