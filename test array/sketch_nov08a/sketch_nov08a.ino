int liste[] = {10, -10, 18, 17, 200, 51, 33, 73}; // Tall i et array (liste)
// float total = 330;                           // Defineres i oppgave 5
// int average = 0;                             // Defineres i oppgave 5.

void setup() {

Serial.begin(9600);
}

void loop() {                                   // Kjøres i loop

/** Oppgave i timen
 * for(int i=0 ; i < 10; i++){
 * Serial.println(i);
 * delay(500);}


/** Oppgave 3
 * Definerer tall på en rekke, samtidig som den printer ut tall 4 på en egen rekke
 * Serial.print(Liste[2]);                      // Printer ut tall 2 i liste
 * Serial.print(" ")
 * Serial.println(liste[7]);
 * delay(1000);
 * Serial.println(liste[4]);
    

/** Oppgave 4 ARRAY, FOR, IF
 *  for (int i = 0; i < 10; i++){               // Skriver ut alle elementene som har tall over 25. 
 * Serial.println(liste[i]);                    // Skriver ut linje Liste og array [i] 
 * if ( i <= 25){ Serial.println(i);            // Sjekker om i er større en eller lik 25. er den større printer den ut verdiene i Serial monitor. 
}
}
*/

/** Oppgave 5 - Finne gjennomsnitt av array liste
 * for (int i=0; i < 10; i++){
 * average = total / 10;
 * Serial.println(average);
 * delay(50);
 * Serial.end();                                // Skriver ut linja bare en gang
 * } */


/** Oppgave 6 - Finne tall i omvendt rekkefølge
 for (int i = 9; i > -1; i--) {
    int value = liste[i];

    if (i < 9) {
        Serial.print(", ");
    }

    Serial.print(value);

    if (i == 0) {
        Serial.println();
    }
}*/


/** Oppgave 7 - Switch case
*/

int lengde = (sizeof(liste) / sizeof(int));                 // Setter antall elementer i lista (array)
int maxval = 0;                                             // Setter maxval til 0

// Definerer høyeste verdi for array
for (int hei = 0; hei < lengde; hei++){                     
    maxval = max(maxval, liste[hei]);
} 
for (int i = 0; i < lengde; i++)                            // Definerer i = 0 og om lengde er høyere enn variabelen "lengde"
{
    float kjottkake = liste[i];                             // Float definerer liste + 1
    float value = 0.0;                                      // Setter value til desimaltall som skrives ut når det kjøres. 


    Serial.print("Index:");                                 // Skriver ut "Index" som settes sammen med "i" når det skrives ut. 
    Serial.println(i);
    Serial.print("Case:");                                  // Setter sammen Ordet "Case" og "kjottkake" verdi.
    Serial.println(kjottkake);

// Switchcase
switch(i){
    case 0: // Ganger med 3
    value = kjottkake * 3;
    break;
    case 1:
    // Absolutt tall
    value = abs(kjottkake);
    break;
    case 2:
    // Ganger med 5 og deler på 4. 
    value = ((kjottkake *5) / 4);
    break;
    case 3:
    // Opphøyes med 3.
    value = pow(kjottkake, 3);
    break;
    case 4:
    // Kvadratrot av variabelen kjøttkake
    value = sqrt(kjottkake);
    break;
    case 5:
    // Differanse mellom tall som deles på 4
    value = (int) kjottkake % 4;
    break;
    case 6:
    // Høyeste verdi i listen
    value = maxval;
    break;
    case 7:
    // Deling på 2
    value = (kjottkake / 2);
    break;
}
Serial.println(value);
delay(2000);
}
Serial.end();
}