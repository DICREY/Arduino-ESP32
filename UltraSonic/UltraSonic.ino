#define TRIG_PIN 5
#define ECHO_PIN 18

// Vars
int leds[] = {1, 2, 4};
int btn = 7;
int state = 0;
long duracion;
float distancia;

// Functions
void ultraSonic();
void powerOn();
void triggerBtn ();

void setup() {
  Serial.begin(115200);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(btn, INPUT_PULLUP);
  for (const int& led : leds) {
    pinMode(led, OUTPUT);
  }
  
  // Asegurar que el pin TRIG esté en bajo antes de empezar
  digitalWrite(TRIG_PIN, LOW);
}

void loop() {
  // if (digitalRead(btn) == LOW) {
  //   delay(500);
  //   triggerBtn();
  // }
  // state? ultraSonic(): powerOn();
  ultraSonic();
}

void ultraSonic() {
  for (const int& led : leds) {
    digitalWrite(led, LOW);
  }

  // 1. Enviar pulso de 10us
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2); // Pequeña pausa para limpiar el pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10); // Pulso de 10 microsegundos
  digitalWrite(TRIG_PIN, LOW);
  
  // 2. Medir duración con TIMEOUT (30ms = 30000us)
  // Si no recibe eco en 30ms, devuelve 0
  duracion = pulseIn(ECHO_PIN, HIGH, 30000);
  
  // 3. Depuración: Imprimir el valor crudo
  Serial.print("Tiempo (us): ");
  Serial.println(duracion);
  
  // 4. Calcular distancia
  if (duracion == 0) {
    Serial.println("Estado: Sin señal (Revisa cableado o alimentación)");
  } else {
    // Fórmula: distancia = (duracion * 0.034) / 2
    distancia = (duracion * 0.034) / 2.0;
    if (distancia < 20) {
      digitalWrite(leds[0], HIGH);
    } else if (distancia <= 50) {
      digitalWrite(leds[2], HIGH);      
    } else digitalWrite(leds[1], HIGH);
    
    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");
  }
  
  delay(500); // Espera un poco para no saturar el monitor
}

void triggerBtn () {
  state = !state;
  delay(100);
}

void powerOn() {
  for (const int& led : leds) { digitalWrite(led, HIGH);}
}