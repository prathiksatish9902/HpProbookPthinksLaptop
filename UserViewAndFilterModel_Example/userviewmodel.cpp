#include "userviewmodel.h"

UserViewModel::UserViewModel()
{
    qDebug() << Q_FUNC_INFO;
    dataModel = new UserDataModel;
}

UserViewModel::~UserViewModel()
{
    qDebug() << Q_FUNC_INFO;    
}

int UserViewModel::rowCount(const QModelIndex &parent) const
{
    qDebug() << Q_FUNC_INFO;
    if (parent.isValid())
        return 0;
    return dataModel->getRowCount();
}

QVariant UserViewModel::data(const QModelIndex &index, int role) const
{
    qDebug() << Q_FUNC_INFO;
    if (!index.isValid())
    {
        return QVariant();
    }
    int row = index.row();
    if (row < 0 || row >= dataModel->getRowCount())
        return QVariant();

    const User *u = dataModel->getIndexData(row);

    switch(role)
    {
    case NameRole:
        return u->name();
    case UserRole:
        return u->userRole();
    case UserIdRole:
        return u->userId();
    case PasswordRole:
        return u->password();
    case RowExpaned:
        return u->isExpanded();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> UserViewModel::roleNames() const
{
    qDebug() << Q_FUNC_INFO;
    QHash <int , QByteArray> l_userRole;
    l_userRole[NameRole] = "name";
    l_userRole[UserRole] = "role";
    l_userRole[UserIdRole] = "id";
    l_userRole[PasswordRole] = "password";
    l_userRole[RowExpaned] = "isExpanded";

    return l_userRole;
}

UserDataModel *UserViewModel::getDataModel() const
{
    return dataModel;
}

void UserViewModel::setDataModel(UserDataModel *newDataModel)
{
    dataModel = newDataModel;
}

void UserViewModel::rowExpand(int index)
{
    int previous = dataModel->setExpandedRow(index);

    if (previous >= 0 && previous < rowCount()) {
        QModelIndex prevIdx = createIndex(previous, 0);
        emit dataChanged(prevIdx, prevIdx, {RowExpaned});
    }
    if (index >= 0 && index < rowCount()) {
        QModelIndex curIdx = createIndex(index, 0);
        emit dataChanged(curIdx, curIdx, {RowExpaned});
    }
}
