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
#define TEMPERATURE	Halogen
#define CORRECTION	TypicalSMD5050
CRGB leds[NUM_LEDS];

#include "ESP8266Ping.h"         //https://github.com/dancol90/ESP8266Ping

//const IPAddress remote_ip(192, 168, 111, 23);
//const char* remote_host = "www.google.com";
const char* remote_host[] = {
	"192.168.111.1",
	"c-71-56-236-1.hsd1.co.comcast.net",
	"xe-9-1-3-sur02.boulder.co.denver.comcast.net",
	"ae-10-sur03.boulder.co.denver.comcast.net",
	"ae-29-ar01.denver.co.denver.comcast.net",
	"be-33652-cr01.1601milehigh.co.ibone.comcast.net",
	"be-11719-cr02.denver.co.ibone.comcast.net",
	"hu-0-10-0-6-pe02.910fifteenth.co.ibone.comcast.net",
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	"www.google.com", NULL,
	"www.comcast.net", NULL,
	"www.live.com", NULL,
	"www.facebook.com", NULL,
	NULL,
	"www.youtube.com", NULL,
	"www.twitter.com", NULL,
	"www.apple.com", NULL,
	"www.microsoft.com", NULL
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
}


void setIndicator (const int number)
{
    if(remote_host[number] != NULL)
		if(Ping.ping(remote_host[number],1)) 
			{
			DEBUG(Ping.averageTime(), "ms.", remote_host[number]);
		
			if (Ping.averageTime() < 25)
				leds[number] = CRGB(CRGB::Green);
			else if (Ping.averageTime() < 40)
				leds[number] = CRGB(55,230,0);
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
		if (WiFi.status() == WL_CONNECTED)
			setIndicator (i);	
			
	DEBUG("- - - - - - -");

	if (WiFi.status() != WL_CONNECTED)
		{
		Serial.println("Error WiFi not connected");
		FastLED.clear();
		leds[0] = CRGB(CRGB::Red); 
		}

    FastLED.show();
    FastLED.delay(2000);
}
