/**
 * @file MachineSystemActual.cpp
 * @author Amery Johnson
 */
#include "pch.h"
#include "MachineSystemActual.h"
#include "Machine.h"
#include "MachineFactory.h"
#include "MachineFactory2.h"

MachineSystemActual::MachineSystemActual(const std::wstring& resourcesDir, ma_engine* audioEngine) :
    mResourcesDir(resourcesDir), mAudioEngine(audioEngine)
{

    MachineFactory machineFactory(resourcesDir, audioEngine);
    mMachine = machineFactory.Create();
    mMachine->SetMachineSystem(this);

    mMachineNumber = 1;
}

void MachineSystemActual::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    mMachine->SetTime(GetMachineTime());
    mMachine->Draw(graphics, mLocation.x, mLocation.y);
}
void MachineSystemActual::SetMachineNumber(int machine)
{
    mMachineNumber = machine;
    if(machine == 2)
    {
        MachineFactory2 machineFactory(mResourcesDir, mAudioEngine);
        mMachine = machineFactory.Create();
        mMachine->SetMachineSystem(this);
    }
    else
    {
        MachineFactory machineFactory(mResourcesDir, mAudioEngine);
        mMachine = machineFactory.Create();
        mMachine->SetMachineSystem(this);
    }
}
