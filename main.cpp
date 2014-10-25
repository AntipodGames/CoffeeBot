#include <iostream>

using namespace std;

int main()
{
    QApplication* App = new QApplication(argc,argv);

    InGame* IG = new InGame(WIDTH,HEIGHT);

    IG->init();
    IG->show();



    return App->exec();
}

