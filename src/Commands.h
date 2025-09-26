#pragma once

enum Commands
{
    CLEAR_DISPLAY = 0x81,
    WRITE_TEXT = 0x82,              // followed by characters until \0
    WRITE_CHARACTER = 0x83,         // followed by single byte (index)
    SET_CURSOR = 0x84,              // followed by 2 bytes (row, collums)
    CREATE_CUSTOM_CHARACTER = 0x85, // followed by single byte with the index and 8 bytes containing the data
    SET_BLINK = 0x86,               // followed by single byte (value)

};
