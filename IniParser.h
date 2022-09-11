#include "Arduino.h"

class IniParser {
  private:
  public:
    String contents;
    inline IniParser(String iniContents = "") {
      contents = iniContents;
    }

    inline String getValue(const char* section, const char* key) {
      if (contents.charAt(contents.length() - 1) != '\n')
        contents += "\n";
        
      int start = 0;
      int end = 0;
      String _section;
      String _key;
      String _value;
      
      for (int i = 0; i < contents.length(); i++) {
        char thisChar = contents.charAt(i);
        
        if (thisChar == '[') {
          start = i + 1;
        } else if (thisChar == ']') {
          end = i;
          _section = contents.substring(start, end);
          _key = ""; // gotta clear the key when we change sections
        } else if ((thisChar == '\n')) {
          end = i;
          _value = contents.substring(start, end);

          /* Begin Comment Filter */
          char commentChars[] = {'#', ';'};
          for (int i = 0; i < sizeof(commentChars); i++) {
            int commentIndex = _value.indexOf(commentChars[i]);
            if (commentIndex > -1) {
              // we snagged a comment
              _value = _value.substring(0, commentIndex);
            }
          }
          /* End Comment Filter */
          
          start = i + 1;

          _section.trim();
          _key.trim();
          _value.trim();
          
          if (_section.equals(section) && _key.equals(key)) {
            return _value;
          }
        } else if (thisChar == '=') {
          end = i;
          _key = contents.substring(start, end);
          start = i + 1;
        }
      }
      
      return "";
    }
};
