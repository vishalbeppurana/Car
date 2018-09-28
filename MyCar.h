#ifndef MYCAR_H
#define MYCAR_H

#include <QWidget>

class MyCar : public QWidget
{
    Q_OBJECT

public:
    MyCar(QWidget *parent = 0);
    ~MyCar();
};

#endif // MYCAR_H
