/**
 * @file Instrument.h
 * @author Amery Johnson
 */

#ifndef CANADIANEXPERIENCE_INSTRUMENT_H
#define CANADIANEXPERIENCE_INSTRUMENT_H

#include <miniaudio.h>
#include "Shape.h"

class Instrument : public Shape {
private:
    ma_sound mSound;
public:
    /// Constructor
    Instrument(std::wstring resourcesDir, ma_engine* audioEngine, std::wstring audioFile);

    /// Destructor
    virtual ~Instrument();

    /// Copy constructor/disabled
    Instrument(const Instrument&) = delete;

    /// Assignment operator/disabled
    void operator=(const Instrument&) = delete;

    void PlaySound();
};


#endif //CANADIANEXPERIENCE_INSTRUMENT_H
