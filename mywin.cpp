#include "mywin.h"

#define WIN_L 3*180
#define WIN_H 3*90

#define BUTTON_L 80
#define BUTTON_H 30

MyWin::MyWin(QWidget *parent) : QWidget(parent)
{
    setFixedSize(WIN_L,WIN_H);

    buttonDialog=new QPushButton("push me !",this);
    buttonDialog->setGeometry((WIN_L-BUTTON_L)/2,(WIN_H+BUTTON_H)/2,BUTTON_L,BUTTON_H);

    buttonHello=new QPushButton("hello !",this);
    buttonHello->setGeometry((WIN_L-BUTTON_L)/2,(WIN_H-3*BUTTON_H)/2,BUTTON_L,BUTTON_H);

    QObject::connect(buttonDialog,SIGNAL(clicked()),this,SLOT(openDialog()));
    QObject::connect(buttonHello,SIGNAL(clicked()),this,SLOT(helloWho()));
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

void MyWin::helloWho()
{
    bool ok=false;
    QString pseudo=QInputDialog::getText(this,"Hello !","Salut, c'est quoi ton pseudo ?",
                                         QLineEdit::Normal,QString(),&ok);
    if(ok && !pseudo.isEmpty())
    {
        QMessageBox::information(this,"Pseudo", "Ah ! "+pseudo+" mais quel drôles de nom ?");
    }
    else
    {
        QMessageBox::critical(this,"Pseudo","Mais mais ... c'est parce que ton pseudo est si moche ?");
    }

}
