/*************************************************************
//                 Vehicle Module
// File    Vehicle.h
// Version 1.0
// Date    November 12, 2022
// Author  James Giroux - jgiroux1@myseneca.ca
// Description:
// Vehicle class
// --------------------------------------
// Name            Date            Reason
// ----            ----            ------
// J Giroux       Nov 12, 22       Initial Version 1.0
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the
// code that my professor provided to complete my project
// milestones.
// -----------------------------------------------------------
*************************************************************/

#ifndef SDDS_VEHICLE_H_
#define SDDS_VEHICLE_H_

#include "ReadWritable.h"

namespace sdds {
    // abstract base class Vehicle bc writeType() is pure virtual
    // to be impemented in Car and Motorcycle classes
    class Vehicle : public ReadWritable {
        char m_plate[9]{ '\0' };
        char* m_makeModel = nullptr;
        int m_spot = 0;
    protected:
        void setEmpty();
        bool isEmpty() const;
        const char* getMakeModel() const;
        void setMakeModel(const char* mkModel);
        const char* getLicencePlate() const;
    public:
        int getParkingSpot() const;
        Vehicle();
        Vehicle(const char* plate, const char* mkModel);
        virtual ~Vehicle();
        Vehicle& operator=(const Vehicle& V);
        Vehicle(const Vehicle& V);
        void setParkingSpot(int spot);
        bool operator==(const char* plate) const;
        bool operator==(const Vehicle& V) const;
        std::istream& read(std::istream& is = std::cin);
        std::ostream& write(std::ostream& os = std::cout) const;
        // will print the car or motorcycle
        virtual std::ostream& writeType(std::ostream& os) const = 0;
     };
}

#endif // !SDDS_VEHICLE_H_