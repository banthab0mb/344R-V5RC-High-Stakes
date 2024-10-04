#include "vex.h"
#include "robot-config.h"

using namespace vex;

void preAuton();

extern int autonToRun;

class Button
{
  public:
    int x, y, width, height;
    std::string text;
    color buttonColor, textColor;
    
    Button(int x, int y, int width, int height, std::string text, color buttonColor, color textColor)
    : x(x), y(y), width(width), height(height), text(text), buttonColor(buttonColor), textColor(textColor){}

    void render()
    {
      Brain.Screen.drawRectangle(x, y, width, height, buttonColor);
      Brain.Screen.printAt(x + 10, y + 10, false, text.c_str());
    }

    bool isClicked()
    {
      if(Brain.Screen.pressing() && Brain.Screen.xPosition() >= x && Brain.Screen.xPosition() <= x + width &&
      Brain.Screen.yPosition() >= y && Brain.Screen.yPosition() <= y + width) return true;
      return false;
    }
};

extern Button autonButtons[];
