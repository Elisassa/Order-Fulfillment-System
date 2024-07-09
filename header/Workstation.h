// Name:Rong Chen
// Seneca Student ID:132356221
// Seneca email:rchen104@myseneca.ca
// Date of completion:3/15
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.#pragma once


#ifndef SENECA_WORKSTATION_H
#define SENECA_WORKSTATION_H

#include <deque>
#include <string>
#include "Station.h" 
#include "CustomerOrder.h"

namespace seneca {

    extern std::deque<CustomerOrder> g_pending; //holds the orders to be placed onto the assembly line at the first station.
    extern std::deque<CustomerOrder> g_completed;
    extern std::deque<CustomerOrder> g_incomplete;
    extern std::deque<CustomerOrder> g_incomplete;

    class Workstation : public Station {

        std::deque<CustomerOrder> m_orders;
        Workstation* m_pNextStation=nullptr;

    public:
        Workstation() {}; 
        Workstation(const std::string&);
        void fill(std::ostream&);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station = nullptr);
        Workstation* getNextStation() const;
        void display(std::ostream&) const;
        Workstation& operator+=(CustomerOrder&& newOrder);
        
    };
}
#endif // WORKSTATION_H
