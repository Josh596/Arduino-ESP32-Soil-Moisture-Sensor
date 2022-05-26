int msensor = A1; // moisture sensor is connected with the analog pin A1 of the Arduino
int msvalue = 0;
int moisture;
float percentage;
int led = 13; 
boolean flag = false; 

int map_low = 686; // We need to calibrate this
int map_high = 350; // and this

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  moisture = analogRead(msensor);
  Serial.println(moisture);
  delay(5000);
//  percentage = ( 100 - ( (moisture/1023.00) * 100 ) );
////  percentage = map(moisture, map_low, map_high, 0, 100);
//  Serial.println(percentage);
//  if ( (percentage >= 50  ) && ( flag == false ) )
//{
//  digitalWrite(led, HIGH); 
//  flag = true; 
//  delay(1000); 
//}
// 
//  if ( (percentage <= 50  ) && ( flag == true ) )
//{
//  digitalWrite(led, LOW); 
//  flag = false; 
//  delay(1000); 
//}
// 
//  delay(1000);
}
