
#include <ItemSubMenu.h>
#include <LcdMenu.h>
#include <MenuScreen.h>
#include <display/LiquidCrystalAdapter.h>
#include <input/AnalogButtonAdapter.h>
#include <input/KeyboardAdapter.h>
#include <renderer/CharacterDisplayRenderer.h>

#include <RemoteLcd.hpp>

#define LCD_ROWS 2
#define LCD_COLS 16

//DisplayTransmitter st(&Serial);
//RemoteLcdAdapter sa(&st);





extern MenuScreen *settingsScreen;
extern MenuScreen *settings2Screen;

// Define the main menu
// clang-format off
MENU_SCREEN(mainScreen, mainItems,
    ITEM_SUBMENU("Settings", settingsScreen),
    ITEM_BASIC("Start service"),
    ITEM_BASIC("Connect to WiFi"),
    ITEM_BASIC("Blink SOS"),
    ITEM_BASIC("Blink random"),
    ITEM_SUBMENU("Settings 2", settings2Screen));

// Create submenu and precise its parent
MENU_SCREEN(settingsScreen, settingsItems,
    ITEM_BASIC("Backlight"),
    ITEM_BASIC("Contrast"),
    ITEM_BASIC("Contrast1"),
    ITEM_BASIC("Contrast2"),
    ITEM_BASIC("Contrast3"),
    ITEM_BASIC("Contrast4"),
    ITEM_BASIC("Contrast5"),
    ITEM_BASIC("Contrast6"),
    ITEM_BASIC("Contrast7"),
    ITEM_SUBMENU("Settings2", settings2Screen));

MENU_SCREEN(settings2Screen, settings2Items,
    ITEM_BASIC("Backlight"),
    ITEM_BASIC("Contrast"));
// clang-format on

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

LiquidCrystalAdapter di = LiquidCrystalAdapter(&lcd, LCD_COLS, LCD_ROWS);
//RemoteLcdReceiver dr(&di, &Serial);
CharacterDisplayRenderer renderer(new LiquidCrystalAdapter(&lcd, LCD_COLS, LCD_ROWS), LCD_COLS, LCD_ROWS);
// CharacterDisplayRenderer renderer(&sa, LCD_COLS, LCD_ROWS);
LcdMenu menu(renderer);

RemoteLcd::InputAadpter inputAdapter(&menu, &Serial);

// right 0, left 480, up 131, down 307, select 722

// AnalogButtonAdapter ButtonUp(&menu, A0, 131, UP);
// AnalogButtonAdapter ButtonDown(&menu, A0, 307, DOWN, 500UL, 200UL);
// AnalogButtonAdapter ButtonBack(&menu, A0, 480, BACK);
// AnalogButtonAdapter ButtonEnter(&menu, A0, 722, ENTER);

// KeyboardAdapter keyboardAdapter(&menu, &Serial);
// StreamInputAdapter streamInputAdapter(&menu, &Serial);

void setup()
{
    Serial.begin(9600);
    lcd.begin(LCD_COLS, LCD_ROWS);

    // Initialize LcdMenu with the menu items
    // renderer.begin();
    // menu.setScreen(mainScreen);
}

void loop()
{
    // ButtonUp.observe();
    // ButtonDown.observe();
    // ButtonBack.observe();
    // ButtonEnter.observe();
    // keyboardAdapter.observe();
    // streamInputAdapter.observe();

    dr.update();
}
