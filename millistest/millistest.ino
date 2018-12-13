unsigned long tidnaa;
unsigned long tidforrige = 0;
void setup() {

Serial.begin(9600);

}

void loop() {
  tidnaa = millis();

  if ((tidnaa - tidforrige)>999) //
  {
    tidforrige = tidnaa; // Sier at forrige registrerte tid skal printes som tidnaa
    Serial.println(tidnaa); // Printer tidnaa hvert sekund
  }

} // loop
