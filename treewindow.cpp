#include "treewindow.h"

TreeWindow::TreeWindow(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(300,600);
    sceneTree = new QTreeWidget(this);
    sceneTree->setHeaderLabel(tr("Scene"));
}

void TreeWindow::ListScene(Scene myScene) {
   /* QTreeWidgetItem *solids = new QTreeWidgetItem(sceneTree);
    solids->setText(0, "Solids");
    for(unsigned int i = 0 ; i < myScene.Solids().size() ; i++) {
        QTreeWidgetItem *cS = new QTreeWidgetItem(solids);
        cS->setText(0, "Solid " + i);
        for(unsigned int j = 0 ; j < myScene.Solids()[i].Faces().size() ; j++) {
            QTreeWidgetItem *cF = new QTreeWidgetItem(cS);
            cF->setText(0, "Face " + j);
            for(unsigned int k = 0 ; k < myScene.Solids()[i].Faces()[j].Points().size() ; k++) {
                QTreeWidgetItem *cP = new QTreeWidgetItem(cF);
                std::string pCoords;
                pCoords = "Point: x:" + std::to_string(myScene.Solids()[i].Faces()[j].Points()[k].Coords(0)) + " ; y:" + std::to_string(myScene.Solids()[i].Faces()[j].Points()[k].Coords(1)) + " ; z:" + std::to_string(myScene.Solids()[i].Faces()[j].Points()[k].Coords(2));
                cP->setText(0, pCoords);
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
    */
}
