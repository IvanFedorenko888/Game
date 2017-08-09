#include "view.h"
#include <conio.h>
#include <cstdio>

View::View (Model *m){
model = m;
model->setListener(this);
}

void View::update(){
    int x = model->getPlayer().getX();
    int y = model->getPlayer().getY();
    if (model->getWon() == 0){
        system("cls");
        cout<<"You are in the room ["<<x<<","<<y<<"]. There are ["<<model->getRoom(x,y).getCountDoors()<<"] doors: ["<<model->getRoom(x,y).getDoors().c_str()<<"].";
        cout<<"Items in the room: ["<<model->getRoom(x,y).getItem().c_str()<<"]."<<endl;
        if (model->getRoom(x,y).getDarkRoom() && !model->getPlayer().checkItem("torchlight") && !model->getRoom(x,y).oneItem("torchlight")){
            cout<<endl<<"Can't see anything in this dark place!"<<endl;
        }
        cout<<"Steps: "<<model->getPlayer().getLimitMove()<<endl;
        if (model->getError() != 0)
            cout<<"Error"<<endl;
        if (model->getShow() == 1){
            string str = "";
            for (auto i = 0; i < model->getPlayer().showBack().size(); i++){
                str.append(model->getPlayer().showBack().at(i).getName().c_str());
                str.append(" ");
            }
            cout<<"Backpack:"<<str.c_str()<<endl;
        }

    }
    else if (model->getWon() == 1){
        system("cls");
        cout<<"You Win!"<<endl;
        system("pause");
    }else if (model->getWon() == 2){
        system("cls");
        cout<<"You Lose!"<<endl;
        system("pause");
    }
};