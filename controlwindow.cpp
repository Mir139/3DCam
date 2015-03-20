#include "controlwindow.h"

ControlWindow::ControlWindow(Scene myScene, QWidget *parent) :
    QFrame(parent)
{
    const unsigned int _tb_width = 80;
    const unsigned int _tb_height = 28;
    const unsigned int _l_width = 20;
    const unsigned int _l_height = _tb_height;
    const unsigned int _pb_width = 60;
    const unsigned int _pb_height = _pb_width;
    const unsigned int _w_margin = 10;
    const unsigned int _h_margin = 10;

    setFixedSize(4 * (_pb_height + 2 * _h_margin), 5 * (_tb_height + 2 * _h_margin) + 3 * (_pb_height + 2 * _h_margin));
    setFrameStyle(QFrame::Panel | QFrame::Plain);
    setLineWidth(1);

    l_camera = new QLabel(this);
    l_coord_x = new QLabel(this);
    l_coord_y = new QLabel(this);
    l_coord_z = new QLabel(this);
    l_angle_x = new QLabel(this);
    l_angle_y = new QLabel(this);
    l_angle_z = new QLabel(this);
    l_focal = new QLabel(this);

    tb_coord_x = new QLineEdit(this);
    tb_coord_y = new QLineEdit(this);
    tb_coord_z = new QLineEdit(this);
    tb_angle_x = new QLineEdit(this);
    tb_angle_y = new QLineEdit(this);
    tb_angle_z = new QLineEdit(this);
    tb_focal = new QLineEdit(this);
    tb_move_step = new QLineEdit(this);

    pb_up = new QPushButton(this);
    pb_down = new QPushButton(this);
    pb_left = new QPushButton(this);
    pb_right = new QPushButton(this);
    pb_fwd = new QPushButton(this);
    pb_bwd = new QPushButton(this);

    l_camera->move(_w_margin, _h_margin);
    l_coord_x->move(_w_margin, 3 * _h_margin + _l_height);
    l_coord_y->move(_w_margin, 5 * _h_margin + 2 * _l_height);
    l_coord_z->move(_w_margin, 7 * _h_margin + 3 * _l_height);
    l_focal->move(2 * _w_margin + _l_width, 9 * _h_margin + 4 * _l_height);

    tb_coord_x->move(2 * _w_margin + _l_width, 3 * _h_margin + _tb_height);
    tb_coord_y->move(2 * _w_margin + _l_width, 5 * _h_margin + 2 * _tb_height);
    tb_coord_z->move(2 * _w_margin + _l_width, 7 * _h_margin + 3 * _tb_height);
    tb_focal->move(4 * _w_margin + _l_width + _tb_width, 9 * _h_margin + 4 * _tb_height);

    l_angle_x->move(4 * _w_margin + _l_width + _tb_width, 3 * _h_margin + _l_height);
    l_angle_y->move(4 * _w_margin + _l_width + _tb_width, 5 * _h_margin + 2 * _l_height);
    l_angle_z->move(4 * _w_margin + _l_width + _tb_width, 7 * _h_margin + 3 * _l_height);

    tb_angle_x->move(5 * _w_margin + 2 * _l_width + _tb_width, 3 * _h_margin + _tb_height);
    tb_angle_y->move(5 * _w_margin + 2 * _l_width + _tb_width, 5 * _h_margin + 2 * _tb_height);
    tb_angle_z->move(5 * _w_margin + 2 * _l_width + _tb_width, 7 * _h_margin + 3 * _tb_height);

    pb_up->move(3 * _w_margin + _pb_width, 11 * _h_margin + 5 * _tb_height);
    pb_fwd->move(7 * _w_margin + 3 * _pb_width, 11 * _h_margin + 5 * _tb_height);
    pb_left->move(_w_margin, 13 * _h_margin + 5 * _tb_height + _pb_height);
    tb_move_step->move(3 * _w_margin + _pb_width,13 * _h_margin + 5 * _tb_height + _pb_height);
    pb_right->move(5 * _w_margin + 2 * _pb_width, 13 * _h_margin + 5 * _tb_height + _pb_height);
    pb_down->move(3 * _w_margin + _pb_width, 15 * _h_margin + 5 * _tb_height + 2 * _pb_height);
    pb_bwd->move(7 * _w_margin + 3 * _pb_width, 15 * _h_margin + 5 * _tb_height + 2 * _pb_height);

    l_camera->setFixedSize(200, _l_height);
    l_coord_x->setFixedSize(_l_width, _l_height);
    l_coord_y->setFixedSize(_l_width, _l_height);
    l_coord_z->setFixedSize(_l_width, _l_height);
    l_angle_x->setFixedSize(_l_width, _l_height);
    l_angle_y->setFixedSize(_l_width, _l_height);
    l_angle_z->setFixedSize(_l_width, _l_height);
    l_focal->setFixedSize(100, _l_height);

    l_camera->setText("Camera:");
    l_coord_x->setText("x:");
    l_coord_y->setText("y:");
    l_coord_z->setText("z:");
    l_angle_x->setText("a:");
    l_angle_y->setText("b:");
    l_angle_z->setText("c:");
    l_focal->setText("Focal:");

    tb_coord_x->setFixedSize(_tb_width, _tb_height);
    tb_coord_y->setFixedSize(_tb_width, _tb_height);
    tb_coord_z->setFixedSize(_tb_width, _tb_height);
    tb_angle_x->setFixedSize(_tb_width, _tb_height);
    tb_angle_y->setFixedSize(_tb_width, _tb_height);
    tb_angle_z->setFixedSize(_tb_width, _tb_height);
    tb_focal->setFixedSize(_tb_width, _tb_height);
    tb_move_step->setFixedSize(_pb_width, _pb_height);

    pb_up->setFixedSize(_pb_width, _pb_height);
    pb_down->setFixedSize(_pb_width, _pb_height);
    pb_left->setFixedSize(_pb_width, _pb_height);
    pb_right->setFixedSize(_pb_width, _pb_height);
    pb_fwd->setFixedSize(_pb_width, _pb_height);
    pb_bwd->setFixedSize(_pb_width, _pb_height);

    tb_coord_x->setText(QString::number(myScene.Cameras(0).GetRepere().Origin(0)));
    tb_coord_y->setText(QString::number(myScene.Cameras(0).GetRepere().Origin(1)));
    tb_coord_z->setText(QString::number(myScene.Cameras(0).GetRepere().Origin(2)));
    tb_angle_x->setText(QString::number(myScene.Cameras(0).Orientation(0) * 180 / M_PI));
    tb_angle_y->setText(QString::number(myScene.Cameras(0).Orientation(1) * 180 / M_PI));
    tb_angle_z->setText(QString::number(myScene.Cameras(0).Orientation(2) * 180 / M_PI));
    tb_focal->setText(QString::number(myScene.Cameras(0).Focal()));

    pb_up->setText("up");
    pb_down->setText("down");
    pb_left->setText("left");
    pb_right->setText("right");
    pb_fwd->setText("fwd");
    pb_bwd->setText("bwd");

    tb_move_step->setText("10");

    QObject::connect(tb_coord_x, SIGNAL(editingFinished()), this, SLOT(UpdateCam()));
    QObject::connect(tb_coord_y, SIGNAL(editingFinished()), this, SLOT(UpdateCam()));
    QObject::connect(tb_coord_z, SIGNAL(editingFinished()), this, SLOT(UpdateCam()));
    QObject::connect(tb_angle_x, SIGNAL(editingFinished()), this, SLOT(UpdateCam()));
    QObject::connect(tb_angle_y, SIGNAL(editingFinished()), this, SLOT(UpdateCam()));
    QObject::connect(tb_angle_z, SIGNAL(editingFinished()), this, SLOT(UpdateCam()));
    QObject::connect(tb_focal, SIGNAL(editingFinished()), this, SLOT(UpdateCam()));

    QObject::connect(pb_up, SIGNAL(clicked()), this, SLOT(Move_Up()));
    QObject::connect(pb_down, SIGNAL(clicked()), this, SLOT(Move_Down()));
    QObject::connect(pb_left, SIGNAL(clicked()), this, SLOT(Move_Left()));
    QObject::connect(pb_right, SIGNAL(clicked()), this, SLOT(Move_Right()));
    QObject::connect(pb_fwd, SIGNAL(clicked()), this, SLOT(Move_Forward()));
    QObject::connect(pb_bwd, SIGNAL(clicked()), this, SLOT(Move_Backward()));
}

