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
    for(int i = -2; i <= 2; i ++){
        for(int j = -2; j <= 2; j ++){
            if(x + i < im.width() && x + i >= 0 && y + j < im.height() && y + j >=0){
                HSLAPixel * temp = im.getPixel(x+i, y+j);
                if(temp->dist(ctr) > tol) nearEdge = true;
            }
        }
    }

    if(x + 3 < im.width()){
        HSLAPixel * temp = im.getPixel(x+3, y);
        if(temp->dist(ctr) > tol) nearEdge = true;
    }
    if(x - 3 >= 0){
        HSLAPixel * temp = im.getPixel(x-3, y);
        if(temp->dist(ctr) > tol) nearEdge = true;
    }
    if(y + 3 < im.height()){
        HSLAPixel * temp = im.getPixel(x, y+3);
        if(temp->dist(ctr) > tol) nearEdge = true;
    }
    if(y - 3 >=0){
        HSLAPixel * temp = im.getPixel(x, y-3);
        if(temp->dist(ctr) > tol) nearEdge = true;
    }

    if(!nearEdge) return *p;

    return color;
}
