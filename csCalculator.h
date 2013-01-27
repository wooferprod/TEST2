#ifndef CSCALCULATOR_H
#define CSCALCULATOR_H

#include <QObject>
#include <QVector>

class csCalculator : public QObject
{
	Q_OBJECT
public:
	explicit csCalculator(QObject *parent = 0);
	csCalculator  *add(int aNumber);
	int size() { return -1;}
	double average();

signals:

public slots:
private:
	QVector<int> m_ListOfInts;
};

#endif // CSCALCULATOR_H
