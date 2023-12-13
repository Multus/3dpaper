#include "curved_region.h"


//CurvedRegion::CurvedRegion(std::vector<Point>& start_region, std::vector<Point>& flat_geodesic, std::vector<Point>& flat_left_border, std::vector<Point>& flat_right_border,
//    Point start, std::vector<Point>& main_tangent, Point end_side, double dist) {
//    double lenth = flat_geodesic[0].get_dist(flat_geodesic[1]);
//    Geodesic_line geodesic_line = Geodesic_line(start, main_tangent, end_side, dist, lenth);
//    geodesic = geodesic_line.get_geodesic_curve();
//
//    std::vector<double> coeff = get_flat_coeff(flat_geodesic[0]);
//    std::vector<std::pair<double, double>> angles = get_flat_angles_tan(coeff, flat_geodesic, flat_right_border, flat_left_border);
//    calculate_borders(start_region, flat_geodesic, flat_left_border, flat_right_border, coeff, angles); 
//}
//
//
//std::vector<std::vector<Point>> CurvedRegion::get_curved_region() {
//
//    std::vector<Point> vertex {};
//    vertex.insert(vertex.end(), geodesic.begin(), geodesic.end());
//    vertex.insert(vertex.end(), left_border.begin(), left_border.end());
//    vertex.insert(vertex.end(), right_border.begin(), right_border.end());
//
//    std::vector<std::vector<int>> faces {};
//    int lb_start = geodesic.size();
//    int rb_start = geodesic.size() * 2;
//
//
//    for (int i = 0; i < geodesic.size() - 1; ++i) {
//        std::vector<int> face = {i, rb_start + i + 1, i + 1};
//        faces.emplace_back(face);
//        face = {i, i + 1, lb_start + i + 1};
//        faces.emplace_back(face);
//        face = {i, rb_start + i, rb_start + i + 1};
//        faces.emplace_back(face);
//        face = {i, lb_start + i, lb_start + i + 1};
//        faces.emplace_back(face);
//    }
//    std::pair<std::vector<Point>, std::vector<std::vector<int>>> ret {vertex, faces};
//
//    return std::vector<std::vector<Point>> {geodesic, left_border, right_border};
//}
//
//
//std::vector<double> CurvedRegion::get_flat_coeff(Point start) {
//    std::vector<double> coeff {0};
//    double sum = 0;
//    Point prev = Point();
//    bool first = true;
//    for (Point p : geodesic) {
//        if (first) {
//            prev = p;
//            first = false;
//            continue;
//        }
//        double dist = p.get_dist(prev);
//        coeff.push_back(coeff[coeff.size() - 1] + dist);
//        sum += dist;
//        prev = p;
//    }
//    for (int i = 0; i < coeff.size(); ++i) {
//        coeff[i] /= sum;
//    }
//    return coeff;
//}
//
//
//std::vector<std::pair<double, double>> CurvedRegion::get_flat_angles_tan(std::vector<double>& coeff, std::vector<Point>& flat_geodesic, std::vector<Point>& flat_right_border, std::vector<Point>& flat_left_border) {
//    std::vector<std::pair<double, double>> angles {(0, 0)};
//    Point prev_r_border = Point(0, 0, 0);
//    Point prev_l_border = Point(0, 0, 0);
//    Point prev_geo = Point(0, 0, 0);
//    for (int i = 1; i < coeff.size(); ++i) {
//        Point geo = flat_geodesic[0].get_mid(flat_geodesic[1], coeff[i]);
//        Point r_border = flat_right_border[0].get_mid(flat_right_border[1], coeff[i]);
//        Point l_border = flat_left_border[0].get_mid(flat_left_border[1], coeff[i]);
//        angles.emplace_back(std::pair<double, double>(r_border.get_dist(prev_r_border)/geo.get_dist(prev_geo), l_border.get_dist(prev_l_border)/geo.get_dist(prev_geo)));
//        prev_r_border = r_border;
//        prev_l_border = l_border;
//        prev_geo = geo;
//    }
//    return angles;
//}
//
//
//
//void CurvedRegion::calculate_borders(std::vector<Point>& start_region, std::vector<Point>& flat_geodesic, std::vector<Point>& first_left_border, std::vector<Point>& first_right_border, std::vector<double>& coeff, std::vector<std::pair<double, double>> angles) {
//    left_border = {start_region[0]};
//    right_border = {start_region[1]};
//
//    Point prev_r_border = start_region[1];
//    Point prev_l_border = start_region[0];
//
//    for (int i = 1; i < geodesic.size(); ++i) {
//        Point vector_right = (geodesic[i] - geodesic[i - 1]) * angles[1].first;
//        Point vector_left = (geodesic[i] - geodesic[i - 1]) * angles[1].second;
//
//        right_border.emplace_back(Point(right_border[right_border.size() - 1].x + vector_right.x, right_border[right_border.size() - 1].y + vector_right.y, right_border[right_border.size() - 1].z + vector_right.z));
//        left_border.emplace_back(Point(left_border[left_border.size() - 1].x + vector_left.x, left_border[left_border.size() - 1].y + vector_left.y, left_border[left_border.size() - 1].z + vector_left.z));
//
//        Point prev_r_border = prev_r_border + vector_right;
//        Point prev_l_border = prev_l_border + vector_left;
//    }
//}
//
//
//Paper::Paper(std::string file_name) {
//    std::vector<Point> geodesic {};
//    std::vector<Point> left_border {};
//    std::vector<Point> right_border {};
//
//    std::ifstream file;
//    file.open(file_name);
//
//    int width; int height;
//    file >> width >> height;
//
//    std::vector<Point> start_region {Point(-width, 0, 0), Point(width, 0, 0)};
//    std::vector<Point> flat_geodesic {Point(0, 0, 0), Point(0, 0, 0)};
//    std::vector<Point> flat_left_border {Point(-width, 0, 0), Point(0, 0, 0)};
//    std::vector<Point> flat_right_border {Point(width, 0, 0), Point(0, 0, 0)};
//    Point start = Point(0, 0, 0);
//    std::vector<Point> main_tangent {Point(0, 1, 0), Point(0, 0, 0)};
//    Point end_side = Point(0, 0, 0);
//    double dist = 0;
//
//
//    while(!file.eof()) {
//        std::string s;
//
//        bool is_flat;
//        file >> is_flat >> s;
//
//        if (file.eof()) {
//            break;
//        }
//
//        file >> flat_left_border[1].x >> flat_left_border[1].y >> flat_left_border[1].z >> s;
//        file >> flat_geodesic[1].x >> flat_geodesic[1].y >> flat_geodesic[1].z >> s;
//        file >> flat_right_border[1].x >> flat_right_border[1].y >> flat_right_border[1].z >> s;
//
//        if (!is_flat) {
//            file >> main_tangent[1].x >> main_tangent[1].y >> main_tangent[1].z >> s;
//            file >> end_side.x >> end_side.y >> end_side.z >> s;
//            file >> dist;
//        } else {
//            continue;
//        }
//
//        CurvedRegion region = CurvedRegion(start_region, flat_geodesic, flat_left_border, flat_right_border,
//                start, main_tangent, end_side, dist);
//        std::vector<std::vector<Point>> ret = region.get_curved_region();
//
//        geodesic.insert(geodesic.end(), ret[0].begin(), ret[0].end());
//        left_border.insert(left_border.end(), ret[1].begin(), ret[1].end());
//        right_border.insert(right_border.end(), ret[2].begin(), ret[2].end());
//
//        start = ret[0][ret[0].size() - 1];
//        start_region = std::vector<Point>{ret[1][ret[1].size() - 1], ret[2][ret[2].size() - 1]};
//        flat_geodesic = std::vector<Point>{flat_geodesic[1], Point(0, 0, 0)};
//        flat_left_border = std::vector<Point>{flat_left_border[1], Point(0, 0, 0)};
//        flat_right_border = std::vector<Point>{flat_right_border[1], Point(0, 0, 0)};
//        main_tangent = std::vector<Point>{main_tangent[1] * -1, Point(0, 0, 0)};
//    }
//
//    std::vector<Point> vertex {};
//    vertex.insert(vertex.end(), geodesic.begin(), geodesic.end());
//    vertex.insert(vertex.end(), left_border.begin(), left_border.end());
//    vertex.insert(vertex.end(), right_border.begin(), right_border.end());
//
//    std::vector<std::vector<int>> faces {};
//    int lb_start = geodesic.size();
//    int rb_start = geodesic.size() * 2;
//
//    for (int i = 0; i < geodesic.size() - 1; ++i) {
//        std::vector<int> face = {i, lb_start + i, lb_start + i + 1};
//        faces.emplace_back(face);
//        face = {i, rb_start + i, rb_start + i + 1};
//        faces.emplace_back(face);
//        face = {i, i + 1, lb_start + i + 1};
//        faces.emplace_back(face);
//        face = {i, rb_start + i + 1, i + 1};
//        faces.emplace_back(face);
//    }
//
//    V = Eigen::MatrixXi(vertex.size(), 3);
//
//    for (int i = 0; i < vertex.size(); ++i) {
//        V(i, 0) = std::round(vertex[i].x);
//        V(i, 1) = std::round(vertex[i].y);
//        V(i, 2) = std::round(vertex[i].z);
//    }
//
//    std::cout << "\n";
//
//    F = Eigen::MatrixXi(faces.size(), 3);
//
//    for (int i = 0; i < faces.size(); ++i) {
//        F(i, 0) = faces[i][0];
//        F(i, 1) = faces[i][1];
//        F(i, 2) = faces[i][2];
//    }
//}
//
//void Paper::get_file(std::string file_name) {
//    igl::writeOBJ(file_name + ".obj",V,F);
//}
