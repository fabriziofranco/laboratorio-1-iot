// Definir pines de salida para LEDs
const int redCarLED = 3;     // Pin para el LED rojo del semaforo de vehiculos
const int yellowCarLED = 4;  // Pin para el LED amarillo del semaforo de vehiculos
const int greenCarLED = 5;   // Pin para el LED verde del semaforo de vehiculos

const int redPedLED = 6;     // Pin para el LED rojo del semaforo de peatones
const int greenPedLED = 7;   // Pin para el LED verde del semaforo de peatones

const int nightModeInput = A0; // Pin para lectura del modo madrugada
int nightModeValue; // Valor leido a través del pin defenido en la línea anterior

long greenCarTime=0, yellowCarTime=0, redCarTime=0, greenPedTime=0, redPedTime=0; //Variables de control de tiempo

void setup() {
  //Serial begin
  Serial.begin(9600);
  // Configurar modo dia-noche como input
  pinMode(nightModeInput, INPUT);
   
  // Configurar pines como salidas
  pinMode(greenCarLED, OUTPUT);   // Configurar el pin del LED verde del semaforo de vehiculos como salida
  pinMode(yellowCarLED, OUTPUT);  // Configurar el pin del LED amarillo del semaforo de vehiculos como salida
  pinMode(redCarLED, OUTPUT);     // Configurar el pin del LED rojo del semaforo de vehiculos como salida
  pinMode(greenPedLED, OUTPUT);   // Configurar el pin del LED verde del semaforo de peatones como salida
  pinMode(redPedLED, OUTPUT);     // Configurar el pin del LED rojo del semaforo de peatones como salida
}

void loop() {
  nightModeValue = digitalRead(nightModeInput);
  Serial.print(nightModeValue);
  Serial.print(" - ");
  if (nightModeValue==LOW){
    Serial.print("MODO REGULAR\n");
    greenCarTime = 60;    // Duracion en segundos del estado verde del semaforo de vehiculos
    yellowCarTime = 2;    // Duracion en segundos del estado amarillo del semaforo de vehiculos
    redCarTime = 30;      // Duracion en segundos del estado rojo del semaforo de vehiculos
    greenPedTime = redCarTime;   // Duracion en segundos del estado verde del semaforo de peatones
    redPedTime = greenCarTime + yellowCarTime;   // Duracion en segundos del estado rojo del semaforo de peatones
  }
  else{
    Serial.print("MODO NOCHE\n");
    greenCarTime = 90;    // Duracion en segundos del estado verde del semaforo de vehiculos
    yellowCarTime = 2;    // Duracion en segundos del estado amarillo del semaforo de vehiculos
    redCarTime = 10;      // Duracion en segundos del estado rojo del semaforo de vehiculos
    greenPedTime = redCarTime;   // Duracion en segundos del estado verde del semaforo de peatones
    redPedTime = greenCarTime + yellowCarTime;  // Duracion en segundos del estado rojo del semaforo de peatones
  }
  
  digitalWrite(redPedLED, HIGH);     // Encender el LED rojo del semaforo de peatones
  digitalWrite(greenPedLED, LOW);    // Apagar el LED verde del semaforo de peatones

  digitalWrite(greenCarLED, HIGH);   // Encender el LED verde del semaforo de vehiculos
  digitalWrite(yellowCarLED, LOW);   // Apagar el LED amarillo del semaforo de vehiculos
  digitalWrite(redCarLED, LOW);      // Apagar el LED rojo del semaforo de vehiculos
  delay(greenCarTime * 1000);        // Esperar el tiempo correspondiente al estado verde del semaforo de vehiculos

  digitalWrite(greenCarLED, LOW);    // Apagar el LED verde del semaforo de vehiculos
  digitalWrite(yellowCarLED, HIGH);  // Encender el LED amarillo del semaforo de vehiculos
  delay(yellowCarTime * 1000);       // Esperar el tiempo correspondiente al estado amarillo del semaforo de vehiculos

  digitalWrite(yellowCarLED, LOW);   // Apagar el LED amarillo del semaforo de vehiculos
  digitalWrite(redCarLED, HIGH);     // Encender el LED rojo del semaforo de vehiculos
  digitalWrite(redPedLED, LOW);      // Apagar el LED rojo del semaforo de peatones
  digitalWrite(greenPedLED, HIGH);   // Encender el LED verde del semaforo de peatones
  delay(greenPedTime * 1000);        // Esperar el tiempo correspondiente al estado verde del semaforo de peatones
}