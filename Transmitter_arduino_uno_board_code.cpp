#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <LiquidCrystal.h>

#define buttonPin1 3

RF24 radio(9, 8); // CE, CSN
LiquidCrystal lcd(3, 2, 4, 5, 6, 7); // RS, Enable, D4, D5, D6, D7


const byte address[6] = "00002";

const int joystickXPin = A0; // Joystick X-axis connected to analog pin A0
const int joystickYPin = A1; // Joystick Y-axis connected to analog pin A1
const int joystickSwitchPin = 10; // Joystick switch connected to digital pin 2

void setup() {

  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  lcd.begin(16, 2); // Initialize the LCD
  lcd.print("     Smart      ");
  lcd.setCursor(0, 1);
  lcd.print("   Door Bell    ");
  delay(3000);
  lcd.clear();
  lcd.print("Another creation");
  lcd.setCursor(0, 1);
  lcd.print("   of Kalindu   ");
  delay(3000);
  lcd.clear();


}
void loop() {

  int a = 100;

 for (int i = 1; i <= 30; i++) {
  lcd.clear();
  lcd.print(" Welcome to my ");
  lcd.setCursor(0, 1);
  lcd.print("     home      ");
  delay(a);
  lcd.clear();

  input();
 }

 for (int i = 1; i <= 30; i++) {
  lcd.clear();
  lcd.print("   If are you   ");
  lcd.setCursor(0, 1);
  lcd.print("   relative     ");
  delay(100);
  lcd.clear();

  input();
 }

 for (int i = 1; i <= 30; i++) {
  lcd.clear();
  lcd.print(" Please up the  ");
  lcd.setCursor(0, 1);
  lcd.print("    jokystic    ");
  delay(a);
  lcd.clear();

  input();
 }

 for (int i = 1; i <= 30; i++) {
    lcd.clear();
  lcd.print("   If are you   ");
  lcd.setCursor(0, 1);
  lcd.print("     guest      ");
  delay(100);
  lcd.clear();

  input();

 }

 for (int i = 1; i <= 30; i++) {
  lcd.clear();
  lcd.print("Please down the");
  lcd.setCursor(0, 1);
  lcd.print("    jokystic    ");
  delay(a);
  lcd.clear();

  input();

 }


}

void input(){

  int joystickSwitchState = digitalRead(joystickSwitchPin);
  int joystickYValue = analogRead(joystickYPin);
  int buttonState1;


    if (joystickSwitchState == 0)
  {
     buttonState1 = 1;
    Serial.println(buttonState1);
    radio.write(&buttonState1, sizeof(buttonState1));
    Serial.println(buttonState1);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Verifying...");
    lcd.setCursor(0, 1);
    delay(500);
    lcd.print("veryfied as VIP");
    delay(3000);
    lcd.clear();


   }


  if (joystickYValue > 800) {
     buttonState1 = 3;
  radio.write(&buttonState1, sizeof(buttonState1));
  Serial.println(buttonState1);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Verifying...");
    lcd.setCursor(0, 1);
    delay(500);
    lcd.print("Ver. as relative");
    delay(3000);
    lcd.clear();

 }


  if(joystickYValue < 200) {
     buttonState1 = 5;
    radio.write(&buttonState1, sizeof(buttonState1));
    Serial.println(buttonState1);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Verifying...");
    lcd.setCursor(0, 1);
    delay(500);
    lcd.print("veryfi. as guest");
    delay(3000);
    lcd.clear();

  }

}