#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <notes.h>
#include <CantinaTheme.h>
#include <ImperialMarch.h>
#include <StarWarsTheme.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define BUZZER 3

int counter = 0;


void setup() {
  pinMode(BUZZER, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("** Buzzer  Module **");
}

void loop() {
  if (counter == 0) {
    lcd.setCursor(0, 2);
    lcd.print(ImperialMarchName);

    for (int x = 0; x < ImperialMarchSize; x++) {
      if (ImperialMarch[x][0]){
        tone(BUZZER, ImperialMarch[x][0], ImperialMarch[x][1]*5);
      } else {
        delay(ImperialMarch[x][1]*5);
      }
    }

    // lcd.setCursor(0, 2);
    // lcd.print(CantinaThemeName);

    // for (int x = 0; x < CantinaThemeSize; x++) {
    //   if (CantinaTheme[x][0]){
    //     tone(BUZZER, CantinaTheme[x][0], CantinaTheme[x][1]*5);
    //   } else {
    //     delay(CantinaTheme[x][1]*5);
    //   }
    // }

    lcd.setCursor(0, 2);
    lcd.print(StarWarsThemeName);

    for (int x = 0; x < StarWarsThemeSize; x++) {
      if (StarWarsTheme[x][0]){
        tone(BUZZER, StarWarsTheme[x][0], StarWarsTheme[x][1]*5);
      } else {
        delay(StarWarsTheme[x][1]*5);
      }
    }

    counter++;
  }
}

