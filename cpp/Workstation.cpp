// Name:Rong Chen
// Seneca Student ID:132356221
// Seneca email:rchen104@myseneca.ca
// Date of completion:3/15
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.#pragma once

#include <iostream>
#include <string>
#include "Workstation.h"

using namespace std;
namespace seneca {

    deque<CustomerOrder> g_pending;
    deque<CustomerOrder> g_completed;
    deque<CustomerOrder> g_incomplete;

 

    Workstation::Workstation(const std::string& str) : Station(str){
        //Workstation* m_pNextStation = nullptr;
    }

    void Workstation::fill(std::ostream& os) {
        if (!m_orders.empty()) {
            m_orders.front().fillItem(*this, os);
        }
    }
   

    bool Workstation::attemptToMoveOrder() {
        if (!m_orders.empty()) { 
            if (m_orders.front().isItemFilled(this->getItemName())|| this->getQuantity() < 1) {//very important! check if have item and it's quantity
                if (m_pNextStation != nullptr) {//if there still have order
                    *m_pNextStation += move(m_orders.front()); //move to next station 
                }
                else {
                     //if this is last station
                    if (m_orders.front().isOrderFilled()) {//if order is complete
                        g_completed.push_back(move(m_orders.front())); 
                    }
                    else {//if order is incomplete
                        g_incomplete.push_back(move(m_orders.front())); 
                    }
                }
                m_orders.pop_front(); 
                return true; 
            }
        }
        return false; 
    }

  
    void Workstation::setNextStation(Workstation* station) {
        m_pNextStation = station;
    }

    Workstation* Workstation::getNextStation() const {
        return m_pNextStation;
    }

    void Workstation::display(std::ostream& os) const {
      
        os << getItemName(); 

        if (m_pNextStation != nullptr) {
            os << " --> " << m_pNextStation->getItemName() << '\n';
        }
        else {

            os << " --> End of Line\n";
        }
    }

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
        m_orders.push_back(move(newOrder));
        return *this;
    }
}