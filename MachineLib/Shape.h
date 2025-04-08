/**
 * @file Shape.h
 * @author Amery Johnson
 *
 */

#ifndef CANADIANEXPERIENCE_SHAPE_H
#define CANADIANEXPERIENCE_SHAPE_H

#include "Component.h"
#include "Polygon.h"

class Shape : public Component
{
private:
    cse335::Polygon mPolygon;

public:
    Shape();

    virtual ~Shape() = default;

    /// Copy constructor/disabled
    Shape(const Shape&) = delete;

    /// Assignment operator/disabled
    void operator=(const Shape&) = delete;


    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

    /**
     * Set an image we will use as a texture for the polygon
     * @param filename Image filename
     */
    void SetImage(std::wstring filename) { mPolygon.SetImage(filename); }

    /**
     * Create a rectangle
     * @param x Left side X
     * @param y Bottom left Y
     * @param wid Width of the rectangle. If not supplied, use an image width
     * @param hit Height of the rectangle. If not supplied, use an image height
     */
    void Rectangle(int x, int y, int wid = 0, int hit = 0) { mPolygon.Rectangle(x, y, wid, hit); }

    /**
     * Get the width of any set image for this polygon. This may not be
     * the width we actually draw, but is the size of the polygon itself.
     * @return Width in pixels
    */
    int GetImageWidth() { return mPolygon.GetImageWidth(); }

    void SetColor(wxColour color) {mPolygon.SetColor(color);}

    //cse335::Polygon GetPolygon() {return mPolygon;}


};


#endif //CANADIANEXPERIENCE_SHAPE_H
