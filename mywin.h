#ifndef MYWIN_H
#define MYWIN_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QLineEdit>

class MyWin : public QWidget
{
    Q_OBJECT

private:
    QPushButton *buttonDialog;
    QPushButton *buttonHello;

public:
    explicit MyWin(QWidget *parent = nullptr);

signals:

public slots:
    void openDialog();
    void helloWho();
};

#endif // MYWIN_H
