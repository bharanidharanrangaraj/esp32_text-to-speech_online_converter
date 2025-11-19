
# How to Convert Text to Speech using ESP32 Offline

This project implements a fully offline Text-to-Speech (TTS) system using the ESP32 microcontroller and the Talkie LPC speech synthesis library.
The ESP32 reads text from the Serial Monitor, breaks it into words, matches each word with an LPC entry, and generates audible speech through its DAC output. Paired with a PAM8403 amplifier and a small speaker, the system becomes a compact and reliable voice output engine suitable for embedded applications.


## Features

- Fully offline TTS (no Wi-Fi or cloud services required)
- Lightweight LPC-based speech generation
- Simple wiring, minimal components
- Easily expandable vocabulary
- Works in remote or isolated environments
- Suitable for alarms, automation panels, educational devices, and more


## Hardware Requirements

| Component               | Quantity |
| ----------------------- | -------- |
| ESP32 Development Board | 1        |
| PAM8403 Audio Amplifier | 1        |
| 4–8Ω Speaker            | 1        |
| Breadboard              | 1        |
| Jumper Wires            | —        |
| USB Cable               | 1        |

<p align="center">
    <img src="Images%20&%20Videos/components_used_esp32_offline_tts.png" width="400">
    <p align="center">Components used</p>
  </a>
</p>

## Hardware Wiring

ESP32 → PAM8403
| ESP32 Pin | PAM8403 Pin  | Description      |
| --------- | ------------ | ---------------- |
| GPIO25    | R (Audio In) | DAC Audio Output |
| 5V        | VCC          | Amplifier Power  |
| GND       | GND          | Common Ground    |

PAM8403 → Speaker

| PAM8403 | Speaker |
| ------- | ------- |
| R+      | +       |
| R-      | -       |

<p align="center">
    <img src="Images%20&%20Videos/wiring_diagram_of_esp32_tts_converterpng.png" width="400">
    <p align="center">Circuit diagram</p>
  </a>
</p>

## Installing the Talkie Library

Download the Talkie library from GitHub:
https://github.com/ArminJo/Talkie

Install using:

**Arduino IDE → Sketch → Include Library → Add .ZIP Library**
## How to Use

- Connect the ESP32, amplifier, and speaker as shown.
- Upload the code to ESP32.
- Open Serial Monitor → 9600 baud.
- Type:

```python
    START MACHINE
    CHECK TEMPERATURE
    POWER ALERT
```

- The ESP32 will speak each word using the LPC vocabulary.
- Adjust volume using the PAM8403 module if needed.
## Adding New Words

Open ```Vocab_US_Large.h```

Find an LPC array (e.g., ```sp2_HELLO```)

Add it to the mapping table:
```
{"HELLO", sp2_HELLO},
```

You can extend the dictionary as much as flash memory allows.
## Troubleshooting
**Distorted Audio**
- Add 100–220Ω resistor between GPIO25 and amplifier input
- Reduce amplifier gain

**Very Low Volume**
- Check PAM8403 wiring
- Ensure ESP32 DAC pin is GPIO25 or GPIO26

**"Word not found" Error**
- The word is not in your vocabulary mapping table
- Add the LPC entry manually

## License
[MIT](https://choosealicense.com/licenses/mit/)

