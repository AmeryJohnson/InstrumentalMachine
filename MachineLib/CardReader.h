/**
 * @file CardReader.h
 * @author Amery Johnson
 */

#ifndef CANADIANEXPERIENCE_CARDREADER_H
#define CANADIANEXPERIENCE_CARDREADER_H

#include "Component.h"
#include "Polygon.h"
#include "AirSource.h"

class CardReader : public Component {
private:
    cse335::Polygon mBack;
    cse335::Polygon mFront;
    cse335::Polygon mCard;
    int mColumn = 0;
    double mBeatsPerMinute = 180;
    /// The air sources to drive things
    std::vector<std::shared_ptr<AirSource>> mSources;

public:
    /// Constructor
    CardReader(std::wstring resourcesDir);

    /// Destructor
    virtual ~CardReader() = default;

    /// Copy constructor/disabled
    CardReader(const CardReader&) = delete;

    /// Assignment operator/disabled
    void operator=(const CardReader&) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

    void SetTime(double time) override;

    /**
     * Get an air source.
     * @param i Source index 0-9
     * @return Pointer to AirSource object.
    */
    std::shared_ptr<AirSource> GetSource(int i) { return mSources[i]; }

    bool IsPunched(int column, int row);

    void SetCard(std::wstring filePath);

};


#endif //CANADIANEXPERIENCE_CARDREADER_H
