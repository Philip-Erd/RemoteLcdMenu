#pragma once

#include "StreamDisplayTransmitter.hpp"

#include <Arduino.h>
// #include <LcdMenu.h>
#include <display/CharacterDisplayInterface.h>

class StreamDisplayAdapter : public CharacterDisplayInterface
{
private:
  StreamDisplayTransmitter *transmitter;

public:
  StreamDisplayAdapter(StreamDisplayTransmitter *transmitter) : CharacterDisplayInterface(), transmitter(transmitter) {}

  void begin() override
  {
  }

  void createChar(uint8_t id, uint8_t *c)
  {
    transmitter->createCustomCharacter(id, c);
  }

  void clear() override { transmitter->clear(); }

  void setBacklight(bool enabled) override {}

  void setCursor(uint8_t col, uint8_t row) override
  {
    transmitter->setCursor(col, row);
  }

  void draw(const char *text) override
  {
    transmitter->writeText(text);
  }

  void draw(uint8_t byte) override
  {
    transmitter->writeCharacter(byte);
  }

  void drawBlinker()
  {
    transmitter->setBlink(true);
  }

  void clearBlinker()
  {
    transmitter->setBlink(false);
  }

  void show() override
  {
  }

  void hide() override
  {
  }
};