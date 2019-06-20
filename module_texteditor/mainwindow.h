#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    bool openTextByIODevice(const QString&aFileName);

private slots:
    void on_openFileAction_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
