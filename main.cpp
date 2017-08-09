#include "view.h"
#include "controller.h"
int main() {
    Model model;
    Controller controller(&model);
    View view(&model);
    controller.start();
    return 0;
}