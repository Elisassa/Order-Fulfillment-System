// Name:Rong Chen
// Seneca Student ID:132356221
// Seneca email:rchen104@myseneca.ca
// Date of completion:3/15
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SENECA_STATION_H
#define SENECA_STATION_H

#include <iostream>
#include <string>
#include <vector>

namespace seneca
{

	class Station
	{
		int id;
		std::string name;
		std::string desc;
		size_t nextNum;
		size_t stock;
		static size_t m_widthField;
		static int id_generator;

	public:
		Station() {};
		Station(const std::string &str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};

}

#endif

