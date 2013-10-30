#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <QTabWidget>

namespace Ui {
class Scheduler;
}

class Scheduler : public QTabWidget
{
    Q_OBJECT

public:
    explicit Scheduler(QWidget *parent = 0);
    ~Scheduler();

private:
    Ui::Scheduler *ui;
};

#endif // SCHEDULER_H
