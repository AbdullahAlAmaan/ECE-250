#include "PotentialField.hpp"
#include <iostream>
#include <cmath>

// Constructor: Initializes the map and sets all potential values to (0, 0)
PotentialField::PotentialField(int n, int m) : N(n), M(m), K(1.0) {
   createMap(n,m);
}

PotentialField::~PotentialField() {
    for (int i = 0; i < N; i++) {
        delete[] map[i];
        
    }
    // Deallocate the array of row pointers
    delete[] map;
    map=nullptr;
}

void PotentialField::createMap(int n, int m)  {
    // Previous map deletion
    if (map != nullptr) {
        for (int i = 0; i < N; i++) {
            delete[] map[i];
        }
        delete[] map;
        map = nullptr;
    }

    N = n;
    M = m;

    // Allocate new memory for the map
    map = new Vector2D*[N];
    for (int i = 0; i < N; i++) {
        map[i] = new Vector2D[M];
        for (int j = 0; j < M; j++) {
            map[i][j].x = 0.0;
            map[i][j].y = 0.0;
        }
    }

    std::cout << "success" << std::endl;  
}



void PotentialField::addPoint(char type, int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < M) {
        double factor = (type == 'G') ? -1.0 : 1.0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                double distance = sqrt(pow(i - x, 2) + pow(j - y, 2));
                if (distance != 0) {
                    map[i][j].x += factor * K / distance;
                    map[i][j].y += factor * K / distance;
                }
            }
        }
        std::cout << "success" << std::endl;
    } else {
        std::cout << "failure" << std::endl;
    }
}

void PotentialField::clearMap() {
    if (map!=nullptr) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                map[i][j].x = 0.0;
                map[i][j].y = 0.0;
            }
        }
        std::cout << "success" << std::endl;
    } else {
        std::cout << "failure" << std::endl;
    }
}

void PotentialField::updateK(double newK) {
    if (newK > 0) {
        K = newK;
        std::cout << "success" << std::endl;
    } else {
        std::cout << "failure" << std::endl;
    }
}

void PotentialField::moveRobot(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < M) {
        std::cout << map[x][y].x << " " << map[x][y].y << std::endl;
    } else {
        std::cout << "failure" << std::endl;
    }
}
