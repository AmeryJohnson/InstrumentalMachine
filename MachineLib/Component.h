/**
 * @file Component.h
 * @author Amery Johnson
 */

#ifndef CANADIANEXPERIENCE_COMPONENT_H
#define CANADIANEXPERIENCE_COMPONENT_H

class Machine;

class Component {
private:

    wxPoint mPosition = wxPoint(0, 0);

    double mTime;

    Machine* mMachine = nullptr;

public:

    /// Constructor
    Component();

    /// Destructor
    virtual ~Component() = default;

    /// Copy constructor/disabled
    Component(const Component&) = delete;

    /// Assignment operator/disabled
    void operator=(const Component&) = delete;

    void SetPosition(int x, int y);

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) = 0;

    virtual void SetTime(double time);

    void SetMachine(Machine* machine) {mMachine = machine;}

    int GetX() {return mPosition.x;}

    int GetY() {return mPosition.y;}

};


#endif //CANADIANEXPERIENCE_COMPONENT_H
