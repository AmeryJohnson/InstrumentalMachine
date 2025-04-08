/**
 * @file MachineFactory2.h
 * @author Amery Johnson
 */

#ifndef CANADIANEXPERIENCE_MACHINEFACTORY2_H
#define CANADIANEXPERIENCE_MACHINEFACTORY2_H


#include <memory>
#include <string>

class Machine;
struct ma_engine;

/**
 * Factory for creating Machine #1
 */
class MachineFactory2 {
private:
    /// Path to the resources directory
    std::wstring mResourcesDir;

    /// The miniaudio engine
    ma_engine* mAudioEngine;

public:
    MachineFactory2(const std::wstring& resourcesDir, ma_engine* audioEngine);

    std::shared_ptr<Machine> Create();

};


#endif //CANADIANEXPERIENCE_MACHINEFACTORY2_H
