#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->onOff = true;
    ui->setupUi(this);
    connect(ui->action_Koniec, SIGNAL(triggered()), this, SLOT(koniec_programu()));
    connect(ui->przycisk, SIGNAL(clicked()), this, SLOT(przelacz()));
    ui->przycisk->setIcon(QIcon(":/img/media-playback-pause.png"));

}

void MainWindow::przelacz()
{
    this->onOff = !this->onOff;
    if (this->onOff)
    {
        ui->przycisk->setIcon(QIcon(":/img/media-playback-pause.png"));
    }
    else
    {
        ui->przycisk->setIcon(QIcon(":/img/media-playback-start.png"));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::koniec_programu()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Potwierdzenie zakończenia programu");
    msgBox.setText("Czy na pewno chcesz zakończyć program?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.button(QMessageBox::Yes)->setText("Tak");
    msgBox.button(QMessageBox::No)->setText("Nie");

    int reply = msgBox.exec();
    if (reply == QMessageBox::Yes)
    {
        qApp->quit();
    }

}


void MainWindow::on_action_O_programie_triggered()
{
    QMessageBox::aboutQt(this,"O wspaniałym programie");
}
