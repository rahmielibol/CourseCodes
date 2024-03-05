/*
  State change detection (edge detection)

  Often, you don't need to know the state of a digital input all the time, but
  you just need to know when the input changes from one state to another.
  For example, you want to know when a button goes from OFF to ON. This is called
  state change detection, or edge detection.

  This example shows how to detect when a button or button changes from off to on
  and on to off.

  The circuit:
  - pushbutton attached to pin 2 from +5V
  - 10 kilohm resistor attached to pin 2 from ground
  - LED attached from pin 13 to ground through 220 ohm resistor (or use the
    built-in LED on most Arduino boards)

  created  27 Sep 2005
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/StateChangeDetection
*/

// degismesini istemedigimiz sabitler
const int butonPin = 2;  // butonun bagli oldugu pin
const int ledPin = 13;    // LED in bagli oldugu pin

// degiskenler
int butonsayaci = 0;  // butona kac kez basildigini sayan degisken
int butondurumu = 0;        // butonun mevcut durumu
int ButonSonDurumu = 0;    // butonun bir onceki durumu

void setup() {
  // initialize the button pin as a input:
  pinMode(butonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  // read the pushbutton input pin:
  butondurumu = digitalRead(butonPin);

  // buton durumunu önceki durumu ile karsilastir
  if (butondurumu != ButonSonDurumu) {
    // eger farklilik varsa buton sayacini artir
    if (butondurumu == HIGH) {
      // eger butona basildi ise:
      butonsayaci++;
      Serial.println("on");
      Serial.print("Butona basilma sayisi: ");
      Serial.println(butonsayaci);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  ButonSonDurumu = butondurumu;


  // turns on the LED every four button pushes by checking the modulo of the
  // button push counter. the modulo function gives you the remainder of the
  // division of two numbers:
  if (butonsayaci % 5 == 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
