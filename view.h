
#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "model.h"

class View : public Listen{
private:
    Model *model;
public:
    View (Model *);
    virtual void update();
};
#endif //GAME_VIEW_H