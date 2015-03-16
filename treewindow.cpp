#include "treewindow.h"

TreeWindow::TreeWindow(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(300,600);
    sceneTreeShow = new QTreeWidget(this);
    sceneTree = new QTreeWidgetItem(sceneTreeShow);
    sceneTree->setText(0, "Solids");
    sceneTree->setText(1, "Lights");
    sceneTree->setText(2, "Cameras");
    sceneTreeShow->show();
}

void TreeWindow::ListScene(Scene myScene) {
    for(unsigned int i = 0 ; i < myScene.Solids().size() ; i++) {

        for(unsigned int j = 0 ; j < myScene.Solids()[i].Faces().size() ; j++) {
            for(unsigned int k = 0 ; k < myScene.Solids()[i].Faces()[j].Points().size() ; k++) {
                //cout << "      +Point: x:" <<  myScene.Solids()[i].Faces()[j].Points()[k].Coords(0) << " ; y:" << myScene.Solids()[i].Faces()[j].Points()[k].Coords(1) << " ; z:" << myScene.Solids()[i].Faces()[j].Points()[k].Coords(2) << endl;
            }
        }
    }
    for(unsigned int i = 0 ; i < myScene.Lights().size() ; i++) {
        //cout << "+ Light: x:" << myScene.Lights()[i].Coords(0) << " ; y:" << myScene.Lights()[i].Coords(1) << " ; z:" << myScene.Lights()[i].Coords(2) << endl;
    }
    for(unsigned int i = 0 ; i < myScene.Cameras().size() ; i++) {
        //cout << "+ Camera: x:" << myScene.Cameras()[i].Coords(0) << " ; y:" << myScene.Cameras()[i].Coords(1) << " ; z:" << myScene.Cameras()[i].Coords(2) << endl;
    }
}
