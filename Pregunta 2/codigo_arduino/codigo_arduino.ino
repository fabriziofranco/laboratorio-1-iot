const int analogPin = A0; // Conectar la señal al pin A0

void setup() {
  Serial.begin(9600);
  // analogReadResolution(4); // Esta línea no es necesaria en SimulIDE, ajustar manualmente el valor del ADC en la ventana de configuración de componentes de Arduino
}

void loop() {
  int sensorValue = analogRead(analogPin); // Leer el valor de la señal en el pin A0
  
sensorValue = sensorValue >> 6; // Dividir por 64 para convertir a una resolución de 4 bits
  float voltage = sensorValue * (5.0 / 15.0); // Convertir el valor leído a voltaje (5V / 15, ya que hay 16 niveles de amplitud)
  
  Serial.print("Sensor value: ");
  Serial.print(sensorValue);
  Serial.print("\tVoltage: ");
  Serial.println(voltage);
  
  delay(200); // Esperar 100 ms antes de la siguiente lectura
}