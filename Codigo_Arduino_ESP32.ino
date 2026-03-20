#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE 4
#define CSN 5
#define LED 2

RF24 radio(CE, CSN);

const byte direccion[6] = "00701";

int datoRecibido;

void setup() {

  Serial.begin(115200);
  pinMode(LED, OUTPUT);

  radio.begin();
  radio.openReadingPipe(0, direccion);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();
}

void loop() {

  if (radio.available()) {

    radio.read(&datoRecibido, sizeof(datoRecibido));

    Serial.print("Dato recibido: ");
    Serial.println(datoRecibido);

    if (datoRecibido == 1) {

      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED, LOW);

    }

  }

}
