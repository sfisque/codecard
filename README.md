# The Code Card
![](images/codecard.png)

Code Card is a Wi-Fi-enabled device with an e-paper display that can retrieve content from Oracle Cloud. Code Cards are available on a first-come basis to Oracle OpenWorld and Oracle Code One attendees who sign up for a cloud trial account. Stop by the Groundbreakers Hub to sign up and start configuring your Code Card.

### How did we build the Code Card?
We partnered with [Squarofumi](http://www.sqfmi.com/), creators of [Badgy](https://www.tindie.com/products/squarofumi/badgy-iot-badge/), an IoT badge, to create the Code Card.

![](images/badgy.jpg)

# Codecard Resources

## Below is useful information for working with the Codecard provided by Oracle. 

### Arduino IDE Configuration:

Make sure you have:
- Installed the ESP8266 boards 
- Installed the GxEPD2 library and it's dependencies
- Selected the board 'Generic ESP8266 Module'. 

Configure the board as per the information below (the changes from default are highlighted):
- Upload Speed; “115200”
- CPU Frequency: “80 MHz”
- Crystal Frequency: “26 MHz”
- **_Flash Size: “4MB (FS:3MB OTA:~512KB)”_**
- **_Flash Mode: “DIO”_**
- Flash Frequency: “40MHz”
- Reset Method: “dtr (aka nodemcu)”
- Debug port: “Disabled”
- Debug Level: “None”
- IwIP Variant: “v2 Lower Memory”
- VTables: “Flash”
- Builtin Led: “2”
- Erase Flash: “Only Sketch”
- Port: This is the port that shows up once you turn on the CodeCard and press the 'A' button
- Programmer: “ArduinoISP”  

#### Important: To make sure the board is recognised when uploading, make sure you press the 'A' button when you turn the board on!

## Notes for Writing Programs:

### Code must include the following line before ```void setup()``` :
```c++
GxEPD2_BW<GxEPD2_270, GxEPD2_270::HEIGHT> display(GxEPD2_270(/*CS=D8*/ 2, /*DC=D3*/ 0, /*RST=D4*/ 4, /*BUSY=D2*/ 5)); // 2.7" b/w 264x176
```

### To Set Font:
1. Go the the sketchbook folder where the library is installed (can be found in Arduino preferences)
2. Find the ```libraries``` folder
3. find the ```Adafruit_GFX_Library``` folder
4. Open the ```Fonts``` folder
5. Find the font you want and copy the filename
6. In your sketch, include the file 
```c++
 #include <Fonts/#FONT_FILE.h>
 ```
7. Set the font using the display.setFont command and appending the font name with & while also removing the .h extention 
```c++ 
display.setFont(&FONT_NAME);
```

### To Set Cursor Position:
#### Note: The cursor automtically moves to the end of any text you display so it doesn't overlap, as well as wraps at the edge of the screen

```c++
display.setCursor(x,y);
```
Valid ranges are: x: 0 - 264, y: 0 - 176

### Display Text:
Once the position, font and colour are configured, text can be displayed with:
```c++
display.print('TEXT HERE');
```

### Valid Colours:
- GxEPD_WHITE
- GxEPD_BLACK

### Fill Screen / Blank with a Colour:
```c++
display.fillScreen(<COLOR>);
```

### Digital pin (top left back of code card)

The D8 pin maps to pin 15 on the ESP board.
Can set the pin to an digital output pin by:
```c++
pinMode(other_led, OUTPUT);
```

