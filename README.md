# IniParser
Arduino library for getting Section/Key Values from an .ini-formatted String

I wrote this because I wanted to use a familiar configuration file format without the tie-downs that other libraries that parse .ini files have, e.g. it only takes a filename and not an arbitrary string of bytes from a file that's already been read into memory somehow. There were some libraries that did that, however they were not compatible with Arduino.

This library is just a single .h file that you can include into any Arduino project. Its only dependency is "Arduino.h"

How to use:

```
#include "IniParser.h"

IniParser iniParser(myIniString);

String myValue = iniParser.getValue("mySection", "myKey"); // returns your value for the section/key pair

Serial.print(myValue);
```
