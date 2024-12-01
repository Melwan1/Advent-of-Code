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

int calculate_similarity_score(const std::vector<int>& left, const std::vector<int>& right) {
    int similarity_score = 0;
    for (int left_element : left) {
        for (int right_element : right) {
            if (left_element == right_element) {
                similarity_score += left_element;
            }
        }
    }
    return similarity_score;
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
    std::cout << "Similarity score is: " << calculate_similarity_score(left_vec, right_vec) << '\n';
    file.close();
    return 0;
}
