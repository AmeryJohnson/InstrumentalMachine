/**
 * @file MachineFactory.h
 * @author Amery Johnson
 */

#ifndef CANADIANEXPERIENCE_MACHINEFACTORY_H
#define CANADIANEXPERIENCE_MACHINEFACTORY_H

#include <memory>
#include <string>

class Machine;
struct ma_engine;

/**
 * Factory for creating Machine #1
 */
class MachineFactory {
private:
    /// Path to the resources directory
    std::wstring mResourcesDir;

    /// The miniaudio engine
    ma_engine* mAudioEngine;

public:
    MachineFactory(const std::wstring& resourcesDir, ma_engine* audioEngine);

    std::shared_ptr<Machine> Create();

};


#endif //CANADIANEXPERIENCE_MACHINEFACTORY_H
