#pragma once

#include "input/InputInterface.h"
#include "Arduino.h"

namespace RemoteLcd
{

  /**
   * @class InputAdapter
   *
   * @brief listens on the given Stream and relays the commands to LcdMenu
   *
   * Commands a relayed one to one to the menu withe the process method.
   * So even invalid commands will be relayed.
   */

  class InputAdapter : public InputInterface
  {

  private:
    Stream *inputStream;

  public:
    /**
     * create an InputAdapter
     *
     * @param menu the LcdMenu to use
     * @param inputStream the Stream to listen for new commands
     */
    InputAdapter(LcdMenu *menu, Stream *inputStream) : InputInterface(menu), inputStream(inputStream) {}

    void observe();
  };
} // namespace RemoteLcd
