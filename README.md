# 🌱 Arduino ESP32 Soil Moisture Sensor

This project is an **IoT-based soil moisture monitoring system** built using an ESP32 microcontroller to read soil moisture levels and upload data to a backend server for real-time monitoring and analysis.

## 🚀 Features

- Reads soil moisture levels using analog soil moisture sensors
- Processes sensor data on the ESP32 microcontroller
- Connects to WiFi to enable cloud communication
- Sends data as HTTP POST requests to a backend server with timestamps
- Enables remote monitoring for precision agriculture and environmental analysis

## 💻 Technologies Used

- **Hardware:** ESP32, soil moisture sensor, jumper wires
- **Firmware:** Arduino C++ (ESP32 Arduino core)
- **Networking:** WiFi (ESP32 built-in WiFi module)
- **Backend:** Python (Flask API for receiving and storing data)
- **Data Storage:** Server database (e.g. PostgreSQL or MySQL)

## 📚 What I Learned

- Interfacing analog sensors with ESP32 microcontrollers
- WiFi setup and HTTP communication in embedded systems
- Designing RESTful APIs to receive sensor data
- Integrating IoT hardware with backend software systems
- Building end-to-end data pipelines for real-world monitoring applications

## 🛠️ Getting Started

### 🔧 Prerequisites

- ESP32 microcontroller
- Soil moisture sensor (analog output)
- Arduino IDE with ESP32 board support installed
- WiFi credentials and backend server URL

### ⚙️ Installation

1. Clone the repository:

```bash
git clone https://github.com/Josh596/Arduino-ESP32-Soil-Moisture-Sensor.git
cd Arduino-ESP32-Soil-Moisture-Sensor
