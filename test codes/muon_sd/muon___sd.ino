#include <SPI.h>
#include <SD.h>

// Sensor pin (use stable ADC1 pin)
#define SENSOR_PIN 3  


#define SD_CS_PIN 18    // CS pin for SD card
#define SD_MOSI 0
#define SD_MISO 19
#define SD_SCK  1

SPIClass customSPI(2);  // or HSPI if needed

File dataFile;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);  // 12-bit ADC (0-4095)

  // Initialize custom SPI bus
  customSPI.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS_PIN);

  if (!SD.begin(SD_CS_PIN, customSPI)) {
    Serial.println("SD card initialization failed!");
    while (1);  // Halt
  }
  Serial.println("SD card initialized.");

  // Create file and write CSV header if it doesn't exist
  dataFile = SD.open("/datalog.csv", FILE_WRITE);
  if (dataFile) {
    if (dataFile.size() == 0) {
      dataFile.println("Raw ADC Value,Voltage (in V)");
    }
    dataFile.close();
  } else {
    Serial.println("Error opening datalog.csv for writing.");
  }
}

void loop() {
  int rawValue = analogRead(SENSOR_PIN);
  float voltage = (rawValue / 4095.0) * 3.3;

  // Print to Serial
  Serial.printf("%d,%.3f\n", rawValue, voltage);

  // Append data to SD card
  dataFile = SD.open("/datalog.csv", FILE_APPEND);
  if (dataFile) {
    dataFile.printf("%d,%.3f\n", rawValue, voltage);
    dataFile.close();
  } else {
    Serial.println("Error writing to datalog.csv");
  }

  delay(500);  // Sample every 500 ms
}
