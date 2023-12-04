#include "Point.h"
#include <vector> 
#include <iostream>


class Triangulation {

public:

    Triangulation() = default;

    Triangulation(const std::vector<GUI::Point>& points);

    ~Triangulation() = default;

    

private:

    std::vector<GUI::Point> points;

    int indicateTurnDirection(const GUI::Point& a, const GUI::Point& b, const GUI::Point& c);

    bool isInsideTriangle(const GUI::Point& a, const GUI::Point& b, const GUI::Point& c, const GUI::Point& d);

    int getMostLeftPointIndex();

    void sortInCounterclockwise();
};
