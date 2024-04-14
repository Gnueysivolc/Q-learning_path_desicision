#ifndef render

#define render

const int GRID_SIZE = 10;
const int WINDOW_SIZE = 1000;
const int CELL_SIZE = WINDOW_SIZE / GRID_SIZE;
const int frame_rate = 40;

void set_map();

   extern sf::RenderWindow window;
   extern sf::RectangleShape grid[GRID_SIZE][GRID_SIZE];

extern std::vector<std::pair<int, int> > values;

void render_window();

void setupWindow();

#endif



