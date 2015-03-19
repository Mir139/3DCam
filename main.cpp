#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <QApplication>
#include "treewindow.h"
#include "renderwindow.h"
#include "Scene.h"
#include "rapidxml.hpp"
#include "repere.h"
#include "lam.h"

double atof(const char *str);

using namespace std;

Scene importSceneFromXML(string PathToXMLFile);
void Render(Scene myScene, RenderWindow &myWindow);

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Scene MainScene;
    MainScene = importSceneFromXML("cube.xml");
    RenderWindow renderWindow;
    renderWindow.show();
    Render(MainScene, renderWindow);
    //TreeWindow treeWindow;
    //treeWindow.show();
    return app.exec();
}

Scene importSceneFromXML(string PathToXMLFile) {
    Scene myScene;
    char* myPath;
    myPath = (char*)PathToXMLFile.c_str();
    ifstream file(myPath, ios::in);
    // Check for file existence
    if(!file) {
        cerr << "Datei wird nicht gefunden oder ist unlesebar!" << endl;
    }
    else {
        string myLine;
        string myFile;
        // Copying into one string
        while(getline(file, myLine)) {
            myFile = myFile + myLine;
        }
        file.close();
        char* myChar;
        myChar = (char*)myFile.c_str();
        rapidxml::xml_document<> doc;
        // Parsing the XML Document
        doc.parse<0>(myChar);
        rapidxml::xml_node<> *nodeScene = doc.first_node("scene");
        vector<Solid> Solids;
        // Get all Solids
        for(rapidxml::xml_node<> *nodeSolid = nodeScene->first_node("solid") ; nodeSolid ; nodeSolid = nodeSolid->next_sibling("solid")) {
            vector<Face> Faces;
            // Get all Faces of current Solid
            for(rapidxml::xml_node<> *nodeFace = nodeSolid->first_node("face") ; nodeFace ; nodeFace = nodeFace->next_sibling("face")) {
                vector<Point> Points;
                // Get all Points of current Face
                for(rapidxml::xml_node<> *nodePoint = nodeFace->first_node("point") ; nodePoint; nodePoint = nodePoint->next_sibling("point")) {
                    // Create Point from Coords
                    Point currentPoint(atof(nodePoint->first_attribute("x")->value()), atof(nodePoint->first_attribute("y")->value()), atof(nodePoint->first_attribute("z")->value()));
                    // Add Point to current Face's Points list
                    Points.push_back(currentPoint);
                }
                // Create Face from Points
                Face currentFace(Points);
                // Add Face to current Solid's Faces list
                Faces.push_back(currentFace);
            }
            // Create Solid from Faces
            Solid currentSolid(Faces);
            // Add Solid to Scene's Solids list
            Solids.push_back(currentSolid);
        }
        myScene.Set(Solids);
        vector<Camera> Cameras;
        // Get all Cameras
        for(rapidxml::xml_node<> *nodeCamera = nodeScene->first_node("camera") ; nodeCamera ; nodeCamera = nodeCamera->next_sibling("camera")) {
            Camera currentCamera(atof(nodeCamera->first_attribute("x")->value()), atof(nodeCamera->first_attribute("y")->value()), atof(nodeCamera->first_attribute("z")->value()));
            std::vector<double> currentOrientation = {atof(nodeCamera->first_attribute("orientationx")->value()), atof(nodeCamera->first_attribute("orientationy")->value()), atof(nodeCamera->first_attribute("orientationz")->value())};
            currentCamera.SetOrientation(currentOrientation);
            currentCamera.SetFocal(atof(nodeCamera->first_attribute("focal")->value()));
            Cameras.push_back(currentCamera);
        }
        myScene.Set(Cameras);

        vector<Light> Lights;
        // Get all Lights
        for(rapidxml::xml_node<> *nodeLight = nodeScene->first_node("light") ; nodeLight ; nodeLight = nodeLight->next_sibling("light")) {
            Light currentLight(atof(nodeLight->first_attribute("x")->value()), atof(nodeLight->first_attribute("y")->value()), atof(nodeLight->first_attribute("z")->value()));
            std::vector<double> currentOrientation = {atof(nodeLight->first_attribute("orientationx")->value()), atof(nodeLight->first_attribute("orientationy")->value()), atof(nodeLight->first_attribute("orientationz")->value())};
            currentLight.SetOrientation(currentOrientation);
            string currentType(nodeLight->first_attribute("type")->value());
            currentLight.SetType(currentType);
            Lights.push_back(currentLight);
        }
        myScene.Set(Lights);

    }
    return myScene;
}

void Render(Scene myScene, RenderWindow &myWindow) {
    vector<Face> faces;
    for(int i = 0 ; i < myScene.Solids().size() ; i++) {
        bool showFace = true;
        for(int j = 0 ; j < myScene.Solids(i).Faces().size() ; j++) {
            Face cF;
            vector<Point> points;
            for(int k = 0 ; k < myScene.Solids(i).Faces(j).Points().size() ; k++) {
                if(showFace) {
                    Point cP;
                    cP = myScene.Solids(i).Faces(j).Points(k);
                    cP.SetRepere(myScene.Cameras(0).GetRepere());
                    if(LAM::ProdScal(cP.Coords(), myScene.Cameras(0).GetPlanCam().Coords()) > 0) {
                        cP = myScene.Cameras(0).Projection(cP.Coords());
                        points.push_back(cP);
                    }
                    else {
                        showFace = false;
                    }
                    /*
                    vector<double> vectCamPoint = {cP.Coords(0) - myScene.Cameras(0).Coords(0), cP.Coords(1) - myScene.Cameras(0).Coords(1), cP.Coords(2) - myScene.Cameras(0).Coords(2)};
                    vector<double> vectCamPlan = {myScene.Cameras(0).GetPlanCam().Coords(0) - myScene.Cameras(0).Coords(0), myScene.Cameras(0).GetPlanCam().Coords(1) - myScene.Cameras(0).Coords(1), myScene.Cameras(0).GetPlanCam().Coords(2) - myScene.Cameras(0).Coords(2)};
                    if(vectCamPoint[0] * vectCamPlan[0] + vectCamPoint[1] * vectCamPlan[1] + vectCamPoint[2] * vectCamPlan[2] > 0) {

                        vectCamPoint = {cP.Coords(0) - myScene.Cameras(0).Coords(0), cP.Coords(1) - myScene.Cameras(0).Coords(1), cP.Coords(2) - myScene.Cameras(0).Coords(2)};
                        cP = myScene.Cameras(0).Projection(vectCamPoint);
                        points.push_back(cP);
                    }
                    else {
                        showFace = false;
                    }
                    */
                }
            }
            if(showFace) {
                cF.SetPoints(points);
                faces.push_back(cF);
            }
        }
    }
    vector<QPainterPath> paths;
    for(int i = 0 ; i < faces.size() ; i++) {
        paths.push_back(myWindow.faceToPath(faces[i]));
    }
    myWindow.imageRender(paths);
}
