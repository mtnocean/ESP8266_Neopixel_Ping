# ESP8266 Neopixel Ping
### Multi IP Address Ping Indicator

Simultaneously displays the Ping status of Multiple IP addresses 
on a 4x8 RGB LED array that updates every two seconds

### "Hey WiFi's not working!"

Now when somebody says that, you can have an indicator to show you what's happening. All red LEDs means your internet connection really is down. Watch your internet service quality change, even when you are not actively online

![](/images/Ping_Animation.gif)

## Software
Every two seconds the software pings a list of IP addresses or domain names. The response times of each ping are indicated on the LEDs, one LED per item in the list. Green is for fast, green-yellow and yellow for slower, orange and red for slow to none.

Here I have set the top line to be my local routers. The first LED is my WiFi router, then the LEDs to the right of it are routers of my ISP. The LEDs on the bottom are specific websites. Any LED can be left blank by entering a NULL item in the list.
	
## Hardware

Adafruit Feather HUZZAH with ESP8266 WiFi
https://www.adafruit.com/products/2821
![](/images/ESP8266_Feather_Huzzah.png)

NeoPixel FeatherWing - 4x8 RGB LED
https://www.adafruit.com/products/2945
![](/images/NeoPixel_FeatherWing.png)

These are WS2812 LEDs. The data signal is sent on pin 13 of the ESP8266.

**Note**: The default pin on the FeatherWing does not work with the ESP8266. 
The jumper on the back of the wing must be cut then another jumper 
must be shorted with a blob of solder. I used pin 13.
![](/images/NeoPixel_FeatherWing_Back.png)

## Configuration
Sites to ping must be listed in the source code before compilation

I prefer to have the first line of eight LEDs are my ISP's routers to the internet.

Use the traceroute utility to find these routers. Traceroute lists all of the routers in line to the source.
Line 1 ```192.168.1.1``` is the WiFi router. 
Line 2 ```xe-9-1-3-sur02.boulder.co.denver.comcast.net (68.86.129.29) ``` is the name and IP address of the first 
router of my ISP.
```
> traceroute 8.8.8.8
traceroute to 8.8.8.8 (8.8.8.8), 64 hops max, 52 byte packets
 1  192.168.1.1 (192.168.1.1)  2.090 ms  2.816 ms  1.151 ms
 2  xe-9-1-3-sur02.boulder.co.denver.comcast.net (68.86.129.29)  10.069 ms  11.231 ms  11.802 ms
 3  ae-10-sur03.boulder.co.denver.comcast.net (162.151.51.33)  18.547 ms  10.179 ms  10.486 ms
 4  ae-29-ar01.denver.co.denver.comcast.net (162.151.50.249)  17.275 ms  12.704 ms  11.743 ms
 5  be-33652-cr01.1601milehigh.co.ibone.comcast.net (68.86.92.121)  4099.176 ms  3304.423 ms  2175.305 ms
 6  be-11719-cr02.denver.co.ibone.comcast.net (68.86.86.77)  14.441 ms  16.605 ms  15.927 ms
 7  hu-0-10-0-6-pe02.910fifteenth.co.ibone.comcast.net (68.86.83.14)  13.016 ms  12.925 ms  19.726 ms
 8  as15169-1-c.910fifteenth.co.ibone.comcast.net (23.30.206.106)  59.012 ms  58.685 ms  61.827 ms
 9  216.239.42.249 (216.239.42.249)  12.805 ms  12.628 ms  11.918 ms
10  google-public-dns-a.google.com (8.8.8.8)  14.797 ms  16.668 ms  12.908 ms
```
The routers can be set by name or IP address. From line 2 above ```xe-9-1-3-sur02.boulder.co.denver.comcast.net``` 
works as does ```68.86.129.29```. NULL entries represent blank LEDs.

The rest of the LEDs are websites
```
const char* remote_host[] = {
	// first line of 8
	"192.168.111.1",
	"xe-9-1-3-sur02.boulder.co.denver.comcast.net",
	"ae-10-sur03.boulder.co.denver.comcast.net",
	"ae-29-ar01.denver.co.denver.comcast.net",
	"be-33652-cr01.1601milehigh.co.ibone.comcast.net",
	"be-11719-cr02.denver.co.ibone.comcast.net",
	"hu-0-10-0-6-pe02.910fifteenth.co.ibone.comcast.net",
	"as15169-1-c.910fifteenth.co.ibone.comcast.net",
	// second line of 8 blank LEDs
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	// third line
	"www.google.com", NULL,
	"www.comcast.net", NULL,
	"www.live.com", NULL,
	"www.facebook.com", NULL,
	// fourth line
	NULL,
	"www.youtube.com", NULL,
	"www.twitter.com", NULL,
	"www.apple.com", NULL,
	"www.microsoft.com", NULL
	};
```

Once you list the sites, compile and upload to the ESP8266

# Limitations
The  list of IP addresses or domain names is fixed at compile time.

# Credits

#### ESP8266Ping - Ping library for ESP8266
The actual ping code  
Copyright (c) 2015 Daniele Colanardi.  
https://github.com/dancol90/ESP8266Ping

#### Arduino-Ping
Copyright (c) 2010 by Blake Foster  
blfoster@vassar.edu  
https://github.com/BlakeFoster/Arduino-Ping

#### WiFi Manager
Controls the connection to the WiFi router and handles the SSID and password  
https://github.com/tzapu/WiFiManager

#### FastLED
Controls the LEDs  
https://github.com/FastLED/FastLED
