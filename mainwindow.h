#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "treewindow.h"
#include "renderwindow.h"
#include "Scene.h"
#include "rapidxml.hpp"
#include "repere.h"
#include "lam.h"
#include "controlwindow.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    Scene importSceneFromXML();
    void Render();
    double atof(const char *str);

private:
    ControlWindow *controlField;
    RenderWindow *renderField;
    Scene mainScene;
    std::string xmlPath;

signals:

public slots:
    void UpdateCamera(std::vector<double> newAttr);
    void MoveCamera(std::vector<double> addAttr);
};

#endif // MAINWINDOW_H
