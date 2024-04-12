#ifndef Qfunction_H
#define Qfunction_H

// functions
void initial_Qtable();
double get_Qvalue(std::string state, int action);
void update_Qtable(int state, int action, int reward, int next_state);
int get_best_action(int characterX, int characterY);
void update_Qtable_final(double (&state_action)[2][2][2][2][4]);
int* get_state(int characterX, int characterY);

// array and values
double state_action[2][2][2][2][4]; // the Qtable

static int state[4]; // state[4], when state[0] = 1,  means the upper gird is black, when = -1, that means it is white, dangerous
// state[5] is to check recursive timees

int action; // action 1 = up, 2 = down, 3 = left, 4 = right,
double learning_rate = 0.7;
int discount_value;
int reward;

#endif

