/**
 * @file AirSource.h
 * @author Amery Johnson
 */

#ifndef CANADIANEXPERIENCE_AIRSOURCE_H
#define CANADIANEXPERIENCE_AIRSOURCE_H

#include "AirSink.h"
#include "AirSinkDestination.h"

class AirSource {
private:
    double mPressure = 0;
    AirSink* mSink = nullptr;
    AirSinkDestination* mTubing = nullptr;
public:

    AirSource();

    virtual ~AirSource() = default;
    /// Copy constructor (disabled)
    AirSource(const AirSource &) = delete;

    /// Assignment operator (disabled)
    void operator=(const AirSource &) = delete;

    void SetPressure(double pressure);

    AirSink *GetSink() {return mSink;}

    void SetSink(AirSink* sink) {mSink = sink;}

};


#endif //CANADIANEXPERIENCE_AIRSOURCE_H
