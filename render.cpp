#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include "random.hpp"
#include "render.hpp"
#include "Qfunction.hpp"
#include "movement.hpp"

        sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Grid Game");
        sf::RectangleShape grid[GRID_SIZE][GRID_SIZE];

    std::vector<std::pair<int, int> > values;

    
    void set_map(){

        
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            grid[i][j].setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            grid[i][j].setPosition(i * CELL_SIZE, j * CELL_SIZE);
            grid[i][j].setFillColor(sf::Color::Black);
        }
    }









    // Set some killing grids to white

        //generate the map

    // Create grid squares
int random_number_of_white_grid= random_number()*random_number(); //give a random number of filling the white grid
for (int i = 0; i < 100; i++) {
    int a = random_number();
    int b = random_number();

    if (a == 0 && b == 0) {
        continue;
    }
    if (a == 9 && b == 9) {
        continue;
    }

    bool hasDiagonalNeighbor = false;
    for (const auto& pair : values) {
        int x = pair.first;
        int y = pair.second;

        if (std::abs(a - x) == 1 && std::abs(b - y) == 1) {
            hasDiagonalNeighbor = true;
            break;
        }
    }

    if (hasDiagonalNeighbor) {
        continue;
    }

    values.push_back(std::make_pair(a, b));
    grid[a][b].setFillColor(sf::Color::White);
}
}





   void render_window(){

        set_map();

    // Create character (circle)
    sf::CircleShape character(CELL_SIZE / 2);
    character.setFillColor(sf::Color::Red);






        
       // ai_movement();




while (window.isOpen()) {
        sf::Event event;

     human_movement(event);

    window.clear();


        // Draw grid squares
        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                window.draw(grid[i][j]);
            }
        }

        // Draw character
        character.setPosition(characterX * CELL_SIZE, characterY * CELL_SIZE);
        window.draw(character);

        window.display();

        if (grid[characterX][characterY].getFillColor() == sf::Color::White) {
            // Character touched killing grid
            characterX = 0;
            characterY = 0;
            set_map();
             // Close the window to end the current game
        }
    }
   }