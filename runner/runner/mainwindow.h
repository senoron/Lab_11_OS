#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_stop_clicked();

private:
    Ui::MainWindow *ui;
    int CountClients;
    QString StatusServer;
    QString WayToServer = "/home/Desktop/Lab11_OS/";
    QString WayToClient = "//hoem//Desktop//Lab11_OS//client";
};
#endif // MAINWINDOW_H
