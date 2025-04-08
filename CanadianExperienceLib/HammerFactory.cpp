/**
 * @file HammerFactory.cpp
 * @author Amery Johnson
 */


#include "pch.h"
#include "HammerFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"
#include "PolyDrawable.h"

using namespace std;

std::shared_ptr<Actor> HammerFactory::Create(std::wstring imagesDir)
{

    shared_ptr<Actor> actor = make_shared<Actor>(L"Hammer");

    auto hammer = make_shared<ImageDrawable>(L"Hammer", imagesDir + L"/hammer.png");
    hammer->SetCenter(wxPoint(62, 62));
    hammer->SetPosition(wxPoint(0, -144));
    actor->SetRoot(hammer);

    actor->AddDrawable(hammer);
    return actor;
}
