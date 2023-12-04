#include "Triangulation.h"

Triangulation::Triangulation(const std::vector<GUI::Point>& points) : points(points) {
    this->points = points;
    sortInCounterclockwise();
}



int Triangulation::indicateTurnDirection(const GUI::Point& a, const GUI::Point& b, const GUI::Point& c) {
    int pivot_l1c1 = a.x() * (b.y() - c.y());
    int pivot_l1c2 = -1 * a.y() * (b.x() - c.x());
    int pivot_l1c3 = b.x() * c.y() - b.y() * c.x();
    int norme = pivot_l1c1 + pivot_l1c2 + pivot_l1c3;
    if (norme < 0) {
        return -1;
    } else if (norme == 0) {
        return 0;
    } else {
        return 1;
    }
}



bool Triangulation::isInsideTriangle(const GUI::Point& a, const GUI::Point& b, const GUI::Point& c, const GUI::Point& d) {
    int relDirection1 = indicateTurnDirection(a, b, d);
    int relDirection2 = indicateTurnDirection(b, c, d);
    int relDirection3 = indicateTurnDirection(c, a, d);
    if ((relDirection1 == 1 && relDirection2 == 1 && relDirection3 == 1) ||
        (relDirection1 == -1 && relDirection2 == -1 && relDirection3 == -1)) {
        return true;
    } else {
        return false;
    }
}


int Triangulation::getMostLeftPointIndex() {
    int index = 0;
    GUI::Point res = points[index];
    for (int i = 1; i < points.size(); i++) {
        if (points[i].x() < res.x() || (points[i].x() == res.x() && points[i].y() < res.y())) {
            res = points[i];
            index = i;
        }
    }
    return index;
}




void Triangulation::sortInCounterclockwise() {

    int i0 = getMostLeftPointIndex();
    GUI::Point p0 = points[i0];

    std::vector<GUI::Point> t1(points.begin(), points.begin() + i0);
    std::vector<GUI::Point> t2(points.begin() + i0 + 1, points.end());
    std::vector<GUI::Point> others = t1;
    others.insert(others.end(), t2.begin(), t2.end());
    std::sort(others.begin(), others.end(), [this, p0](GUI::Point a, GUI::Point b) {
        return indicateTurnDirection(p0, a, b) < 0;
    });

    this->points = {p0};
    this->points.insert(this->points.end(), others.begin(), others.end());
}