# Environment-Monitor
This is a board that serves as an environment sensor, recording the temperature, humidity, air pressure, brightness, and air quality of the area around it. It does this through the use of 5 sensors: TMP102AIDR, AHT20-F, BMP388, LTR303, and AGS10. The information can be displayed of the built in SSD1306 0.91 screen.
# Why I Made It
Not surprisingly I spend a lot of time sitting indoors in my room on my computer.  With this, I often have my door closed and sometimes the window open. I wanted a device that can monitor my room so I can make optimize my environment so if it detects that it's getting to hot (for example) I can open the window more or open my door. 

# Pictures

![alt text](board.png)
![alt text](image.png)
![alt text](image2.png)

# BOM
|Name             |Purpose                           |Quantity|Total Cost (USD)|Link|Distributor|
|-----------------|----------------------------------|--------|----------------|----|-----------|
|3.7v Battery     |Power when not plugged in         |        |6.57            |    |Aliexpress |
|SSD1306 Display  |Displaying Measured Stats         |        |2.20            |    |Aliexpress |
|JST Connector    |Battery Connector                 |        |0.67            |    |LCSC       |
|USB C Receptacle |Programming and Power             |        |0.41            |    |LCSC       |
|4.3k Resistor    |Configuration Resistor            |        |0.11            |    |LCSC       |
|62k Resistor     |Configuration Resistor            |        |0.11            |    |LCSC       |
|3k Resistor      |Configuration Resistor For BQ24075|        |0.12            |    |LCSC       |
|2.2k Resistor    |I2C Pullups                       |        |0.10            |    |LCSC       |
|1k Resistor      |For LEDs                          |        |0.10            |    |LCSC       |
|10k Resistor     |Pull Ups                          |        |0.10            |    |LCSC       |
|5.1k Resistor    |For USB CC1 and CC2               |        |0.10            |    |LCSC       |
|4.7uF Capacitor  |Decoupling Capacitor              |        |0.30            |    |LCSC       |
|100nF Resistor   |Decoupling                        |        |0.25            |    |LCSC       |
|USBLC6-2SC6      |Protection for USB                |        |0.16            |    |LCSC       |
|BQ24075RGTR      |Power Path and Battery Charging   |        |1.05            |    |LCSC       |
|TPAP2112K-3.0TRG1|Power Regulator for AGS10         |        |0.35            |    |LCSC       |
|AMS1117-3.3      |Power Regulator                   |        |0.42            |    |LCSC       |
|LTR-303ALS-01    |Light Sensor                      |        |0.41            |    |LCSC       |
|AGS10            |TVOC/Air Quality Sensor           |        |1.59            |    |LCSC       |
|BMP388           |Air Pressure Sensor               |        |2.81            |    |LCSC       |
|TMP102AIDRLR     |Accurate Temperature Sensor       |        |1.27            |    |LCSC       |
|AHT20-F          |Humidity Sensor                   |1       |0.76            |    |LCSC       |
|ESP32-S3         |Microcontroller for board         |1       |5.25            |    |LCSC       |
|Stencil          |Help With Soldering               |        |7.11            |    |JLCPCB     |
|PCB              |Place Components On               |        |5.11            |    |JLCPCB     |
