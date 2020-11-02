#include <iostream>
#include "SDL_Plotter.h"
#include "constant.h"
#include "point.h"
#include "color.h"
#include "ball.h"

using namespace std;

int main(int argc, char* argv[])
{
    SDL_Plotter g(NUM_ROW,NUM_COL);

    ball_t a;
    ball_t b(point_t(200,200), color_t(255,25,25), 10,0.5,rand());
    a.draw(cout);
    cout << endl;
    b.draw(cout);
    cout << endl;

    while(!g.getQuit()){
        if(g.kbhit()){
            char key = g.getKey();
        }
        b.draw(g);
        g.update();
        b.draw(g,true);
        b.move();

    }
    return 0;
}
