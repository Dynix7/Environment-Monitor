#include <Arduino.h>
#include <Wire.h>

#include <AGS10.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BMP3XX.h"
#include <Adafruit_AHTX0.h>
#include "Adafruit_LTR329_LTR303.h"
#include <SparkFunTMP102.h>


#include "config.hpp"

struct totalData data;


Adafruit_SSD1306 SCREEN(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_WIRE, OLED_RESET);
AGS10 AGSSensor = AGS10();
Adafruit_BMP3XX BMPSensor;
Adafruit_AHTX0 AHT20;
Adafruit_LTR303 LTR = Adafruit_LTR303();
TMP102 TMP;

// Prototypes
void initScreen();
void updateScreen();

void initAGS();
void initBMP();
void initAHT();
void initLTR();
void initTMP();

void readAllData();



void setup() {
    Serial.begin(115200);

    pinMode(CSB, OUTPUT);
    pinMode(ALRT, INPUT);
    
    Wire.begin(SDA_PIN, SCL_PIN);
    Wire.setClock(400000);


    initScreen();

    initAGS();
    initBMP();
    initAHT();
    initLTR();
    initTMP();
}


void loop() {
    readAllData();
    updateScreen();

    delay(2000);
}

void initScreen() {
    SCREEN.begin(SSD1306_SWITCHCAP, SCREEN_ADDRESS);
    SCREEN.clearDisplay();
    SCREEN.setTextSize(2);
    SCREEN.setTextColor(SSD1306_WHITE);

    SCREEN.print("Starting...");
    SCREEN.display();
}

void updateScreen() {
    SCREEN.clearDisplay();
    SCREEN.setTextSize(1);
    SCREEN.setCursor(0, 0);

    SCREEN.print("Temperature: ");
    SCREEN.println(data.temperature);

    SCREEN.print("Humidity: ");
    SCREEN.println(data.humidity);

    SCREEN.print("TVOC: ");
    SCREEN.println(data.TVOC);

    SCREEN.print("Pressure: ");
    SCREEN.println(data.pressure);

    SCREEN.print("Altitude: ");
    SCREEN.println(data.altitude);

    SCREEN.print("Visible + IR: ");
    SCREEN.println(data.visbleAndIR);

    SCREEN.print("IR: ");
    SCREEN.println(data.IR);

    SCREEN.display();
}

void initAGS() {
    AGSSensor.begin();
    AGSSensor.calibrateFact();
}

void initBMP() {
    if(!BMPSensor.begin_SPI(CSB, SCK, MISO, MOSI)) {
        Serial.print("BMP Error");
    }

    BMPSensor.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
    BMPSensor.setPressureOversampling(BMP3_OVERSAMPLING_4X);
    BMPSensor.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
    BMPSensor.setOutputDataRate(BMP3_ODR_50_HZ);
}

void initAHT() {
    if (!AHT20.begin()) {
        Serial.print("AHT Error");
    }
}

void initLTR() {
    if (!LTR.begin(&Wire)) {
        Serial.print("LTR Error");
    }

    LTR.setGain(LTR3XX_GAIN_1);
    LTR.setIntegrationTime(LTR3XX_INTEGTIME_150);
    LTR.setMeasurementRate(LTR3XX_MEASRATE_150);
}

void initTMP() {
    if (!TMP.begin()) {
        Serial.print("TMP Error");
    }
    TMP.setConversionRate(1);
    TMP.setExtendedMode(0);
}

void readAllData() {

    //BMP388
    BMPSensor.performReading();
    data.pressure = (BMPSensor.pressure / 100.0);
    data.altitude = BMPSensor.readAltitude(SEALEVELPRESSURE_HPA);

    //AHT20
    sensors_event_t humidity, temp;
    AHT20.getEvent(&humidity, &temp);
    data.humidity = humidity.relative_humidity;

    //AGOS
    data.TVOC = AGSSensor.readTVOC();

    //TMP
    TMP.wakeup();
    data.temperature = TMP.readTempF();
    TMP.sleep();

    // LTR
    if (LTR.newDataAvailable()) {
        LTR.readBothChannels(data.visbleAndIR, data.IR);
    }


}