#include "ILI9327.h"
#include <SPI.h>

#define DISPLAY_CS 5
#define DISPLAY_DC 26
#define DISPLAY_MOSI 23
#define DISPLAY_MISO 19
#define DISPLAY_SCK 18
#define DISPLAY_RST 27

ILI9327 display(DISPLAY_CS, DISPLAY_DC, &SPI, DISPLAY_RST);

uint16_t color_table[] = {
    ILI9327_BLACK,
    ILI9327_NAVY,
    ILI9327_DARKGREEN,
    ILI9327_DARKCYAN,
    ILI9327_MAROON,
    ILI9327_PURPLE,
    ILI9327_OLIVE,
    ILI9327_LIGHTGREY,
    ILI9327_DARKGREY,
    ILI9327_BLUE,
    ILI9327_GREEN,
    ILI9327_CYAN,
    ILI9327_RED,
    ILI9327_MAGENTA,
    ILI9327_YELLOW,
    ILI9327_WHITE,
    ILI9327_ORANGE,
    ILI9327_GREENYELLOW,
    ILI9327_PINK};

void setup()
{
  Serial.begin(115200);
  Serial.println("Hello!");

  delay(500);
  display.begin(16000000);

  display.fillRect(0, 0, 400, 240, ILI9327_WHITE);
  delay(500);

  for (int h = 0; h < 4; h++) {
    for (int w = 0; w < 5; w++) {
      display.fillRect(w * 80, h * 60, 80, 60, color_table[(h * 5 + w) % 19]);
      delay(30);
    }
  }

  delay(10);
}

int i = 0;

void loop()
{
  Serial.println("loop!");

  // display.setTextSize(25);
  // display.setTextColor(ILI9327_ORANGE);
  // display.setCursor(50, 25);
  // display.println(i);

  delay(1000);

  // display.setTextSize(25);
  // display.setTextColor(ILI9327_BLUE);
  // display.setCursor(50, 25);
  // display.println(i);

  // i++;
}
