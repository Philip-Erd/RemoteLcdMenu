#include "InputTransmitter.hpp"

void RemoteLcd::InputTransmitter::select()
{
    outputStream->write(10); // linefeed
}

void RemoteLcd::InputTransmitter::back()
{
    outputStream->write(27); // Esc
}

void RemoteLcd::InputTransmitter::up()
{
    outputStream->write(128);
}

void RemoteLcd::InputTransmitter::down()
{
    outputStream->write(129);
}

void RemoteLcd::InputTransmitter::right()
{
    outputStream->write(130);
}

void RemoteLcd::InputTransmitter::left()
{
    outputStream->write(131);
}