/**
 * @file MachineSystemActual.h
 * @author Amery Johnson
 */
#ifndef CANADIANEXPERIENCE_MACHINESYSTEMACTUAL_H
#define CANADIANEXPERIENCE_MACHINESYSTEMACTUAL_H


#include "MachineSystem.h"
class Machine;
struct ma_engine;

class MachineSystemActual : public MachineSystem {
private:
    double mFrameRate = 0;
    int mFrame = 0;
    wxPoint mLocation;
    int mMachineNumber;
    std::shared_ptr<Machine> mMachine;
    std::wstring mResourcesDir;
    ma_engine* mAudioEngine;

public:
    /// Constructor
    MachineSystemActual(const std::wstring& resourcesDir, ma_engine* audioEngine);

    /// Destructor
    virtual ~MachineSystemActual() = default;

    /// Copy constructor/disabled
    MachineSystemActual(const MachineSystemActual&) = delete;

    /// Assignment operator/disabled
    void operator=(const MachineSystemActual&) = delete;

    void SetMachine(std::shared_ptr<Machine> machine) {mMachine = machine;}

    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;

    void SetLocation(wxPoint loc) override {mLocation = loc;}

    wxPoint GetLocation() override {return mLocation;}

    void SetMachineFrame(int frame) override {mFrame = frame;}

    void SetFrameRate(double rate) override {mFrameRate = rate;}

    void SetMachineNumber(int machine) override;

    int GetMachineNumber() override {return mMachineNumber;}

    double GetMachineTime() override {return static_cast<double>(mFrame) / mFrameRate;}
};


#endif //CANADIANEXPERIENCE_MACHINESYSTEMACTUAL_H
