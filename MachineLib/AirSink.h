/**
 * @file AirSink.h
 *
 * @author Amery Johnson
 */

#ifndef CANADIANEXPERIENCE_AIRSINK_H
#define CANADIANEXPERIENCE_AIRSINK_H

#include "Component.h"
#include "AirSinkDestination.h"
class AirSource;

class AirSink {
private:
    double mPressure = 0;
    AirSinkDestination* mComponent = nullptr;
    std::shared_ptr<AirSource> AirSource;
public:
    AirSink(AirSinkDestination* component);

    virtual ~AirSink() = default;
    /// Copy constructor (disabled)
    AirSink(const AirSink &) = delete;

    void SetPressure(double pressure);

};


#endif //CANADIANEXPERIENCE_AIRSINK_H
