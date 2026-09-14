# Pin Connections

## HC-05 Bluetooth Module

| HC-05 Pin | Arduino Connection             |
| --------- | ------------------------------ |
| VCC       | 5V                             |
| GND       | GND                            |
| TX        | Pin 10                         |
| RX        | Pin 11 through voltage divider |

## LEDs

| Component | Arduino Connection          |
| --------- | --------------------------- |
| Red LED   | Pin 2 through 220Ω resistor |
| Green LED | Pin 3 through 220Ω resistor |

## Buzzer

| Component  | Arduino Connection |
| ---------- | ------------------ |
| Buzzer     | Pin 4              |
| Buzzer GND | GND                |

## Relay Module

| Relay Pin | Arduino Connection |
| --------- | ------------------ |
| IN        | Pin 7              |
| VCC       | 5V                 |
| GND       | GND                |

## Motor and Power

The relay output is connected to the DC motor and battery for ignition simulation.

The 9V battery is connected to Arduino VIN and GND.
