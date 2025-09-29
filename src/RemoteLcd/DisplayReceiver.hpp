#pragma once

#include "Arduino.h"
#include "Commands.hpp"
#include "display/CharacterDisplayInterface.h"

namespace RemoteLcd
{

    enum InputState
    {
        I_START = 1,
        I_WRITE_TEXT = 2,
        I_WRITE_CHARACTER = 3,
        I_SET_CURSOR = 4,
        I_CREATE_CUSTOM_CHARACTER = 5,
        I_SET_BLINK = 6
    };

    /**
     * @class DisplayReceiver
     *
     * @brief Class for receiving data over a Stream and controlling a display.
     *
     * This Class reads all commands and data from its inputStream and calls the
     *  appropriate methods on the CharacterDisplayInterface. The CharacterDisplayInterface
     * comes from the LcdMenu library.
     */
    class DisplayReceiver
    {
    private:
        Stream *inputStream;
        CharacterDisplayInterface *display;

        InputState state = InputState::I_START;

        uint8_t parameters[9];
        uint8_t parameter_index = 0;

        void process_write_text(uint8_t data);
        void process_write_character(uint8_t data);
        void process_set_cursor(uint8_t data);
        void process_create_custom_character(uint8_t data);
        void process_set_blink(uint8_t data);

        void process_start(uint8_t data);

        void process(uint8_t data);

    public:
        DisplayReceiver(CharacterDisplayInterface *display, Stream *inputStream) : display(display), inputStream(inputStream) {}

        /**
         * read commands from the Stream and process them
         */
        void update();
    };
} // namespace RemoteLcd
