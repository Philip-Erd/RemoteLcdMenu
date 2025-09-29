#pragma once

#include "Arduino.h"

namespace RemoteLcd
{

    /**
     * @class InputTransmitter
     *
     * @brief transmit commands over the Stream
     *
     * For each method the appropriate command is transmitted over the Stream.
     */
    class InputTransmitter
    {
    private:
        Stream *outputStream;

    public:
        /**
         * create an InputTransmitter
         *
         * @param outputStream the Stream to write the commands to
         */
        InputTransmitter(Stream *outputStream) : outputStream(outputStream) {}

        /**
         * transmit select command
         */
        void select();

        /**
         * transmit back command
         */
        void back();

        /**
         * transmit up command
         */
        void up();

        /**
         * transmit down command
         */
        void down();

        /**
         * transmit right command
         */
        void right();

        /**
         * transmit left command
         */
        void left();
    };
} // namespace RemoteLcd
