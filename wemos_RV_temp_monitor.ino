#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <DHT.h>

#define OLED_ADDRESS 0x3C // OLED display address
#define OLED_SDA 4        // OLED SDA pin
#define OLED_SCL 5        // OLED SCL pin

#define ONE_WIRE_BUS 2    // Dallas 1-Wire bus pin

#define DHT_PIN 3         // DHT11 data pin

#define TEMP_REFRESH_INTERVAL 2000 // Temperature refresh interval in milliseconds

Adafruit_SSD1306 display(128, 64, &Wire, OLED_ADDRESS);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DHT dht(DHT_PIN, DHT11);

int temp1, temp2,temp3, humidity;


void setup() {
  Serial.begin(9600);
  Serial.println("Temperature and Humidity Sensor Test");

  // Initialize OLED display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS);
  display.display();
  delay(2000);
  display.clearDisplay();

  // Initialize Dallas temperature sensors
  sensors.begin();

  // Initialize DHT11 sensor
  dht.begin();
}

void loop() {
  // Request temperatures
  sensors.requestTemperatures();
  
  // Read temperature values
  temp1 = sensors.getTempCByIndex(0);
  temp2 = sensors.getTempCByIndex(1);
  temp3 = sensors.getTempCByIndex(2);

  // Read humidity value
  humidity = dht.readHumidity();

  // Output temperature and humidity values to serial monitor
  Serial.print("Fridge: ");
  Serial.print(temp1);
  Serial.println(" °C");
  
  Serial.print("Cabin: ");
  Serial.print(temp2);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  
  
  // Update OLED display
  display.clearDisplay();
  
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Fridge: ");
  display.print(temp1);
  display.println(" C");
  
  display.setCursor(0, 10);
  display.print("Cabin: ");
  display.print(temp2);
  display.println(" C");

  // Calculate the difference between temp1 and temp2
   int tempDiff = round(temp1) - round(temp2);
   int tempDiff2 = temp2 - temp3;
 
  display.setCursor(0, 20);
  display.print("FridgeDiff: ");
  display.print(tempDiff);
  display.println(" C");

  display.setCursor(0, 30);
  display.print("Cabin Humidity:");
  display.print(humidity);
  display.println("%");
  
  
  display.setCursor(0, 40);
  display.print("Ext Temp: ");
  display.print(temp3);
  //calculates interior and exterior temp differences
  display.setCursor(0, 50);
  display.print("Int/Out Diff: ");
  display.print(tempDiff2);
  display.println(" C");
  
  //Display will not refresh/print without this command
  display.display();
  
  delay(TEMP_REFRESH_INTERVAL);
}
