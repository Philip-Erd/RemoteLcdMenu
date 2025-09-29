#pragma once

#include "Arduino.h"
#include "Commnads.hpp"

namespace RemoteLcd
{
    /**
     * class DisplayTransmitter
     *
     * @brief transmits data to a remote Lcd
     *
     * For each method it transmits the command and data over the Stream.
     */
    class DisplayTransmitter
    {
    private:
        Stream *outputStream;

    public:
        /**
         * create an DisplayTransmitter
         *
         * @param outputStream the Stream to write the commands and to
         */
        DisplayTransmitter(Stream *outputStream) : outputStream(outputStream) {}

        /**
         * clear the display
         */
        void clear();

        /**
         * write a NULL terminated string to the display
         *
         * @param text pointer to a NULL terminated string
         */
        void writeText(char *text);

        /**
         * write a single character to the display
         *
         * @param index between 0 and 255 to indicate which character to draw
         */
        void writeCharacter(uint8_t index);

        /**
         * sets the cursor to the given column and row
         *
         * @param column the column of the cursor
         * @param row the row of the cursor
         */
        void setCursor(uint8_t column, uint8_t row);

        /**
         * create a custom character on the display
         *
         * @param index index of the character (on real displays 0 to 7 are valid)
         * @param data pointer to an array with 8 bytes of character data
         */
        void createCustomCharacter(uint8_t index, uint8_t *data);

        /**
         * blink the cursor
         *
         * @param value if true cursor blinks and does not blink if false
         */
        void setBlink(bool value);
    };
} // namespace RemoteLcd
