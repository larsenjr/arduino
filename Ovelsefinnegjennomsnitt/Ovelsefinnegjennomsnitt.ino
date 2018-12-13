/* Finne gjennomsnittet av 4 tall og finne de 2 største tallene
 *  
 */
  
  int num1 =3000 ;
  int num2 =1337 ;
  int num3 =173 ;
  int num4 =256 ;
  int sum;
  
void setup() {
  Serial.begin(9600);
  
}

void loop() {
  if (num1 > num2) {
Serial.println (num1);
  }
  else (num2 > num1){
Serial.println (num2);
  }

  sum = (num1 + num2 + num3 + num4) /4;
  Serial.println (sum);
  Serial.end();

}
