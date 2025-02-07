/*************************************************************
//                 Parking Module
// File    Parking.h
// Version 1.0
// Date    November 7, 2022
// Author  James Giroux - jgiroux1@myseneca.ca
// Description:
// Parking class header file
// --------------------------------------
// Name            Date            Reason
// ----            ----            ------
// J Giroux       Nov 7, 22       Initial Version 1.0
//
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the
// code that my professor provided to complete my project
// milestones.
// -----------------------------------------------------------
*************************************************************/

#ifndef SDDS_PARKING_H_
#define SDDS_PARKING_H_

#include "Menu.h"
#include "Vehicle.h"

const int MAX_PARKING_SPOTS = 100;

namespace sdds {
    class Parking {
        char* m_path;
        Menu m_menu;
        Menu m_Vmenu; // sub - Menu for type of Vehicle
        Vehicle* m_vehicles[MAX_PARKING_SPOTS];
        int m_numSpots = MAX_PARKING_SPOTS;
        int m_numParked = 0;
        bool isEmpty() const;
        void status() const;
        void park();
        // used for parking either a car or motorcycle
        void parkVehicle(Vehicle* V, int loc);
        // used in find() and returnV()
        // heading is either "Vehicle found" or "Returning:"
        int findVehicle(const char* heading);
        void pause();
        void find();
        void returnV();
        void list();
        bool close();
        bool exitApp();
        bool loadData();
        void saveData();
    public:
        Parking(const char* filePath, int numSpots);
        Parking(const Parking& P) = delete;
        Parking& operator=(const Parking& P) = delete;
        int run();
        // making distructor virtual ensures that if Parking is inherited
        // and our main() was using pointers or references to a Parking obj, 
        // the base class destructors would still get called and we won't have 
        // memory leaks
        virtual ~Parking();
    };
}

#endif // !SDDS_PARKING_H_