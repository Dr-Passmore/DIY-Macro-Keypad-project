
#include "Keyboard.h"
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four Columns 

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

byte rowPins[ROWS] = {2, 3, 4, 5}; 
byte colPins[COLS] = {6, 7, 8, 9 };

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Keyboard.begin();
}

void sendMacroCommand(uint8_t key) {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(key);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);
    switch (key) {
      // Banging head on wall Emoji
      case '1':
        Keyboard.print("(headbang)");
        break;
      // Coffee Emoji
      case '2':
        Keyboard.print("(coffee)");
        break;
      case '3':
        Keyboard.print("(facepalm)");
        break;
      case '4':
        Keyboard.print("(highfive)");
        break;
      case '5':
        Keyboard.print("(party)");
        break;
      case '6':
        Keyboard.print("(champagne)");
        break;
      case '7':
        Keyboard.print("(smile)");
        break;
      case '8':
        Keyboard.print("(tongueout)");
        break;
      case '9':
        Keyboard.print("(rofl)");
        break;
      case '0':
        Keyboard.print("(holidayspirit)");
        break;
     // mark as important
      case '*':
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('I');
        break;
      // new chat
      case '#':
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('1');
        break;
        // accept call
      case 'A':
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('S');
        break;
      case 'B':
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('M');
        break;
      case 'C':
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('4');
        break;
      case 'D':
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('D');
        break;
    }

    delay(100);
    Keyboard.releaseAll(); // this releases the buttons
  }
}
