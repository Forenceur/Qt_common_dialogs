#ifndef MYWIN_H
#define MYWIN_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>

class MyWin : public QWidget
{
    Q_OBJECT

private:
    QPushButton *buttonDialog;

public:
    explicit MyWin(QWidget *parent = nullptr);

signals:

public slots:
    void openDialog();
};

#endif // MYWIN_H
