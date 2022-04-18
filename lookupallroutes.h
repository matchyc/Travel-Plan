#ifndef LOOKUPALLROUTES_H
#define LOOKUPALLROUTES_H

#include <QDialog>

namespace Ui {
class lookUpAllRoutes;
}

class lookUpAllRoutes : public QDialog
{
    Q_OBJECT

public:
    explicit lookUpAllRoutes(QWidget *parent = nullptr);
    ~lookUpAllRoutes();

    void setUI();
    void dealIndexChange();

private:
    Ui::lookUpAllRoutes *ui;
};

#endif // LOOKUPALLROUTES_H
