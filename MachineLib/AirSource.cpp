/**
 * @file AirSource.cpp
 * @author Amery Johnson
 */
#include "pch.h"
#include "AirSource.h"

AirSource::AirSource()
{
}

void AirSource::SetPressure(double pressure)
{
    if(mSink != nullptr)
    {
        mSink->SetPressure(pressure);
    }
}
