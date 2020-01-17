#include <LiquidCrystal.h>
LiquidCrystal LCD(A0,A1,A2,A3,A4,A5);
int myCounter = 0;
#include <Keypad.h>
const byte rows = 4;
const byte cols = 3;

int greenLed = 3;
int redLed = 2;

//set our code
char* ourCode = "2639";
int currentPosition = 0;

char keys[rows][cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
  };

  byte rowPins[rows] ={10,9,8,7};
  byte colPins[cols] ={13,12,11};

  Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);
   

void setup() {
  // put your setup code here, to run once:
LCD.begin(20,4);
LCD.setCursor(0,0);
LCD.print("YOU PRESSED");
pinMode(redLed,OUTPUT);
pinMode(greenLed,OUTPUT);
digitalWrite(redLed,LOW);
digitalWrite(greenLed,LOW);
Serial.begin(9600);
}

void loop() {

int l;
char key = keypad.getKey();

if(int(key) != 0){
  LCD.setCursor(13,0);
  LCD.print("          ");
  LCD.setCursor(13,0);

  for(l=0; l<=currentPosition; ++l){
    LCD.print("*");
    }
    if(key == ourCode[currentPosition]){
      ++currentPosition;
      if(currentPosition == 4){
        unlockDoor();
        currentPosition = 0;
        }
      }
      else{
        invalidCode();
        currentPosition = 0;
        }
  }
}

void invalidCode(){
  digitalWrite(redLed,HIGH);
  clearScreen();
  LCD.setCursor(0,0);
  LCD.print("*************");
  LCD.setCursor(0,1);
  LCD.print("** ACCESS DENIED! **");
  LCD.setCursor(0,2);
  LCD.print("** INVALID CODE**");
  LCD.setCursor(0,3);
  LCD.print("***************");

  delay(1000);
  digitalWrite(redLed,LOW);
  displayCodeEntryScreen();
  }

  void unlockDoor(){
    digitalWrite(greenLed,HIGH);
    clearScreen();
    LCD.setCursor(0,0);
    LCD.print("** ACCESS GRANTED **");
    LCD.setCursor(0,1);
    LCD.print("** WELCOME!! **");

    delay(1000);
    digitalWrite(greenLed,LOW);
    displayCodeEntryScreen();
    }

   void displayCodeEntryScreen(){
    clearScreen();
    LCD.setCursor(0,0);
    LCD.print("ANDY-JAZZ TECH");
    LCD.setCursor(0,1);
    LCD.print("TECH FOR AFRICA");
    
    }
  void clearScreen(){
    LCD.setCursor(0,0);
    LCD.print("                ");
    LCD.setCursor(0,1);
    LCD.print("                ");
    }
