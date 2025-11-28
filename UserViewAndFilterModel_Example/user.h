#ifndef USER_H
#define USER_H

#include <QObject>
#include <QDebug>
#include <QString>
class User : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(QString userRole READ userRole WRITE setUserRole NOTIFY userRoleChanged FINAL)
    Q_PROPERTY(QString userId READ userId WRITE setUserId NOTIFY userIdChanged FINAL)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged FINAL)
    Q_PROPERTY(bool isExpanded READ isExpanded WRITE setIsExpanded NOTIFY isExpandedChanged FINAL)

public:
    explicit User(QObject *parent = nullptr);

    User(QString name, QString userRole, QString userId, QString password);
    ~User();

    QString name() const;
    void setName(const QString &newName);

    QString userRole() const;
    void setUserRole(const QString &newUserRole);

    QString userId() const;
    void setUserId(const QString &newUserId);

    QString password() const;
    void setPassword(const QString &newPassword);

    bool isExpanded() const;
    void setIsExpanded(bool newIsExpanded);

signals:
    void nameChanged();
    void userRoleChanged();
    void userIdChanged();
    void passwordChanged();
    void isExpandedChanged();

private:
    QString m_name;
    QString m_userRole;
    QString m_userId;
    QString m_password;
    bool m_isExpanded;
};

#endif // USER_H
