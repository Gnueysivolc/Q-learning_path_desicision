#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include "random.hpp"
#include "render.hpp"
#include "Qfunction.hpp"
#include "movement.hpp"

        double state_action[2][2][2][2][4] = {};
 int state[4] = {};
int action = 0;
double learning_rate = 0.7;
double reward ;



void initial_Qtable() { // up, down, left, right, action
    std::ifstream inputfile("Qtable.txt");  // open Qtable file
    if (!inputfile) {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }
if(!(inputfile.peek() == std::ifstream::traits_type::eof())){   //input the Qtable from the file last time stored
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    for (int m = 0; m < 4; m++) {
                        // Read each element from the file
                        inputfile >> state_action[i][j][k][l][m];
                    }
                }
            }
        }
    }
}
    inputfile.close();
}



int* get_state(int characterX, int characterY) {
    static int state[4];
    if(grid[characterX][characterY-1].getFillColor()== sf::Color::White){
        state[0] = -1;
    } else {
        state[0] = 1;
    }
    if(grid[characterX][characterY+1].getFillColor()== sf::Color::White){
        state[1] = -1;
    } else {
        state[1] = 1;
    }
    if(grid[characterX-1][characterY].getFillColor()== sf::Color::White){
        state[2] = -1;
    } else {
        state[2] = 1;
    }
    if(grid[characterX+1][characterY].getFillColor()== sf::Color::White){
        state[3] = -1;
    } else {
        state[3] = 1;
    }
    return state;
}


double get_Qvalue(int characterX, int characterY, int action,int index){  //make a reecursive function to get and find the reward in three steps to calculate the Qvalue
                           //index=0, stop recursive
   if(index == 0){        
    return 0;
   }
      index--;

   int discount_value = 0.6+index/10; // index=1, discount_value=0.7, index=2, discount_value=0.8, index=3, discount_value=0.9
    int a,b,c,d;
    int* state = get_state(characterX, characterY);
    a=state[0];
    b=state[1];
    c=state[2];
    d=state[3];
    double reward = state_action[a][b][c][d][action];
     
    double next_reward = discount_value * std::max(get_Qvalue( characterX,  characterY-1,  action, index),std::max(get_Qvalue( characterX-1,  characterY,  action, index),std::max(0.01+ get_Qvalue( characterX+1,  characterY,  action, index), 0.01+ get_Qvalue( characterX,  characterY+1,  action, index))));
                       //get_Qvalue( characterX+1,  characterY,  action, index)
                       //get_Qvalue( characterX,  characterY+1,  action, index)
                       //get_Qvalue( characterX-1,  characterY,  action, index)
                       //get_Qvalue( characterX,  characterY-1,  action, index)   
                                
// 0.01 = instant reward for moving near destination

 reward = reward + learning_rate * (next_reward-reward);

state_action[a][b][c][d][action] = reward;

return reward;

}





int get_best_action(int characterX, int characterY){
    int a, b, c, d;
       a = get_Qvalue(characterX, characterY, 1, 2);
        b = 0.01 + get_Qvalue(characterX, characterY, 2, 2); // down, move near to destination
       c =  get_Qvalue(characterX, characterY, 3, 2);
       d = 0.01 + get_Qvalue(characterX, characterY, 4, 2) ; // left, move near to destination
    double max_value = std::max(d,std::max(c,std::max(a, b)));
    if (max_value == a) {
        return 1;
    } else if (max_value == b) {
        return 2;
    } else if (max_value == c) {
        return 3;
    } else if (max_value == d) {
        return 4;
    } else {
        return 2;
}
}

void update_Qtable_final() {
    std::ofstream outputfile("Qtable.txt", std::ofstream::trunc);  // open Qtable file for writing, discard old contents
    if (!outputfile) {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }

    // Write the Qtable to the file
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    for (int m = 0; m < 4; m++) {
                        // Write each element to the file
                        outputfile << state_action[i][j][k][l][m] << ' ';
                    }
                }
            }
        }
    }

    outputfile.close();
}





