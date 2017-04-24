#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    scene = new paintscene();
    scene->setSceneRect(0,0,400,400);
    ui->graphicsView->setScene(scene);
    teach_on = false;
    //TODO fill network with alphabet
    network.resize(26, Neuron('A'));
    for (int i=0;i<26;++i)
    {
        network[i].symbol = 'A' + i;
        scan(network[i].symbol);
    }
}



Widget::~Widget()
{
    delete ui;
}


void Widget::scan(char letter)
{
    QFile file(letter+".txt");
    file.open(QIODevice::ReadWrite);
    QTextStream stream(&file);

    for (int i=0;i<45;++i)
    {
        for (int j=0;j<45;++j)
        {
            stream >> network[letter - 'A'].pic[i][j];
        }
    }
    file.close();
}

void Widget::on_pushButton_2_clicked()
{
    ui->graphicsView->scene()->clear();
}

void Widget::on_checkBox_stateChanged(int arg1)
{
    if (arg1){
        teach_on = !teach_on;
    }
    if (teach_on){
        ui->graphicsView->scene()->clear();
    }
    else{
        ui->graphicsView->scene()->clear();
    }
}



void Widget::on_pushButton_clicked()
{
    if (teach_on)
    {
        std::string s = ui->lineEdit->text().toStdString();
        teach(s[0]);
    }
    else
        find();
}

void Widget::teach(char letter)
{
    char ans = 'A';
    int mx = 0;
    for (int i=0;i<26;++i)
    {
        int tmp = 0;
        for (int j=0;j<45;++j)
        {
            for (int k=0;k<45;++k)
            {
                tmp += network[i].pic[j][k] * scene->img[j][k];
            }
        }
        if (tmp > mx)
        {
            mx = tmp;
            ans = 'A' + i;
        }
    }
    if (ans == letter)
    {
        for (int j=0;j<45;++j)
        {
            for (int k=0;k<45;++k)
            {
                if (scene->img[j][k] != 0)
                {
                    ++network[ans - 'A'].pic[j][k];
                }
            }
        }
    }
    else
    {
        for (int j=0;j<45;++j)
        {
            for (int k=0;k<45;++k)
            {
                if (scene->img[j][k] != 0)
                {
                    --network[ans - 'A'].pic[j][k];
                    ++network[letter-'A'].pic[j][k];
                }
            }
        }
    }
    QFile file(letter+".txt");
    file.open(QIODevice::WriteOnly);
    QTextStream stream(&file);

    for (int i=0;i<45;++i)
    {
        for (int j=0;j<45;++j)
        {
            stream >> network[letter - 'A'].pic[i][j];
        }
    }
    file.close();
}

void Widget::find()
{
    char ans = 'A';
    int mx = 0;
    for (int i=0;i<26;++i)
    {
        int tmp = 0;
        for (int j=0;j<45;++j)
        {
            for (int k=0;k<45;++k)
            {
                tmp += network[i].pic[j][k] * scene->img[j][k];
            }
        }
        if (tmp > mx)
        {
            mx = tmp;
            ans = 'A' + i;
        }
    }
    ui->lineEdit->text() = QString(ans);
}
