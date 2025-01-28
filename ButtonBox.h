// ButtonBox.h
#ifndef ButtonBox_h
#define ButtonBox_h

#include <HID-Project.h>

#define MAX_INPUTS 16  // Aumentato il numero massimo di input supportati

// Definizione dei tipi di input supportati
enum InputType {
    ENCODER,
    BUTTON
};

// Classe base per le azioni
class InputAction {
public:
    virtual void onPress() {}
    virtual void onRelease() {}
    virtual void onRotateCW() {}    // Rotazione oraria (clockwise)
    virtual void onRotateCCW() {}   // Rotazione antioraria (counter-clockwise)
};

class ButtonBox {
private:
    struct Input {
        InputType type;
        union {
            struct {
                uint8_t pin;
            } button;
            struct {
                uint8_t clkPin;
                uint8_t dtPin;
                uint8_t swPin;
                int lastClkState;
            } encoder;
        };
        InputAction* action;
        bool lastState;
        unsigned long lastDebounceTime;
    };

    Input inputs[MAX_INPUTS];
    uint8_t inputCount;
    static const unsigned long DEBOUNCE_DELAY = 50;

public:
    ButtonBox() : inputCount(0) {}

    // Aggiunge un encoder EC11
    void addEncoder(uint8_t clkPin, uint8_t dtPin, uint8_t swPin, InputAction* action) {
        if (inputCount >= MAX_INPUTS) return;

        Input& input = inputs[inputCount++];
        input.type = ENCODER;
        input.encoder.clkPin = clkPin;
        input.encoder.dtPin = dtPin;
        input.encoder.swPin = swPin;
        input.encoder.lastClkState = 0;
        input.action = action;
        input.lastState = false;
        input.lastDebounceTime = 0;

        pinMode(clkPin, INPUT);
        pinMode(dtPin, INPUT);
        pinMode(swPin, INPUT_PULLUP);
        input.encoder.lastClkState = digitalRead(clkPin);
    }

    // Aggiunge un pulsante semplice
    void addButton(uint8_t pin, InputAction* action) {
        if (inputCount >= MAX_INPUTS) return;

        Input& input = inputs[inputCount++];
        input.type = BUTTON;
        input.button.pin = pin;
        input.action = action;
        input.lastState = false;
        input.lastDebounceTime = 0;

        pinMode(pin, INPUT_PULLUP);
    }

    // Aggiorna lo stato di tutti gli input
    void update() {
        for (uint8_t i = 0; i < inputCount; i++) {
            Input& input = inputs[i];
            
            switch (input.type) {
                case ENCODER:
                    updateEncoder(input);
                    break;
                    
                case BUTTON:
                    updateButton(input);
                    break;
            }
        }
    }

private:
    void updateEncoder(Input& input) {
        // Gestione della rotazione
        int currentClkState = digitalRead(input.encoder.clkPin);
        
        if (currentClkState != input.encoder.lastClkState && currentClkState == HIGH) {
            if (digitalRead(input.encoder.dtPin) != currentClkState) {
                input.action->onRotateCW();
            } else {
                input.action->onRotateCCW();
            }
        }
        input.encoder.lastClkState = currentClkState;

        // Gestione del pulsante dell'encoder
        bool currentState = digitalRead(input.encoder.swPin) == LOW;
        if (currentState != input.lastState) {
            if ((millis() - input.lastDebounceTime) > DEBOUNCE_DELAY) {
                if (currentState) {
                    input.action->onPress();
                } else {
                    input.action->onRelease();
                }
                input.lastState = currentState;
                input.lastDebounceTime = millis();
            }
        }
    }

    void updateButton(Input& input) {
        bool currentState = digitalRead(input.button.pin) == LOW;
        if (currentState != input.lastState) {
            if ((millis() - input.lastDebounceTime) > DEBOUNCE_DELAY) {
                if (currentState) {
                    input.action->onPress();
                } else {
                    input.action->onRelease();
                }
                input.lastState = currentState;
                input.lastDebounceTime = millis();
            }
        }
    }
};

#endif