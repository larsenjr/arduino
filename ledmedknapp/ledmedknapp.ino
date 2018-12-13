/**
 * Input på ledpin og buttonPin.
 *
*/

int buttonPin = 2;
int ledPin = 13;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);
    Serial.begin(9600);
}

int buttonState = 0;
int lastButtonState = 0;
int ledState = 0;
void loop()
{
    buttonState = digitalRead(buttonPin);

    /**
     * "Toggle"-funksjon med LED.
     *
     * 
     * Sjekker om knappen "lastButtonState" er "toggled" til enten HIGH/LOW. Snur Ledstate til omvendt
     * 
     */
    if (buttonState == HIGH && buttonState != lastButtonState) {
        ledState = ledState == HIGH ? LOW : HIGH;

        Serial.print("LED state: ");
        Serial.println(ledState == HIGH ? "HIGH" : "LOW");
        digitalWrite(ledPin, ledState);
    }

    /**
     *
     * Sjekker om buttonState avviker fra lastButtonState.
     * Oppdaterer lastButtonState og logger til terminal.
     */
    if (buttonState != lastButtonState) {
        Serial.print("Button state changed: ");
        Serial.println(buttonState == HIGH ? "HIGH" : "LOW");

        lastButtonState = buttonState;
    }
}
