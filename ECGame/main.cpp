#include <iostream>
#include "SDL_Plotter.h"
using namespace std;

int main(int argc, char** argv){
  SDL_Plotter g(1000, 1000);
  char key;

  while(!g.getQuit()){
    if(g.kbhit()){
      key = g.getKey();
    }
    for(int y = 0; y < g.getRow(); y++){
      for(int x = 0; x < g.getCol(); x++){
        g.plotPixel(x, y, 255, 0, 0);
      }
    }
    g.update();
  }

  return 0;
}
