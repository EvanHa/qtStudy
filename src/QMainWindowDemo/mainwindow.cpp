#include "mainwindow.h"
#include <QPushButton>
#include <QMenuBar>
#include <QStatusBar>
#include <QDebug>
#include <QAction>
#include <QApplication>
#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //Add central widget
    QPushButton * button = new QPushButton("Hello",this);
    setCentralWidget(button);


    //Declare Quit Action
    QAction * quitAction = new QAction("Quit");
    connect(quitAction,&QAction::triggered,[=](){
        QApplication::quit();
    });

    //Add menus
    QMenu * fileMenu = menuBar()->addMenu(tr("&File"));
    QToolBar *fileToolBar = addToolBar(tr("File"));
    fileMenu->addAction(quitAction);
    fileToolBar->addAction(quitAction);
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Window");
    menuBar()->addSeparator();
    menuBar()->addMenu("Settings");
    menuBar()->addMenu("Help");

    menuBar()->addSeparator();
    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    QAction *aboutQtAct = helpMenu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));

    QMenu *myMenu = menuBar()->addMenu(tr("&MyMenu"));
    QAction * myMenuAction = new QAction("myMenu");
    myMenu->addAction(myMenuAction);

    //Add status bar message
    statusBar()->showMessage("Uploading file ...",3000);
    //statusBar()->clearMessage();
    setUnifiedTitleAndToolBarOnMac(true);
}

MainWindow::~MainWindow()
{

}

QSize MainWindow::sizeHint() const
{
    return QSize(800,500);
}
