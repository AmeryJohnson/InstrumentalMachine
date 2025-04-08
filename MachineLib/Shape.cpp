/**
 * @file Shape.cpp
 * @author Amery Johnson
 */
#include "pch.h"
#include "Shape.h"

Shape::Shape()
{
}
void Shape::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    mPolygon.DrawPolygon(graphics, x + GetX(), y + GetY());
}