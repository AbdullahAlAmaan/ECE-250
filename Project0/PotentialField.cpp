#include "PotentialField.hpp"
#include <iostream>
#include <cmath>

PotentialField::PotentialField(int n, int m) : N(n), M(m), K(1.0) {
    map = new std::pair<double, double>*[N];
    for (int i = 0; i < N; i++) {
        map[i] = new std::pair<double, double>[M];
        for (int j = 0; j < M; j++) {
            map[i][j] = {0.0, 0.0}; // Initializing the potential vector to (0, 0)
        }
    }
}

PotentialField::~PotentialField() {
    for (int i = 0; i < N; i++) {
        delete[] map[i];
    }
    delete[] map;
}

void PotentialField::createMap(int n, int m) {
    // Clear previous map
    for (int i = 0; i < N; i++) {
        delete[] map[i];
    }
    delete[] map;

    // Assign new dimensions
    N = n;
    M = m;

    // Create new map
    map = new std::pair<double, double>*[N];
    for (int i = 0; i < N; i++) {
        map[i] = new std::pair<double, double>[M];
        for (int j = 0; j < M; j++) {
            map[i][j] = {0.0, 0.0};
        }
    }

    std::cout << "success" << std::endl;
}

void PotentialField::addPoint(char type, int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < M) {
        // Compute new potential based on goal or obstacle
        double factor = (type == 'G') ? -1.0 : 1.0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                double distance = sqrt(pow(i - x, 2) + pow(j - y, 2));
                if (distance != 0) {
                    map[i][j].first += factor * K / distance;
                    map[i][j].second += factor * K / distance;
                }
            }
        }
        std::cout << "success" << std::endl;
    } else {
        std::cout << "failure" << std::endl;
    }
}

void PotentialField::clearMap() {
    if (map) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                map[i][j] = {0.0, 0.0};
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
        std::cout << map[x][y].first << " " << map[x][y].second << std::endl;
    } else {
        std::cout << "failure" << std::endl;
    }
}
