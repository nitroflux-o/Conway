#include "board.hpp"
#include <cstdlib>
#include <fstream>
#include <string>

int main() {
  std::ifstream file;
  file.open("src/input.txt");
  std::string line;
  int widthcheck = -1;
  int i = 0;
  std::vector<std::pair<int, int>> initlist;
  while (std::getline(file, line)) {
    if (widthcheck == -1) {
      widthcheck = line.length();
    } else {
      if (line.length() != widthcheck) {
        std::cout << "Invalid grid" << '\n';
        return 0;
      }
    }
    for (int j = 0; j < line.length(); j++) {
      if (line[j] == 'O') {
        initlist.push_back({i, j});
      } else if (line[j] == 'X') {
        continue;
      } else {
        std::cout << "Invalid grid" << '\n';
        return 0;
      }
    }
    i++;
  }
  Board board(i + 1, widthcheck, initlist);
  system("clear");
  int tick = 1;
  while (1) {
    char c;
    std::cout << "Press enter to continue, press q+enter to exit." << '\n';
    std::cout << "Tick " << tick << '\n';
    std::cout << "Number of alive cells: " << board.getAlive() << '\n';
    board.display();
    std::cin.get(c);
    if(c == 'q') {
      break;
    }
    system("clear");
    board.update();
    tick++;
  }
  return 0;
}
