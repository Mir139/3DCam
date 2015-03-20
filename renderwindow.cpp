#include "renderwindow.h"

RenderWindow::RenderWindow(QWidget *parent) :
    QFrame(parent)
{
    setFixedSize(1280,720);
    setFrameStyle(QFrame::Panel | QFrame::Plain);
    setLineWidth(1);
    frame.moveTo(0,0);
    frame.lineTo(1280,0);
    frame.lineTo(1280,720);
    frame.lineTo(0,720);
    frame.lineTo(0,0);
}

QPainterPath RenderWindow::faceToPath(Face myFace) {
    QPainterPath path;
    path.moveTo(-myFace.Points(0).Coords(1) + this->width() / 2, -myFace.Points(0).Coords(2) + this->height() / 2);
    path.lineTo(-myFace.Points(1).Coords(1) + this->width() / 2, -myFace.Points(1).Coords(2) + this->height() / 2);
    path.lineTo(-myFace.Points(2).Coords(1) + this->width() / 2, -myFace.Points(2).Coords(2) + this->height() / 2);
    path.lineTo(-myFace.Points(0).Coords(1) + this->width() / 2, -myFace.Points(0).Coords(2) + this->height() / 2);
    return path;
}

void RenderWindow::imageRender(std::vector<QPainterPath> paths) {
    /*
    painter->setPen(Qt::black);
    for(int i = 0 ; i < paths.size() ; i++) {
        painter->drawPath(paths[i]);
        painter->fillPath(paths[i], Qt::blue);
    }
    */
    this->paths = paths;
    this->repaint();
}

void RenderWindow::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    //painter.setPen(Qt::black);
    for(unsigned int i = 0 ; i < this->paths.size() ; i++) {
        painter.drawPath(this->paths[i]);
        painter.setOpacity(0.5);
        painter.fillPath(this->paths[i], Qt::blue);
        painter.setOpacity(1);
    }
    painter.drawPath(frame);
}
