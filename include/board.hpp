#ifndef BOARD
#define BOARD
#include <iostream>
#include <vector>

class Board {
private:
  int width;
  int depth;
  std::vector<std::vector<bool>> status;
  int no_alive;

public:
  Board(int depth, int width, std::vector<std::pair<int, int>> initlist)
      : depth(depth), width(width) {
    status.resize(depth);
    for (auto &v : status) {
      v = std::vector<bool>(width, false);
    }
    no_alive = initlist.size();
    for (auto &p : initlist) {
      if (p.first < 0 || p.first >= depth || p.second < 0 ||
          p.second >= width) {
        continue;
      }
      status[p.first][p.second] = true;
    }
  }
  int getAlive() const {
    return no_alive;
  }
  void display() {
    for (auto &v : status) {
      for (auto b : v) {
        std::cout << (b ? "■" : "□") << " ";
      }
      std::cout << '\n';
    }
  }
  bool check(int y, int x) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if(y + i < 0 || y + i >= depth || x + j < 0 || x + j >= width){
          continue;
        }
        if (i == 0 && j == 0) {
          continue;
        }
        if (status[y + i][x + j]) {
          count++;
        }
      }
    }
    if (!status[y][x]) {
      if (count == 3) {
        return true;
      }
      return false;
    }
    else{
      if(count == 2 || count == 3){
        return true;
      }
      return false;
    }
  }
  void update() {
    no_alive = 0;
    std::vector<bool> updatevec;
    for (int i = 0; i < depth; i++) {
      for (int j = 0; j < width; j++) {
        if(check(i, j)){
          no_alive++;
        }
        updatevec.push_back(check(i, j));
      }
    }
    int index = 0;
    for(int i = 0; i < status.size(); i++){
      for(int j = 0; j < status[0].size(); j++){
        status[i][j] = updatevec[index];
        index++;
      }
    }
  }
};
#endif
