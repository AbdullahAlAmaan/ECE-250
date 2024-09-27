#include "PotentialField.hpp"
#include <iostream>

int main() {
    std::string command;
    int N, M;
    PotentialField* pf = nullptr;

    while (std::cin >> command) {
        if (command == "CREATE") {
            std::cin >> N ;
            std::cin >> M;
            if (pf != nullptr) {
                delete pf;
            }
            pf = new PotentialField(N, M);  
        }
        else if (command == "POINT") {
            char type;
            int x, y;
            std::cin >> type ;
            std::cin >> x;
            std::cin >> y;
            pf->addPoint(type, x, y);
        }
        else if (command == "MOVE") {
            int x, y;
            std::cin >> x;
            std::cin >> y;
            pf->moveRobot(x, y);
        }
        else if (command == "CLEAR") {
            pf->clearMap();
        }
        else if (command == "UPDATE") {
            double K;
            std::cin >> K;
            pf->updateK(K);
        }
        else if (command == "EXIT") {
            break;
        }
    }

    if (pf != nullptr) {
        delete pf;
    }

    return 0;
}
