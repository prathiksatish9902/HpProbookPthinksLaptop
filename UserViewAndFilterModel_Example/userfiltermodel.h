#ifndef USERFILTERMODEL_H
#define USERFILTERMODEL_H

#include <QSortFilterProxyModel>
#include <QDebug>
#include<QString>
#include "userviewmodel.h"

class UserFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(QString nameFilter READ nameFilter WRITE setNameFilter NOTIFY nameFilterChanged FINAL)
    Q_PROPERTY(QString roleFilter READ roleFilter WRITE setRoleFilter NOTIFY roleFilterChanged FINAL)
public:
    explicit UserFilterModel(QObject *parent = nullptr);
    ~UserFilterModel();

    QString nameFilter() const;
    QString roleFilter() const;

    Q_INVOKABLE void expandRow(int index);

public slots:
    void setNameFilter(const QString &newNameFilter);
    void setRoleFilter(const QString &newRoleFilter);

signals:
    void nameFilterChanged();
    void roleFilterChanged();
    // QSortFilterProxyModel interface
protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;

private:
    QString m_nameFilter;
    QString m_roleFilter;
    UserViewModel *viewModel;

};

#endif // USERFILTERMODEL_H
