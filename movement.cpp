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
 
            int coordinate = get_best_action(characterX, characterY);

                                    std::cout<<"ai movement start_2"<<std::endl;


                                  std::cout<<"coorddinate action = "<<coordinate<<"\n;";

                
int a,b,c,d,e;

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




int* state = get_state(characterX, characterY+1);
                    a=state[0];
                     b=state[1];
                     c=state[2];
                     d=state[3];
                     e=state[4];

            if(last_time_coordinateX == characterX && last_time_coordinateY == characterY){
                state_action[a][b][c][d][e][coordinate] -= 100; 
                                                                                std::cout<<"state_action[a][b][c][d][e][1]==============================================="<<state_action[a][b][c][d][e][coordinate]<<std::endl;

            }

            if(last_time_coordinateX2 == characterX && last_time_coordinateY2 == characterY){
                 state_action[a][b][c][d][e][coordinate] -= 100; 
                                                                                 std::cout<<"state_action[a][b][c][d][e][1]==============================================="<<state_action[a][b][c][d][e][coordinate]<<std::endl;


            }

        last_time_action = coordinate;
        last_time_coordinateX2 = last_time_coordinateX;
        last_time_coordinateY2 = last_time_coordinateY;
std::cout<<last_time_coordinateX<<" "<<last_time_coordinateY<<std::endl;
std::cout<<last_time_coordinateX2<<" "<<last_time_coordinateY2<<std::endl;


        last_time_coordinateX = characterX;
        last_time_coordinateY = characterY;
        
                    delete[] state;
        




        std::cout <<characterX<<" "<<characterY<<std::endl;

            
       // }
}
}