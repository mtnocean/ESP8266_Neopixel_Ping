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

#include "ESP8266Ping.h"

const IPAddress remote_ip(192, 168, 111, 33);

void setup() {
    Serial.begin(115200);
    pixels.begin(); // Init NeoPixel library
    pixels.setPixelColor(0, pixels.Color(20,0,0));
    pixels.show();

    delay (2000);

    WiFiManager wifiManager;
    //wifiManager.resetSettings();
    wifiManager.autoConnect("AutoConnectAP");

    Serial.println("WiFi connected");
    pixels.setPixelColor(0, pixels.Color(0,20,0));
    pixels.show();
}

void loop() {
    delay(1000);
    Serial.print("Pinging ip ");
    Serial.println(remote_ip);

    if(Ping.ping(remote_ip,1)) 
        { // success
        Serial.print(Ping.averageTime());
        Serial.println(" ms.");

        if (Ping.averageTime() < 25)
            { // green
            pixels.setPixelColor(0, pixels.Color(0,20,0));
            }
        else
            { // yellow
            pixels.setPixelColor(0, pixels.Color(22,22,0)); 
            }
        }
    else {
        Serial.println("Error :(");
        pixels.setPixelColor(0, pixels.Color(20,0,0));
        }

    pixels.show();
}
