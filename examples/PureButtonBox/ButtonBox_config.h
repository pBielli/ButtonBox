

// Azione per encoder con tasti funzione (F13-F14)
class CustomEncoder1 : public InputAction {
    void onPress() override {
        Keyboard.press(KEY_F13);
        Serial.println("F13 Pressed");
    }
    
    void onRelease() override {
        Keyboard.release(KEY_F13);
        Serial.println("F13 Released");
    }
    
    void onRotateCW() override {
        Keyboard.press(KEY_F14);
        Keyboard.release(KEY_F14);
        Serial.println("F14 Pressed");
    }
    
    void onRotateCCW() override {
        Keyboard.press(KEY_F15);
        Keyboard.release(KEY_F15);
        Serial.println("F15 Pressed");
    }
};

// Azione per encoder con tasti funzione (F16-F17)
class CustomEncoder2 : public InputAction {
    void onPress() override {
        Keyboard.press(KEY_F16);
        Serial.println("F16 Pressed");
    }
    
    void onRelease() override {
        Keyboard.release(KEY_F16);
        Serial.println("F16 Released");
    }
    
    void onRotateCW() override {
        Keyboard.press(KEY_F17);
        Keyboard.release(KEY_F17);
        Serial.println("F17 Pressed");
    }
    
    void onRotateCCW() override {
        Keyboard.press(KEY_F18);
        Keyboard.release(KEY_F18);
        Serial.println("F18 Pressed");
    }
};

// Azione per encoder con tasti funzione (F16-F17)
class CustomEncoder3 : public InputAction {
    void onPress() override {
        Keyboard.press(KEY_F19);
        Serial.println("F19 Pressed");
    }
    
    void onRelease() override {
        Keyboard.release(KEY_F19);
        Serial.println("F19 Released");
    }
    
    void onRotateCW() override {
        Keyboard.press(KEY_F20);
        Keyboard.release(KEY_F20);
        Serial.println("F20 Pressed");
    }
    
    void onRotateCCW() override {
        Keyboard.press(KEY_F21);
        Keyboard.release(KEY_F21);
        Serial.println("F21 Pressed");
    }
};

// Azione per encoder con tasti funzione (F16-F17)
class CustomEncoder4 : public InputAction {
    void onPress() override {
        Keyboard.press(KEY_F22);
        Serial.println("F22 Pressed");
    }
    
    void onRelease() override {
        Keyboard.release(KEY_F22);
        Serial.println("F22 Released");
    }
    
    void onRotateCW() override {
        Keyboard.press(KEY_F23);
        Keyboard.release(KEY_F23);
        Serial.println("F23 Pressed");
    }
    
    void onRotateCCW() override {
        Keyboard.press(KEY_F24);
        Keyboard.release(KEY_F24);
        Serial.println("F24 Pressed");
    }
};
