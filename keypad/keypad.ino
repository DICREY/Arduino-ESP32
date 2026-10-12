  // Librarys 
  #include <Keypad.h>

  // Vars
  // pins GPIO = {1, 2,4,5,7, 10, 11, 12, 13, 14, 15, 16, 17, 18, 21, 47};
  int leds[] = {13};
  long duration;
  float distance;
  int ultraSonic[] = {18, 16}; // 18 output 
  const byte ROWS = 4; // Define the number of rows in the keypad
  const byte COLS = 4; // Define the number of columns in the keypad

  // Functions 
void sonic ();

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
    Serial.begin(9600); // Initialize serial communication at 115200
    Serial.println("El sistema esta listo");
    pinMode(leds[0], OUTPUT);
    pinMode(ultraSonic[1], OUTPUT);
    pinMode(ultraSonic[0], INPUT);
  }

  void loop() {
    char key = keypad.getKey(); // Get the key pressed
    sonic();
    if (key) { // If a key is pressed
      int number = key - '0';
      Serial.println(key);
      Serial.println(number);
      switch (key) {
        case '1':
          tone(leds[0],1046.50, 200);
          break;
        case '2':
          tone(leds[0],1174.66, 200);
          break;
        case '3':
          tone(leds[0],1318.51, 200);
          break;
        case 'A':
          tone(leds[0],1396.91, 200);
          break;
        case '4':
          tone(leds[0],1567.91, 200);
          break;
        case '5':
          tone(leds[0],1760.00, 200);
          break;
        case '6':
          tone(leds[0],1975.53, 200);
          break;
        case 'B':
          tone(leds[0],2093.00, 200);
          break;
        case '7':
          tone(leds[0],2349.32, 200);
          break;
        case '8':
          tone(leds[0],2637.02, 200);
          break;
        case '9':
          tone(leds[0],2793.83, 200);
          break;
        case 'C':
          tone(leds[0],3135.96, 200);
          break;
        case '*':
          tone(leds[0],3520.00, 200);
          break;
        case '0':
          tone(leds[0],3951.07, 200);
          break;
        case '#':
          tone(leds[0],4186.01, 200);
          break;
        default:
          tone(leds[0],4434.92, 200);
      }
    }
  }


void sonic () {
  digitalWrite(ultraSonic[1], LOW);
  delayMicroseconds(2);
  digitalWrite(ultraSonic[1], HIGH);
  delayMicroseconds(10);
  digitalWrite(ultraSonic[1], LOW);

  duration = pulseIn(ultraSonic[0], HIGH);
  distance = duration * 0.034 / 2;
  Serial.println("Distance: ");
  Serial.println(distance);
  delay(500);
}