#include "csCalculator.h"
#include <QDebug>

csCalculator::csCalculator(QObject *parent) :
	QObject(parent)
{
}


csCalculator  *csCalculator::add(int aNumber)
{
	m_ListOfInts.append(aNumber);
	return this;
}

double csCalculator::average()
{


	double aTotal = 0.0;
	foreach(int i, m_ListOfInts)
		aTotal += i;

	double aResult = aTotal/m_ListOfInts.size();

	qDebug() << "aTotal:" << aTotal;
	qDebug() << "aAvg:" << aResult;

	return aResult;
}
