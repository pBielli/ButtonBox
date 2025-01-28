// BTNbox_test.ino
#include "ButtonBox.h"
#include "ButtonBox_config.h"

// Pin definitions for encoders
const uint8_t ENCODER1_CLK = 2;
const uint8_t ENCODER1_DT = 3;
const uint8_t ENCODER1_SW = 4;

const uint8_t ENCODER2_CLK = 5;
const uint8_t ENCODER2_DT = 6;
const uint8_t ENCODER2_SW = 7;

const uint8_t ENCODER3_CLK = 8;
const uint8_t ENCODER3_DT = 9;
const uint8_t ENCODER3_SW = 10;

const uint8_t ENCODER4_CLK = 11;
const uint8_t ENCODER4_DT = 12;
const uint8_t ENCODER4_SW = 13;

ButtonBox box;

void setup() {
    Serial.begin(9600);
    Consumer.begin();
    Keyboard.begin();
    
    // Configura encoder per il volume
    box.addEncoder(ENCODER1_CLK, ENCODER1_DT, ENCODER1_SW, new CustomEncoder1());
    
    // Configura encoder per controlli multimediali
    box.addEncoder(ENCODER2_CLK, ENCODER2_DT, ENCODER2_SW, new CustomEncoder2());
    
    // Configura encoder custom con F13-F15
    box.addEncoder(ENCODER3_CLK, ENCODER3_DT, ENCODER3_SW, new CustomEncoder3());
    
    // Configura encoder custom con F16-F18
    box.addEncoder(ENCODER4_CLK, ENCODER4_DT, ENCODER4_SW, new CustomEncoder4());
}

void loop() {
    box.update();
    delay(10);
}