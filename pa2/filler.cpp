/**
 * @file filler.cpp
 * Implementation of functions in the filler namespace. 
 *
 */
//#include "filler.h"

animation filler::fillCustomDFS(PNG& img, int x, int y, HSLAPixel fillColor,
                int vertStripeSpacing, int horizStripeSpacing, double tolerance, int frameFreq)
{
    customColorPicker a(fillColor, vertStripeSpacing, horizStripeSpacing);
    return fill<Stack>(img, x, y, a, tolerance, frameFreq);
}

animation filler::fillCustomBFS(PNG& img, int x, int y, HSLAPixel fillColor,
                int vertStripeSpacing, int horizStripeSpacing, double tolerance, int frameFreq)
{
    customColorPicker a(fillColor, vertStripeSpacing, horizStripeSpacing);
    return fill<Queue>(img, x, y, a, tolerance, frameFreq);
}

animation filler::fillStripeDFS(PNG& img, int x, int y, HSLAPixel fillColor,
                                int stripeSpacing, double tolerance, int frameFreq)
{
    stripeColorPicker a(fillColor, stripeSpacing);
    return fill<Stack>(img, x, y, a, tolerance, frameFreq);
    cout << "after fill" << endl;
}

animation filler::fillBorderDFS(PNG& img, int x, int y,
                                    HSLAPixel borderColor, double tolerance, int frameFreq)
{
    /**
     * @todo Your code here! 
     */
}

/* Given implementation of a DFS rainbow fill. */
animation filler::fillRainDFS(PNG& img, int x, int y,
                                    long double freq, double tolerance, int frameFreq)
{
    rainbowColorPicker a(freq);
    return fill<Stack>(img, x, y, a, tolerance, frameFreq);
}

animation filler::fillStripeBFS(PNG& img, int x, int y, HSLAPixel fillColor,
                                int stripeSpacing, double tolerance, int frameFreq)
{
    stripeColorPicker a(fillColor, stripeSpacing);
    return fill<Queue>(img, x, y, a, tolerance, frameFreq);
}

animation filler::fillBorderBFS(PNG& img, int x, int y,
                                    HSLAPixel borderColor, double tolerance, int frameFreq)
{
    //TODO
}

/* Given implementation of a BFS rainbow fill. */
animation filler::fillRainBFS(PNG& img, int x, int y,
                                    long double freq, double tolerance, int frameFreq)
{
    rainbowColorPicker a(freq);
    return fill<Queue>(img, x, y, a, tolerance, frameFreq);
}

/**
     * @todo You need to implement this function!
     *
     * This is the basic description of a flood-fill algorithm: Every fill
     * algorithm requires an ordering structure, which is passed to this
     * function via its template parameter. For a breadth-first-search
     * fill, that structure is a Queue, for a depth-first-search, that
     * structure is a Stack. To begin the algorithm, you simply place the
     * given point in the ordering structure, marking it processed
     * (the way you mark it is a design decision you'll make yourself).
     * We have a choice to either change the color, if appropriate, when we
     * add the point to the OS, or when we take it off. In our test cases,
     * we have assumed that you will change the color when a point is added
     * to the structure. 
     *
     * Until the structure is empty, you do the following:
     *
     * 1.     Remove a point from the ordering structure, and then...
     *
     *        1.    add its unprocessed neighbors whose color values are 
     *              within (or equal to) tolerance distance from the center, 
     *              to the ordering structure.
     *        2.    use the colorPicker to set the new color of the point.
     *        3.    mark the point as processed.
     *        4.    if it is an appropriate frame, send the current PNG to the
     *              animation (as described below).
     *
     * 2.     When implementing your breadth-first-search and
     *        depth-first-search fills, you will need to explore neighboring
     *        pixels in some order.
     *
     *        For this assignment, each pixel p has 8 neighbors, consisting of 
     *        the 8 pixels who share an edge or corner with p. (We leave it to
     *        you to describe those 8 pixel locations, relative to the location
     *        of p.)
     *
     *        While the order in which you examine neighbors does not matter
     *        for a proper fill, you must use the same order as we do for
     *        your animations to come out like ours! 
     *
     *        The order you should put
     *        neighboring pixels **ONTO** the ordering structure (queue or stack) 
     *        is as follows: **UPRIGHT(+x,-y), UP(-y), UPLEFT(-x,-y), LEFT(-x), 
     *        DOWNLEFT(-x,+y), DOWN(+y), DOWNRIGHT(+x,+y), RIGHT(+x)**
     *
     *        If you do them in a different order, your fill may
     *        still work correctly, but your animations will be different
     *        from the grading scripts!
     *
     *        IMPORTANT NOTE: *UP*
     *        here means towards the top of the image, so since an image has
     *        smaller y coordinates at the top, this is in the *negative y*
     *        direction. Similarly, *DOWN* means in the *positive y*
     *        direction.  
     *
     * 3.     For every k pixels filled, **starting at the kth pixel**, you
     *        must add a frame to the animation, where k = frameFreq.
     *
     *        For example, if frameFreq is 4, then after the 4th pixel has
     *        been filled you should add a frame to the animation, then again
     *        after the 8th pixel, etc.  You must only add frames for the
     *        number of pixels that have been filled, not the number that
     *        have been checked. So if frameFreq is set to 1, a pixel should
     *        be filled every frame.
     * 4.     Finally, as you leave the function, send one last frame to the
     *        animation. This frame will be the final result of the fill, and 
     *        it will be the one we test against.
     */
