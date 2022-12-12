#define _USE_MATH_DEFINES

#include <vector>
#include <cstdlib>
#include <cmath>

#include "geometry_classes.h"


Point::Point() {
    Point(0, 0, 0);
};

Point Point::get_mid(const Point& another, double t) const {
    return Point(x + (another.x - x)*t, y + (another.y - y)*t, z + (another.z - z)*t);
}

double Point::get_dist(const Point& another) const {
    return sqrt(pow(x - another.x, 2) + pow(y - another.y, 2) + pow(z - another.z, 2));
}

double Point::get_angle(const Point& first, const Point& second) const {
    double a = first.get_dist(second);
    double b = get_dist(second);
    double c = get_dist(first);
    double cos = (pow(b , 2) + pow(c, 2) - pow(a, 2))/(2 * b * c);
    if (cos > 1) {
        cos = 1;
    }
    else if (cos < -1) {
        cos = -1;
    }
    return acos(cos) * 180 / M_PI;
}


Line::Line(std::pair<double, double> p, std::pair<double, double> q){
    if (fabs(q.second - p.second) < 0.1) {
        a = 0;
        b = 1;
        c = -p.second;
    }
    else if (fabs(q.first - p.first) < 0.1) {
        a = 1;
        b = 0;
        c = -p.first;
    }
    else {
    a = 1;
    b = (p.first - q.first)/(q.second - p.second);
    c = - b * p.second - p.first;
    }
};

std::pair<double, double> Line::intersection(Line another) const {
    double x, y;
    if (a == 0) {
        y = -c/b;
        x = ( - another.c - y * another.b) / another.a;
    }
    else if (another.b * a != another.a * b) {
        y = - (another.c * a - c * another.a)/(another.b * a - another.a * b);
        x = (- c - y * b) / a;
    }
    return std::pair<double, double>(x, y);
};


Line Line::perpendicular(std::pair<double, double> p) const {
    return Line(-b, a, -p.second * a + b * p.first);
};


std::pair<double, double> Line::get_point_on_dist(const std::pair<double, double>& from, const std::pair<double, double>& to, double dist) {
    double t = dist/(sqrt(pow(from.first - to.first, 2) + pow(from.second - to.second, 2)));
    return std::pair<double, double>(from.first + (to.first - from.first)*t, from.second + (to.second - from.second)*t);
};
