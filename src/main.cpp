#include <Arduino.h>
#include "FastLED.h"
#include "main.h"

#define NUM_LEDS 60
#define DATA_PIN 2
#define SOUND_PIN 3

void setFirstNLEDS(CRGB leds[], int n, CRGB color);

CRGB leds[NUM_LEDS];
CRGB color = CRGB::Red;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello World");

  pinMode(DATA_PIN, OUTPUT);

  pinMode(SOUND_PIN, INPUT);


  FastLED.addLeds<WS2812B, 2, GRB>(leds, NUM_LEDS);


}

Interval fadeInterval(10);

void loop() {
  // put your main code here, to run repeatedly:

  int sound = analogRead(SOUND_PIN);

  Serial.println(sound);


  if (fadeInterval.isReady()) {
    color.fadeToBlackBy(1);
  }


  setFirstNLEDS(leds, (sound / 100) * NUM_LEDS, CRGB::Blue);
}




void setFirstNLEDS(CRGB leds[], int n, CRGB color) {
  for (int i = 0; i < n; i++) {
    leds[i] = color;
  }

  for (int i = n; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }

  FastLED.show();
}

