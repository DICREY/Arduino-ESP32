#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

#define PIN_SDA 4
#define PIN_SCL 5
int count = 0;
const char * messages[] = {"Pendejo", "Estupido", "Bobo", "gay"};

U8G2_SH1106_128X64_NONAME_F_HW_I2C
u8g2(U8G2_R0, /* reset= */ U8X8_PIN_NONE);

void setup() {
  Wire.begin(PIN_SDA, PIN_SCL);
  u8g2.begin();
}


void loop() {
  for (const auto& i : messages) {
    u8g2.clearBuffer();
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "Que miras %s", i);

    u8g2.setFont(u8g2_font_ncenB08_tr);
    // u8g2.getDisplayHeight();
    // u8g2.getDisplayWidth();
    u8g2.drawStr(1,48, buffer);
    u8g2.sendBuffer();
    delay(1000);
  }
  
}