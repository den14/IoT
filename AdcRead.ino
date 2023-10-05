/*
NodeMCU (ESP8266) Analog Port Polling Program
The Ticker library is used for independent processing
of the polling cycle from LED flashing
*/

#include <Ticker.h>

#define analogPin A0

//Ticker tickerLedFlip;
Ticker tickerAdcRead;

int adcValue = 500;
float LedDelay = 1;

void LedFlip()
{
  int state = digitalRead(LED_BUILTIN);
  digitalWrite(LED_BUILTIN, !state);
}

void AdcRead() {
  adcValue = analogRead(analogPin);
  Serial.print("ADC Value = ");
  Serial.println(adcValue);
  //Serial.print("LED delay = ");
  Serial.println(int(LedDelay));
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  tickerAdcRead.attach(1, AdcRead);
  //tickerLedFlip.attach(0.5, LedFlip);
}

void loop() {
  LedDelay = (1.0/adcValue*550-0.6)*1000;
  delay(int(LedDelay));
  LedFlip();
}
