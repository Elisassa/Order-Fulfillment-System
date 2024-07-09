# Order-Fulfillment-System
Order Fulfillment System
The Order Fulfillment System is a C++ application designed to simulate an assembly line with multiple workstations. Each workstation processes customer orders by filling requested items if available in stock. The project showcases the use of object-oriented programming, dynamic memory management, and move semantics in C++ to efficiently manage customer orders, inventory, and processing.

## Table of Contents

- [Project Overview](#project-overview)
- [Features](#features)
  - [Dynamic Order Processing](#dynamic-order-processing)
  - [Customer Order Handling](#customer-order-handling)
  - [Line Management](#line-management)
  - [Workstation Functionality](#workstation-functionality)
- [Example Input Files](#example-input-files)
- [Example Output](#example-output)
- [Dependencies](#dependencies)

## Project Overview

This project simulates an assembly line where customer orders are processed through multiple workstations. Each workstation holds specific stock items and fills customer orders as they move along the line. The line manager oversees the movement of orders, ensuring efficient processing. The project demonstrates skills in C++ object-oriented programming, dynamic memory management, and effective resource handling.

## Features

### Dynamic Order Processing

The system utilizes dynamic memory allocation and move semantics to manage order processing efficiently, allowing flexible memory management and improved performance.


### Customer Order Handling
The CustomerOrder class represents and manages customer orders. It stores order details, processes item requests, and checks the status of each order.

class CustomerOrder {
public:
    // Constructor
    CustomerOrder(const std::string& line);

    // Method to fill items in the order
    void fillItem(Station& station, std::ostream& os);

    // Method to check if the order is filled
    bool isOrderFilled() const;

    // Method to check if a specific item in the order is filled
    bool isItemFilled(const std::string& itemName) const;
};

### Line Management
The LineManager class coordinates the movement of orders through the assembly line's workstations. It ensures that orders are processed efficiently and manages the order flow between stations.

class LineManager {
public:
    // Constructor
    LineManager(const std::string& file, const std::vector<Workstation*>& stations);

    // Method to reorder stations based on configuration
    void reorderStations();

    // Method to run the assembly line and process orders
    bool run(std::ostream& os);

    // Method to display the status of stations in the assembly line
    void display(std::ostream& os) const;
};

### Workstation Functionality
The Workstation class represents individual workstations that process orders and update inventory. Each workstation fills items and moves orders to the next station in the assembly line.

class Workstation {
public:
    // Method to fill items at the workstation
    void fill(std::ostream& os);

    // Method to attempt to move an order to the next station
    bool attemptToMoveOrder();

    // Method to set the next station in the assembly line
    void setNextStation(Workstation* station);

    // Method to display the status of the workstation
    void display(std::ostream& os) const;
};

## Example Input Files
- AssemblyLine.txt: Configuration of the assembly line, indicating the order in which stations are connected.
- CustomerOrders.txt: List of customer orders to be processed by the system.
- Stations1.txt and Stations2.txt: Details about the stations involved in the fulfillment process, including item names, serial numbers, quantities, and descriptions.
- Example Output
After running the Order Fulfillment System, the program will display the processed orders, inventory status, and any relevant information about the assembly line operations.

## Dependencies
- C++ compiler
- Input files in CSV and text formats
