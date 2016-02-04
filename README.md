#ESP8266 Neopixel Ping
##Multi IP Address Ping Indicator

Simultaneously displays the Ping status of Multiple IP addresses 
on a 4x8 RGB LED array

![](/images/Ping_Animation.gif)
	
###Hardware

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

##Credits

#####Arduino-Ping
Where all the actual ping code came from  
Copyright (c) 2010 by Blake Foster  
blfoster@vassar.edu  
https://github.com/BlakeFoster/Arduino-Ping
