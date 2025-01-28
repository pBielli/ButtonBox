
// Azione per il controllo del volume
class VolumeControl : public InputAction {
    void onPress() override {
        Consumer.write(MEDIA_VOLUME_MUTE);
        Serial.println("Volume Mute");
    }
    
    void onRotateCW() override {
        Consumer.write(MEDIA_VOLUME_UP);
        Serial.println("Volume Up");
    }
    
    void onRotateCCW() override {
        Consumer.write(MEDIA_VOLUME_DOWN);
        Serial.println("Volume Down");
    }
};

// Azione per il controllo multimediale
class MediaControl : public InputAction {
    void onPress() override {
        Consumer.write(MEDIA_PLAY_PAUSE);
        Serial.println("Play/Pause");
    }
    
    void onRotateCW() override {
        Consumer.write(MEDIA_NEXT);
        Serial.println("Next Track");
    }
    
    void onRotateCCW() override {
        Consumer.write(MEDIA_PREVIOUS);
        Serial.println("Previous Track");
    }
};

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
