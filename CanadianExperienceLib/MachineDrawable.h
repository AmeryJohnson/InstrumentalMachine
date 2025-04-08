/**
 * @file MachineDrawable.h
 *
 * @author Amery Johnson
 */

#ifndef CANADIANEXPERIENCE_MACHINEDRAWABLE_H
#define CANADIANEXPERIENCE_MACHINEDRAWABLE_H

#include "Drawable.h"
#include "Timeline.h"
#include <machine-api.h>

class MachineDrawable : public Drawable
{
private:
    double mStartTime = 0;
    std::shared_ptr<MachineSystem> mMachineSystem;
public:
    MachineDrawable(std::wstring name, std::wstring resourcesDir, ma_engine* audioEngine);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    bool HitTest(wxPoint pos) override;
    void SetTime(int time);
};


#endif //CANADIANEXPERIENCE_MACHINEDRAWABLE_H
