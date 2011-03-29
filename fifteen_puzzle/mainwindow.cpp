#include <QtGui>

#include "mainwindow.h"

MainWindow::MainWindow()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    infoLabel = new QLabel(tr("<i>Choose a menu option, or right-click to "
                              "invoke a context menu</i>"));
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addWidget(topFiller);
    layout->addWidget(infoLabel);
    layout->addWidget(bottomFiller);
    widget->setLayout(layout);

    createActions();
    createMenus();

    QString message = tr("Game will be played here");
    statusBar()->showMessage(message);

    setWindowTitle(tr("Fifteen Puzzle"));
    setMinimumSize(160, 160);
    resize(480, 320);
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    //menu.addAction(cutAct);
    //menu.addAction(copyAct);
    //menu.addAction(pasteAct);
    //menu.exec(event->globalPos());
}

void MainWindow::quit()
{
    infoLabel->setText(tr("Invoked <b>File|New</b>"));
}

void MainWindow::mix()
{
    infoLabel->setText(tr("Invoked <b>Mix</b>"));
}

void MainWindow::resetBoard()
{
    infoLabel->setText(tr("Invoked <b>Reset</b>"));
}


void MainWindow::help()
{
    infoLabel->setText(tr("Invoked <b>Help</b>"));
}


void MainWindow::about() {
    infoLabel->setText(tr("Invoked <b>Help|About</b>"));
    QMessageBox::about(this, tr("About Menu"),
            tr("The <b>Menu</b> example shows how to create "
               "menu-bar menus and context menus."));
}

void MainWindow::createActions() {

    exitAction = new QAction(tr("&Quit"), this);
    exitAction->setShortcuts(QKeySequence::Quit);
    exitAction->setStatusTip(tr("Exit the application"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    mixAction = new QAction(tr("&Mix"), this);
    mixAction->setShortcuts(QKeySequence::Undo);
    mixAction->setStatusTip(tr("Mix"));
    connect(mixAction, SIGNAL(triggered()), this, SLOT(mix()));

    resetAction = new QAction(tr("&Reset"), this);
    resetAction->setShortcuts(QKeySequence::Redo);
    resetAction->setStatusTip(tr("Reset"));
    connect(resetAction, SIGNAL(triggered()), this, SLOT(resetBoard()));

    aboutAction = new QAction(tr("&About"), this);
    aboutAction->setShortcuts(QKeySequence::Cut);
    aboutAction->setStatusTip(tr("About"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(cut()));

    helpAction = new QAction(tr("&Help"), this);
    helpAction->setShortcuts(QKeySequence::Copy);
    helpAction->setStatusTip(tr("Help"));
    connect(helpAction, SIGNAL(triggered()), this, SLOT(copy()));
}

void MainWindow::createMenus(){
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAction);

    gameMenu = menuBar()->addMenu(tr("&Game"));
    gameMenu->addAction(resetAction);
    gameMenu->addSeparator();
    gameMenu->addAction(mixAction);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(helpAction);
    helpMenu->addAction(aboutAction);
}
