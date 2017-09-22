
unsigned long Time = 0;
unsigned long timeDifference;
int prevstate = 0;
const int buzzer = 9;
#define ACCELX A0
#define ACCELY A1
#define ACCELZ A2
int StartX = 0;
int StartY = 0;
int StartZ = 0;

unsigned long interval = 5000;
unsigned long previousMillis = 0;
int move = 0;


void setup() {
  Serial.begin(9600);
  pinMode(6, INPUT);

  pinMode(buzzer, OUTPUT);

  StartX = analogRead(ACCELX);
  StartY = analogRead(ACCELY);
  StartZ = analogRead(ACCELZ);
//  previousMillis = millis();

}


void loop() {

  Serial.print(" X " );
  Serial.print(analogRead(ACCELX));
  Serial.print(" Y " );
  Serial.print(analogRead(ACCELY));
  Serial.print(" Z " );
  Serial.print(analogRead(ACCELZ));
  //  Serial.print(" Minutes: ");
  //  Time = millis();
  //  Serial.print(Time);
  Serial.println();



  int CurrentX = analogRead(ACCELX);
  int CurrentY = analogRead(ACCELY);
  int CurrentZ = analogRead(ACCELZ);


  unsigned long currentMillis = millis();


  if (CurrentX - StartX >= 50 || CurrentY - StartY >= 50 || CurrentZ - StartZ >= 50) {//when you move
    Serial.print("MOVING ");
//     delay(interval);
      Serial.println(currentMillis);
      //Serial.println(previousMillis);
      previousMillis = currentMillis;
    
      move = 0;
    }

  else {//not moving
    //previousMillis = currentMillis;
    Serial.print("No movement");
    Serial.println(currentMillis);
    //previousMillis = millis();


      if ( (currentMillis - previousMillis > interval )) {

      currentMillis = millis();
      previousMillis = currentMillis;

      Serial.print("beep ");
//      Serial.println(move);
      Serial.println(currentMillis);
      move = 1;
      tone(buzzer, 2000);
      delay(1000);
      noTone(buzzer);
      delay(1000);

    }
    else {
      if (move == 1) {
      Serial.print("beep ");
      Serial.println(currentMillis);
      tone(buzzer, 2000);
      delay(1000);
      noTone(buzzer);
      delay(1000);
      }
    }

     // Serial.println(move);
//    if (CurrentX - StartX < 50 || CurrentY - StartY < 50 || CurrentZ - StartZ < 50) {
//    if(move<1){
//      Serial.println("move == 0");
//      tone(buzzer, 2000);
//      delay(1000);
//      noTone(buzzer);
//      delay(1000);

    }




  delay(1000);
}













