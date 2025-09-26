#pragma once

#include "Arduino.h"
#include "Commands.h"
#include "display/CharacterDisplayInterface.h"

enum InputState
{
    I_START = 1,
    I_WRITE_TEXT = 2,
    I_WRITE_CHARACTER = 3,
    I_SET_CURSOR = 4,
    I_CREATE_CUSTOM_CHARACTER = 5,
    I_SET_BLINK = 6
};

class StreamDisplayReceiver
{
private:
    Stream *inputStream;
    CharacterDisplayInterface *display;

    InputState state = InputState::I_START;

    uint8_t parameters[9];
    uint8_t parameter_index = 0;

    void process_write_text(uint8_t data)
    {
        if (data == '\0')
        {
            state = InputState::I_START;
        }
        else
        {
            display->draw(data);
        }
    }
    void process_write_character(uint8_t data)
    {
        display->draw(data);
        state = InputState::I_START;
    }
    void process_set_cursor(uint8_t data)
    {
        if (parameter_index == 1)
        {
            uint8_t row = parameters[0];
            uint8_t col = data;
            display->setCursor(col, row);
            parameter_index = 0;
            state = InputState::I_START;
        }
        else
        {
            parameters[parameter_index] = data;
            parameter_index++;
        }
    }
    void process_create_custom_character(uint8_t data)
    {
        if (parameter_index == 8)
        {
            parameters[parameter_index] = data;

            display->createChar(parameters[0], (*parameters +1));

            parameter_index = 0;
            state = InputState::I_START;
        }
        else
        {
            parameters[parameter_index] = data;
            parameter_index++;
        }
    }
    void process_set_blink(uint8_t data)
    {
        if (data)
        {
            display->drawBlinker();
        }
        else
        {
            display->clearBlinker();
        }
        state = InputState::I_START;
    }

    void process_start(uint8_t data)
    {
        switch (data)
        {
        case Commands::CLEAR_DISPLAY:
            display->clear();
            break;
        case Commands::WRITE_TEXT:
            state = InputState::I_WRITE_TEXT;
            break;
        case Commands::WRITE_CHARACTER:
            state = InputState::I_WRITE_CHARACTER;
            break;
        case Commands::SET_CURSOR:
            state = InputState::I_SET_CURSOR;
            parameter_index = 0;
            break;
        case Commands::CREATE_CUSTOM_CHARACTER:
            state = InputState::I_CREATE_CUSTOM_CHARACTER;
            parameter_index = 0;
            break;
        case Commands::SET_BLINK:
            state = InputState::I_SET_BLINK;
            break;
        default:
            break;
        }
    }

    void process(uint8_t data)
    {
        switch (state)
        {
        case InputState::I_START:
            process_start(data);
            break;
        case InputState::I_WRITE_TEXT:
            process_write_text(data);
            break;
        case InputState::I_WRITE_CHARACTER:
            process_write_character(data);
            break;
        case InputState::I_SET_CURSOR:
            process_set_cursor(data);
            break;
        case InputState::I_CREATE_CUSTOM_CHARACTER:
            process_create_custom_character(data);
            break;
        case InputState::I_SET_BLINK:
            process_set_blink(data);
            break;

        default:
            break;
        }
    }

public:
    StreamDisplayReceiver(CharacterDisplayInterface *display, Stream *inputStream) : display(display), inputStream(inputStream) {}

    void update()
    {
        while (inputStream->available())
        {
            process(inputStream->read());
        }
    }
};