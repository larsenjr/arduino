 /** Innlevering Led med knapp og dimming.
  * Oppgave 1 og 2.
  * Stian Larsen - 18IT-D
  * Har fått noe hjelp, tips / råd fra andre klassekamerater. :)
  */

int LED_PIN = 3;                            // Angir hvilken PIN som kobles til LED */
int MINUS_BTN = 1;                          // Knapp for å regulere lys ned når man har en dimmefunksjon.
int PLUS_BTN = 12;                          // Knapp som regulerer lys "på" når man oppnår dimmefunksjon. 

/** 
 * Setter hvor mye lyset skal lyslevel "dimmes". Her er plusminusval = 10 så det vil si at den øker med 10 eller minsker med 10 når man trykker inn knappene
 * Når Arduinoen starter begynner lyslevel på 0 ettersom vi har satt en "int" lyslevel = 0.
 */
int lyslevel = 0;
int plusminusval = 10;

unsigned long lyspa = millis();                 // Når vi trykker ned knappen
unsigned long lysav = millis();                 // Når vi slipper vi knappen

void setup(){
    pinMode(LED_PIN, OUTPUT);                   // Setter LED-output til PIN 3.
    pinMode(MINUS_BTN, INPUT_PULLUP);           // Setter minusknapp som input. Default er HIGH state. 
    pinMode(PLUS_BTN, INPUT_PULLUP);            // Setter plussknapp som input. Default er HIGH state.
}

bool btnON = false;                             // Setter value til "false" på knapp på. Bool gjør så verdien blir "omvendt" av det som "veksles".
bool btnOFF = false;                            // Setter value til "false" på knapp av. 

/** 
 * Setter en maxtid som det er tillatt at vi skal få knappen til å dimmes eller skrus på. 
 * Hvis knappen trykkes lenger enn 300ms vil den gå over til dimmefunksjon.  
 */
int tid = 300;

// Koden som kjører i loop

void loop(){
    analogWrite(LED_PIN, lyslevel);             // Setter LED til lysverdi. Denne settes fra 0 - 255. 

    unsigned long currentTime = millis();       // Setter unsigned long som starter å telle når koden føres over. Måles i millisekunder.

    if (digitalRead(PLUS_BTN) == LOW)           // Sjekker om knappen er trykket ned. Hvis den er det vil state være "LOW". 
    {
        if (!btnON)                             // Sjekker om btnON er trykket ned. Hvis den er trykket vil den sette "currentTime" til å telle ms. 
        {
            lyspa = currentTime;
            btnON = true;
        }

        /** 
         * Lyslevel + plusminusval setter value som å øke med 10 når man holder inne knappen. 
         * Dette gjøres ved at den husker på "lyslevel" variabelen og plusser på 10 hver gang når den holdes inne.  
         * Dette gir en dimmefunksjon. Denne stopper på value "255" for det er satt nederst i koden. 
         */
        if (lyslevel < 255) {

            lyslevel = lyslevel + plusminusval;           
            delay(50);                          // En liten delay på lyset så man ser at det dimmes på LED.
            lysav = millis();               
        }
    }
    /**
     * Sjekker om knappen blir sluppet mindre enn 300ms. 
     * Hvis knappen er trykket ned mer enn det blir lyslevel satt til 255.
     */
    else {
        if ((currentTime - lysav) < tid){
            lyslevel = 255;
        }

        lysav = false;                          // Knappen blir sluppet opp eller ikke trykket inn. 
    }

    if (digitalRead(MINUS_BTN) == LOW)          // Sjekker om knappen er trykket ned igjen. Hvis den er det vil state være "LOW". 
    {
        if (!btnOFF) 
        {
            lysav = currentTime;
            btnOFF = true;
        }
        /**
         * Danner en dimmefunksjon for å minske lyslevelet. 
         * Denne sjekker / husker på den gamle verdien og trekker ifra i "plusminusval" for å oppnå en dimmefunksjon.
         * Stoppes på value "0".
         */
        if (lyslevel > 0)                    
        {
            lyslevel = lyslevel - plusminusval;    // "lyslevel" - "plusminusval" trekker ifra 10 når vi holder inne knappen.
            delay(50);                             // En liten delay for å se at det dimmes på LED.             
            lyspa = millis();                       
        }
    }
    /**
     * Sjekker om knappen blir sluppet mindre enn 300ms.
     * Hvis knappen blir det vil den gå tilbake til lyslevel 0.
     */
    else 
    {
        if ((currentTime - lyspa) < tid)
        {
            lyslevel = 0;
        }

        lyspa = false;                             // Knappen blir sluppet opp eller ikke trykket inn.
    }

    // Passer på at lysverdi ikke går høyere enn 255, eller lavere enn 0.
    // Setter verdi til 255 som er det høyeste.
    if (lyslevel > 255) 
    { 
        lyslevel = 255; 
    }
    // Setter verdi til 0. 
    if (lyslevel < 0)
    {
        lyslevel = 0;
    }
} // Loop