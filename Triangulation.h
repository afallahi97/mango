#ifndef TRIANGULATION_H
#define TRIANGULATION_H


#include "Point.h"
#include <vector> 
#include <iostream>


class Triangulation {

public:

    Triangulation() = default;

    Triangulation(const std::vector<GUI::Point>& points);

    ~Triangulation() = default;

    std::vector<GUI::Point> getResult();

    

private:

    // Attributes

    std::vector<GUI::Point> points;

    int ear_tmp = -1;

    std::vector<GUI::Point> triangulationContainer;

    // Methods

    int indicateTurnDirection(const GUI::Point& a, const GUI::Point& b, const GUI::Point& c);

    bool isInsideTriangle(const GUI::Point& a, const GUI::Point& b, const GUI::Point& c, const GUI::Point& d);

    int getMostLeftPointIndex();

    void sortInCounterclockwise();

    int mod(int n, int m);

    bool triangleWasFreeFromOtherVertices(int a, int b, int c, const std::vector<GUI::Point>& poly);

    void findAnEar();

    void findTriangles();

    void runTriangulation();
};


#endif