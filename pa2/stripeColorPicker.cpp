#include "stripeColorPicker.h"

stripeColorPicker::stripeColorPicker(HSLAPixel fillColour, int stripeSpacing){
    colour = fillColour;
    spacing = stripeSpacing;
}

HSLAPixel stripeColorPicker::operator()(int x, int y){
    if(x % spacing == 0){// || y % spacing == 0){
        return colour;
    } else {
        HSLAPixel newPixel;
        newPixel.h = 0;
        newPixel.s = 0;
        newPixel.l = 1.0;

        return newPixel;
    }
}
