#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "point.h"
#include "color.h"
#include "constant.h"

class  ball_t{
   private:
       point_t center;
       color_t color;
       double  radius;
       double  direction; //radians
       double  speed;
   public:
       ball_t();
       ball_t(point_t, color_t, double, double = 0, double = 0);

       point_t getCenter() const;
       color_t getColor()  const;
       double  getRadius() const;

       void setCenter(point_t);
       void setColor(color_t);
       void setRadius(double);
       void setDirection(double);
       void setSpreed(double);

       void draw(ostream&) const;
       void draw(SDL_Plotter&, bool = false) const;

       void move();

};

#endif // BALL_H_INCLUDED
