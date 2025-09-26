#pragma once

#include "Arduino.h"
#include "Commands.h"

class StreamDisplayTransmitter
{
private:
    Stream *outputStream;

public:
    StreamDisplayTransmitter(Stream *outputStream) : outputStream(outputStream) {}

    void clear()
    {
        outputStream->write(Commands::CLEAR_DISPLAY);
    }
    void writeText(char *text)
    {
        outputStream->write(Commands::WRITE_TEXT);
        while (*text != '\0')
        {
            outputStream->write(*text);
            ++text;
        }

        // write \0 to finish
        outputStream->write('\0');
    }
    void writeCharacter(uint8_t index)
    {
        outputStream->write(Commands::WRITE_CHARACTER);
        outputStream->write(index);
    }
    void setCursor(uint8_t column, uint8_t row)
    {
        outputStream->write(Commands::SET_CURSOR);
        outputStream->write(row);
        outputStream->write(column);
    }
    void createCustomCharacter(uint8_t index, uint8_t *data)
    {
        outputStream->write(Commands::CREATE_CUSTOM_CHARACTER);
        outputStream->write(index);
        for (int row = 0; row < 8; row++)
        {
            outputStream->write(data[row]);
        }
    }
    void setBlink(bool value)
    {
        outputStream->write(Commands::SET_BLINK);
        outputStream->write(value);
    }
};
