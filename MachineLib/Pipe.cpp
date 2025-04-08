/**
 * @file Pipe.cpp
 * @author Amery Johnson
 */
#include "pch.h"
#include "Pipe.h"

/// The pipe base image
const std::wstring PipeBaseImage = L"/images/pipe-base.png";

/// The pipe image
const std::wstring PipeImage = L"/images/pipe.png";

/// The pipe top image
const std::wstring PipeTopImage = L"/images/pipe-top.png";

/// The pipe puff image
const std::wstring PuffImage = L"/images/puff.png";

/// Pipe images width in pixels
const int PipeWidth = 20;

/// Pipe base height
const int PipeBaseHeight = 20;

/// Puff image width in pixels
const int PuffWidth = 65;

Pipe::Pipe(std::wstring resourcesDir, ma_engine *audioEngine, std::wstring audioFile, int length) :
        Instrument(resourcesDir, audioEngine, audioFile), mSink(this)
{
    // Instrument base class polygon
    SetImage(resourcesDir + PipeBaseImage);
    Rectangle(-PipeWidth / 2, 0, PipeWidth, PipeWidth);

    // Polygons for the other components
    mPipe.SetImage(resourcesDir + PipeImage);
    mPipe.Rectangle(-PipeWidth / 2, -PipeBaseHeight, PipeWidth, length);


    mPipeTop.SetImage(resourcesDir + PipeTopImage);
    mPipeTop.Rectangle(-PipeWidth / 2, -PipeBaseHeight - length, PipeWidth);

    mPuff.SetImage(resourcesDir + PuffImage);
    mPuff.Rectangle(-PuffWidth / 2, -PipeBaseHeight - length, PuffWidth);
}
void Pipe::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    Shape::Draw(graphics, x, y);
    if(mPressure > 0)
    {

        mPuff.DrawPolygon(graphics, x + GetX(), y + GetY());
    }
    mPipe.DrawPolygon(graphics, x + GetX(), y + GetY());
    mPipeTop.DrawPolygon(graphics, x + GetX(), y + GetY());

}

void Pipe::SetPressure(double pressure)
{
    mPressure = pressure;
    if(pressure > 0 && mPressureBefore != 1)
    {
        PlaySound();
    }
    mPressureBefore = pressure;
}
