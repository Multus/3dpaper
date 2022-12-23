/*!
 * @mainpage Моделирование изгибов бумаги
 * 
 * @section intro_sec Продукт
 *
 * Библиотека, с помощью которой возможно получить 3d mesh файл, содержащий представление изогнутой бумаги. 
 * 
 * @section install_sec Пример использования
 * 
 * @code
 * Geodesic_line line1 = Geodesic_line(Point(0, 0, 0), Point(200, 200, 200), Point(200, 200, 0));
 * Geodesic_line line2 = Geodesic_line(Point(0, 1000, 0), Point(200, 800, 200), Point(300, 700, 0));
 * Geodesic_line line3 = Geodesic_line(Point(1000, 1000, 0), Point(800, 800, 100), Point(800, 800, 0));
 * Geodesic_line line4 = Geodesic_line(Point(1000, 0, 0), Point(800, 200, 300), Point(700, 300, 0));

 * std::vector<Geodesic_line> curves = std::vector<Geodesic_line>{line1, line2, line3, line4};
 * std::vector<Point> corners = std::vector<Point>{Point(0, 0, 0), Point(0, 1000, 0), Point(1000, 1000, 0), Point(1000, 0, 0)};
 * Paper_Mesh mesh = Paper_Mesh(curves, corners);
 * mesh.get_file("different_parameter_example");
 * return 0;
 * @endcode
 * 
 * @section classes_sec Основной класс
 * 
 * @ref Paper_Mesh
 * 
 * <a href="https://github.com/alicepozd/crumpled_paper"> ссылка на отчет </a>
 */


#ifndef MESH_H
#define MESH_H


#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <cmath>

#include <igl/writeOBJ.h>
#include <igl/cotmatrix.h>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <igl/readOFF.h>

#include "geodesic_line.cpp"


/*! @brief Класс Paper Mesh
 *
 * Класс реализует алгоритм работы с 3d mesh представлением бумаги.
 */
class Paper_Mesh {
public:
    /*!
     * @param curves вектор геодезических кривых
     * @param corners вектор соответствующих углов бумаги
     * @note Кривые передаются ввиде класса Geodesic_line, углы ввиде структуры Point
     */
    Paper_Mesh(const std::vector<Geodesic_line>& curves, const std::vector<Point>& corners);
    ~Paper_Mesh() = default;

    /*!
     * @param file_name строка
     * @note Создает файл .obj с представлением бумаги
     */
    void get_file(std::string file_name);
private:
    std::vector<int> flat;
    std::vector<Point> vertex;
    std::vector<std::vector<int>> faces;

    Point get_border_point(double dist, const Point& corner, const Point& geo_point, bool is_left) const;

    void construct_rigeon(const Geodesic_line& line, const Point& corner);
};


#endif
