#include "dialog.h"
#include <QGridLayout>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    radiusLabel=new QLabel(this);
    radiusLabel->setText(tr("半径："));

    radiusLineEdit=new QLineEdit(this);

    areaLabel=new QLabel(this);

    calButton=new QPushButton(this);
    calButton->setText(tr("计算面积"));

    QGridLayout *mainLayout=new QGridLayout(this);
    mainLayout->addWidget(radiusLabel,0,0);
    mainLayout->addWidget(radiusLineEdit,0,1);
    mainLayout->addWidget(areaLabel,1,0);
    mainLayout->addWidget(calButton,1,1);
    this->setLayout(mainLayout);
    connect(calButton,SIGNAL(clicked()),this,SLOT(showArea()));
    connect(radiusLineEdit,SIGNAL(textChanged(QString)),this,SLOT(showArea()));
}

Dialog::~Dialog()
{
}
const static double PI=3.14159;
void Dialog::showArea(){
    QString radiusText=radiusLineEdit->text();
    bool ok;
    double radius=radiusText.toDouble(&ok);
    double area=radius*radius*PI;
    QString temp;
    areaLabel->setText(temp.setNum(area));
}

