#include "punto.h"
#include "ui_punto.h"
#include <QDebug> //library to show the error percentage

punto::punto(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::punto)
{
    ui->setupUi(this);
    connect(ui->iniciar,SIGNAL(clicked()),this,SLOT(ejecutar()));
    connect(ui->reiniciar,SIGNAL(clicked()),this,SLOT(limpiar()));
}

punto::~punto()
{
    delete ui;
}
double punto::g(double d){
    return (5*exp(-d-1));
}
void punto::ejecutar(){ //in this slot operations will be executed by pressing enter
    x=ui->inicial->value(); //in this part the values are assigned to the variable of x and the acceptable error
    ea=ui->error->value(); //in this part the values are assigned to the variable of x and the acceptable error
    while(ei>ea){ //in this while is maked all the magic, this is where the calculations of the root
        xr=g(x);
        ei=100*std::abs(xr-x)/xr;
        qDebug()<<ei;
        i++;
        x=xr;
        if (i==100) //this if controls the number of interactions to avoid infinite cycles
        break;
    }
    ui->raiz->display(x); //root is send to the display
    ui->interacciones->display(i); // number of interactions
    ui->errorcalculado->display(ei); //error calculated
}
void punto::limpiar(){ // this slot clean all and prepare all the program for other interaction,
    ui->inicial->setValue(0.0); //set to zero the display
    ui->error->setValue(0.0);  //set to zero the display
    ui->raiz->display(0.0);  //set to zero the display
    ui->interacciones->display(0.0);  //set to zero the display
    ui->errorcalculado->display(0.0);  //set to zero the display
    x=0; //set to zero the variable
    ea=0;//set to zero the variable
    xr=0;//set to zero the variable
    i=0;//set to zero the variable
    ei=100;//initial error is set to 100 again, for the new calculation
}
