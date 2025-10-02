#include "DisplayAdapter.hpp"

void RemoteLcd::DisplayAdapter::begin()
{
}

void RemoteLcd::DisplayAdapter::createChar(uint8_t id, uint8_t *c)
{
    transmitter->createCustomCharacter(id, c);
}

void RemoteLcd::DisplayAdapter::clear() { transmitter->clear(); }

void RemoteLcd::DisplayAdapter::setBacklight(bool enabled) {}

void RemoteLcd::DisplayAdapter::setCursor(uint8_t col, uint8_t row)
{
    transmitter->setCursor(col, row);
}

void RemoteLcd::DisplayAdapter::draw(const char *text)
{
    transmitter->writeText(text);
}

void RemoteLcd::DisplayAdapter::draw(uint8_t byte)
{
    transmitter->writeCharacter(byte);
}

void RemoteLcd::DisplayAdapter::drawBlinker()
{
    transmitter->setBlink(true);
}

void RemoteLcd::DisplayAdapter::clearBlinker()
{
    transmitter->setBlink(false);
}

void RemoteLcd::DisplayAdapter::show()
{
}

void RemoteLcd::DisplayAdapter::hide()
{
}