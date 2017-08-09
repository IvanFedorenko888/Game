#include "controller.h"

Controller::Controller(Model *m){
model = m;
}
void Controller::start(){
    int roomCount;
    cout<<"Enter the number of doors: "; cin>>roomCount;
    model->createLabyrinth(roomCount);
    model->generatePlayer();
    model->notify();
    game();
}
void Controller::game(){
    int x;
    int y;
    string action;
    while (model->getWon() == 0){
        x = model->getPlayer().getX();
        y = model->getPlayer().getY();
        model->setError();
        cout<<"Enter an action: ";
        cin>>action;
        MakeAction(action,x,y);
    }
}
void Controller::MakeAction (string c, int x, int y){
    if (strcmp(c.c_str(),"W") == 0)
        model->playerW();
    if (strcmp(c.c_str(), "S") == 0)
        model->playerS();
    if (strcmp(c.c_str(), "A") == 0)
        model->playerA();
    if (strcmp(c.c_str(),"D") == 0)
        model->playerD();
    if (!model->getRoom(x,y).getDarkRoom() || (model->getRoom(x,y).getDarkRoom() && model->getPlayer().checkItem("torchlight") || (model->getRoom(x,y).getDarkRoom() && model->getRoom(x,y).oneItem("torchlight")))){
        if (strcmp(c.c_str(), "get") == 0){
            string get;
            cout<<"What item to get?"<<std::endl;
            cin>>get;
            model->getItem(get,x,y);
        }
        if (strcmp(c.c_str(), "open") == 0){
            model->openChest(x,y);
        }
        if (strcmp(c.c_str(), "open_backpack") == 0){
            model->showBackpack();
        }
        if (strcmp(c.c_str(), "close_backpack") == 0)
            model->closeBackpack();
        if (strcmp(c.c_str(), "drop") == 0){
            string drop;
            cout<<"What subject to throw away?"<<std::endl;
            cin>>drop;
            model->dropItem(drop,x,y);
        }
        if (strcmp(c.c_str(), "eat") == 0){
            model->upPlayerLimit(x,y);
        }
    }
}