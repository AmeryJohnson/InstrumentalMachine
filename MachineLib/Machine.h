/**
 * @file Machine.h
 * @author Amery Johnson
 */

#ifndef CANADIANEXPERIENCE_MACHINE_H
#define CANADIANEXPERIENCE_MACHINE_H

class MachineSystemActual;
class Component;

class Machine {
private:
    wxPoint mPosition = wxPoint(0, 0);

    double mTime;

    MachineSystemActual* mMachineSystem = nullptr;

    std::vector<std::shared_ptr<Component>> mComponents;


public:
    /// Constructor
    Machine();

    /// Destructor
    virtual ~Machine() = default;

    /// Copy constructor/disabled
    Machine(const Machine&) = delete;

    /// Assignment operator/disabled
    void operator=(const Machine&) = delete;

    void SetMachineSystem(MachineSystemActual* machineSystem) {mMachineSystem = machineSystem;}

    void SetPosition(wxPoint position) {mPosition = position;}

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);

    void SetTime(double time) {mTime = time;}

    void AddComponent(std::shared_ptr<Component> component);

    void SetMachineNumber(int num);




};


#endif //CANADIANEXPERIENCE_MACHINE_H
