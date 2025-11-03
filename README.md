# Arduino Uno Timemachine Project

This project is set up for programming an Arduino Uno using PlatformIO in VS Code.

## Hardware Requirements

- Arduino Uno board
- USB cable (A to B)
- Optional: Breadboard, LEDs, resistors, sensors, buttons

## Software Requirements

- Visual Studio Code
- PlatformIO extension for VS Code
- Arduino drivers (usually auto-installed)

## Getting Started

### 1. Install PlatformIO Extension

1. Open VS Code
2. Go to Extensions (Ctrl+Shift+X)
3. Search for "PlatformIO IDE"
4. Install the extension by PlatformIO

### 2. Connect Your Arduino

1. Connect your Arduino Uno to your computer via USB
2. Note the COM port it's assigned to (check Device Manager on Windows)

### 3. Build and Upload

1. Open the project folder in VS Code
2. PlatformIO will automatically detect the project
3. Use the PlatformIO toolbar at the bottom or:
   - **Build**: Click the checkmark (✓) or `Ctrl+Alt+B`
   - **Upload**: Click the arrow (→) or `Ctrl+Alt+U`
   - **Serial Monitor**: Click the plug icon or `Ctrl+Alt+S`

## Project Structure

```
timemachine/
├── src/
│   └── main.cpp          # Main Arduino sketch
├── lib/                  # Custom libraries
├── platformio.ini        # PlatformIO configuration
└── README.md            # This file
```

## Example Code Features

The included `main.cpp` demonstrates:

- **Digital I/O**: Button input with debouncing, LED output
- **Serial Communication**: Debug messages via USB serial
- **Custom Functions**: Reusable code for blinking and sensor reading
- **Best Practices**: Proper pin definitions, debouncing, non-blocking code

## Pin Configuration

- **Pin 13**: Built-in LED (output)
- **Pin 2**: Button input (with internal pullup)
- **A0-A5**: Analog sensor inputs (available)
- **Pins 3-12**: Additional digital I/O (available)

## Serial Monitor

To view debug messages:

1. Upload your code to the Arduino
2. Open Serial Monitor in PlatformIO (plug icon)
3. Set baud rate to 9600
4. Press the reset button on Arduino to see startup messages

## Common Commands

- **Build**: `pio run`
- **Upload**: `pio run --target upload`
- **Serial Monitor**: `pio device monitor`
- **Clean**: `pio run --target clean`

## Troubleshooting

### Upload Issues

- Check USB connection
- Verify correct COM port in Device Manager
- Try different USB cable
- Press reset button on Arduino just before upload

### Serial Monitor Issues

- Ensure correct baud rate (9600)
- Check COM port selection
- Close other serial applications

### Build Issues

- Check PlatformIO installation
- Verify platformio.ini configuration
- Restart VS Code if needed

## Adding Libraries

To add external libraries, edit `platformio.ini`:

```ini
lib_deps =
    adafruit/Adafruit SSD1306@^2.5.7
    arduino-libraries/Servo@^1.1.8
```

## Next Steps

1. Modify `main.cpp` for your specific project needs
2. Add sensors, actuators, or displays
3. Create custom functions in separate header files
4. Explore Arduino libraries for advanced features

## Resources

- [Arduino Reference](https://www.arduino.cc/reference/en/)
- [PlatformIO Documentation](https://docs.platformio.org/)
- [Arduino Uno Pinout](https://docs.arduino.cc/hardware/uno-rev3)

Happy coding with your Arduino Uno!
