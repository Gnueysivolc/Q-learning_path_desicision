#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include "random.hpp"
#include "render.hpp"
#include "Qfunction.hpp"
#include "movement.hpp"
double future_step = 3; // the number of steps in the future to consider
        int last_time_action=0, last_time_coordinateX=0, last_time_coordinateX2=0, last_time_coordinateY2=0, last_time_coordinateY=0;

        int characterX = 0;
        int characterY = 0;

    void human_movement(sf::Event& event){

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else
            
             if (event.type == sf::Event::KeyPressed) {
                // Move character
                if (event.key.code == sf::Keyboard::Up && characterY > 0) {
                    --characterY;
                }
                else if (event.key.code == sf::Keyboard::Down && characterY < GRID_SIZE - 1) {
                    ++characterY;
                }
                else if (event.key.code == sf::Keyboard::Left && characterX > 0) {
                    --characterX;
                }
                else if (event.key.code == sf::Keyboard::Right && characterX < GRID_SIZE - 1) {
                    ++characterX;
                }
            }
        }
        if (grid[characterX][characterY].getFillColor() == sf::Color::White) {
            // Character touched killing grid

        }
    
    }


void ai_movement(sf::Event& event){
  //  sf::Clock clock; // Start the clock
    

                                     std::cout<<"ai movement start"<<std::endl;


    while (window.pollEvent(event)) {

        if (event.type == sf::Event::Closed) {
            update_Qtable_final();
            window.close();
        }
    }
    
                                    std::cout<<"ai movement start_1"<<std::endl;
 

 //int coordinate = get_best_action(characterX, characterY); // it is in the Qfunction.cpp
 //use this when need to learn

           int coordinate = static_cast<int>(get_Qvalue_without_learning(characterX, characterY, future_step)); // it is in the Qfunction.cpp
            //this is the one that doesn't need to learn
                                    std::cout<<"ai movement start_2"<<std::endl;



                                  std::cout<<"coorddinate action = "<<coordinate<<"\n;";

                
int a,b,c,d,e;

/*
    // this is the one for learning !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            // coordinate is the direction to move actually
            if(coordinate == 0){
                characterY--;
            } else if(coordinate == 1){
                    int* state = get_state(characterX, characterY);
                    a=state[0];
                     b=state[1];
                     c=state[2];
                     d=state[3];
                     e=state[4];
                state_action[a][b][c][d][e][1] += 0.5; 
                    delete[] state;
                characterY++;
            } else if(coordinate == 2){
                characterX--;
            } else if(coordinate == 3){
                int* state = get_state(characterX, characterY);
                    a=state[0];
                     b=state[1];
                     c=state[2];
                     d=state[3];
                     e=state[4];
                state_action[a][b][c][d][e][3] += 0.5; 
                    delete[] state;
                characterX++;
            }


            std::cout<<"finished movement, coorddinate action = "<<characterX<<" "<<characterY<<"\n;";


        if(characterX < 0){
            int* state = get_state(characterX+1, characterY);
                    a=state[0];
                     b=state[1];
                     c=state[2];
                     d=state[3];
                     e=state[4];
                state_action[a][b][c][d][e][2] -= 0.2; 
                    delete[] state;
            characterX = 0;
        }else if(characterY < 0){
            int* state = get_state(characterX, characterY+1);
                    a=state[0];
                     b=state[1];
                     c=state[2];
                     d=state[3];
                     e=state[4];
                state_action[a][b][c][d][e][0] -= 0.2; 
                    delete[] state;
            characterY = 0;
            
        }

*/


// this is the one for no learning, the above is the one for learning
                    if(coordinate == 0){
                characterY--;
            } else if(coordinate == 1){
                characterY++;
            } else if(coordinate == 2){
                characterX--;
            } else if(coordinate == 3){
                characterX++;
            }

/*
            std::cout<<"finished movement, coorddinate action = "<<characterX<<" "<<characterY<<"\n;";


        if(characterX < 0){
            int* state = get_state(characterX+1, characterY);
                    a=state[0];
                     b=state[1];
                     c=state[2];
                     d=state[3];
                     e=state[4];
                state_action[a][b][c][d][e][2] -= 0.2; 
                    delete[] state;
            characterX = 0;
        }else if(characterY < 0){
            int* state = get_state(characterX, characterY+1);
                    a=state[0];
                     b=state[1];
                     c=state[2];
                     d=state[3];
                     e=state[4];
                state_action[a][b][c][d][e][0] -= 0.2; 
                    delete[] state;
            characterY = 0;
            
        }

if(!(characterX >= GRID_SIZE && characterY >= GRID_SIZE) ){
        if(characterX >= GRID_SIZE){
            characterX = 9;
            int* state = get_state(characterX, characterY);
                    a=state[0];
                     b=state[1];
                     c=state[2];
                     d=state[3];
                     e=state[4];
                state_action[a][b][c][d][e][3] -= 10; 
                                                            std::cout<<"state_action[a][b][c][d][e][1]"<<state_action[a][b][c][d][e][3]<<std::endl;

                    delete[] state;
        }
        if(characterY >= GRID_SIZE){
             characterY = 9;
             int* state = get_state(characterX, characterY);
                    a=state[0];
                     b=state[1];
                     c=state[2];
                     d=state[3];
                     e=state[4];
                state_action[a][b][c][d][e][1] -= 10; 

                                            std::cout<<"state_action[a][b][c][d][e][1]"<<state_action[a][b][c][d][e][1]<<std::endl;
                    delete[] state;
        }





        std::cout <<characterX<<" "<<characterY<<std::endl;

            
       // }
}
*/



}
