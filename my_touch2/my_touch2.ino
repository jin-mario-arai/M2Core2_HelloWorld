#include <M5Core2.h>
#include <Fonts/EVA_20px.h>
#include <stdio.h>

void showNum(short int X, short int Y) {
  char Str[10];
  M5.Lcd.clear(BLACK);
  M5.Lcd.setCursor(10, 10);
  M5.Lcd.printf("DISPLAY Test!");
  M5.Lcd.setCursor(10, 26);
  sprintf(Str, "X:%d", X);
  M5.Lcd.printf(Str);
  M5.Lcd.setCursor(10, 42);
  sprintf(Str, "Y:%d", Y);
  M5.Lcd.printf(Str);
}

void touchsetup() {
  showNum(0, 0);
}

void touchflush() {
  char X[4];
  char Y[4];
  M5.Lcd.setCursor(10, 10);
  TouchPoint_t pos = M5.Touch.getPressPoint();
  bool touchStateNow = ( pos.x == -1 ) ? false : true;
  if ( touchStateNow )
  {
    showNum(pos.x, pos.y);
  }
}

void setup() {
  M5.begin(true, true, true, true);
  Serial.begin(115200);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(2);
  touchsetup();
}

void loop() {
  TouchPoint_t pos = M5.Touch.getPressPoint();
  
  if (pos.y > 240) {  // Button area
    if (pos.x < 109) { // Left
      M5.Lcd.setTextColor(WHITE);
    }
    else if (pos.x > 218) { // Right
      M5.Lcd.setTextColor(RED);
    } 
    else if (pos.x >= 109 && pos.x <= 218) { // Middle
      M5.Lcd.setTextColor(BLUE);
    }
  }
  touchflush();
  delay(100);
}
