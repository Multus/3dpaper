#include "mesh.h"


Paper_Mesh::Paper_Mesh(const std::vector<Geodesic_line>& curves, const std::vector<Point>& corners) {
    for (int i = 0; i < curves.size(); ++i) {
        construct_rigeon(curves[i], corners[i]);
    }
    // region_inter_check();
    for (int v = 1; v < flat.size() - 1; ++v) {
        faces.push_back(std::vector<int>{flat[0], flat[v], flat[v+1]});
    }
}

void Paper_Mesh::get_file(std::string file_name) {
    Eigen::MatrixXi V(vertex.size(), 3);

    for (int i = 0; i < vertex.size(); ++i) {
        V(i, 0) = vertex[i].x;
        V(i, 1) = vertex[i].y;
        V(i, 2) = vertex[i].z;
    }

    Eigen::MatrixXi F(faces.size(), 3);

    for (int i = 0; i < faces.size(); ++i) {
        F(i, 0) = faces[i][0];
        F(i, 1) = faces[i][1];
        F(i, 2) = faces[i][2];
    }

    igl::writeOBJ(file_name + ".obj",V,F);
}

Point Paper_Mesh::get_border_point(double dist, const Point& corner, const Point& geo_point, bool is_left) const {
    std::pair<double, double> projection = std::pair<double, double>{geo_point.x, geo_point.y};
    std::pair<double, double> corner_2d = std::pair<double, double>{corner.x, corner.y};

    std::pair<double, double> left_border;
    if ((projection.first - corner_2d.first) * (projection.second - corner_2d.second) > 0) {
        if (is_left) {
            left_border = std::pair<double, double>{corner_2d.first, projection.second};
        } 
        else {
            left_border = std::pair<double, double>{projection.first, corner_2d.second};
        }
    }
    else {
        if (!is_left) {
            left_border = std::pair<double, double>{corner_2d.first, projection.second};
        } 
        else {
            left_border = std::pair<double, double>{projection.first, corner_2d.second};
        }
    }

    Line border = Line(corner_2d, left_border);
    Line curve_proj = Line(corner_2d, projection);


    std::pair<double, double> geo_flat = curve_proj.get_point_on_dist(corner_2d, projection, dist);
    Line perp = curve_proj.perpendicular(geo_flat);
    std::pair<double, double> inter = perp.intersection(border);

    return Point(round((geo_point.x + inter.first - geo_flat.first)*100)/100, round((geo_point.y + inter.second - geo_flat.second)*100)/100, geo_point.z);
}

void Paper_Mesh::construct_rigeon(const Geodesic_line& line, const Point& corner) {
    std::vector<Point> curve = line.get_geodesic_curve();
    
    vertex.push_back(curve[0]);
    if (curve.size() == 1) {
        flat.push_back(vertex.size()-1);
        return;
    }
    int left_point = vertex.size()-1; int right_point = vertex.size()-1;

    double dist = 0;

    int prev_geodesic = 0;

    for (int i = 1; i < curve.size(); ++i) {
        dist += curve[i].get_dist(curve[i-1]);

        vertex.push_back(curve[i]); 
        int now_geodisic = vertex.size()-1;

        faces.push_back(std::vector<int>{now_geodisic, left_point, right_point});

        Point left = get_border_point(dist, corner, vertex[now_geodisic], true);

        vertex.push_back(left);
        int new_left = vertex.size()-1;
        faces.push_back(std::vector<int>{now_geodisic, left_point, new_left});
        left_point = new_left;

        Point right = get_border_point(dist, corner, vertex[now_geodisic], false);

        vertex.push_back(right);
        int new_right = vertex.size()-1;
        faces.push_back(std::vector<int>{now_geodisic, right_point, new_right});
        right_point = new_right;
    }

    flat.push_back(right_point);
    flat.push_back(left_point);
}
