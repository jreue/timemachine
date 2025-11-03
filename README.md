# Arduino Uno Timemachine Project

## Required Libraries

The following libraries are required for this project and are automatically installed via PlatformIO:

### LCD Display Library

- **marcoschwartz/LiquidCrystal_I2C@^1.1.4**
  - Used for controlling the 20x4 I2C LCD display
  - Handles initialization, text display, and backlight control

### 7-Segment Display Library

- **diyables/DIYables_4Digit7Segment_74HC595@^1.0.2**
  - Used for controlling the two 4-digit 7-segment display modules
  - Handles multiplexing and digit patterns for 74HC595 shift registers
  - GitHub: https://github.com/DIYables/DIYables_4Digit7Segment_74HC595

### Keypad Library

- **chris--a/Keypad@^3.1.1**
  - Used for interfacing with the 3x4 matrix membrane keypad
  - Handles key detection, debouncing, and event handling
  - GitHub: https://github.com/Chris--A/Keypad

### Custom Library

- **timemachine.h/cpp** (local library)
  - Contains utility functions for LED patterns, button debouncing, and LCD time display
  - Located in `lib/timemachine/` directory

## Hardware Connections

### Arduino Uno Pin Assignments

#### I2C LCD Display (20x4)

- **VCC** → 5V
- **GND** → GND
- **SDA** → Pin A4 (I2C Data)
- **SCL** → Pin A5 (I2C Clock)

#### 7-Segment Display Module #1 (Left Display)

- **VCC** → 5V
- **GND** → GND
- **DIO** → Pin 11 (Data Input)
- **RCLK** → Pin 12 (Register Clock/Latch)
- **SCLK** → Pin 13 (Shift Clock)

#### 7-Segment Display Module #2 (Right Display)

- **VCC** → 5V
- **GND** → GND
- **DIO** → Pin A0 (Data Input)
- **RCLK** → Pin A1 (Register Clock/Latch)
- **SCLK** → Pin A2 (Shift Clock)

#### 3x4 Matrix Keypad (7 pins total)

- **Row 1** → Pin 4
- **Row 2** → Pin 5
- **Row 3** → Pin 6
- **Row 4** → Pin 7
- **Col 1** → Pin 8
- **Col 2** → Pin 9
- **Col 3** → Pin 10

### Power Requirements

- **Arduino Uno**: 5V via USB or external power supply
- **Total Current**: Approximately 200-300mA with all components active
- **All components**: Share common 5V and GND connections
