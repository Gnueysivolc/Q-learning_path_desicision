#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include "random.hpp"
#include "render.hpp"
#include "Qfunction.hpp"
#include "movement.hpp"

        double state_action[2][2][2][2][2][4] = {};

 int state[5] = {};
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
                    for (int n = 0; n < 2; n++) {
                    for (int m = 0; m < 4; m++) {
                        // Read each element from the file
                        inputfile >> state_action[i][j][k][l][n][m];
                    }
                }
            }
        }
    }
}
    inputfile.close();
}
}


int* get_state(int characterX, int characterY) {
    int* state = new int[5];  //state[5] iss the gird on

     if(characterX >= 0 && characterX < GRID_SIZE && characterY-1 >= 0 && characterY-1 < GRID_SIZE){
    if(grid[characterX][characterY-1].getFillColor()== sf::Color::White){
        state[0] = 1;
    } else if(grid[characterX][characterY-1].getFillColor()== sf::Color::Black){
        state[0] = 0;
    }else{
        state[0] = 1;
    }

    if(grid[characterX][characterY+1].getFillColor()== sf::Color::White){
        state[1] = 1;   // 0 = nothing, safe, //1 = dangerous
    } else if(grid[characterX][characterY+1].getFillColor()== sf::Color::Black){
        state[1] = 0;
    }else{
        state[1] = 1;
    }
    
    if(grid[characterX-1][characterY].getFillColor()== sf::Color::White){
        state[2] = 1;
    } else if(grid[characterX-1][characterY].getFillColor()== sf::Color::Black){
        state[2] = 0;
    }else{
        state[2] = 1;
    }
    
    if(grid[characterX+1][characterY].getFillColor()== sf::Color::White){
        state[3] = 1;
    } else if(grid[characterX+1][characterY].getFillColor()== sf::Color::Black){
        state[3] = 0;
    }else{
        state[3] = 1;
    }

    if(grid[characterX][characterY].getFillColor()== sf::Color::White){
        state[4] = 1;
    } else if(grid[characterX+1][characterY].getFillColor()== sf::Color::Black){
        state[4] = 0;
    }else{
        state[4] = 1;
    }
    return state;
}else{
    state[0]=1;
    state[1]=1;
    state[2]=1;
    state[3]=1;
    state[4]=1;
    return state;
}
}




