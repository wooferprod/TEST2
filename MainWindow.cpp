#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "csCalculator.h"

#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	connect(ui->btnByeBye,SIGNAL(clicked()),this,SLOT(close()));
	connect(ui->lineEdit,SIGNAL(textChanged(QString)), ui->textBrowser, SLOT(append(QString)));
	connect(ui->lineEdit,SIGNAL(textChanged(QString)), this, SLOT(sayWhatTheFuck(QString)));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	QString sMessage = QString("Welcome %1").arg(ui->lineEdit->text());
	QMessageBox::information(this,"Greeting",sMessage);
}

/*
void MainWindow::on_btnByeBye_clicked()
{
	QApplication::quit();
}
*/

void MainWindow::sayWhatTheFuck(QString s)
{
	qDebug() << Q_FUNC_INFO << "WTF? " << s;
}

void MainWindow::on_pushButton_2_clicked()
{
	csCalculator *aCalculator = new csCalculator();

	double aAvg = aCalculator
			->add(15)
			->add(20)
			->add(15)->average();

	QMessageBox::information(this,"Answer",QString("%1").arg(aAvg));

}
