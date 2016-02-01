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
#define TEMPERATURE	Tungsten100W
#define CORRECTION	TypicalSMD5050
CRGB leds[NUM_LEDS];

#include "ESP8266Ping.h"         //https://github.com/dancol90/ESP8266Ping

//const IPAddress remote_ip(192, 168, 111, 23);
//const char* remote_host = "www.google.com";
const char* remote_host[] = {
	"192.168.111.1",
	"c-71-56-236-1.hsd1.co.comcast.net",
	//"xe-9-1-3-sur02.boulder.co.denver.comcast.net",
	"ae-10-sur03.boulder.co.denver.comcast.net",
	"ae-29-ar01.denver.co.denver.comcast.net",
	//"be-11719-cr02.denver.co.ibone.comcast.net",
	//"be-11724-cr02.dallas.tx.ibone.comcast.net",
	//"be-20-pe01.houston.tx.ibone.comcast.net",
	//"as8075-1.2001sixthave.wa.ibone.comcast.net",
	//"oommco.com",
	"www.comcast.net",
	"www.facebook.com",
	"www.live.com",
	"www.google.com",
	};

void setup() {
    Serial.begin(115200);

    FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    // FastLED.addLeds<CHIPSET, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness( BRIGHTNESS );
    FastLED.setTemperature( TEMPERATURE );
    FastLED.setCorrection( CORRECTION );
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
    
    leds[24] = CRGB(CRGB::Green); 
    leds[25] = CRGB(CRGB::LawnGreen); 
    leds[26] = CRGB(CRGB::YellowGreen); 
    leds[27] = CRGB(CRGB::Yellow); 
    leds[28] = CRGB(CRGB::Orange); 
    leds[29] = CRGB(CRGB::OrangeRed); 
    leds[30] = CRGB(CRGB::DarkOrange); 
    leds[31] = CRGB(CRGB::Red); 
}

void setIndicator (const int number)
{
    if(Ping.ping(remote_host[number],1)) {
        Serial.print(Ping.averageTime());
        Serial.println(" ms.");

        if (Ping.averageTime() < 25)
        	leds[number] = CRGB(CRGB::Green);
        else if (Ping.averageTime() < 45)
        	leds[number] = CRGB(CRGB::LawnGreen);
        else if (Ping.averageTime() < 65)
        	leds[number] = CRGB(CRGB::Yellow);
        else if (Ping.averageTime() < 85)
        	leds[number] = CRGB(CRGB::OrangeRed);
        else
        	leds[number] = CRGB(CRGB::Red);
        }
    else {
        Serial.println("Error :(");
        leds[number] = CRGB(CRGB::Red); 
        }
}

void loop() {
    for (int i=0; i < (sizeof(remote_host) / sizeof(remote_host[ 0 ])); i++)
    	setIndicator (i);

    FastLED.show();
    FastLED.delay(1000);
}
