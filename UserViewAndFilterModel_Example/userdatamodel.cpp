#include "userdatamodel.h"

UserDataModel::UserDataModel()
{
    qDebug()<<Q_FUNC_INFO;
    m_expandedIndex = -1;
    setUserList(UserDatabaseHandler::loadUserFromDb());
}

UserDataModel::~UserDataModel()
{
    qDebug()<<Q_FUNC_INFO;
    qDeleteAll(m_userList);
    m_userList.clear();
}

QList<User *> UserDataModel::userList() const
{
    return m_userList;
}

void UserDataModel::setUserList(const QList<User *> &newUserList)
{
    m_userList = newUserList;
}

int UserDataModel::getRowCount()
{
    qDebug()<<Q_FUNC_INFO;
    return m_userList.size();
}

User *UserDataModel::getIndexData(int index)
{
    qDebug()<< Q_FUNC_INFO;

    if(index <= m_userList.size())
    {
        return m_userList.at(index);
    }
    else
    {
        qDebug()<< Q_FUNC_INFO << " out of bound";
    }
    return nullptr;
}

bool UserDataModel::isRowExpanded(int index)
{
    if(index >= 0 && index < m_userList.size())
    {
        User *user  = m_userList.at(index);
        user->setIsExpanded(!user->isExpanded());
        if (user->isExpanded())
            m_expandedIndex = index;
        else if (m_expandedIndex == index)
            m_expandedIndex = -1;
        return true;
    }
    else
    {
        qDebug()<< Q_FUNC_INFO << " out of bound";
    }
    return false;
}

int UserDataModel::setExpandedRow(int index)
{
    if (index < 0 || index >= m_userList.size()) {
        qDebug() << Q_FUNC_INFO << " invalid index" << index;
        return -1;
    }

    int previous = m_expandedIndex;

    if (previous == index) {
        m_userList.at(index)->setIsExpanded(false);
        m_expandedIndex = -1;
        return previous;
    }

    if (previous >= 0 && previous < m_userList.size()) {
        m_userList.at(previous)->setIsExpanded(false);
    }
    m_userList.at(index)->setIsExpanded(true);
    m_expandedIndex = index;

    return previous;
}

int UserDataModel::expandedIndex() const
{
    return m_expandedIndex;
}
