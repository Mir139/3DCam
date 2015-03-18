#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <Face.h>
#include <vector>

class RenderWindow : public QWidget
{
    Q_OBJECT
public:
    explicit RenderWindow(QWidget *parent = 0);
    QPainterPath faceToPath(Face myFace);
    void imageRender(std::vector<QPainterPath> paths);

private:
    //QPainter *painter;
    std::vector<QPainterPath> paths;

protected:
    void paintEvent(QPaintEvent *e);

signals:

public slots:

};

#endif // RENDERWINDOW_H
