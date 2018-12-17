/**Oppgaveinnlevering Programmerbar LED-kontroller. 
 * Stian Åsvestad Larsen - 18IT-D
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
int rekkelys[] = {LedBlu, LedGre, LedYel, LedRed};          // Rød, Gul, Blå og Grønt lys
int Valgpin = 0;                                            // Tracker Valgpin som brukes i arrayet. Det brukes også i loop. 

// Setup for arduinokortet.

void setup() 
{
    /** Sier at for Valgpin = 0 så går denne opp til 4 og øker med 1 hver gang. 
     * Setter LED pins til OUTPUT med (rekkelys[valgpin], OUTPUT)
    */
    for (int Valgpin = 0; Valgpin < 4; Valgpin++)
    {
        pinMode(rekkelys[Valgpin], OUTPUT);
    }
/** Starter en serial. Denne er ikke relevant for koden, og Serial.println brukes ikke heller,
 *  men er der hvis det er behov for feilsøking / feil i koden. 
 */
    Serial.begin(9600);
}

// loop
void loop() 
{
            // Array Rekkefølge 1
    int sekvens [] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

            //  Eventuelt Array rekkefølge 2 hvis man trenger å bytte ut eller ha andre tall. 
            //  int sekvens [] = {3, 6, 8, 5, 15, 0};

    for (byte Valgpin = 0; Valgpin <= 15; Valgpin++)
    {
        DisplayBinary(sekvens[Valgpin]);
        delay(1000);                                          // Litta delay på 1000ms (1s)
    }
}
// Void som beskriver hva som skal være i "DisplayBinary". 
void DisplayBinary(byte numbers)
{
    for (int Valgpin = 0; Valgpin < 4; Valgpin++)
    {
            // Sjekker bit av "value" du henter inn. Hvis tallet er satt til 1, slår den på LED / LEDs
        if (bitRead(numbers, Valgpin)==1)
        {
            digitalWrite(rekkelys[Valgpin], HIGH); 
        }
            // Sjekker om bit av "value" du henter inn  er lav (eller 0), hvis den er Lav slår den av LED / LEDs
        else
        {
            digitalWrite(rekkelys[Valgpin], LOW); 
        }
    }
}
