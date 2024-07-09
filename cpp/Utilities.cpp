// Name:Rong Chen
// Seneca Student ID:132356221
// Seneca email:rchen104@myseneca.ca
// Date of completion:3/15
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include <vector>
#include "Utilities.h"

using namespace std;

namespace seneca
{
	char Utilities::m_delimiter = ' ';

	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const {
		return  m_widthField;
	}

    string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

        size_t pos = str.find(m_delimiter, next_pos);

        if (pos == string::npos) {
            more = false;
            pos = str.length();
        }
        else if (pos == next_pos) {
            more = false;
            throw "Delimiter found at next_pos.";
        }
        else {
            more = true;
        }

        string token = str.substr(next_pos, pos - next_pos);
        next_pos = pos + 1;

        size_t first = token.find_first_not_of(' ');
        size_t last = token.find_last_not_of(' ');
        if (first != std::string::npos && last != std::string::npos) {
            token = token.substr(first, (last - first + 1));
        }

        if (m_widthField < token.length()) {
            m_widthField = token.length();
        }

        return token;
    }

	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter() {
		return m_delimiter;
	}

}