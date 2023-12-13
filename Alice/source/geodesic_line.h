#ifndef GEODESIC_LINE_H
#define GEODESIC_LINE_H

#include <vector>
#include <list>

#include "geometry_classes.cpp"


/*! @brief Класс Geodesic Line
 *
 * Класс реализует геодезическую кривую.
 */
class Geodesic_line {
private:
    struct Node;
public:
    /*!
     * @param begin точка, в которой начинается кривая
     * @param main_tangent вектор из 2 точек, задающий касательные к бумаге в начале и конце геодезической кривой
     * @param end_side точка, задающая направление, в котором будет конец геодезической кривой
     * @param dist расстояние на котором будет конец геодезической кривой
     * @param lenth длина геодезической кривой
     * @param theta угол, при достижении которого считаем бумагу гладкой
     * @note Рассчитывает точки геодезической кривой
     */
    // Geodesic_line(Point vertex, Point begin, Point end, double theta = 175);
    Geodesic_line(Point begin, std::vector<Point>& main_tangent, Point end_side, double dist, double lenth, double theta = 175);
    ~Geodesic_line() = default;

    /*!
     * @note Возвращает геодезическую кривую
     */
    std::vector<Point> get_geodesic_curve() const;
private:
    Point vertex;
    Point begin;
    Point end;
    Point first_inter_point;
    Point second_inter_point;
    double theta;
    std::list<Node> geodesic_curve;

    double lenth;
    std::vector<Point>& main_tangent;


    struct Node;


    void balance_first_inter_point();


    void balance_second_inter_point();


    void balance(Point&& new_end);



    double get_curve_length(const std::list<Node>& curve);


    Point get_bezier_point(double t);


    bool bezier_curve();


    void calculate_curve();


    void get_first_inter_point(double t);


    void get_second_inter_point(double t);


    void calculate_curve_using_end();


    struct Node {
        Point point;
        double bezier_param;

        Node(double bezier_param, const Point& begin, const Point& first_inter_point, const Point& second_inter_point, const Point& end);
        Node(double t, Point point) : bezier_param(t), point(point) {};
        ~Node() = default;

        double get_angle(const Node& prev, const Node& next) const;

        double get_dist(const Node& another) const;
    };
};


#endif
