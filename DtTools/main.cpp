#include "homepage.h"
#include <musicplayer.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HomePage h;
    h.show();
    return a.exec();
}
