#pragma once

#include "input/InputInterface.h"
#include "Arduino.h"

class StreamInputAdapter : public InputInterface
{

private:
    Stream *inputStream;

public:
    StreamInputAdapter(LcdMenu *menu, Stream *inputStream) :InputInterface(menu) ,inputStream(inputStream) {}

    void observe() override
    {
      while(inputStream->available()){
        uint8_t command = inputStream->read();
        menu->process(command);
      }
    }
};