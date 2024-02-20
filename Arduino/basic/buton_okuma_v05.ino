int pushButton = 2;

void setup() {

  Serial.begin(9600);
  pinMode(pushButton, INPUT);
}


void loop() {

  int button_durumu = digitalRead(pushButton);

  Serial.println(button_durumu);
  delay(1);  
}
