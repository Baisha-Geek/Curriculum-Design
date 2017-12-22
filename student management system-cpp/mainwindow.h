#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QDialog *parent = 0);
    ~MainWindow();
    void failList();

    void searched(int);
private slots:
    void on_action_11_triggered();

    void on_action_3_triggered();

    void on_action_2_triggered();

    void receiveData(QString user);

    void on_action_7_triggered();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_action_triggered();

    void on_action_5_triggered();

    void on_pushButton_4_clicked();

    void on_action_9_triggered();

    void on_action_6_triggered();

private:
    Ui::MainWindow *ui;
    QString userName;
};

#endif // MAINWINDOW_H
