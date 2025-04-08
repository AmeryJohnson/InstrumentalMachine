/**
 * @file StruckInstrument.cpp
 * @author Amery Johnson
 */
#include "pch.h"
#include "StruckInstrument.h"
#include "Cylinder.h"

StruckInstrument::StruckInstrument(std::wstring resourcesDir, ma_engine *audioEngine, std::wstring audioFile)
        : Instrument(resourcesDir, audioEngine, audioFile)
{
}

