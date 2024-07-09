//// Name:Rong Chen
//// Seneca Student ID:132356221
//// Seneca email:rchen104@myseneca.ca
//// Date of completion:3/15
////
//// I confirm that I am the only author of this file
////   and the content was created entirely by me.
//
//#include <iomanip> 
//#include "CustomerOrder.h"
//#include "Utilities.h"
//
//using namespace std;
//
//namespace seneca {
//	size_t CustomerOrder::m_widthField{};
//
//	CustomerOrder::CustomerOrder(const string& str) {
//
//		Utilities util; 
//		size_t next_pos = 0;
//		bool more = true;
//
//		//get customer name
//		if (more) {
//			m_name = util.extractToken(str, next_pos, more);
//		}
//
//		//get product name
//		if (more) {
//			m_product = util.extractToken(str, next_pos, more);
//		}
//
//		//count num of item
//		size_t start_pos = next_pos;
//		while (more) {
//			util.extractToken(str, next_pos, more);
//			m_cntItem++;
//		}
//
//		m_lstItem = new Item * [m_cntItem];
//
//		more = true;
//		next_pos = start_pos;
//
//		for (size_t i = 0; i < m_cntItem; ++i) {
//			string itemStr = util.extractToken(str, next_pos, more);
//			m_lstItem[i] = new Item(itemStr); 
//		}
//
//		if (m_widthField < util.getFieldWidth()) {
//			CustomerOrder::m_widthField = util.getFieldWidth();
//		}
//		
//	}
//
//	CustomerOrder::CustomerOrder(const CustomerOrder& src) {
//		throw "You can't use copy construction";
//	}
//
//	//Move constr
//	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
//		if (this != &src)
//		{
//			*this = std::move(src);
//		}
//	}
//
//	//Move assign
//	/*CustomerOrder& CustomerOrder::operator= (CustomerOrder&& src) noexcept {
//		if (this != &src) {
//			for (size_t i = 0; i < m_cntItem; ++i) {
//				delete m_lstItem[i];
//			}
//			delete[] m_lstItem;
//
//			if (src.m_lstItem) {
//				m_name = move(src.m_name);
//				m_product = move(src.m_product);
//				m_cntItem = src.m_cntItem;
//				m_lstItem = src.m_lstItem;
//			}
//		}
//		src.m_lstItem = nullptr;
//		src.m_cntItem = 0;
//
//		return *this;
//	}*/
//	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& copy)noexcept
//	{
//		if (this != &copy)
//		{
//			for (size_t i = 0; i < m_cntItem; i++)
//			{
//				delete m_lstItem[i];
//			}
//			delete[] m_lstItem;
//			m_lstItem = nullptr;
//
//			m_name = copy.m_name;
//			m_product = copy.m_product;
//			m_cntItem = copy.m_cntItem;
//			m_lstItem = copy.m_lstItem;
//
//			copy.m_name = "";
//			copy.m_product = "";
//			copy.m_cntItem = 0;
//			copy.m_lstItem = nullptr;
//		}
//		return *this;
//	}
//
//
//	CustomerOrder::~CustomerOrder() {
//		for (size_t i = 0; i < m_cntItem; ++i) {
//			delete m_lstItem[i];
//		}
//		delete[] m_lstItem;
//	}
//
//	bool CustomerOrder::isOrderFilled() const {
//		for (size_t i = 0; i < m_cntItem; ++i) {
//			if (m_lstItem[i]->m_isFilled==false) {
//				return false;
//			}
//		}
//		return true; 
//	}
//
//	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
//		for (size_t i = 0; i < m_cntItem; ++i) {
//			if (m_lstItem[i]->m_itemName == itemName && !m_lstItem[i]->m_isFilled) {
//				return false; 
//			}
//		}
//		return true; 
//	}
//
//	//void CustomerOrder::fillItem(Station& station, std::ostream& os) {
//
//	//	for (size_t i = 0; i < m_cntItem; ++i) {
//	//		if (m_lstItem[i]->m_itemName == station.getItemName()) {
//	//			if (!m_lstItem[i]->m_isFilled) { 
//	//				if (station.getQuantity() > 0) { 
//	//					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
//	//					m_lstItem[i]->m_isFilled = true;
//	//					station.updateQuantity(); 
//
//	//					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]\n";
//	//					break; //brak after filled
//	//				}
//	//				else {
//	//					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]\n";
//	//					break; 
//	//				}
//	//			}
//	//		}
//	//	}
//
//	//
//	//}
//
//	void CustomerOrder::fillItem(Station& station, std::ostream& os)
//	{
//		for (size_t i = 0; i < m_cntItem; i++)
//		{
//			Item* currentItem = m_lstItem[i];
//			if (station.getItemName() == currentItem->m_itemName && !currentItem->m_isFilled)
//			{
//				if (station.getQuantity() > 0)
//				{
//					station.updateQuantity();
//					currentItem->m_serialNumber = station.getNextSerialNumber();
//					currentItem->m_isFilled = true;
//					os << "    Filled " << m_name << ", " << m_product << " [" << currentItem->m_itemName << "]" << endl;
//					break;
//				}
//				else
//				{
//					os << "    Unable to fill " << m_name << ", " << m_product << " [" << currentItem->m_itemName << "]" << endl;
//				}
//			}
//
//		}
//	}
//
//
//
//
//	void CustomerOrder::display(std::ostream& os) const {
//		os << m_name << " - " << m_product << endl;
//
//
//		for (size_t i = 0; i < m_cntItem; ++i) {
//			os << "[" << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
//			os << left << setfill(' ')<< setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";
//			os << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << endl;
//
//		}
//	}
//
//}


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <iomanip>
#include <algorithm>
#include <istream>
#include "CustomerOrder.h"
#include "Utilities.h"
using namespace std;
namespace seneca
{
	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder()
	{
		m_name = "";
		m_product = "";
	}

