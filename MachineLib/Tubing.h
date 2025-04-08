/**
 * @file Tubing.h
 * @author Amery Johnson
 */

#ifndef CANADIANEXPERIENCE_TUBING_H
#define CANADIANEXPERIENCE_TUBING_H

#include "AirSink.h"
#include "AirSource.h"
#include "Component.h"
#include "AirSinkDestination.h"

class Tubing : public Component, AirSinkDestination {
private:
    double mPressure = 0;
    double mPressureBefore = 0;
    AirSink mSink;
    AirSource mSource;
public:
    /// Constructor
    Tubing();

    /// Destructor
    virtual ~Tubing() = default;

    /// Copy constructor/disabled
    Tubing(const Tubing&) = delete;

    /// Assignment operator/disabled
    void operator=(const Tubing&) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

    void SetPressure(double pressure) override;

    AirSink *GetSink() {return &mSink;}

    AirSource *GetSource() {return &mSource;}
};


#endif //CANADIANEXPERIENCE_TUBING_H