std::vector<double> ControlWindow::GetCamAttr() {
    std::vector<double> newAttr(7);
    newAttr[0] = tb_coord_x->text().toDouble();
    newAttr[1] = tb_coord_y->text().toDouble();
    newAttr[2] = tb_coord_z->text().toDouble();
    newAttr[3] = tb_angle_x->text().toDouble();
    newAttr[4] = tb_angle_y->text().toDouble();
    newAttr[5] = tb_angle_z->text().toDouble();
    newAttr[6] = tb_focal->text().toDouble();
    return newAttr;
}

void ControlWindow::UpdateCam() {
    emit CamToUpdate(GetCamAttr());
}

void ControlWindow::Move_Up() {
    std::vector<double> mV = {0, 0, tb_move_step->text().toDouble(), 0, 0, 0, 0};
    emit CamToMove(mV);
}

void ControlWindow::Move_Down() {
    std::vector<double> mV = {0, 0, - tb_move_step->text().toDouble(), 0, 0, 0, 0};
    emit CamToMove(mV);
}

void ControlWindow::Move_Left() {
    std::vector<double> mV = {0, tb_move_step->text().toDouble(), 0, 0, 0, 0, 0};
    emit CamToMove(mV);
}

void ControlWindow::Move_Right() {
    std::vector<double> mV = {0, - tb_move_step->text().toDouble(), 0, 0, 0, 0, 0};
    emit CamToMove(mV);
}

void ControlWindow::Move_Forward() {
    std::vector<double> mV = {tb_move_step->text().toDouble(), 0, 0, 0, 0, 0, 0};
    emit CamToMove(mV);
}

void ControlWindow::Move_Backward() {
    std::vector<double> mV = {- tb_move_step->text().toDouble(), 0, 0, 0, 0, 0, 0};
    emit CamToMove(mV);
}

void ControlWindow::UpdateCtrlAttr(std::vector<double> newAttr) {
    tb_coord_x->setText(QString::number(newAttr[0]));
    tb_coord_y->setText(QString::number(newAttr[1]));
    tb_coord_z->setText(QString::number(newAttr[2]));
    tb_angle_x->setText(QString::number(newAttr[3]));
    tb_angle_y->setText(QString::number(newAttr[4]));
    tb_angle_z->setText(QString::number(newAttr[5]));
    tb_focal->setText(QString::number(newAttr[6]));
}
