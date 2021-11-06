#pragma once
#include"../include/algebra.hpp"
#include"../include/functions.hpp"
#include"../include/System.hpp"

int main()
{
    int steps;
    double dimension[2] = {15, 15};
    System sistema = System(dimension, 3, 3, 0.1, 1);
    sistema.list();

    return 0;
}