#ifndef POTENTIAL_FIELD_H
#define POTENTIAL_FIELD_H

#include <utility>

class PotentialField {
private:
    int N, M; // Dimensions of the map
    double K; // Constant for potential calculation
    std::pair<double, double>** map; // 2D array for potential values

public:
    // Constructor: Initialize the map with N x M grid and set all potentials to (0, 0)
    PotentialField(int n, int m);

    // Destructor: Deallocate the dynamically allocated memory
    ~PotentialField();

    // Create a new map with different dimensions
    void createMap(int n, int m);

    // Add a goal ('G') or obstacle ('O') at position (x, y)
    void addPoint(char type, int x, int y);

    // Clear the map of all goals and obstacles
    void clearMap();

    // Update the constant K
    void updateK(double newK);

    // Get the direction for the robot to move at position (x, y)
    void moveRobot(int x, int y);
};

#endif
