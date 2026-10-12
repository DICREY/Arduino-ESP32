#include <WiFi.h>

// Reemplaza con tus credenciales de Wi-Fi
const char* ssid = "Cristian";
const char* password = "Cristian";

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("Iniciando conexión Wi-Fi...");
  
  // Intentar conectar a la red
  WiFi.begin(ssid, password);
  
  // Esperar hasta que se conecte
  int intentos = 0;
  while (WiFi.status() != WL_CONNECTED && intentos < 20) {
    delay(500);
    Serial.print(".");
    intentos++;
  }
  
  // Verificar resultado
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n¡Conectado exitosamente!");
    Serial.print("Dirección IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nError: No se pudo conectar al Wi-Fi.");
  }
}

void loop() {
  // En el nivel básico, el loop puede estar vacío o usarse para leer sensores
}
