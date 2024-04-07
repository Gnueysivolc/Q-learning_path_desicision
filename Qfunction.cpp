#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <random>
#include "random.hpp"
#include "render.hpp"
#include "Qfunction.hpp"
void initial_Qtable(double (&state_action)[2][2][2][2][4]) {
    std::ifstream inputfile("Qtable.txt");
    if (!inputfile) {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }
if(!(inputfile.peek() == std::ifstream::traits_type::eof()){
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    for (int m = 0; m < 4; m++) {
                        // Read each element from the file
                        inputFile >> state_action[i][j][k][l][m];
                    }
                }
            }
        }
    }
}
    inputfile.close();
}


double get_best_action(state){
    int up, down, left, right;
    std::string a,b,c,d;
    a=state[0];
    b=state[1];
    c=state[2];
    d=state[3];
    
}
