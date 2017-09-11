#ifndef PUNTO_H
#define PUNTO_H

#include <QMainWindow>
#include <cmath>


namespace Ui {
class punto;
}

class punto : public QMainWindow
{
    Q_OBJECT

public:
    explicit punto(QWidget *parent = 0);
    ~punto();
    double x; // variable for the firts value that the user is requested
    double xr; // variable for make the calculations
    double ea; // error acceptable
    double ei=100; // error initial, is 100% but we have no idea where the root is
    int i=0; // variable for the interactions
    double g(double d); //variable that returns the value for the future calculations
public slots:
    void ejecutar(); //slot that performs the method
    void limpiar(); //slot that cleans the whole program


private:
    Ui::punto *ui;
};

#endif // PUNTO_H
