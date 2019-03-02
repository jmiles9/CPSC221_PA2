#include "borderColorPicker.h"

borderColorPicker::borderColorPicker(HSLAPixel fillColor, PNG & img, double tolerance,HSLAPixel center)
{
    im = img;
    color = fillColor;
    tol = tolerance;
    ctr = center;
}

HSLAPixel borderColorPicker::operator()(int x, int y)
{
    HSLAPixel * p = im.getPixel(x, y);
    bool nearEdge = false;
    for(int i = -3; i <=3; i ++){
        for(int j = -3; j <= 3; j ++){
            HSLAPixel * temp = im.getPixel(x, y);
            if(temp->dist(*p) <= 3) nearEdge = true;
        }
    }

    if(!nearEdge) return *p;

    return color;
}
