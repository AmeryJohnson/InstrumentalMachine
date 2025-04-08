/**
 * @file Cylinder.cpp
 * @author Amery Johnson
 */
#include "pch.h"
#include "Cylinder.h"
#include "StruckInstrument.h"
/// Cylinder base image
const std::wstring CylinderBaseImage = L"/images/cylinder-base.png";

/// Cylinder body image
const std::wstring CylinderBodyImage = L"/images/cylinder.png";

/// Cylinder ram image
const std::wstring CylinderRamImage = L"/images/cylinder-ram.png";

/// The maximum pixels to move the cylinder ram when enabled
const int CylinderMaxExtent = 44;

/// Angle from bottom center of the cylinder to the tubing connector
const double ConnectorAngle = -0.17;

/// Distance from bottom center of the cylinder to the tubing connector
const double ConnectorDistance = 24.5;

Cylinder::Cylinder(std::wstring resourcesDir) : mSink(this) {
    mMount.SetImage(resourcesDir + CylinderBaseImage);
    mMount.Rectangle(-mMount.GetImageWidth() / 2, 0);

    mCylinder.SetImage(resourcesDir + CylinderBodyImage);
    mCylinder.Rectangle(-mCylinder.GetImageWidth() / 2, 0);

    mRam.SetImage(resourcesDir + CylinderRamImage);
    mRam.Rectangle(-mCylinder.GetImageWidth() / 2, 0);

}

void Cylinder::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    if(mPressure > 0)
    {
        if(mRam.GetRotation() == 0.25)
        {
            mMount.DrawPolygon(graphics, x + GetX(), y + GetY());
            mRam.DrawPolygon(graphics, x + GetX() + CylinderMaxExtent, y + GetY());
            mCylinder.DrawPolygon(graphics, x + GetX(), y + GetY());
        }
        else
        {
            mMount.DrawPolygon(graphics, x + GetX(), y + GetY());
            mRam.DrawPolygon(graphics, x + GetX(), y + mMaxExtent*CylinderMaxExtent + GetY());
            mCylinder.DrawPolygon(graphics, x + GetX(), y + GetY());
        }

    }
    else
    {
        mMount.DrawPolygon(graphics, x + GetX(), y + GetY());
        mRam.DrawPolygon(graphics, x + GetX(), y + GetY());
        mCylinder.DrawPolygon(graphics, x + GetX(), y + GetY());
    }

}

void Cylinder::SetRotation(double rotation)
{
    mMount.SetRotation(rotation);
    mRam.SetRotation(rotation);
    mCylinder.SetRotation(rotation);
}
void Cylinder::SetMotionSink(std::shared_ptr<StruckInstrument> instrument)
{
    mInstrument = instrument;
    mInstrument->SetCylinder(this);
}
void Cylinder::SetPressure(double pressure)
{
    mPressure = pressure;
    if(pressure > 0 && mPressureBefore != 1)
    {
        mInstrument->PlaySound();
    }
    mPressureBefore = pressure;
}


