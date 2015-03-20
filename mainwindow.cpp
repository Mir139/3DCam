#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    xmlPath = "cube.xml";
    mainScene = importSceneFromXML();

    setFixedSize(1680, 1050);
    controlField = new ControlWindow(mainScene, this);
    renderField = new RenderWindow(this);

    renderField->move(0,0);
    controlField->move(1280,0);

    Render();

    QObject::connect(controlField, SIGNAL(CamToUpdate(std::vector<double>)), this, SLOT(UpdateCamera(std::vector<double>)));
    QObject::connect(controlField, SIGNAL(CamToMove(std::vector<double>)), this, SLOT(MoveCamera(std::vector<double>)));
}

Scene MainWindow::importSceneFromXML() {
    Scene myScene;
    char* myPath;
    myPath = (char*)xmlPath.c_str();
    std::ifstream file(myPath, std::ios::in);
    // Check for file existence
    if(!file) {
        std::cerr << "Datei wird nicht gefunden oder ist unlesebar!" << std::endl;
    }
    else {
        std::string myLine;
        std::string myFile;
        // Copying into one string
        while(std::getline(file, myLine)) {
            myFile = myFile + myLine;
        }
        file.close();
        char* myChar;
        myChar = (char*)myFile.c_str();
        rapidxml::xml_document<> doc;
        // Parsing the XML Document
        doc.parse<0>(myChar);
        rapidxml::xml_node<> *nodeScene = doc.first_node("scene");
        std::vector<Solid> Solids;
        // Get all Solids
        for(rapidxml::xml_node<> *nodeSolid = nodeScene->first_node("solid") ; nodeSolid ; nodeSolid = nodeSolid->next_sibling("solid")) {
            std::vector<Face> Faces;
            // Get all Faces of current Solid
            for(rapidxml::xml_node<> *nodeFace = nodeSolid->first_node("face") ; nodeFace ; nodeFace = nodeFace->next_sibling("face")) {
                std::vector<Point> Points;
                // Get all Points of current Face
                for(rapidxml::xml_node<> *nodePoint = nodeFace->first_node("point") ; nodePoint; nodePoint = nodePoint->next_sibling("point")) {
                    // Create Point from Coords
                    Point currentPoint(std::stod((std::string)nodePoint->first_attribute("x")->value()), std::stod((std::string)nodePoint->first_attribute("y")->value()), std::stod((std::string)nodePoint->first_attribute("z")->value()));
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
        std::vector<Camera> Cameras;
        // Get all Cameras
        for(rapidxml::xml_node<> *nodeCamera = nodeScene->first_node("camera") ; nodeCamera ; nodeCamera = nodeCamera->next_sibling("camera")) {
            Camera currentCamera(std::stod((std::string)nodeCamera->first_attribute("x")->value()), std::stod((std::string)nodeCamera->first_attribute("y")->value()), std::stod((std::string)nodeCamera->first_attribute("z")->value()));
            std::vector<double> currentOrientation = {std::stod((std::string)nodeCamera->first_attribute("orientationx")->value()), std::stod((std::string)nodeCamera->first_attribute("orientationy")->value()), std::stod((std::string)nodeCamera->first_attribute("orientationz")->value())};
            currentCamera.SetOrientation(currentOrientation);
            currentCamera.SetFocal(std::stod((std::string)nodeCamera->first_attribute("focal")->value()));
            Cameras.push_back(currentCamera);
        }
        myScene.Set(Cameras);

        std::vector<Light> Lights;
        // Get all Lights
        for(rapidxml::xml_node<> *nodeLight = nodeScene->first_node("light") ; nodeLight ; nodeLight = nodeLight->next_sibling("light")) {
            Light currentLight(std::stod((std::string)nodeLight->first_attribute("x")->value()), std::stod((std::string)nodeLight->first_attribute("y")->value()), std::stod((std::string)nodeLight->first_attribute("z")->value()));
            std::vector<double> currentOrientation = {std::stod((std::string)nodeLight->first_attribute("orientationx")->value()), std::stod((std::string)nodeLight->first_attribute("orientationy")->value()), std::stod((std::string)nodeLight->first_attribute("orientationz")->value())};
            currentLight.SetOrientation(currentOrientation);
            std::string currentType(nodeLight->first_attribute("type")->value());
            currentLight.SetType(currentType);
            Lights.push_back(currentLight);
        }
        myScene.Set(Lights);

    }
    return myScene;
}

void MainWindow::Render() {
    std::vector<Face> faces;
    for(unsigned int i = 0 ; i < mainScene.Solids().size() ; i++) {
        bool showFace = true;
        for(unsigned int j = 0 ; j < mainScene.Solids(i).Faces().size() ; j++) {
            Face cF;
            std::vector<Point> points;
            for(unsigned int k = 0 ; k < mainScene.Solids(i).Faces(j).Points().size() ; k++) {
                if(showFace) {
                    Point cP;
                    cP = mainScene.Solids(i).Faces(j).Points(k);
                    cP.SetRepere(mainScene.Cameras(0).GetRepere());
                    if(LAM::ProdScal(cP.Coords(), mainScene.Cameras(0).GetPlanCam().Coords()) > 0) {
                        cP = mainScene.Cameras(0).Projection(cP.Coords());
                        points.push_back(cP);
                    }
                    else {
                        showFace = false;
                    }
                }
            }
            if(showFace) {
                cF.SetPoints(points);
                faces.push_back(cF);
            }
        }
    }
    std::vector<QPainterPath> paths;
    for(unsigned int i = 0 ; i < faces.size() ; i++) {
        paths.push_back(renderField->faceToPath(faces[i]));
    }
    renderField->imageRender(paths);
}

void MainWindow::UpdateCamera(std::vector<double> newAttr) {
    if(newAttr.size() == 7) {
        std::vector<Camera> tmp = mainScene.Cameras();
        tmp[0].SetCoords(newAttr[0], newAttr[1], newAttr[2]);
        tmp[0].SetOrientation(newAttr[3], newAttr[4], newAttr[5]);
        tmp[0].SetFocal(newAttr[6]);
        mainScene.Set(tmp);
        Render();
    }
}

void MainWindow::MoveCamera(std::vector<double> addAttr) {
    std::vector<double> addCoords = {addAttr[0], addAttr[1], addAttr[2]};
    std::vector<double> addAngles = {addAttr[3], addAttr[4], addAttr[5]};
    double addFocal = addAttr[6];
    std::vector<double> newCoords(3);
    std::vector<double> newAngles(3);
    double newFocal;
    addCoords = LAM::ProdMatVec(LAM::Transpose(mainScene.Cameras(0).GetRepere().Matrix(), 3, 3), addCoords);
    newCoords = LAM::Sum(addCoords, mainScene.Cameras(0).GetRepere().Origin());
    newAngles = LAM::Sum(LAM::Prod(180 / M_PI, mainScene.Cameras(0).Orientation()), addAngles);
    newFocal = mainScene.Cameras(0).Focal() + addFocal;
    std::vector<double> newAttr = {newCoords[0], newCoords[1], newCoords[2], newAngles[0], newAngles[1], newAngles[2], newFocal};
    UpdateCamera(newAttr);
    controlField->UpdateCtrlAttr(newAttr);
}
