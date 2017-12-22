#include "mainwindow.h"
#include <QApplication>
#include "logindlg.h"
QString username;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginDlg dlg;
    dlg.show();
    return a.exec();

    /*
    MainWindow w;
    loginDlg dlg;
    if (dlg.exec() == QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    else
        return 0;
    */
}
