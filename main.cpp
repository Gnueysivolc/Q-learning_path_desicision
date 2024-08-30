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


// the ai running thing is in render.cpp -> ai_movement() in movement.cpp -> get_best_action() in Qfunction.cpp

/*
can't solve, maybe need to add reward for those who can go out the correct grid so they knwo where to go but not only where not to go
*/