double get_Qvalue(int characterX, int characterY, int action,int index){  
    if(index == 0){        
     return 0.01;
    }
    index--;

    int discount_value = 0.6+index/10; 
     int a,b,c,d,e;




                if (grid[characterX][characterY+1].getFillColor() == sf::Color::White){
                    int* state = get_state(characterX, characterY);
                    a=state[0];
                     b=state[1];
                     c=state[2];
                     d=state[3];
                     e=state[4];
                state_action[a][b][c][d][e][1] -= 0.05; // penalty for bumping into a wall or a white grid
                    delete[] state;
        }

                if (grid[characterX][characterY-1].getFillColor() == sf::Color::White){
                    int* state = get_state(characterX, characterY);
                    a=state[0];
                     b=state[1];
                     c=state[2];
                     d=state[3];
                     e=state[4];
                state_action[a][b][c][d][e][0] -= 0.05; // penalty for bumping into a wall or a white grid
                    delete[] state;
        }

                 if (grid[characterX-1][characterY].getFillColor() == sf::Color::White){
                    int* state = get_state(characterX, characterY);
                    a=state[0];
                     b=state[1];
                     c=state[2];
                     d=state[3];
                     e=state[4];
                state_action[a][b][c][d][e][2] -= 0.05; // penalty for bumping into a wall or a white grid
                    delete[] state;
        }

                 if (grid[characterX+1][characterY].getFillColor() == sf::Color::White){
                    int* state = get_state(characterX, characterY);
                    a=state[0];
                     b=state[1];
                     c=state[2];
                     d=state[3];
                     e=state[4];
                state_action[a][b][c][d][e][3] -= 0.05; // penalty for bumping into a wall or a white grid
                    delete[] state;
        }









     int* state = get_state(characterX, characterY);


                                 std::cout<<"get_Qvalue_1"<<std::endl;



     a=state[0];
     b=state[1];
     c=state[2];
     d=state[3];
     e=state[4];
                                std::cout<<"state= "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<std::endl;
                                 std::cout<<"get_Qvalue_2"<<std::endl;




     // Check if the next state is a wall or a white grid
      if(grid[characterX][characterY].getFillColor() == sf::Color::White){
          state_action[a][b][c][d][e][action] -= 0.05; // penalty for bumping into a wall or a white grid
      }



                                 std::cout<<"get_Qvalue_2.1"<<std::endl;



        if(characterX < 0){
            characterX = 0;
            state_action[a][b][c][d][e][2] -= 0.4;
            return -0.05;
        }else if(characterY < 0){
            characterY = 0;
            state_action[a][b][c][d][e][0] -= 0.4;
            return -0.05;
        }
        if(characterX >= GRID_SIZE ){
            characterX = 9;
            state_action[a][b][c][d][e][3] -= 0.4;
            return -0.05;
        }else if(characterY >= GRID_SIZE){
            characterY = 9;
            state_action[a][b][c][d][e][1] -= 0.4;
            return -0.05;
        }


                                 std::cout<<"get_Qvalue_2.2"<<std::endl;



     double reward = state_action[a][b][c][d][e][action];
      
                                 std::cout<<"get_Qvalue_3"<<"real reward=========="<<reward<<std::endl;

double max_value = -std::numeric_limits<double>::infinity();
int max_action = -1;
int max_coordinateX = -1;
int max_coordinateY = -1;

for (int coordinateX : {characterX-1, characterX+1}) {
    for (int coordinateY : {characterY-1, characterY+1}) {
        for (int action = 0; action < 4; ++action) {
            double value = get_Qvalue(coordinateX, coordinateY, action, index) + 0.01 * action;
            if (value > max_value) {
                max_value = value;
                max_action = action;
                max_coordinateX = coordinateX;
                max_coordinateY = coordinateY;
            }
        }
    }
}


     double next_reward = discount_value * max_value ;
                              
                              std::cout<<"max_value is "<<max_value<<std::endl;

     //                            std::cout<<"get_Qvalue_4"<<" next reward= "<<next_reward<<std::endl;

                                 std::cout<<"get_Qvalue_4"<<" reward= "<<reward<<std::endl;


  reward = reward + learning_rate * (next_reward-reward);

state_action[a][b][c][d][e][action] = reward;

                                std::cout<<"get_Qvalue_5 reward"<<" "<<reward<<std::endl;

delete[] state;

return reward;

}





int get_best_action(int characterX, int characterY){
    double a, b, c, d, e;


                                 std::cout<<"get_best_action_1"<<std::endl;


       a = get_Qvalue(characterX, characterY, 0, 2);


                                 std::cout<<"get_best_action_2"<<std::endl;



        b = 0.01 + get_Qvalue(characterX, characterY, 1, 2); // down, move near to destination
       c =  get_Qvalue(characterX, characterY, 2, 2);
       d = 0.01 + get_Qvalue(characterX, characterY, 3, 2) ; // left, move near to destination


                                    std::cout<<"get_best_action_3"<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<std::endl;


    double max_value = std::max(d,std::max(c,std::max(a, b)));

  /*    int x = random_number()*random_number();
    if(x <=2){
        return 4; //random action
    }else if(x <=5){
        return 3; //random action
    }else if(x <=7){
        return 2; //random action
}else if(x<=9){
    return 1; //random action
    }
    */




    if (max_value == b) {  //b first to make it not bump wall
         
        return 1;
    } else if (max_value == a) {
        
        return 0;
    } else if (max_value == c) {
       
        return 2;
    } else if (max_value == d) {
       
        return 3;
    } else {
        return 0;
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
                    for (int n = 0; n < 2; n++) {
                    for (int m = 0; m < 4; m++) {
                        // Write each element to the file
                        outputfile << state_action[i][j][k][l][n][m] << ' ';
                    }
                }
            }
        }
    }
    }
    outputfile.close();
}





