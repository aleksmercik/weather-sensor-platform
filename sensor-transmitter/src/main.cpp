#include <LoRa.h>

int counter = 0;
int txPower = 2; //2 - 17 --> LoRa lib sets 0x09 to txPower - 2 --> Pout = 17-(15-0bxxxx)

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  //Set TX Power
  LoRa.setTxPower(txPower);

  // send packet
  LoRa.beginPacket();
  LoRa.print("tx ");
  LoRa.print(txPower);
  LoRa.endPacket();

  txPower++;

  if (txPower > 17)
    txPower = 2;

  counter++;

  delay(1000);
}
