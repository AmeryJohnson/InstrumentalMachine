/**
 * @file CardReader.cpp
 * @author Amery Johnson
 */
/// Image for the back of the card reader
const std::wstring CardReaderBackImage = L"/images/card-reader-back.png";

/// Image for the front of the card reader
const std::wstring CardReaderFrontImage = L"/images/card-reader-front.png";

const std::wstring SuzannaCard = L"/images/cards/suzanna.png";
// The card actual dimensions are 847 by 379 pixels,
// a size chosen to make the column spacing exactly
// 10 pixels. We draw it much smaller than that on the screen

/// Width to draw the card on the screen in pixels
const int CardWidth = 132;

/// Height to draw the card on the screen in pixels
const int CardLength = 297;

/// Amount of offset the center of the card so it will
/// appear at the right place relative to the card reader.
const int CardOffsetX = 126;

/// Y dimension of the offset
const int CardOffsetY = 65;

// These values are all for the underlying image. They
// can be used for find the punches.

/// Width of a card column in pixels
const int CardColumnWidth = 10;

/// Height of a card row in pixels
const int CardRowHeight = 29;

/// X offset for the first column (left side)
const int CardColumn0X = 24;

/// Y offset to the first row (0's)
/// There are actually two rows above this that can be used
const int CardRow0Y = 78;

/// Width of a punched hole
const int CardPunchWidth = 8;

/// Height of a punched hole
const int CardPunchHit = 20;

/// Any average luminance below this level is considered a punched hole
const double CardPunchLuminance = 0.1;

//
// These values are for the outputs of the card reader,
// where the tubing attaches.
//

/// Y offset to the first card reader output in pixels
const int OutputOffsetY = -92;

/// X offset to the first card reader output in pixels
const int OutputOffsetX = -35;

/// X spacing for the outputs
const double OutputSpacingX = 10.7;

const int NumSources = 10;
#include "pch.h"
#include "CardReader.h"
#include "AirSinkDestination.h"


CardReader::CardReader(std::wstring resourcesDir)
{
    // Set up the sources
    for (int i = 0; i < NumSources; i++)
    {
        auto source = std::make_shared<AirSource>();
        mSources.push_back(source);
    }

    mBack.SetImage(resourcesDir + CardReaderBackImage);
    mBack.Rectangle(-mBack.GetImageWidth() / 2, 0);

    mFront.SetImage(resourcesDir + CardReaderFrontImage);
    mFront.Rectangle(-mFront.GetImageWidth() / 2, 0);

    mCard.SetImage(resourcesDir + SuzannaCard);
    mCard.Rectangle(CardOffsetX, CardOffsetY, CardLength, CardWidth);
    mCard.SetRotation(-0.25);
}

void CardReader::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{

    mBack.DrawPolygon(graphics, x+GetX(), y);

    auto cardScale = (double)CardLength / mCard.GetImageWidth();

    mCard.DrawPolygon(graphics, x+GetX(), static_cast<int>(y) + (mColumn-1) * cardScale * CardColumnWidth);
    mFront.DrawPolygon(graphics, x+GetX(), y);

}
void CardReader::SetTime(double time)
{
    double beat = time * mBeatsPerMinute / 60.0;
    double remainder = fmod(beat, 1);
    mColumn = (int)beat;
    if(remainder < 0.5)
    {
        // detect the holes and send pressure to the outputs
        // Determine what is punched in this row
        for (int row = 0; row < NumSources; row++)
        {
            bool punched = IsPunched(mColumn, row);
            if(punched && mColumn <= 80)
            {
                mSources[row]->SetPressure(1);
            }
            else
            {
                mSources[row]->SetPressure(0);
            }

        }
    }
    else
    {
        for (int row = 0; row < NumSources; row++)
        {
            mSources[row]->SetPressure(0);
        }
    }
}
/**
 * Determine if a hole is punched in the card.
 * @param column Column on the card, from 0 (left of first column) to 80 (last column)
 * @param row Row on the card, -2 to 9.
 * @return True if hole is punched at column, row
*/
bool CardReader::IsPunched(int column, int row)
{
    auto luminance = mCard.AverageLuminance(CardColumn0X + (column - 1) * CardColumnWidth,
                                            CardRow0Y + CardRowHeight * row, CardPunchWidth, CardPunchHit);
    return luminance < CardPunchLuminance;
}

void CardReader::SetCard(std::wstring filePath)
{
    mCard.SetImage(filePath);
}
