#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H
#include "model.h"

class Controller{
private:
    Model *model;
public:
    Controller(Model *);
    void start();
    void game();
    void MakeAction (string, int, int);
};
#endif //GAME_CONTROLLER_H
