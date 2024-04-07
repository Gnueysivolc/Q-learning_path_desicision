   #include <SFML/Graphics.hpp>
   #include "render.hpp"
   #include "random.hpp"
   void render_window(){
   sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Grid Game");

    // Create grid squares
    sf::RectangleShape grid[GRID_SIZE][GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            grid[i][j].setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            grid[i][j].setPosition(i * CELL_SIZE, j * CELL_SIZE);
            grid[i][j].setFillColor(sf::Color::Black);
        }
    }









    // Set some killing grids to white
std::vector<std::pair<int, int> > values;

for (int i = 0; i < 100; i++) {
    int a = random_number();
    int b = random_number();

    if (a == 0 && b == 0) {
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









    // Create character (circle)
    sf::CircleShape character(CELL_SIZE / 2);
    character.setFillColor(sf::Color::Red);
    int characterX = 0;
    int characterY = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
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
    }
   }