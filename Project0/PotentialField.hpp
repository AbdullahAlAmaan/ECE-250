#ifndef POTENTIAL_FIELD_H
#define POTENTIAL_FIELD_H

class Vector2D {
    public:
    double x, y;
    Vector2D() : x(0), y(0) {} // Initialize to (0,0)
};

class PotentialField {
private:  
    int N, M;  // Dimensions of the map
    double K;  // Constant for potential calculation
    Vector2D** map;  // 2D array for potential values

public:
  
    PotentialField(int n, int m);
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

