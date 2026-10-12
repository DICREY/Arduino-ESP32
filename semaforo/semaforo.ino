// Librarys 
#include <Keypad.h>

// Vars
// pins GPIO = {1, 2,4,5,7, 10, 11, 12, 13, 14, 15, 16, 17, 18, 21, 47};

int led = 13;

// Define the number of rows and columns in the keypad
const byte ROWS = 4; 
const byte COLS = 4; 

// Define the keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Connect keypad ROW0, ROW1, ROW2, ROW3 to these Arduino pins
byte rowPins[ROWS] = {1, 2, 4, 5}; 

// Connect keypad COL0, COL1, COL2, COL3 to these Arduino pins
byte colPins[COLS] = {7, 10, 11, 12}; 

// Create the Keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(115200); // Initialize serial communication at 115200

  Serial.println("El sistema esta listo");

  pinMode(led, OUTPUT);
}

void loop() {
  char key = keypad.getKey(); // Get the key pressed

  if (key) { // If a key is pressed
    Serial.println(key); // Print the key to the Serial Monitor
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
  }
}