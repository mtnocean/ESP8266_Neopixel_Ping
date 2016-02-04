# ESP8266 Neopixel Ping
### Multi IP Address Ping Indicator

Simultaneously displays the Ping status of Multiple IP addresses 
on a 4x8 RGB LED array

![](/images/Ping_Animation.gif)

## Software
Every two seconds the software pings a list of IP addresses or domain names. The response times of each ping are indicated on the LEDs, one LED per item in the list. Green is for fast response, yellow for slow , red for none.

Here I have set the top line to be my local routers. The first LED is my WiFi router, then the LEDs to the right of it are routers of my ISP. The LEDs on the bottom are specific websites. Any LED can be left blank by entering a NULL item in the list.
	
## Hardware

Adafruit Feather HUZZAH with ESP8266 WiFi
https://www.adafruit.com/products/2821
![](/images/ESP8266_Feather_Huzzah.png)

NeoPixel FeatherWing - 4x8 RGB LED
https://www.adafruit.com/products/2945
![](/images/NeoPixel_FeatherWing.png)

The WS2812 LED data is sent on pin 13

**Note**: The default pin on the FeatherWing does not work with the ESP8266. 
The jumper on the back of the wing must be cut then another jumper 
must be shorted with a blob of solder. I used pin 13 
![](/images/NeoPixel_FeatherWing_Back.png)

## Credits

##### Arduino-Ping
Where all the actual ping code came from  
Copyright (c) 2010 by Blake Foster  
blfoster@vassar.edu  
https://github.com/BlakeFoster/Arduino-Ping

##### WiFi Manager
https://github.com/tzapu/WiFiManager

##### FastLED
https://github.com/FastLED/FastLED
