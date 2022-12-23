#include "../source/mesh.cpp"

int main() {
    Geodesic_line line1 = Geodesic_line(Point(0, 0, 0), Point(200, 200, 200), Point(200, 200, 0));
    Geodesic_line line2 = Geodesic_line(Point(0, 1000, 0), Point(200, 800, 200), Point(300, 700, 0));
    Geodesic_line line3 = Geodesic_line(Point(1000, 1000, 0), Point(800, 800, 100), Point(800, 800, 0));
    Geodesic_line line4 = Geodesic_line(Point(1000, 0, 0), Point(800, 200, 300), Point(700, 300, 0));

    std::vector<Geodesic_line> curves = std::vector<Geodesic_line>{line1, line2, line3, line4};
    std::vector<Point> corners = std::vector<Point>{Point(0, 0, 0), Point(0, 1000, 0), Point(1000, 1000, 0), Point(1000, 0, 0)};
    Paper_Mesh mesh = Paper_Mesh(curves, corners);
    mesh.get_file("different_parameter_example");
    return 0;
}
