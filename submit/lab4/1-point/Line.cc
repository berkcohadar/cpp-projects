/*
add a Line class
which contains two Point's.
It should support a length() member function
which returns the length of the line as well as a toString() method 
which returns a string representation of a line consisting of the string representation
of the frst end-point concatenated with the string " -- " concatenated with
the string representation of the second end-point*/

#include "Line.hh"
#include "point.hh"
#include <cmath>
#include <string>
#include <sstream>

/** return distance of this point from other point */
double Line::length() const {
  //const auto dx = x - other.x;
  //const auto dy = y - other.y;
  double dist = (double) x.distance(y);
  return dist;
}

std::string Line::toString() const {
  std::stringstream s;
  s << "(" << x.toString() << ", " << y.toString() << ")" << " length = " << this -> length();
  return s.str();
}