	CustomerOrder::CustomerOrder(const std::string& str)
	{
		Utilities util;
		size_t next_pos = 0;
		bool more = false;
		int i = 0;
		delete[] m_lstItem;
		m_name = util.extractToken(str, next_pos, more);
		if (more)
		{
			m_product = util.extractToken(str, next_pos, more);
		}
		std::string remain = "";
		if (more)
		{
			remain = str.substr(next_pos);
		}
		size_t count_delim = std::count(remain.begin(), remain.end(), util.getDelimiter());
		count_delim += 1;
		m_cntItem = count_delim;
		m_lstItem = new Item * [m_cntItem];

		next_pos = 0;
		while (more)
		{
			std::string item_name = util.extractToken(remain, next_pos, more);
			Item* item = new Item(item_name);
			m_lstItem[i] = item;
			i++;

		}
		if (util.getFieldWidth() > CustomerOrder::m_widthField)
		{
			CustomerOrder::m_widthField = util.getFieldWidth();
		}

	}

	bool CustomerOrder::isOrderFilled() const
	{
		bool flag = true;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_isFilled != true)
			{
				flag = false;
				break;
			}
		}
		return flag;

	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool flag = true;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_itemName == itemName && m_lstItem[i]->m_isFilled == false)
			{
				flag = false;
			}
		}
		return flag;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			Item* currentItem = m_lstItem[i];
			if (station.getItemName() == currentItem->m_itemName && !currentItem->m_isFilled)
			{
				if (station.getQuantity() > 0)
				{
					station.updateQuantity();
					currentItem->m_serialNumber = station.getNextSerialNumber();
					currentItem->m_isFilled = true;
					os << "    Filled " << m_name << ", " << m_product << " [" << currentItem->m_itemName << "]" << endl;
					break;
				}
				else
				{
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << currentItem->m_itemName << "]" << endl;
				}
			}

		}
	}

	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name;
		os << " - " << m_product << std::endl;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			os << std::right;
			os << "[" << std::setfill('0') << std::setw(6) << m_lstItem[i]->m_serialNumber << "] ";
			os << std::left << setfill(' ');
			os << setw(CustomerOrder::m_widthField);
			os << m_lstItem[i]->m_itemName << " - ";
			if (m_lstItem[i]->m_isFilled == true)
			{
				os << "FILLED" << std::endl;
			}
			else
			{
				os << "TO BE FILLED" << std::endl;

			}
		}
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& copy)noexcept
	{
		if (this != &copy)
		{
			for (size_t i = 0; i < m_cntItem; i++)
			{
				delete m_lstItem[i];
			}
			delete[] m_lstItem;
			m_lstItem = nullptr;

			m_name = copy.m_name;
			m_product = copy.m_product;
			m_cntItem = copy.m_cntItem;
			m_lstItem = copy.m_lstItem;

			copy.m_name = "";
			copy.m_product = "";
			copy.m_cntItem = 0;
			copy.m_lstItem = nullptr;
		}
		return *this;
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& copy)noexcept
	{
		if (this != &copy)
		{
			*this = std::move(copy);
		}
	}

	CustomerOrder::~CustomerOrder()
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
		m_lstItem = nullptr;
	}
}
