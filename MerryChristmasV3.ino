// A test for keyboard and mouse library using the Arduino Pro Micro(Leonardo).
//by Razvan Bota, date: 25.12.2022

#include <Mouse.h>
#include <KeyboardLayout.h>
#include <Keyboard.h>

int switchState = 0;// enter
int switchState1 = 0;//windows
int switchState2 = 0;//Mac

bool select;
bool passwoard;

void setup() {
  Serial.begin(9600);
  
  pinMode(2, INPUT);//The button is on pin 2(enter)
  pinMode(3, INPUT);//The button is on pin 3(windows)
  pinMode(4, INPUT);//The button is on pin 4(Mac)
  pinMode(8, OUTPUT);// piezo buzzer is on pin 7

  select = true;//after you run the code windows will be selected as default
  passwoard = false;
}
void loop() {
  switchState = digitalRead(2);
  switchState1 = digitalRead(3);
  switchState2 = digitalRead(4);
  
  //checking windows select
  if (switchState1 == HIGH) {
    select = true;
    tone(8, 311);
    delay(100);
    noTone(8);
    delay(500);
    }
  //checking Mac select
  if (switchState2 == HIGH) {
    select = false;
    tone(8, 311);
    delay(100);
    noTone(8);
    delay(500);
  }

  // select windows
  if((switchState == HIGH) & (select == true)) {
    //buzzer
    tone(8, 277);
    delay(100);
    tone(8, 370);
    delay(100);
    noTone(8);
    //This is the version for Windows
    //opening notepad
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.release(KEY_LEFT_GUI);
    delay(100);
    Keyboard.print("note");
    delay(500);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(1000);
 
    //typing
    Keyboard.println("Merry Christmas!");
    Keyboard.println("And a happy new year!");
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.release(KEY_RETURN);
    delay(500);
  }
  //select mac
   if((switchState == HIGH) & (select == false)) {
     //buzzer
    tone(8, 370);
    delay(100);
    tone(8, 277);
    delay(100);
    noTone(8);
    //This is the version for MacOs!
    //opening the notes app
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(32);
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.release(32);
    delay(100);
    Keyboard.print("note");
    delay(100);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(500);

    //typing
    Keyboard.println("Merry Christmas!");
    Keyboard.println("And a happy new year!");
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.release(KEY_RETURN);
    delay(500);   
   }
}
