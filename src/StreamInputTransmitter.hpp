#pragma once

#include "Arduino.h"

class StreamInputTransmitter
{
private:
    Stream *outputStream;

public:
    StreamInputTransmitter(Stream *outputStream) : outputStream(outputStream) {}

    void select()
    {
        outputStream->write(10);
    }

    void back()
    {
        outputStream->write(27);
    }

    void up()
    {
        outputStream->write(128);
    }

    void down()
    {
        outputStream->write(129);
    }

    void right()
    {
        outputStream->write(130);
    }

    void left()
    {
        outputStream->write(131);
    }
};