#pragma once
#include <QAbstractTableModel>
#include <QPointF>
#include <vector>

class MyDataModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    void handleNewPoint(const QPointF& point);
signals:
    void newPointAdded(const QPointF& point);
public:
    MyDataModel();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

private:
    void addNewPoint(const QPointF& point);
    std::vector<QPointF> m_data;
};
