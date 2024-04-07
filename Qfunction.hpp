#ifndef Qfunction

#define Qfunction

//functions
void initial_Qtable();
double get_Qvalue(int state[4], int action);
void update_Qtable(int state, int action, int reward, int next_state);
double get_best_action(int state[5]);
void update_Qtable_final();




//array and values
double state_action[2][2][2][2][4]{}; // the Qtable

std::string state; // state[4], when state[0] = 0  means the upper gird is black, when =1, that means it is white, dangerous
int action; //action 1 = up, 2 = down, 3 = left, 4 = right
#endif