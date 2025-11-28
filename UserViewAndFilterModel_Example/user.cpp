#include "user.h"

User::User(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO;
    m_isExpanded = false;
}

User::User(QString name, QString userRole, QString userId, QString password)
{
    qDebug()<<Q_FUNC_INFO;
    m_name = name;
    m_userRole = userRole;
    m_userId = userId;
    m_password = password;
    m_isExpanded = false;
}

User::~User()
{
    qDebug()<<Q_FUNC_INFO;
}

QString User::name() const
{
    return m_name;
}

void User::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

QString User::userRole() const
{
    return m_userRole;
}

void User::setUserRole(const QString &newUserRole)
{
    if (m_userRole == newUserRole)
        return;
    m_userRole = newUserRole;
    emit userRoleChanged();
}

QString User::userId() const
{
    return m_userId;
}

void User::setUserId(const QString &newUserId)
{
    if (m_userId == newUserId)
        return;
    m_userId = newUserId;
    emit userIdChanged();
}

QString User::password() const
{
    return m_password;
}

void User::setPassword(const QString &newPassword)
{
    if (m_password == newPassword)
        return;
    m_password = newPassword;
    emit passwordChanged();
}

bool User::isExpanded() const
{
    return m_isExpanded;
}

void User::setIsExpanded(bool newIsExpanded)
{
    if (m_isExpanded == newIsExpanded)
        return;
    m_isExpanded = newIsExpanded;
    emit isExpandedChanged();
}

