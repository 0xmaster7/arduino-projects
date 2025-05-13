#include <SoftwareSerial.h>
#include <DHT.h>

// Define DHT11 sensor pin and type
#define DHTPIN 3      // Pin connected to the DHT11 sensor
#define DHTTYPE DHT11 // DHT sensor type

// Define Bluetooth RX and TX pins
#define RX_PIN 8   // Bluetooth RX (to TX of BT module)
#define TX_PIN 9   // Bluetooth TX (to RX of BT module)

SoftwareSerial bt(RX_PIN, TX_PIN);  // Create SoftwareSerial object for Bluetooth
DHT dht(DHTPIN, DHTTYPE);           // Create DHT object

void setup() {
  Serial.begin(9600);  // Start Serial Monitor
  bt.begin(9600);      // Start Bluetooth communication
  dht.begin();         // Initialize DHT sensor
  Serial.println("Ready");
  bt.println("Ready");  // Send status to Bluetooth
}

void loop() {
  // Read humidity and temperature
  float hum = dht.readHumidity();       // Read humidity
  float temp = dht.readTemperature();   // Read temperature in Celsius

  // Check if the readings are valid
  if (isnan(hum) || isnan(temp)) {
    Serial.println("Error reading DHT11 sensor!");
    bt.println("Error reading DHT11 sensor!"); // Send error to Bluetooth as well
    delay(5000);  // Delay before trying again
    return;
  }

  // Send formatted data to Bluetooth Terminal
  bt.print("Temp: ");
  bt.print(temp, 2);  // Print 2 decimal places for precision
  bt.print(" °C, Hum: ");
  bt.print(hum, 2);
  bt.println(" %");

  // Print the same data to Serial Monitor for debugging
  Serial.print("Temp: ");
  Serial.print(temp, 2);
  Serial.print(" °C, Hum: ");
  Serial.print(hum, 2);
  Serial.println(" %");

  delay(1000);  // Delay for 5 seconds before taking another reading
}
