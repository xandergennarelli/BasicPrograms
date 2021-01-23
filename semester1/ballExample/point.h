#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <iostream>
#include <cmath>
#include "SDL_Plotter.h"
using namespace std;

struct point_t{
    double x, y;

    point_t(){
       x = y = 0;
    }

    point_t(double xVal, double yVal){
        x = xVal;
        y = yVal;
    }

    void draw(ostream& os) const{
       os << "(" << x << "," << y << ")";
    }

    void draw(SDL_Plotter& g) const{
        g.plotPixel(x,y,0,0,0);
    }

    double distance(point_t p) const{
        return sqrt(pow(x-p.x,2) + pow(y-p.y,2));
    }
};

#endif // POINT_H_INCLUDED
