#include "DisplayAdapter.hpp"

void RemoteLcd::DisplayAdpter::begin() override
{
}

void RemoteLcd::DisplayAdpter::createChar(uint8_t id, uint8_t *c) override
{
    transmitter->createCustomCharacter(id, c);
}

void RemoteLcd::DisplayAdpter::clear() override { transmitter->clear(); }

void RemoteLcd::DisplayAdpter::setBacklight(bool enabled) override {}

void RemoteLcd::DisplayAdpter::setCursor(uint8_t col, uint8_t row) override
{
    transmitter->setCursor(col, row);
}

void RemoteLcd::DisplayAdpter::draw(const char *text) override
{
    transmitter->writeText(text);
}

void RemoteLcd::DisplayAdpter::draw(uint8_t byte) override
{
    transmitter->writeCharacter(byte);
}

void RemoteLcd::DisplayAdpter::drawBlinker() override
{
    transmitter->setBlink(true);
}

void RemoteLcd::DisplayAdpter::clearBlinker() override
{
    transmitter->setBlink(false);
}

void RemoteLcd::DisplayAdpter::show() override
{
}

void RemoteLcd::DisplayAdpter::hide() override
{
}