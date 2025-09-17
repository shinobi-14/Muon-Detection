#define SENSOR_PIN 3  // ADC-capable pin (e.g., GPIO34, 35, 32, etc.)

void setup() {
  Serial.begin(115200);      // Start serial communication
  analogReadResolution(12);  // Set ADC resolution: 12 bits = 0-4095

  Serial.print("Raw ADC Value,");
  Serial.println(",Voltage (in V)");
}

void loop() {
  int rawValue = analogRead(SENSOR_PIN);  // Read raw ADC value
  float voltage = (rawValue / 4095.0) * 3.3;  // Convert to voltage (assuming 3.3V reference)

  
  Serial.print(rawValue);
  Serial.print(",");
  Serial.println(voltage, 3);  // Print voltage with 3 decimal places

  delay(500);  // Delay for readability
}
