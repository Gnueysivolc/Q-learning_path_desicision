#include <iostream>
#include <random>
#include "random.hpp"
int random_number() {
    // Create a random number generator engine
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define the range for the random number
    std::uniform_int_distribution<int> distribution(0, 9);

    // Generate a random number
    int randomNum = distribution(gen);

    // Print the random number
   //  std::cout << "Random number: " << randomNum << std::endl;

    return randomNum;
}