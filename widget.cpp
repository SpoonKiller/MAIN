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
    network.resize(26, Neuron());
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
    std::string str = "";
    str += letter;
    QFile file("C:\\Users\\Antonio\\Desktop\\MyProjects\\MAIN\\"+QString(letter)+".txt");
    file.open(QIODevice::ReadOnly);
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
    teach_on = !teach_on;
    qDebug() << "lololo";
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
    for (int j=0;j<45;++j)
    {
        for (int k=0;k<45;++k)
        {
            if (scene->img[j][k] != 0){
                network[letter - 'A'].pic[j][k] = network[letter-'A'].pic[j][k] + 0.5 * (255 - network[letter-'A'].pic[j][k]);
            }
        }
    }
    std::string str ="";
    str+= letter;
    QFile file("C:\\Users\\Antonio\\Desktop\\MyProjects\\MAIN\\"+QString(letter)+".txt");
    file.open(QIODevice::WriteOnly);
    QTextStream stream(&file);

    for (int i=0;i<45;++i)
    {
        for (int j=0;j<45;++j)
        {
            stream << network[letter - 'A'].pic[i][j];
        }
    }
    file.close();
}

void Widget::find()
{
    char ans = 'A';
    int mx = 0;
    qDebug() << "DanyaTupay";
    for (int i=0;i<26;++i)
    {
        qDebug() << "YuraTupay";
        int tmp = 0;
        for (int j=0;j<45;++j)
        {
            for (int k=0;k<45;++k)
            {
                tmp += network[i].pic[j][k];
            }
        }
        if (tmp > mx)
        {
            mx = tmp;
            ans = 'A' + i;
        }
    }
    qDebug() << "GOLUBUH";
    ui->label->text() = QString(ans);
    qDebug() << "KURLLLLDINI" << ans;
}
