#include <iostream>
#include <ctime>
#include <cstdlib>
#include "SDL_Plotter.h"
using namespace std;

int main(int argc, char** argv){
  SDL_Plotter g(1000, 1000, true);
  char key;
  int rdelta = 1, bdelta = 1, gdelta = 1, red = 1, blue = 0, green = 0, tmp;
  srand(time(0));

  while(!g.getQuit()){
    if(g.kbhit()){
      key = g.getKey();
    }
    for(int y = 0; y < g.getRow(); y++){
      for(int x = 0; x < g.getCol(); x++){
        g.plotPixel(x, y, red, blue, green);
      }
      if(y % 600 == 0){
        if(!blue && !green){
          red += rdelta;
          if(red == 255){
            rdelta = -1;
          }
          if(red == 0){
            rdelta = 1;
            blue = 1;
          }
        }
        if(!red && !green){
          blue += bdelta;
          if(blue == 255){
            bdelta = -1;
          }
          if(blue == 0){
            bdelta = 1;
            green = 1;
          }
        }
        if(!red && !blue){
          green += gdelta;
          if(green == 255){
            gdelta = -1;
          }
          if(green == 0){
            gdelta = 1;
          }
        }
        if((!red && !green && !blue) || (red && green && blue)){
          red += rdelta;
          blue += rdelta;
          green += rdelta;
          if(red == 255){
            rdelta = -1;
          }
          if(red == 0){
            rdelta = 1;
            red = 1;
          }
        }
      }
    }
    g.update();
  }

  return 0;
}

// cd /home/xander/Documents/CPP/BasicPrograms/ECGame/ && clang++ main.cpp SDL_Plotter.cpp -std=c++11 -g -lglfw -lGL -lGLU -lSDL2 -lSDL2_mixer -I/usr/include/SDL2 && ./a.out
