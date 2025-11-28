#ifndef USERVIEWMODEL_H
#define USERVIEWMODEL_H

#include <QAbstractListModel>
#include <QDebug>
#include "userdatamodel.h"

class UserViewModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles
    {
        NameRole = Qt::UserRole + 1,
        UserRole ,
        UserIdRole ,
        PasswordRole,
        RowExpaned
    };
    UserViewModel();
    ~UserViewModel();
    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    // QList<User *> users() const;
    // void setUsers(const QList<User *> &newUsers);

    // QList<UserDataModel *> users() const;
    // void setUsers(const QList<UserDataModel *> &newUsers);

    UserDataModel *getDataModel() const;
    void setDataModel(UserDataModel *newDataModel);

   Q_INVOKABLE void rowExpand(int index);

private:
    // QList<UserDataModel*> m_users;
    UserDataModel *dataModel;
};

#endif // USERVIEWMODEL_H
