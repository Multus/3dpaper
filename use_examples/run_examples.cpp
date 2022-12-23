#include "../source/curved_region.cpp"

int main() {
    Paper paper = Paper("../use_examples/example1.txt");
    paper.get_file("example1");

    paper = Paper("../use_examples/example2.txt");
    paper.get_file("example2");

    paper = Paper("../use_examples/example3.txt");
    paper.get_file("example3");
    return 0;
}
