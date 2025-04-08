/**
 * @file PictureFactory.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "HammerFactory.h"
#include "SpartyFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"
#include "MachineDrawable.h"

using namespace std;

/// Directory within resources that contains the images.
const std::wstring ImagesDirectory = L"/images";


/**
 * Factory method to create a new picture.
 * @param resourcesDir Directory that contains the resources for this application
 * @param audioEngine The audio engine to use in this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring resourcesDir, ma_engine* audioEngine)
{
    auto imagesDir = resourcesDir + ImagesDirectory;

    shared_ptr<Picture> picture = make_shared<Picture>();

    // Create the background and add it
    auto background = make_shared<Actor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(wxPoint(0, 0));
    auto backgroundI =
            make_shared<ImageDrawable>(L"Background", imagesDir + L"/Background.jpg");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    auto timeline = picture->GetTimeline();

    auto machineActor = make_shared<Actor>(L"Machine");
    auto machine = make_shared<MachineDrawable>(L"machine", resourcesDir, audioEngine);
    machine->SetTime(timeline->GetCurrentFrame());
    machineActor->SetPosition(wxPoint(600, 600));
    machineActor->AddDrawable(machine);
    machineActor->SetRoot(machine);


    picture->AddActor(machineActor);

    // Create and add Harold
    HaroldFactory haroldFactory;
    auto harold = haroldFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(300, 500));
    picture->AddActor(harold);



    // Create and add Sparty
    SpartyFactory spartyFactory;
    auto sparty = spartyFactory.Create(imagesDir);

    sparty->SetPosition(wxPoint(900, 620));
    picture->AddActor(sparty);

    //Create and add Hammer
    HammerFactory hammerFactory;
    auto hammer = hammerFactory.Create(imagesDir);

    hammer->SetPosition(wxPoint(220, 485));
    picture->AddActor(hammer);

    return picture;
}

