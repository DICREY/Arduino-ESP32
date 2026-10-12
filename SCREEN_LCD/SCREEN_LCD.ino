#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Fonts/FreeSerif9pt7b.h>
#include <DHT.h>
#include <SPI.h>

// Pines Pantalla TFT SPI en ESP32-S3
#define TFT_CS   10
#define TFT_RST   9
#define TFT_DC    8

// Pin Sensor DHT11
#define DHTPIN    4
#define DHTTYPE DHT11

// Instancias
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
DHT dht(DHTPIN, DHTTYPE);

// Control de tiempo no bloqueante
unsigned long previousMillis = 0;
const long interval = 2000; // Leer cada 2 segundos

void setup() {
  Serial.begin(115200);

  // Inicializar Pantalla
  tft.initR(INITR_BLACKTAB); // Cambia a INITR_REDTAB si los colores salen invertidos
  tft.setRotation(0);
  tft.fillScreen(ST77XX_BLACK);

  // Layout Inicial de la Interfaz
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.setCursor(1, 1);
  // tft.setFont(&FreeSerif9pt7b);
  tft.println("MONITOR CLIMA");
  tft.drawFastHLine(0, 32, tft.width(), ST77XX_WHITE);

  // Inicializar DHT
  dht.begin();
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    float temp = dht.readTemperature();
    float hum = dht.readHumidity();

    if (isnan(temp) || isnan(hum)) {
      Serial.println("Error al leer el sensor DHT11");
      return;
    }

    // Actualizar área de Temperatura
    tft.fillRect(10, 45, 140, 25, ST77XX_BLACK); // Limpiar zona previa
    tft.setCursor(1, 45);
    tft.setTextColor(ST77XX_RED);
    tft.setTextSize(1);
    tft.printf("Temp: %.1f C", temp);
    serial.println("Temp: %.1f C", temp);

    // Actualizar área de Humedad
    tft.fillRect(10, 75, 140, 25, ST77XX_BLACK); // Limpiar zona previa
    tft.setCursor(1, 75);
    tft.setTextColor(ST77XX_BLUE);
    tft.setTextSize(1);
    tft.printf("Hum:  %.1f %%", hum);
    serial.println("Hum:  %.1f %%", hum);
    serial.println(hum);
    serial.println(temp);
  }
}