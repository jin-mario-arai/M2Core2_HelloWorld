#include <M5Core2.h>

void setup() {
  M5.begin(true, true, true, true);
  M5.Lcd.setTextSize(8);
  M5.Lcd.print("Hello\n World");
}

void loop() {

}
