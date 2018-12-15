#include "mywin.h"

#define WIN_L 320
#define WIN_H 180

#define BUTTON_L 80
#define BUTTON_H 30

MyWin::MyWin(QWidget *parent) : QWidget(parent)
{
    setFixedSize(WIN_L,WIN_H);

    buttonDialog=new QPushButton("push me !",this);
    buttonDialog->setGeometry((WIN_L-BUTTON_L)/2,(WIN_H-BUTTON_H)/2,BUTTON_L,BUTTON_H);

    QObject::connect(buttonDialog,SIGNAL(clicked()),this,SLOT(openDialog()));
}

void MyWin::openDialog()
{
    int reponse=QMessageBox::question(this,"confirmation","Do you really want to push ?",QMessageBox::Yes|QMessageBox::No);

    if(reponse==QMessageBox::Yes)
    {
        QMessageBox::information(this,"dialog","Oh Yeah !");
        QMessageBox::warning(this,"Warning !","You push too hard !");
        QMessageBox::critical(this,"error !","Oh no, you kill kenny !");
    }
    else if(reponse==QMessageBox::No)
    {
        QMessageBox::information(this,"information","So Sad ...");
    }
}
