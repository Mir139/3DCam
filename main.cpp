#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <QApplication>
#include "treewindow.h"
#include "Scene.h"
#include "rapidxml.hpp"

double atof(const char *str);

using namespace std;

Scene importSceneFromXML(string PathToXMLFile);

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Scene MainScene;
    MainScene = importSceneFromXML("cube.xml");
    TreeWindow treeWindow;
    treeWindow.show();
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
            double currentOrientation[3] = {atof(nodeCamera->first_attribute("orientationx")->value()), atof(nodeCamera->first_attribute("orientationy")->value()), atof(nodeCamera->first_attribute("orientationz")->value())};
            currentCamera.SetOrientation(currentOrientation);
            currentCamera.SetFocal(atof(nodeCamera->first_attribute("focal")->value()));
            Cameras.push_back(currentCamera);
        }
        myScene.Set(Cameras);

        vector<Light> Lights;
        // Get all Lights
        for(rapidxml::xml_node<> *nodeLight = nodeScene->first_node("light") ; nodeLight ; nodeLight = nodeLight->next_sibling("light")) {
            Light currentLight(atof(nodeLight->first_attribute("x")->value()), atof(nodeLight->first_attribute("y")->value()), atof(nodeLight->first_attribute("z")->value()));
            double currentOrientation[3] = {atof(nodeLight->first_attribute("orientationx")->value()), atof(nodeLight->first_attribute("orientationy")->value()), atof(nodeLight->first_attribute("orientationz")->value())};
            currentLight.SetOrientation(currentOrientation);
            string currentType(nodeLight->first_attribute("type")->value());
            currentLight.SetType(currentType);
            Lights.push_back(currentLight);
        }
        myScene.Set(Lights);

    }
    return myScene;
}
