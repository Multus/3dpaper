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
     * @param vertex угол бумаги в изначальном состоянии 
     * @param begin точка, в которую переходит угол бумаги после изгиба
     * @param end точка, на границе изогнутого и плоского регионов
     * @param theta угол, достаточный для того, чтобы считать бумагу гладкой 
     * @note Рассчитывает точки геодезической кривой
     */
    Geodesic_line(Point vertex, Point begin, Point end, double theta = 175);
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
