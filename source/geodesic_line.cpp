#include <vector>
#include <list>
#include <iostream>

#include "geodesic_line.h"


//Geodesic_line::Geodesic_line(Point begin, std::vector<Point>& main_tangent, Point end_side, double dist, double lenth, double theta) : lenth(lenth), begin(begin), main_tangent(main_tangent), theta(theta) {
//    end = begin + end_side * dist;
//    calculate_curve_using_end();
//}
//
//
//std::vector<Point> Geodesic_line::get_geodesic_curve() const {
//    std::vector<Point> curve = std::vector<Point>();
//    for (const Node& node : geodesic_curve) {
//        curve.push_back(node.point);
//    }
//    return curve;
//}
//
//
//double Geodesic_line::get_curve_length(const std::list<Node>& curve) {
//    double len = 0;
//    auto it_prev = curve.cbegin();
//    for (auto it = curve.begin(); it != curve.end(); ++it) {
//        if (it == curve.begin()){
//            ++it;
//        }
//        len += (*it_prev).get_dist(*it);
//        ++it_prev;
//    }
//    return len;
//};
//
//
//Point Geodesic_line::get_bezier_point(double t) {
//    Point iter1_point1 = begin.get_mid(first_inter_point, t);
//    Point iter1_point2 = first_inter_point.get_mid(second_inter_point, t);
//    Point iter1_point3 = second_inter_point.get_mid(end, t);
//
//    Point iter2_point1 = iter1_point1.get_mid(iter1_point2, t);
//    Point iter2_point2 = iter1_point2.get_mid(iter1_point3, t);
//    return iter2_point1.get_mid(iter2_point2, t);
//};
//
//
//bool Geodesic_line::bezier_curve() {
//    geodesic_curve.empty();
//    geodesic_curve = std::list<Node>{Node(0, begin, end, first_inter_point, second_inter_point), 
//        Node(0.3, begin, first_inter_point, second_inter_point, end), 
//        Node(0.6,  begin, first_inter_point, second_inter_point, end), 
//        Node(1, begin, first_inter_point, second_inter_point, end)};
//
//
//    bool stop_flg = false;
//    while (!stop_flg) {
//        stop_flg = true;
//        auto it_prev = geodesic_curve.cbegin();
//        auto it_base = geodesic_curve.cbegin();
//        for (auto it_next = geodesic_curve.cbegin(); it_next != geodesic_curve.cend(); ++it_next) {
//            if (it_next == geodesic_curve.cbegin()) {
//                ++it_next; ++it_next; ++it_base;
//            }
//
//
//            if ((*it_base).get_angle(*it_prev, *it_next) < theta) {
//                stop_flg = false;
//                geodesic_curve.emplace(it_base, ((*it_prev).bezier_param + (*it_base).bezier_param)/2, begin, first_inter_point, second_inter_point, end);
//                geodesic_curve.emplace(it_next, ((*it_base).bezier_param + (*it_next).bezier_param)/2, begin, first_inter_point, second_inter_point, end);
//                ++it_base; ++it_base; ++it_prev; ++it_prev; ++it_prev;
//                continue;
//            }
//            ++it_prev, ++it_base;
//        }
//    }
//
//    if (get_curve_length(geodesic_curve) - lenth < 0) {
//        return true;
//    }
//    else {
//        return false;
//    };
//};
//
//
//void Geodesic_line::get_first_inter_point(double t) {
//    Point base_point = begin + main_tangent[0] * lenth;
//    first_inter_point = begin.get_mid(base_point, t);
//}
//
//
//void Geodesic_line::get_second_inter_point(double t) {
//    Point base_point = end + main_tangent[1] * lenth;
//    second_inter_point = end.get_mid(base_point, t);
//}
//
//
//void Geodesic_line::calculate_curve_using_end() {
//    for (double t = 1; t > 0; t -= 0.1) {
//        get_first_inter_point(t);
//        get_second_inter_point(t);
//
//        if (bezier_curve()) {
//            break;
//        }
//    }
//}
//
//
//Geodesic_line::Node::Node(double bezier_param, const Point& begin, const Point& first_inter_point, const Point& second_inter_point, const Point& end) : bezier_param(bezier_param) {
//    Point iter1_point1 = begin.get_mid(first_inter_point, bezier_param);
//    Point iter1_point2 = first_inter_point.get_mid(second_inter_point, bezier_param);
//    Point iter1_point3 = second_inter_point.get_mid(end, bezier_param);
//
//    Point iter2_point1 = iter1_point1.get_mid(iter1_point2, bezier_param);
//    Point iter2_point2 = iter1_point2.get_mid(iter1_point3, bezier_param);
//    point = iter2_point1.get_mid(iter2_point2, bezier_param);  
//};
//
//double Geodesic_line::Node::get_angle(const Node& prev, const Node& next) const {
//    return point.get_angle(prev.point, next.point);
//};
//
//double Geodesic_line::Node::get_dist(const Node& another) const {
//    return point.get_dist(another.point);
//};
