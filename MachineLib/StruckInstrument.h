/**
 * @file StruckInstrument.h
 *
 * @author Amery Johnson
 */

#ifndef CANADIANEXPERIENCE_STRUCKINSTRUMENT_H
#define CANADIANEXPERIENCE_STRUCKINSTRUMENT_H

#include "Instrument.h"
class Cylinder;

class StruckInstrument : public Instrument {
private:
    Cylinder* mCylinder = nullptr;
public:
    /// Constructor
    StruckInstrument(std::wstring resourcesDir, ma_engine* audioEngine, std::wstring audioFile);

    /// Copy constructor/disabled
    StruckInstrument(const StruckInstrument&) = delete;

    /// Assignment operator/disabled
    void operator=(const StruckInstrument&) = delete;

    void SetCylinder(Cylinder* cylinder) {mCylinder = cylinder;}

};


#endif //CANADIANEXPERIENCE_STRUCKINSTRUMENT_H
