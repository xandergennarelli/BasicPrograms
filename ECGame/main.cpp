// cd /home/xander/Documents/CPP/BasicPrograms/ECGame/ && clang++ main.cpp SDL_Plotter.cpp -std=c++11 -g -lglfw -lGL -lGLU -lSDL2 -lSDL2_mixer -I/usr/include/SDL2 && ./a.out
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "SDL_Plotter.h"
using namespace std;

enum Color {WHT, BLK, RED, GRN, BLU, YEL, MAG};

int main(int argc, char** argv){
  SDL_Plotter g(1000, 1000, true);
  char key;

  while(!g.getQuit()){
    if(g.kbhit()){
      key = g.getKey();
    }
    for(int y = 0; y < g.getRow(); y++){
      for(int x = 0; x < g.getCol(); x++){
        //g.plotPixel(x, y, red, blue, green);
      }
    }
    g.update();
  }

  return 0;
}

void draw(SDL_Plotter g, int x, int y, Color c){
  switch (c) {
    case WHT: g.plotPixel(x, y, 255, 255, 255); break;
    case BLK: g.plotPixel(x, y, 0, 0, 0); break;
    case RED: g.plotPixel(x, y, 255, 25, 25); break;
    case GRN: g.plotPixel(x, y, 25, 255, 25); break;
    case BLU: g.plotPixel(x, y, 25, 25, 255); break;
    case YEL: g.plotPixel(x, y, 255, 255, 25); break;
    case MAG: g.plotPixel(x, y, 255, 0, 255); break;
  }
}
