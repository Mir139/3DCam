#ifndef CONTROLWINDOW_H
#define CONTROLWINDOW_H

#include <QFrame>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <Scene.h>
#include <cmath>

class ControlWindow : public QFrame
{
    Q_OBJECT
public:
    explicit ControlWindow(Scene myScene, QWidget *parent = 0);
    std::vector<double> GetCamAttr();
    void UpdateCtrlAttr(std::vector<double> newAttr);

private:
    QLabel *l_camera;
    QLineEdit *tb_coord_x;
    QLineEdit *tb_coord_y;
    QLineEdit *tb_coord_z;
    QLineEdit *tb_angle_x;
    QLineEdit *tb_angle_y;
    QLineEdit *tb_angle_z;
    QLineEdit *tb_focal;
    QLabel *l_coord_x;
    QLabel *l_coord_y;
    QLabel *l_coord_z;
    QLabel *l_angle_x;
    QLabel *l_angle_y;
    QLabel *l_angle_z;
    QLabel *l_focal;
    QPushButton *pb_up;
    QPushButton *pb_down;
    QPushButton *pb_left;
    QPushButton *pb_right;
    QPushButton *pb_fwd;
    QPushButton *pb_bwd;
    QLineEdit *tb_move_step;

signals:
    void CamToUpdate(std::vector<double> newAttr);
    void CamToMove(std::vector<double> newAttr);

public slots:
    void UpdateCam();
    void Move_Up();
    void Move_Down();
    void Move_Left();
    void Move_Right();
    void Move_Forward();
    void Move_Backward();
};

#endif // CONTROLWINDOW_H
