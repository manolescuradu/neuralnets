#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Dataset.h"

int main()
{
    // with MSVS, working dir is out\build\x64-Debug
    Dataset ds_train("..\\..\\..\\data\\mnist_train.csv");
    Dataset ds_test("..\\..\\..\\data\\mnist_test.csv");

    std::vector<Image> train_dataset = ds_train.load();
    std::vector<Image> test_dataset = ds_test.load();

    std::cout << "Dataset size: " << train_dataset.size() << std::endl;

    srand(time(NULL));
    train_dataset[rand() % train_dataset.size()].print();
}
