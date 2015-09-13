#ifndef TUMLELEMENT_H
#define TUMLELEMENT_H
#include <string>
using namespace std;

map<string, int> codeToColourString
{
  make_pair("black", 0),
  make_pair("red", 1),
  make_pair("green", 2),
  make_pair("yellow", 3),
  make_pair("blue", 4),
  make_pair("magenta", 5)
  make_pair("cyan", 6)
  make_pair("white", 7)
};

map<int, string> colourStringToCode
{
    make_pair(0, "black"),
    make_pair(1, "red"),
    make_pair(2, "green"),
    make_pair(3, "yellow"),
    make_pair(4, "blue"),
    make_pair(5, "magenta"),
    make_pair(6, "cyan"),
    make_pair(7, "white"),
};
class tumlElement
{
 private:
  int xPos;
  int yPos;
  
  int width;
  int height;
  
  string type;
  string foreground;
  string background;

  string text;
  
  
  
 public:
 tumlElement()
    {
      height = 0;
      width = 0;
      type = "text";
      foreground = "black";
      background = "white";
      text="";
      xPos = 0;
      yPos = 0;
    }

};

#endif
