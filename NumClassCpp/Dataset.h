#pragma once

#include <vector>
#include <string>

#include "Matrix.h"

struct Image
{
    Image(const std::string& line, uint16_t imgx, uint16_t imgy);

    void print();

private:
    uint8_t label_;
    Matrix img_;
};

struct Dataset
{
    Dataset(const std::string& path);

    std::vector<Image> load();

private:
    const std::string path_;
};
