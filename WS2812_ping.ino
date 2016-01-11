#include <ESP8266WiFi.h>         //https://github.com/esp8266/Arduino

#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager

#define SERIAL_DEBUG true
#include <SerialDebug.h>         //https://github.com/rlogiacco/MicroDebug

#include <Adafruit_NeoPixel.h>   //https://github.com/adafruit/Adafruit_NeoPixel
#define PIN            15
#define NUMPIXELS      16
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
    Serial.begin(115200);
    pixels.begin(); // Init NeoPixel library
    pixels.setPixelColor(0, pixels.Color(10,0,0));
    pixels.show();

    delay (2000);

    WiFiManager wifiManager;
    //wifiManager.resetSettings();
    wifiManager.autoConnect("AutoConnectAP");

    Serial.println("WiFi connected");
    pixels.setPixelColor(0, pixels.Color(0,12,0));
    pixels.show();
}

void loop() {

}
