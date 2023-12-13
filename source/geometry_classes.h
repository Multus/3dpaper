#ifndef GEOMETRY_H
#define GEOMETRY_H

#define _USE_MATH_DEFINES

#include <vector>
#include <cstdlib>
#include <cmath>

///*! @brief Структура точка
// *
// * Класс реализует точку.
// */
//struct Point {
//    /*!
//     * @param x - координата по оси х
//     * @param y - координата по оси у
//     * @param z - координата по оси z 
//     * @note Создает точку по координатам
//     */
//    Point(double x, double y, double z): x(x), y(y), z(z) {};
//
//    /*!
//     * @param another - другая точка
//     * @note Создает точку по другой точке
//     */
//    Point(const Point& another): x(another.x), y(another.y), z(another.z) {};
//
//    /*!
//     * @note Дефолтное значение точки
//     */
//    Point();
//
//    /*!
//     * @note Деструктор
//     */
//    ~Point() = default;
//
//    /*!
//     * @param another - другая точка
//     * @note Оператор +
//     */
//    Point operator+(Point another) {
//        return Point(x+another.x, y + another.y, z + another.z);
//    }
//
//    /*!
//     * @param another - другая точка
//     * @note Оператор -
//     */
//    Point operator-(Point another) {
//        return Point(x-another.x, y - another.y, z - another.z);
//    }
//
//    /*!
//     * @param coeff - коеффициент умножения
//     * @note Оператор *
//     */
//    Point operator*(double coeff) {
//        return Point(x * coeff, y * coeff, z * coeff);
//    }
//
//    /*!
//     * @param another - точка другого конца отрезка
//     * @param t - отношение в котором делится отрезок
//     * @note Функция, возвращающая точку, делящую отрезок в отношении t
//     */
//    Point get_mid(const Point& another, double t = 0.5) const;
//
//    /*!
//     * @param another - другая точка
//     * @note Функция, находящая расстояние между точками
//     */
//    double get_dist(const Point& another) const;
//
//    /*!
//     * @param first - другая точка
//     * @param second - другая точка
//     * @note Функция, находящая угол, между лучами, проходящими через переданные точки
//     */
//    double get_angle(const Point& first, const Point& second) const;
//
//    /*!
//     * координата по оси х
//     */
//    double x;
//    /*!
//     * координата по оси у
//     */
//    double y;
//    /*!
//     * координата по оси z
//     */
//    double z;
//};
//
//
///*! @brief Структура прямой
// *
// * Класс реализует прямую
// */
//struct Line {
//    /*!
//     * @param p - первая точка
//     * @param q - вторая точка
//     * @note Создает прямую, проходящую через 2 переданные точки
//     */
//    Line(std::pair<double, double> p, std::pair<double, double> q);
//
//    /*!
//     * @param a - коэффициент при х
//     * @param b - коэффициент при у
//     * @param c - свободный член
//     * @note Создает прямую, с заданными параметрами
//     */
//    Line(double a, double b, double c) : a(a), b(b), c(c) {};
//
//    /*!
//     * @param another - другая прямая
//     * @note Находит пересечение
//     */
//    std::pair<double, double> intersection(Line another) const;
//
//    /*!
//     * @param p - точка
//     * @note Находит перпендикуляр к прямой, проходящей через заданную точку
//     */
//    Line perpendicular(std::pair<double, double> p) const;
//
//    /*!
//     * @param from - точка начала отсчета
//     * @param to - точка к которой направлен вектор
//     * @param dist - расстояние
//     * @note Находит точку по заданному направлению на заданном расстоянии
//     */
//    std::pair<double, double> get_point_on_dist(const std::pair<double, double>& from, 
//        const std::pair<double, double>& to, double dist);
//
//
//    /*!
//     * кооффициент при х
//     */
//    double a;
//    /*!
//     * кооффициент при у
//     */
//    double b;
//    /*!
//     * свободный член
//     */
//    double c;
//};

#endif
