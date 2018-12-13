/**Oppgaveinnlevering Programmerbar LED-kontroller. 
 * Stian Larsen - 18IT-D
 * 13.12.2018
*/
/**
 * Setter pins og hvor kablene skal være.
 * Rekkelys setter et "array" som har "LedBlu, LedGre, LedYel og LedRed" i seg. 
 */
int LedGre = 11;
int LedBlu = 10;
int LedYel = 9;
int LedRed = 8;
int rekkelys[] = {LedBlu, LedGre, LedYel, LedRed};       // Rød, Gul, Blå og Grønt lys
int Valgpin = 0;

// Setup for arduinokortet. 

void setup() 
{
    // Sier at for valgpin = 0 så går denne opp til 4 og øker med 1 hver gang. 
    for (int Valgpin = 0; Valgpin < 4; Valgpin++)
    {
        pinMode(rekkelys[Valgpin], OUTPUT);
    }

    Serial.begin(9600);
}

// loop
void loop() 
{
    // Rekkefølge 1
    int sekvens [] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    //  Eventuelt rekkefølge 2;
    //  int sekvens2 [] = {3, 6, 8, 5, 15, 0};

    for (byte Valgpin = 0; Valgpin <= 15; Valgpin++)
    {
        DisplayBinary(sekvens2[Valgpin]);
        delay(1000);                                           // Litta delay på 1000ms (1s)
    }
}
  // Void som beskriver hva som skal være i "DisplayBinary". 
void DisplayBinary(byte numbers)
{
    for (int Valgpin =0; Valgpin<4; Valgpin++)
    {
            // Sjekker bit av "value" du henter inn. Hvis tallet er satt til 1, slår den på LED. 
        if (bitRead(numbers, Valgpin)==1)
        {
            digitalWrite(rekkelys[Valgpin], HIGH); 
        }
            // Sjekker om bi er lav,
        else
        {
            digitalWrite(rekkelys[Valgpin], LOW); 
        }
    }
  /* Skrur av alle LEDs
  for (int Valgpin = 0; Valgpin < 4; Valgpin++) 
    {
      digitalWrite(Valgpin, LOW);
    }*/
}
