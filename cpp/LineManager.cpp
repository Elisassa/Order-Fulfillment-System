// Name:Rong Chen
// Seneca Student ID:132356221
// Seneca email:rchen104@myseneca.ca
// Date of completion:3/15
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include <fstream> 
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Utilities.h"
#include "LineManager.h"

using namespace std;
namespace seneca {
    
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {

        ifstream fin(file);
        string line;

        if (!fin.is_open()) {
            throw "File failed to open";
        }
        else {
            while (getline(fin, line)) {
                istringstream iss(line);
                string station, nextStation;

                getline(iss, station, '|');
                getline(iss, nextStation);

                //set current station
                auto currentstation = find_if(stations.cbegin(), stations.cend(),
                    [&station](const Workstation* ws) {
                        return ws->getItemName() == station;
                    });//find_if return iterator's address!! so nedd to defferencre to get address

                m_activeLine.push_back(*currentstation);//* to derrfernce iterator

                //set next station
                if (!nextStation.empty()) {//last one don't have next station
                    auto nextstation = find_if(stations.cbegin(), stations.cend(),
                        [&nextStation](const Workstation* workstation) {
                            return workstation->getItemName() == nextStation;
                        });
                    (*currentstation)->setNextStation(*nextstation);
                }
            }
        }

        //find first station that no one define as next station
        Workstation* firstStation = nullptr;

        std::for_each(m_activeLine.begin(), m_activeLine.end(),
            [this, &firstStation](Workstation* ws) {
                if (!firstStation && none_of(this->m_activeLine.begin(), this->m_activeLine.end(),//because m_activeLine is private data member we can't directly access use "this"
                [ws](Workstation* innerWs) { return innerWs->getNextStation() == ws; })) {
                    firstStation = ws;
                }
            });

       
        if (firstStation) {
            m_firstStation = firstStation;
        }
        else {
            throw runtime_error("There is no First station !"); 
        }

        m_cntCustomerOrder = g_pending.size();
    }


	void LineManager::reorderStations()
	{
		vector<Workstation*> sortWs;

		Workstation* current = m_firstStation;
		while (current){
			sortWs.push_back(current);
			current = current->getNextStation();
		}

		m_activeLine = move(sortWs);

	}

	bool LineManager::run(std::ostream& os) {
		static size_t num = 0;
		num++;
		os << "Line Manager Iteration: " << num << std::endl;

		if (!g_pending.empty()) {
			*m_firstStation += move(g_pending.front());
			g_pending.pop_front();
		}

		for (auto& station : m_activeLine) {
			station->fill(os);//executes one fill operation
		}

		for (auto& station : m_activeLine) {
			station->attemptToMoveOrder();// attempts to move an order down the line
		}

		return g_completed.size() + g_incomplete.size() == m_cntCustomerOrder;
	}

	void LineManager::display(std::ostream& os) const{

		for (size_t i = 0; i < m_activeLine.size(); i++){
			m_activeLine[i]->display(os);
		}
	}
}