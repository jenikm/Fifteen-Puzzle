#ifndef MAINWINDOW_H
 #define MAINWINDOW_H

 #include <QMainWindow>

 class QAction;
 class QActionGroup;
 class QLabel;
 class QMenu;

 class MainWindow : public QMainWindow
 {
     Q_OBJECT

 public:
     MainWindow();

 protected:
     void contextMenuEvent(QContextMenuEvent *event);

 private slots:
     void quit();
     void resetBoard();
     void mix();
     void help();
     void about();

 private:
     void createActions();
     void createMenus();

     QMenu *fileMenu;
     QMenu *gameMenu;
     QMenu *helpMenu;
     QAction *exitAction;
     QAction *resetAction;
     QAction *mixAction;
     QAction *helpAction;
     QAction *aboutAction;
     QLabel *infoLabel;
  };

 #endif
