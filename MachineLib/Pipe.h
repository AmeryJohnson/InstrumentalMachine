/**
 * @file Pipe.h
 * @author Amery Johnson
 */

#ifndef CANADIANEXPERIENCE_PIPE_H
#define CANADIANEXPERIENCE_PIPE_H

#include "Instrument.h"
#include "Shape.h"
#include "Polygon.h"
#include "AirSinkDestination.h"
#include "AirSink.h"

class Pipe : public Instrument, AirSinkDestination {
private:
    double mPressure = 0;
    double mPressureBefore = 0;
    AirSink mSink;
    cse335::Polygon mPipe;
    cse335::Polygon mPipeTop;
    cse335::Polygon mPuff;
public:
    /// Constructor
    Pipe(std::wstring resourcesDir, ma_engine* audioEngine, std::wstring sound, int length);

    /// Copy constructor/disabled
    Pipe(const Pipe&) = delete;

    /// Assignment operator/disabled
    void operator=(const Pipe&) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

    void SetPressure(double pressure) override;

    AirSink *GetSink() {return &mSink;}
};


#endif //CANADIANEXPERIENCE_PIPE_H
