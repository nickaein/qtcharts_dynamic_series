#pragma once
#include <QAbstractTableModel>
#include <vector>

class MyDataModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	MyDataModel();
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

	void addNewPoint(std::pair<double, double> point);
private:
	std::vector<std::pair<double,double>> m_data;
};
