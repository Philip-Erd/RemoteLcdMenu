#include "InputAdapter.hpp"

void RemoteLcd::InputAdapter::observe()
{
    // read all available bytes and relay them to the menu
    while (inputStream->available())
    {
        uint8_t command = inputStream->read();
        menu->process(command);
    }
}
