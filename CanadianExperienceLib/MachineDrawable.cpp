/**
 * @file MachineDrawable.cpp
 * @author Amery Johnson
 */
#include "pch.h"
#include "MachineDrawable.h"

MachineDrawable::MachineDrawable(std::wstring name, std::wstring resourcesDir, ma_engine* audioEngine) :
    Drawable(name)
{

    MachineSystemFactory factory(resourcesDir, audioEngine);
    mMachineSystem = factory.CreateMachineSystem();
    if(mMachineSystem->GetMachineTime() < 0)
    {
        mMachineSystem->SetMachineFrame(0);
    }
    mMachineSystem->SetFrameRate(30);


}
void MachineDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mMachineSystem->SetLocation(mPlacedPosition);
    mMachineSystem->DrawMachine(graphics);
}
bool MachineDrawable::HitTest(wxPoint pos)
{
    return false;
}
void MachineDrawable::SetTime(int time)
{
    mMachineSystem->SetMachineFrame(time);

}