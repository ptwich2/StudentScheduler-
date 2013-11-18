#ifndef HOME_H
#define HOME_H

#include <QMainWindow>

namespace Ui {
class Home;
}

class Home : public QMainWindow
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = 0);
    ~Home();

private slots:

private:
    Ui::Home *ui;
};

#endif // HOME_H
