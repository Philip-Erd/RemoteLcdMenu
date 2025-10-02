#include <LcdMenu.h>
#include <MenuScreen.h>
#include <renderer/CharacterDisplayRenderer.h>

#include <RemoteLcd.hpp>

// rows and columns must be between 1 and 255
// the transmitter does not care about the size, but it should match your receiver
#define LCD_ROWS 2
#define LCD_COLS 16

// Initialize the main menu items
// clang-format off
MENU_SCREEN(mainScreen, mainItems,
    ITEM_BASIC("Start service"),
    ITEM_BASIC("Connect to WiFi"),
    ITEM_BASIC("Settings"),
    ITEM_BASIC("Blink SOS"),
    ITEM_BASIC("Blink random"));
// clang-format on

// create a transmitter that transmits data over the serial port
RemoteLcd::DisplayTransmitter transmitter(&Serial);

// create an LCDMenu adapter from the transmitter
RemoteLcd::DisplayAdapter displayAdapter(&transmitter);

// create a renderer from the adapter
CharacterDisplayRenderer renderer(&displayAdapter, LCD_COLS, LCD_ROWS);
LcdMenu menu(renderer);

// create an input adapter that receives data from the serial port
RemoteLcd::InputAdapter inputAdapter(&menu, &Serial);

void setup()
{
  Serial.begin(9600); // match baudrate with your receiver
  // Initialize LcdMenu with the menu items
  renderer.begin();
  menu.setScreen(mainScreen);
}

void loop()
{
  // update the menu acording to the received inputs
  inputAdapter.observe();
}