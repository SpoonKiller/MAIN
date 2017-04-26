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
    image.resize(45, std::vector<int>(45, 0));
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
    image.clear();
    QRectF rect = scene->sceneRect();
    QImage img (rect.width () + 1, rect.height () + 1, QImage::Format_ARGB32);
    img.fill(QColor (Qt::white).rgb());
    QPainter p(&img);
    ui->graphicsView->scene()->render(&p);
    p.end();
    image.resize(45, std::vector<int> (45, 0));
    int mxx=0, mxy=0, mnx=0, mny=0;
    for (int i=0;i<img.height();++i)
    {
        for (int j=0;j<img.width();++j)
        {
            if (img.pixelColor(j, i) != QColor(255, 255, 255)){
                mxx = qMax(mxx, j);
                mnx = qMin(mnx, j);
                mxy = qMax(mxy, i);
                mny = qMin(mny, i);
            }
        }
    }
    qDebug() << "aaa";
    int h1, w1;
    w1 = mxx - mnx;
    h1 = mxy - mny;
    for (int i=0;i<img.height();++i)
    {
        for (int j=0;j<img.width();++j)
        {
            if (img.pixelColor(j, i) != QColor(255, 255, 255, 255)){
                image[qMin((i - mny) * 45 / h1, 44)][qMin((j - mnx) * 45 / w1, 44)] = 255;
            }
        }
    }
    qDebug() << "suk";
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
    for (int j=0;j<45;++j)
    {
       {
            for (int k=0;k<45;++k)
            if (image[j][k] != 0){
                network[letter - 'A'].pic[j][k] = network[letter-'A'].pic[j][k] + 0.5 * (255 - network[letter-'A'].pic[j][k]);
            }
        }
    }
    QFile file("C:\\Users\\Antonio\\Desktop\\MyProjects\\MAIN\\"+QString(letter)+".txt");
    file.open(QIODevice::WriteOnly);
    QTextStream stream(&file);

    for (int i=0;i<45;++i)
    {
        for (int j=0;j<45;++j)
        {
            stream << network[letter - 'A'].pic[i][j] << " ";
        }
        stream << endl;
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
        int cnt = 0;
        int cnt2 = 0;
        for (int j=0;j<45;++j)
        {
            for (int k=0;k<45;++k)
            {
                if (image[j][k] != 0){
                    tmp += network[i].pic[j][k];
                    ++cnt;
                    if (network[i].pic[j][k] != 0)
                        ++cnt2;
                }
            }
        }
        if (tmp > mx)
        {
            mx = tmp;
            ans = 'A' + i;
        }
    }
    qDebug() << "GOLUBUH";
    ui->label->setText(QString(ans));
    qDebug() << "KURLLLLDINI" << ans;
}
