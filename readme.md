# Arduino ButtonBox

A versatile Arduino library for creating a customizable input device with rotary encoders (EC11) and buttons. The ButtonBox can be configured as a media controller, keyboard macro device, or any other HID input device.

## Features

- Support for up to 16 inputs (encoders and/or buttons)
- Built-in debouncing
- Easy-to-use action system for input handling
- Pre-configured actions for:
  - Media controls (volume, play/pause, next/previous track)
  - Custom function key mapping (F13-F18)
- Extensible design for custom actions

## Hardware Requirements

- Arduino Pro Micro or any ATmega32U4 based board (with HID support)
- EC11 rotary encoders
- Push buttons (optional)

## Pin Configuration

Default pin configuration for 4 encoders:

| Encoder | CLK | DT | SW |
|---------|-----|----|----|
| 1       | 2   | 3  | 4  |
| 2       | 5   | 6  | 7  |
| 3       | 8   | 9  | 10 |
| 4       | 11  | 12 | 13 |

## Installation

1. Download this repository
2. Install the [HID-Project](https://github.com/NicoHood/HID) library in your Arduino IDE
3. Copy the `ButtonBox` folder to your Arduino libraries folder

## Basic Usage

Here's a minimal example to get started:

```cpp
#include "ButtonBox.h"
#include "ButtonBox_config.h"

ButtonBox box;

void setup() {
    Consumer.begin();
    Keyboard.begin();
    
    // Configure encoder for volume control
    box.addEncoder(2, 3, 4, new VolumeControl());
}

void loop() {
    box.update();
    delay(10);
}
```

## Creating Custom Actions

You can create custom actions by extending the `InputAction` class:

```cpp
class MyCustomAction : public InputAction {
    void onPress() override {
        // Button press action
    }
    
    void onRelease() override {
        // Button release action
    }
    
    void onRotateCW() override {
        // Clockwise rotation action
    }
    
    void onRotateCCW() override {
        // Counter-clockwise rotation action
    }
};
```

## Testing

To test if your ButtonBox is working correctly:

1. Upload the example sketch to your Arduino
2. Open the Serial Monitor (baud rate: 9600)
3. Try these tests:
   - Rotate Encoder 1: Should control system volume
   - Press Encoder 1: Should mute/unmute
   - Rotate Encoder 2: Should control media next/previous
   - Press Encoder 2: Should play/pause
   - Rotate/press Encoders 3-4: Should trigger F13-F18 keys

You should see corresponding messages in the Serial Monitor for each action.

## Troubleshooting

- If encoders are working in reverse, swap the CLK and DT pin connections
- If buttons seem to trigger multiple times, try adjusting the `DEBOUNCE_DELAY` value in ButtonBox.h
- Make sure you're using a board with HID support (ATmega32U4 based)

## Contributing

Feel free to open issues or submit pull requests for improvements and bug fixes.

## License

This project is released under the MIT License.
