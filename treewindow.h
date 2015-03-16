#ifndef TREEWINDOW_H
#define TREEWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QTreeWidget>
#include "Scene.h"

class TreeWindow : public QWidget
{
    Q_OBJECT
public:
    explicit TreeWindow(QWidget *parent = 0);
    void ListScene(Scene myScene);

private:
    QTreeWidget *sceneTreeShow;
    QTreeWidgetItem *sceneTree;

signals:

public slots:

};

#endif // TREEWINDOW_H
