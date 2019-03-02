/**
 * @file customColorPicker.h
 * Definition of a custom color picker that makes vertical
 * and horizontal lines on the image.
 *
 */
#ifndef CUSTOMCOLORPICKER_H
#define CUSTOMCOLORPICKER_H

#include "colorPicker.h"

/**
 * stripeColorPicker: a functor that determines the color that should be used
 * given an x and a y coordinate using a stripe pattern.
 *
 */
class customColorPicker : public colorPicker
{
  public:
    /**
     * Constructs a new stripeColorPicker.
     *
     * @param fillColor Color for the stripes.
     * @param stripeSpacing space between the stripes
     */
    customColorPicker(HSLAPixel fillColour, int vertStripeSpacing, int horizStripeSpacing);

    /**
     * Picks the color for pixel (x, y). If the x or y coordinate is a
     * multiple of the spacing, it will be filled with the fillColor.
     * otherwise, it will be filled with white.
     *
     * @param x The x coordinate to pick a color for.
     * @param y The y coordinat to pick a color for.
     * @return The color chosen for (x, y).
     */
    virtual HSLAPixel operator()(int x, int y);

  private:
    HSLAPixel colour; /**< Color used for the stripe. */
    int vertSpacing;     /**< Space between vertical stripes. */
    int horizSpacing;   /**< Space between horizontal stripes. */
};

#endif
