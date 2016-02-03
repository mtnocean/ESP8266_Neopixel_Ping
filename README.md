#ESP8266 Neopixel Ping
##Multi IP Address Ping Indicator

Simultaneously displays the Ping status of Multiple IP addresses 
on a 4x8 RGB LED array
	
###Hardware

Adafruit Feather HUZZAH with ESP8266 WiFi
[https://www.adafruit.com/products/2821]
(https://www.adafruit.com/products/2821)

NeoPixel FeatherWing - 4x8 RGB LED
[https://www.adafruit.com/products/2945]
(https://www.adafruit.com/products/2945)

The WS2812 LED data is sent on pin 13

**Note**: The default pin on the FeatherWing does not work with the ESP8266. 
The jumper on the back of the wing must be cut then another jumper 
must be shorted with a blob of solder. I used pin 13 