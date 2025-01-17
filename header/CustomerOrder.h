// Name:Rong Chen
// Seneca Student ID:132356221
// Seneca email:rchen104@myseneca.ca
// Date of completion:3/15
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SENECA_CUSTOMERORDER_H
#define SENECA_CUSTOMERORDER_H

#include <iostream>
#include <string>
#include <vector>
#include"Station.h"

namespace seneca
{
	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder
	{
		std::string m_name{}; //the name of the customer
		std::string m_product{};
		size_t m_cntItem{};// a count of the number of items in the customer's order
		Item** m_lstItem=nullptr;
		static size_t m_widthField; //maximum width of a field,

	public:
		CustomerOrder();
		CustomerOrder(const std::string& str);
		CustomerOrder (const CustomerOrder& src);
		CustomerOrder& operator=(const CustomerOrder& src) = delete;
		CustomerOrder(CustomerOrder&& src) noexcept;
		CustomerOrder& operator = (CustomerOrder&& src) noexcept;
		~CustomerOrder();
		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
		//CustomerOrder(CustomerOrder& copy);//!!!1!!1!11
	};

}

#endif
