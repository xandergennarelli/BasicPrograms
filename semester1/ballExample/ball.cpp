#include "ball.h"

ball_t::ball_t(){
    radius = 1;
    center.x = DEF_X;
    center.y = DEF_Y;
    speed = 0;
    direction = 0;
}

ball_t::ball_t(point_t p, color_t c, double r, double s, double d){
    center = p;
    color = c;
    radius = r;
    speed = s;
    direction = d;
}


point_t ball_t::getCenter() const{
    return center;
}

color_t ball_t::getColor()  const{
    return color;
}

double  ball_t::getRadius() const{
    return radius;
}


void ball_t::setCenter(point_t c){
    center = c;
}

void ball_t::setColor(color_t c){
    color = c;
}

void ball_t::setRadius(double r){
    radius = r;
}

void ball_t::draw(ostream& os) const{
    os << "center = ";
    center.draw(os);
    os << " color = ";
    color.draw(os);
    os << " radius = " << radius;
}

void ball_t::draw(SDL_Plotter& g, bool erase) const{
    double xVal, yVal;
    int R=255, G=255, B=255;

    if(!erase){
        R = color.R;
        G = color.G;
        B = color.B;
    }
    for(int x = -radius; x <= radius; x++){
        for(int y = -radius; y <= radius; y++){
            xVal = center.x + x;
            yVal = center.y + y;
            if(center.distance(point_t(xVal, yVal)) <= radius){
               if(xVal >= 0 && yVal >= 0 && xVal < g.getCol() && yVal < g.getRow()){
                   g.plotPixel(xVal, yVal, R, G, B);
               }
            }
        }
    }
}


void ball_t::setDirection(double d){
    direction = d;
}


void ball_t::setSpreed(double s){
    speed = s;
}


void ball_t::move(){
    center.x += cos(direction)*speed;
    center.y += sin(direction)*speed;

    if(center.x-radius <= 0 || center.x+radius >= NUM_COL){
            direction = PI - direction;
    }
    if(center.y -radius <= 0 ||center.y + radius >= NUM_ROW){
            direction = 2*PI - direction;
    }

}
