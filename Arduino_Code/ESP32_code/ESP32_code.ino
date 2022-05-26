#define RXp2 16
#define TXp2 17
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Galaxy A313BA2";
const char* password = "Olukotun";

// Your Domain name with URL path or IP address with path
String serverName = "http://127.0.0.1:5000/update";

int moisture_value;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);

  // Connect to wifi
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); // Delay for half a second
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial2.available() == 0) {
    delay(1000);
    Serial.println("Waiting to receive data")
    } // Hold till a string is received
  moisture_value = Serial2.parseInt();
  // Pass the data to the server using request and POST
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    // Your Domain name with URL path or IP address with path
    http.begin(client, serverName);

    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    // Data to send with HTTP POST request
    String httpRequestData = "moisture_value=" + moisture_value;
    // Send HTTP Post request
    int httpResponseCode = http.POST(httpRequestData);
    if (httpResponseCode == 200) {
      Serial.println("");
      Serial.println("Data Sent Successfully - " + httpResponseCode);
    }
    else {
      Serial.println("Error Sending Data - " + httpResponseCode);
    };
    // Free resources
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
}
