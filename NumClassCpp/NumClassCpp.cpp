#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

const int IMG_X = 28;
const int IMG_Y = 28;

struct Image {
    Image(const std::string &line) : label(0xFF), img()
    {
        std::stringstream ss(line);
        std::string val;

        std::getline(ss, val, ',');
        label = atoi(val.c_str());

        // avoid vector resize by reserving the right amount
        img.reserve(IMG_X * IMG_Y);
        while(std::getline(ss, val, ',')) {
            img.push_back(atoi(val.c_str()));
        }
    }

    uint8_t label;
    std::vector<uint8_t> img;
};

void printImage(const Image& image) {
    std::cout << "Label: " << (int)image.label;
    for (int i = 0; i < image.img.size(); ++i) {
        if (i % IMG_X == 0)
            std::cout << std::endl;
        std::cout << std::setw(4) << (int)image.img[i];
    }
    std::cout << std::endl;
}

std::vector<Image> loadDataset(const std::string& path) {
    std::vector<Image> dataset;

    std::ifstream ifs(path);

    std::string line;
    while (std::getline(ifs, line))
        dataset.push_back(Image(line));

    return dataset;
}

int main()
{
    // working dir is out\build\x64-Debug
    std::vector<Image> train_dataset = loadDataset("..\\..\\..\\data\\mnist_train.csv");
    std::vector<Image> test_dataset = loadDataset("..\\..\\..\\data\\mnist_test.csv");

    std::cout << "Dataset size: " << train_dataset.size() << std::endl;

    printImage(train_dataset[0]);
}
