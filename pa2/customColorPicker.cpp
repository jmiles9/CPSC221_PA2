#include "customColorPicker.h"

customColorPicker::customColorPicker(HSLAPixel fillColour, int vertStripeSpacing, int horizStripeSpacing){
    colour = fillColour;
    vertSpacing = vertStripeSpacing;
    horizSpacing = horizStripeSpacing;
}

HSLAPixel customColorPicker::operator()(int x, int y){

    if(x % horizSpacing == 0 && y % vertSpacing == 0){ //when on intersection of both then do inverse of fillcolor
        HSLAPixel newPixel1;
        if(colour.h > 179){
            newPixel1.h = colour.h-180;
        }else{
            newPixel1.h = 180+colour.h;
        }
        newPixel1.s = colour.s;
        newPixel1.l = colour.l;
        return newPixel1;
    } else if (x % horizSpacing == 0 || y % vertSpacing == 0){
        return colour; //either main stripe return input value
    }else {
        HSLAPixel newPixel2;
        newPixel2.h = 0;
        newPixel2.s = 0;
        newPixel2.l = 1.0; //returns white 
        return newPixel2;
    }
}
