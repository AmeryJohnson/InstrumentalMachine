/**
 * @file Machine.cpp
 * @author Amery Johnson
 */
#include "pch.h"
#include "Machine.h"
#include "MachineSystemActual.h"
#include "Component.h"

Machine::Machine()
{
}

void Machine::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    for(auto component : mComponents)
    {
        component->SetTime(mMachineSystem->GetMachineTime());
        component->Draw(graphics, x, y);
    }
}

void Machine::AddComponent(std::shared_ptr<Component> component)
{
    mComponents.push_back(component);
    component->SetMachine(this);
}
