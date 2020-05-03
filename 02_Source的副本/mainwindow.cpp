#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->action->setIcon(QIcon("//Users//kanal//Documents//照片//FullSizeRender.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

