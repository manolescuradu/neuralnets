#include "Dataset.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

Image::Image(const std::string& line, uint16_t imgx, uint16_t imgy)
    : label_(0xFF), img_(imgx, imgy)
{
    std::stringstream ss(line);
    std::string val;

    std::getline(ss, val, ',');
    label_ = atoi(val.c_str());

    for (int x = 0; x < imgx; ++x) {
        for (int y = 0; y < imgy; ++y) {
            if (std::getline(ss, val, ','))
                img_.at(x, y) = static_cast<float>(atoi(val.c_str()));
            else {
                std::ostringstream oss;
                oss << "Error loading pixel @ " << x << "," << y << "";
                throw std::runtime_error(oss.str());
            }
        }
    }
}

void Image::print()
{
    std::cout << "Label: " << (int)label_;
    img_.print();
}

Dataset::Dataset(const std::string& path)
    : path_(path) {}

std::vector<Image> Dataset::load()
{
    const int IMG_X = 28;
    const int IMG_Y = 28;
    std::vector<Image> dataset;

    std::ifstream ifs(path_);

    std::string line;
    while (std::getline(ifs, line))
        dataset.push_back(Image(line, IMG_X, IMG_Y));

    return dataset;
}
