#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include "random.hpp"
#include "render.hpp"
#include "Qfunction.hpp"
#include "movement.hpp"


    void human_movement(){
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
           /* if (event.type == sf::Event::Closed) {
                window.close();
            }
            else
            */
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
    }
// ai_movement call in render function, ai_function = the whole thing
    void ai_movement(){
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            update_Qtable_final(double (&state_action)[2][2][2][2][4]);
                window.close();
            }
        
      int coordinate =  get_best_action(characterX, characterY);


      if(coordinate == 1){
         characterY--;
      }else if(coordinate == 2){
         characterY++;
    }else if(coordinate == 3){
        characterX--;
    }else if(coordinate == 4){
        characterX++;
    }

    


    }
    }
    }