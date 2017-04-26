#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCheckBox>
#include <QEvent>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QImage>
#include <QPainter>
#include <QPixmap>

#include "paintscene.h"
#include <neuron.h>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    paintscene * scene;

    void teach(char letter);

    void find();

    void scan(char letter);

private slots:
    void on_pushButton_2_clicked();
    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    bool teach_on;
    std::vector<Neuron> network;
    std::vector<std::vector<int> > image;

};

#endif // WIDGET_H
