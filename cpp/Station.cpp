// Name:Rong Chen
// Seneca Student ID:132356221
// Seneca email:rchen104@myseneca.ca
// Date of completion:3/15
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

using namespace std;

namespace seneca {

    int Station::id_generator=0;
    size_t Station::m_widthField{};

    Station::Station(const std::string& record) {
        size_t next_pos = 0;
        bool more = true;
        Utilities util;

        try {
            if (more) {
                name = util.extractToken(record, next_pos, more);
            }

            if (more) {
                nextNum = stoul(util.extractToken(record, next_pos, more));
            }

            if (more) {
                stock = std::stoul(util.extractToken(record, next_pos, more));
            }

            if (m_widthField > util.getFieldWidth()) {
                m_widthField = m_widthField;
            }
            else {
                m_widthField = util.getFieldWidth();
            }
            desc = util.extractToken(record, next_pos, more);

            if (more) {
                desc = util.extractToken(record, next_pos, more);
            }

        }
        catch (const string err) {
            cout << err << endl;
        }
        id=++id_generator;
    }


	const std::string& Station::getItemName() const {
        return name;
	}


	size_t Station::getNextSerialNumber() { //returns the next serial number
        return nextNum++;
	}

    size_t Station::getQuantity() const {
        return stock;
    }

	void Station::updateQuantity() {
        if (stock > 0) {  
            stock--;
        }
	}

	void Station::display(std::ostream& os, bool full) const {
        os.clear();
        os << right<<setw(3) << setfill('0') << id << " | "
            << setw(m_widthField) << setfill(' ') << left << name << " | "
            << setw(6) << setfill('0') << right <<nextNum <<" | ";

        if (full) {
            os << setw(4) << setfill(' ') <<stock << " | " << desc;
        }
        os << endl;
	}


}