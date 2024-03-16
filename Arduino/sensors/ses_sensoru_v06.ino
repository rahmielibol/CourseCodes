/*
Ses sensoru FC 04
*/


#define cikis_Pini 13
#define ses_Sensoru_Pini 7


int son_Ses_Degeri;

int ses_Degeri;

long son_Gurultu_Zamani = 0;

long cari_Gurultu_Zamani = 0;

long son_Lamba_Degisimi = 0;

int role_Durumu = LOW;

void setup() {
  // put your setup code here, to run once:
  
  
  pinMode(ses_Sensoru_Pini, INPUT);
  pinMode(cikis_Pini, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  ses_Degeri = digitalRead(ses_Sensoru_Pini);
  cari_Gurultu_Zamani = millis();

  Serial.println(ses_Degeri);
  Serial.println(cari_Gurultu_Zamani);

  if (ses_Degeri == 1) { // Eger ortamda bir ses var ise

    if (
      (cari_Gurultu_Zamani > son_Gurultu_Zamani + 200) && // Eger su anda varolan gurultu bir onceki gurultuden 200ms daha buyuk bir gecikme ile yasandi ise
      (son_Ses_Degeri == 0) &&  // Eger oncesinde bir sessizlik var ise
      (cari_Gurultu_Zamani < son_Gurultu_Zamani + 800) && // Eger mevcut alkis sesi ilk alkis sesinden en fazla 800ms daha sonra ise
      (cari_Gurultu_Zamani > son_Lamba_Degisimi + 1000) // Mevcut alkis sesi bir onceki lama degisiminden en fazla 1000ms (1s) sonra oldu ise  
    ) {

      role_Durumu = !role_Durumu;
      digitalWrite(cikis_Pini, role_Durumu);
      son_Lamba_Degisimi = cari_Gurultu_Zamani;
      Serial.println("Lamba yandı veya sondu");
     }

     son_Gurultu_Zamani = cari_Gurultu_Zamani;
     Serial.println("Ses_Var");
  }

  if (role_Durumu == HIGH) {     // Eger lamba yaniyor ise
    Serial.println("Lamba Yaniyor");
  }
  else {Serial.println("Lamba Yan - mi - yor");}

  son_Ses_Degeri = ses_Degeri;

}
