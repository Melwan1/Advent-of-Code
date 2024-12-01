#include <fstream>
#include <iostream>
#include <vector>
#include <utility>

std::pair<int, int> read_input_line(std::ifstream& file) {
    int first, second;
    if (!(file >> first)) {
        return std::make_pair(-1, -1);
    }
    file >> second;
    return std::make_pair(first, second);
}

int main() {
    std::ifstream file("../input.txt");
    std::vector<int> left_vec;
    std::vector<int> right_vec;
    while (!file.eof()) {
        const std::pair<int, int> pair = read_input_line(file);
        if (pair.first != -1) {
            left_vec.push_back(pair.first);
            right_vec.push_back(pair.second);
        }
    }
    std::sort(left_vec.begin(), left_vec.end());
    std::sort(right_vec.begin(), right_vec.end());
    int total_distance = 0;
    for (unsigned i = 0; i < left_vec.size(); i++) {
        int distance = right_vec[i] - left_vec[i];
        distance = (distance > 0) * distance - (distance < 0) * distance;
        total_distance += distance;
    }
    std::cout << "Total distance is: " << total_distance << '\n';
    file.close();
    return 0;
}
