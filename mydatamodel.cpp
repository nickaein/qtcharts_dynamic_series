#include "mydatamodel.h"

MyDataModel::MyDataModel()
{
    QObject::connect(this, &MyDataModel::newPointAdded, this, &MyDataModel::addNewPoint,
                     Qt::QueuedConnection);
}


void MyDataModel::handleNewPoint(const QPointF &point)
{
    emit newPointAdded(point);
}

void MyDataModel::addNewPoint(const QPointF& point)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_data.push_back(point);
    endInsertRows();
}


int MyDataModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_data.size();
}

int MyDataModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 2;
}

QVariant MyDataModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    Q_UNUSED(orientation)
    Q_UNUSED(role)

    if(section == 0)
        return "x";
    else
        return "y";
}

QVariant MyDataModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role)

    if (index.column() == 0)
        return m_data[index.row()].x();
    else
        return m_data[index.row()].y();
}
