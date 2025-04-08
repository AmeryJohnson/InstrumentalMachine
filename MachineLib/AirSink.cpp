/**
 * @file AirSink.cpp
 * @author Amery Johnson
 */
#include "pch.h"
#include "AirSink.h"

AirSink::AirSink(AirSinkDestination* component)
{
    mComponent = component;
}
void AirSink::SetPressure(double pressure)
{
    mComponent->SetPressure(pressure);
}


