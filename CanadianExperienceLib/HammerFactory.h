/**
 * @file HammerFactory.h
 * @author Amery Johnson
 */

#ifndef CANADIANEXPERIENCE_HAMMERFACTORY_H
#define CANADIANEXPERIENCE_HAMMERFACTORY_H

class Actor;

/**
 * Factory class that builds the Hammer character
 */
class HammerFactory {
private:

public:

    std::shared_ptr<Actor> Create(std::wstring imagesDir);
};


#endif //CANADIANEXPERIENCE_HAMMERFACTORY_H
