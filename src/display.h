/*
Copyright (C) 2015 Bruno Golosio

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef DISPLAYH
#define DISPLAYH

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class display
{
 public:
  bool LogFileFlag, ConsoleFlag;
  std::ofstream *LogFile;

  display();
  int Warning(std::string msg);
  int Print(std::string msg);
  int Println(std::string msg);
};

template <class argType>
std::string toStr(argType arg)
{
  std::stringstream ss;
  ss << arg;
  return ss.str();
}

#endif
