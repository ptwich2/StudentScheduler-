#include "welcomepage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WelcomePage  w;
    w.show();
    w.setFixedSize(w.size());
    return a.exec();
}
