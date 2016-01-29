#include <ESP8266WiFi.h>         //https://github.com/esp8266/Arduino

#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager

#define SERIAL_DEBUG true
#include <SerialDebug.h>         //https://github.com/rlogiacco/MicroDebug

#include <FastLED.h>             //https://github.com/FastLED/FastLED
#define DATA_PIN    13
#define CLOCK_PIN   14
#define NUM_LEDS    32
#define CHIPSET     WS2812B
#define COLOR_ORDER GRB
#define BRIGHTNESS  16
CRGB leds[NUM_LEDS];

#include "ESP8266Ping.h"         //https://github.com/dancol90/ESP8266Ping

//const IPAddress remote_ip(192, 168, 111, 23);
//const char* remote_host = "www.google.com";
const char* remote_host = "192.168.111.23";

void setup() {
    Serial.begin(115200);

    FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    // FastLED.addLeds<CHIPSET, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness( BRIGHTNESS );
    leds[0] = CRGB(CRGB::Red); 
    FastLED.show();
    delay (2000);

    WiFiManager wifiManager;
    //wifiManager.resetSettings();
    wifiManager.autoConnect("AutoConnectAP");

    Serial.println("WiFi connected");
    leds[0] = CRGB(CRGB::Green); 
    FastLED.show();
    delay (2000);
}

void loop() {
    delay(1000);
    Serial.print("Pinging ip ");
    Serial.println(remote_host);

    if(Ping.ping(remote_host,1)) 
        { // success
        Serial.print(Ping.averageTime());
        Serial.println(" ms.");

        if (Ping.averageTime() < 25)
            { // green
        leds[0] = CRGB(CRGB::Green); 
            }
        else
            { // yellow
        leds[0] = CRGB(CRGB::Yellow); 
            }
        }
    else {
        Serial.println("Error :(");
        leds[0] = CRGB(CRGB::Red); 
        }

    FastLED.show();
}
