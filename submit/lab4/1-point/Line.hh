#ifndef LINE_HH_
#define LINE_HH_
#include "point.hh"
#include <string>

class Line {
  public:

  const Point x, y;

  Line(Point x=(0,0), Point y=(0,0)): x(x), y(y) { }

  double length() const;

  std::string toString() const;
};

#endif 