template <template <class T> class OrderingStructure>
animation filler::fill(PNG& img, int x, int y, colorPicker& fillColor,
                       double tolerance, int frameFreq)
{
    cout << "\t in fill" << endl;
    //go through pixels in order, add them to ordering structure.
    // when no neighbours left, remove one from ordering structure 
    // and repeat  //yeeettttt
    animation gif = *(new animation());
    gif.addFrame(img);
    int height = img.height();
    int width = img.width();
    HSLAPixel * centrePixel = new HSLAPixel();
    centrePixel->h = img.getPixel(x, y)->h;
    centrePixel->s = img.getPixel(x, y)->s;
    centrePixel->l = img.getPixel(x, y)->l;

    vector< pair<int, int> > * visited = new vector< pair<int, int> >;
    OrderingStructure< pair<int, int> > * toVisit = new OrderingStructure< pair<int, int> >;

    //this is the vector with the order of the neigbours we will visit
    vector< pair<int, int> > neighbours = (*new vector< pair<int, int> >);
    neighbours.push_back(*(new pair<int, int> (1, -1)));
    neighbours.push_back(*(new pair<int, int> (0, -1)));
    neighbours.push_back(*(new pair<int, int> (-1, -1)));
    neighbours.push_back(*(new pair<int, int> (-1, 0)));
    neighbours.push_back(*(new pair<int, int> (-1, 1)));
    neighbours.push_back(*(new pair<int, int> (0, 1)));
    neighbours.push_back(*(new pair<int, int> (1, 1)));
    neighbours.push_back(*(new pair<int, int> (1, 0)));


    //start search
    toVisit->add(*(new pair<int, int>(x, y)));
    int frameCount = 0;

    while(!toVisit->isEmpty()){
        //get the first pair from toVisit, and add all its neighbours to toVisit
        pair<int, int> temp = toVisit->remove();

        //colouring temp
        HSLAPixel * p = img.getPixel(temp.first, temp.second);
        * p = fillColor(temp.first, temp.second); //???????
        if (frameCount % frameFreq == 0) gif.addFrame(img);
        frameCount ++;

        int currX = temp.first;
        int currY = temp.second;

        for(int i = 0; i < 8; i++){
            int newX = currX + neighbours[i].first;
            int newY = currY + neighbours[i].second;

            //if the new x and y coordinates are not outside the img, and tolerance is good:
            if(!(newX >= width || newY >= height || newX < 0 || newY < 0)){
                HSLAPixel * newColour = img.getPixel(newX, newY);

                if(newColour->dist(*centrePixel) <= tolerance){
                    pair<int, int> neigh = *(new pair<int, int>(newX, newY));

                    //check if neigh has been visited
                    vector< pair<int, int> >::iterator it = 
                        find(visited->begin(), visited->end(), neigh);

                    //if it hasn't been visited, add it to visited and toVisit
                    if(it == visited->end()){ 
                        visited->push_back(neigh);
                        toVisit->add(neigh);
                    }
                }
            }      
        }
    }
    cout << "\t out of while loop" << endl;
    gif.addFrame(img);
    return gif;
} 
