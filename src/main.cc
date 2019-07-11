#include <iostream>
#include <thread>
#include <chrono>

#include <rxcpp/rx.hpp>

#include <curses.h>

namespace Rx {
using namespace rxcpp;
using namespace rxcpp::sources;
using namespace rxcpp::operators;
using namespace rxcpp::util;
}
using namespace Rx;

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  clear();
  mvaddch(3, 20, 'a');
  getch();
  endwin();
  return 0;
}
