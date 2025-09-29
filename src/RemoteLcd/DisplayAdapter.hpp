#pragma once

#include "DisplayTransmitter.hpp"

#include <Arduino.h>
#include <display/CharacterDisplayInterface.h>

namespace RemoteLcd
{

  /**
   * @class DisplayAdapter
   *
   * @brief LCDMenu Adapter for interfacing with RemoteLcd.
   *
   * Implements the CharacterDisplay interface from LcdMenu.
   */
  class DisplayAdapter : public CharacterDisplayInterface
  {
  private:
    DisplayTransmitter *transmitter;

  public:
    DisplayAdapter(DisplayTransmitter *transmitter) : CharacterDisplayInterface(), transmitter(transmitter) {}

    void begin();

    void createChar(uint8_t id, uint8_t *c);

    void clear();

    void setBacklight(bool enabled);
    void setCursor(uint8_t col, uint8_t row);

    void draw(const char *text);

    void draw(uint8_t byte);

    void drawBlinker();

    void clearBlinker();

    void show();

    void hide();
  };
} // namespace RemoteLcd
