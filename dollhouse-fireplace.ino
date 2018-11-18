/*
 * Dollhouse fireplace imitation with one led.
 */

int fireplaceLed = 9;

void setup() {
  randomSeed(analogRead(0));

  delay(3000);
  ignite();
  
  analogWrite(fireplaceLed, 2);
}

void loop() {
  for (int intensity = 10 ; intensity <= 155; intensity++) {
    analogWrite(fireplaceLed, intensity);
    delay(10);
    sparkle(255);
  }

  for (int intensity = 155 ; intensity >= 10; intensity--) {
    analogWrite(fireplaceLed, intensity);
    delay(50);
    sparkle(255);
  }
}

void ignite() {
  for (int i = 0; i < 500; i++) {
    int intensity = sparkle(155);
    for (int i = intensity; i >= 0; i--) {
      analogWrite(fireplaceLed, i);
      delay(10);
    }
    delay(10);
  }
}

int sparkle(int maxIntensity) {
  int intensity = 0;
  boolean igniteSparkle = random(100) == 42;
  if (igniteSparkle) {
    intensity = random(maxIntensity);
    analogWrite(fireplaceLed, intensity);
    delay(50);
  }
  return intensity;
}
