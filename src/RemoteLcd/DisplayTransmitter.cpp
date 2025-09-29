#include "DisplayTransmitter.hpp"

void RemoteLcd::DisplayTransmitter::clear()
{
    outputStream->write(Commands::CLEAR_DISPLAY);
}
void RemoteLcd::DisplayTransmitter::writeText(char *text)
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
void RemoteLcd::DisplayTransmitter::writeCharacter(uint8_t index)
{
    outputStream->write(Commands::WRITE_CHARACTER);
    outputStream->write(index);
}
void RemoteLcd::DisplayTransmitter::setCursor(uint8_t column, uint8_t row)
{
    outputStream->write(Commands::SET_CURSOR);
    outputStream->write(row);
    outputStream->write(column);
}
void RemoteLcd::DisplayTransmitter::createCustomCharacter(uint8_t index, uint8_t *data)
{
    outputStream->write(Commands::CREATE_CUSTOM_CHARACTER);
    outputStream->write(index);
    for (int row = 0; row < 8; row++)
    {
        outputStream->write(data[row]);
    }
}
void RemoteLcd::DisplayTransmitter::setBlink(bool value)
{
    outputStream->write(Commands::SET_BLINK);
    outputStream->write(value);
}