#include <SocketIoClient.h>
#include <WebSocketsClient.h>


const char* ssid = "tuan anh";
const char* password = "20041956";
const char* server= "192.168.88.104";
int port = 2323;
SocketIoClient client;
// Kết nối wifi
void setupNetwork() {
    WiFi.begin(ssid, password);
    uint8_t i = 0;
    while (WiFi.status() != WL_CONNECTED && i++ < 20){ 
      delay(500);
      Serial.print('.');}
    if (i == 21) {
        while (1) delay(500);}
    Serial.println("Wifi connected!");
}
void changeLedState(const char* data, size_t length) {
 
  String chuoi=(String) data;
  Serial.print(chuoi);
   if (chuoi == "off") {
        digitalWrite(LED_BUILTIN, HIGH);
        Serial.println("Led off!");
        client.emit("DenBat","\"Đèn đã tắt\"");
    }  else {
        digitalWrite(LED_BUILTIN, LOW);
        Serial.println("Led on!");
        client.emit("DenBat","\"Đèn đã bật\"");
    }
}

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.begin(115200);
    setupNetwork();
    client.on("BatDen",changeLedState );
    client.on("TatDen", changeLedState);
  
    
   
    
     // Kết nối đến server
    client.begin(server, port);
}

void loop() {
     // Luôn luôn giữ kết nối với server.
    client.loop();
}
