#ifndef CONFIG_H
#define CONFIG_H

// Pinout
#define SDA_PIN 10
#define SCL_PIN 9

#define SCK 12
#define CSB 13
#define MISO 14
#define MOSI 21

#define ALRT 38
#define INTR 39


// Screen
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1 
#define SCREEN_ADDRESS 0x3C   
#define SCREEN_WIRE &Wire

#define SEALEVELPRESSURE_HPA (1013.25)

struct totalData {
    //AGS10
    int TVOC = 0;

    // BMP388
    float pressure = 0.0;
    float altitude = 0.0;
    
    //AHT20
    float humidity = 0.0;

    //TMP102
    float temperature = 0.0;

    //LTR303
    uint16_t visbleAndIR = 0;
    uint16_t IR = 0;
};

#endif