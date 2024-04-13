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
    

                                     std::cout<<"ai movement start";


    while (window.pollEvent(event)) {

        if (event.type == sf::Event::Closed) {
            update_Qtable_final();
            window.close();
        }
    }
     //   if (clock.getElapsedTime().asSeconds() >= 0.1f) {        // If 0.1 seconds have passed
         /*   int coordinate = get_best_action(characterX, characterY);

                                  std::cout<<"coorddinate action = "<<coordinate<<"\n;";

            if(coordinate == 1){
                characterY--;
            } else if(coordinate == 2){
                characterY++;
            } else if(coordinate == 3){
                characterX--;
            } else if(coordinate == 4){
                characterX++;
            }
*/
characterX++;
            std::cout<<"finished movement, coorddinate action = "<<characterX<<" "<<characterY<<"\n;";


        if(characterX < 0){
            characterX = 0;
        }else if(characterY < 0){
            characterY = 0;
        }
        if(characterX >= GRID_SIZE){
            characterX = 9;
        }else if(characterY >= GRID_SIZE){
             characterY = 9;
        }

       // clock.restart(); // Restart the clock

        std::cout <<characterX<<" "<<characterY<<std::endl;

            
       // }
    
}