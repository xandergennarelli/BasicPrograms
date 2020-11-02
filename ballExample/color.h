#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

struct color_t{
    int R,G,B;

    color_t(){
       R = G = B = 0;
    }

    color_t(int r, int g, int b){
        R = r;
        G = g;
        B = b;
    }

    void draw(ostream& os) const{
        os << "(" << R << "," << G << "," << B << ")";
    }

};

#endif // COLOR_H_INCLUDED
