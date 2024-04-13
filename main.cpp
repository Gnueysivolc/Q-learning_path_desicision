#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include "random.hpp"
#include "render.hpp"
#include "Qfunction.hpp"
#include "movement.hpp"




int main() {
    initial_Qtable();
std::cout<<"Qtable initialized"<<std::endl;
    render_window();
    return 0;
}











