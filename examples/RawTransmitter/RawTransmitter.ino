/*
NOTE: the import of LcdMenu is necessary to satisfy import errors.
In my undestanding simply includeing RemoteLcd/DisplayTransmitter.hpp should be enough, but I always get
file not found erros in the arduino IDE when compiling, even if it is autocompleting the file when editing.
*/

//#include <RemoteLcd/DisplayTransmitter.hpp>

#include <LcdMenu.h>
#include <RemoteLcd.hpp>

byte customChar[] = {
  B10101,
  B10101,
  B01110,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
};

//create a transmitter that transmits data over the serial port
RemoteLcd::DisplayTransmitter transmitter(&Serial);


void setup() {
  Serial.begin(9600);  //match baudrate with your receiver

  //write text to the display
  transmitter.writeText("Hello");

  //set cursor
  transmitter.setCursor(0, 1);

  //create custom character at index 0
  transmitter.createCustomCharacter(0, customChar);

  //write custom character at index 0
  transmitter.writeCharacter(0);
}

void loop() {

  //read input
  while(Serial.available()){
    uint8_t command = Serial.read();
    transmitter.clear();
    transmitter.setCursor(0, 0);

    switch(command){
      //select aka linefeed
      case 10:
        transmitter.writeText("Select");
        break;
      //back aka esc
      case 27:
        transmitter.writeText("Back");
        break;

      //up
      case 128:
        transmitter.writeText("Up");
        break;

      //down
      case 129:
        transmitter.writeText("Down");
        break;

      //right
      case 130:
        transmitter.writeText("Right");
        break;

      //left
      case 131:
        transmitter.writeText("Left");
        break;
      default:
        transmitter.writeText("Unknown");
    }
  }

}