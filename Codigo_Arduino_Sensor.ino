#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE 9
#define CSN 10
#define entrada 5   // pin del sensor FC-51

RF24 radio(CE, CSN);

const byte direccion[6] = "00701";

int dato;

void setup() {

  pinMode(entrada, INPUT);

  Serial.begin(9600);

  radio.begin();
  radio.openWritingPipe(direccion);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();

  Serial.println("Transmisor listo");
}

void loop() {

  dato = digitalRead(entrada);   // leer sensor FC-51

  radio.write(&dato, sizeof(dato));

  Serial.print("Valor enviado: ");
  Serial.println(dato);

  delay(500);

}