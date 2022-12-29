#ifndef CURVED_REGION_H
#define CURVED_REGION_H

#include "geodesic_line.cpp"

#include <cstdlib>
#include <cmath>
#include <fstream>

#include <igl/writeOBJ.h>
#include <igl/cotmatrix.h>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <igl/readOFF.h>


/*! @brief Класс Curved Region
 *
 * Класс реализует вычисление и хранение одного региона.
 */
class CurvedRegion {
public:
    /*!
     * @param start_region вектор из 2 точек, край начала региона
     * @param flat_geodesic вектор из 2 точек, геодезическая кривая на развертке
     * @param flat_left_border вектор из 2 точек, левый край бумаги относительно геодезической кривой на развертке
     * @param flat_right_border вектор из 2 точек, правый край бумаги относительно геодезической кривой на развертке
     * @param start, точка начала геодезической кривой
     * @param main_tangent вектор из 2 точек, задающий касательные к бумаге в начале и конце геодезической кривой
     * @param end_side точка, задающая направление, в котором будет конец геодезической кривой
     * @param dist расстояние на котором будет конец геодезической кривой
     * @note Создает регион бумаги
     */
    CurvedRegion(std::vector<Point>& start_region, std::vector<Point>& flat_geodesic, std::vector<Point>& flat_left_border, std::vector<Point>& flat_right_border,
        Point start, std::vector<Point>& main_tangent, Point end_side, double dist);
    ~CurvedRegion() = default;

    /*!
     * @note Возвращает вектор из трех векторов: геодезическую кривую и соответствующие ее точкам точки на левой и правой границе бумаги
     */
    std::vector<std::vector<Point>> get_curved_region();

private:
    std::vector<Point> geodesic {};
    std::vector<Point> left_border {};
    std::vector<Point> right_border {};

    std::vector<double> get_flat_coeff(Point start);


    std::vector<std::pair<double, double>> get_flat_angles_tan(std::vector<double>& coeff, std::vector<Point>& flat_geodesic, std::vector<Point>& flat_right_border, std::vector<Point>& flat_left_border);


    void calculate_borders(std::vector<Point>& start_region, std::vector<Point>& flat_geodesic, std::vector<Point>& first_left_border, std::vector<Point>& first_right_border, std::vector<double>& coeff, std::vector<std::pair<double, double>> angles);
};


/*! @brief Класс Paper
 *
 * Класс реализует алгоритм работы с 3d mesh представлением бумаги.
 */
class Paper {
public:
    /*!
     * @param file_name имя файла с заданными параметрами бумаги
     * @note Создает регион бумаги
     */
    Paper(std::string file_name);

    /*!
     * @param file_name имя файла, в который сохранится 3d mesh представление бумаги
     * @note Возвращает 3d mesh регион бумаги
     */
    void get_file(std::string& file_name);
private:
    Eigen::MatrixXi V;
    Eigen::MatrixXi F;
};


// int main() {
//     Paper paper = Paper("../use_examples/example2.txt");
//     paper.get_file("example2");
//     return 0;
// }

#endif
