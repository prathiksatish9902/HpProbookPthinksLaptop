#ifndef USERDATAMODEL_H
#define USERDATAMODEL_H
#include <QDebug>
#include <QList>
#include "user.h"
#include "userdatabasehandler.h"

class UserDataModel
{
public:
    UserDataModel();
    ~UserDataModel();

    QList<User *> userList() const;
    void setUserList(const QList<User *> &newUserList);

    int getRowCount();
    User *getIndexData(int index);
    bool isRowExpanded(int index);
    int setExpandedRow(int index);
    int expandedIndex() const;


private:
    QList<User*> m_userList;
    int m_expandedIndex;

};

#endif // USERDATAMODEL_H
