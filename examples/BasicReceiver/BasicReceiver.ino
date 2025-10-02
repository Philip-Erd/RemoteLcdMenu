#include <LcdMenu.h>
#include <display/LiquidCrystalAdapter.h>
#include <LiquidCrystal.h>
#include <RemoteLcd.hpp>

#define LCD_ROWS 2
#define LCD_COLS 16

// create an LCD (this pinout is for an LCD keypad shield)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// create an LCD adapter
LiquidCrystalAdapter display(&lcd, LCD_COLS, LCD_ROWS);

// create a receiver that receives data from the serial port
RemoteLcd::DisplayReceiver displayReceiver(&display, &Serial);

// create an input tranmitter that transmits controll data over the serial port
RemoteLcd::InputTransmitter inputTranmitter(&Serial);

void setup()
{
  Serial.begin(9600); // match baudrate with your transmitter
}

void loop()
{

  // update the display
  displayReceiver.update();

  // read buttons and transmit data (example for a n LCD Keypad shield)
  int buttonValue = analogRead(A0);

  if (buttonValue < 50 && buttonValue >= 0)
  {
    inputTranmitter.right();
  }

  if (buttonValue < 200 && buttonValue >= 50)
  {
    inputTranmitter.up();
  }

  if (buttonValue < 350 && buttonValue >= 200)
  {
    inputTranmitter.down();
  }

  if (buttonValue < 550 && buttonValue >= 350)
  {
    // inputTranmitter.left();
    inputTranmitter.back(); // use left button as back, since the shield does not have a back button
  }

  if (buttonValue < 900 && buttonValue >= 550)
  {
    inputTranmitter.select();
  }
}