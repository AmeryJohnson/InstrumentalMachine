/**
 * @file Cylinder.h
 * @author Amery Johnson
 */

#ifndef CANADIANEXPERIENCE_CYLINDER_H
#define CANADIANEXPERIENCE_CYLINDER_H

#include "Component.h"
#include "AirSinkDestination.h"
#include "AirSink.h"
#include "Polygon.h"
#include "StruckInstrument.h"

class Cylinder : public Component, AirSinkDestination {
private:
    double mPressure = 0;
    double mPressureBefore = 0;
    double mMaxExtent = 1;
    AirSink mSink;
    std::shared_ptr<StruckInstrument> mInstrument;
    cse335::Polygon mMount;
    cse335::Polygon mCylinder;
    cse335::Polygon mRam;

public:
    /// Constructor
    Cylinder(std::wstring resourcesDir);

    /// Destructor
    virtual ~Cylinder() = default;

    /// Copy constructor/disabled
    Cylinder(const Cylinder&) = delete;

    /// Assignment operator/disabled
    void operator=(const Cylinder&) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

    void SetRotation(double rotation);

    void SetPressure(double pressure) override;

    void SetMaxExtent(double extent) {mMaxExtent = extent;}

    AirSink *GetSink() {return &mSink;}

    void SetMotionSink(std::shared_ptr<StruckInstrument> instrument);

};


#endif //CANADIANEXPERIENCE_CYLINDER_H
