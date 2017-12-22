#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H
#include <QDialog>
#include <QMainWindow>
#define MAX 200

namespace Ui {
class changePassword;
}

class changePassword : public QDialog
{
    Q_OBJECT

public:
    explicit changePassword(QMainWindow *mainwindow = 0,QDialog *logindlg = 0);

    ~changePassword();

    bool judgeEmpty();
    void clearAll();

private slots:
    void returnSlot();
    void submitSlot();


private:
    Ui::changePassword *ui;
};

#endif // CHANGEPASSWORD_H
