#include "userfiltermodel.h"

UserFilterModel::UserFilterModel(QObject *parent): QSortFilterProxyModel(parent)
{
    qDebug()<<Q_FUNC_INFO;
    viewModel = new UserViewModel;
    setSourceModel(viewModel);
    setFilterCaseSensitivity(Qt::CaseInsensitive);
    setDynamicSortFilter(true);

    setSortRole(UserViewModel::NameRole);
    // setSortRole(UserViewModel::UserRole);
    sort(0, Qt::AscendingOrder);
}

UserFilterModel::~UserFilterModel()
{
    qDebug()<<Q_FUNC_INFO;
}

QString UserFilterModel::nameFilter() const
{
    return m_nameFilter;
}

void UserFilterModel::setNameFilter(const QString &newNameFilter)
{
    if (m_nameFilter == newNameFilter)
        return;
    m_nameFilter = newNameFilter;
    invalidateFilter();
    emit nameFilterChanged();
}

QString UserFilterModel::roleFilter() const
{
    return m_roleFilter;
}

void UserFilterModel::expandRow(int index)
{
    QModelIndex proxyIndex = this->index(index, 0);
    if (!proxyIndex.isValid()) {
        qWarning() << "expandRow: invalid proxy index" << index;
        return;
    }
    QModelIndex sourceIndex = mapToSource(proxyIndex);
    if (!sourceIndex.isValid()) {
        qWarning() << "expandRow: could not map to source for proxy row" << index;
        return;
    }
    int sourceRow = sourceIndex.row();
    viewModel->rowExpand(sourceRow);
}

void UserFilterModel::setRoleFilter(const QString &newRoleFilter)
{
    if (m_roleFilter == newRoleFilter)
        return;
    m_roleFilter = newRoleFilter;
    invalidateFilter();
    emit roleFilterChanged();
}

bool UserFilterModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    qDebug()<<Q_FUNC_INFO << "checking row=" << source_row;

    QModelIndex indexName = sourceModel()->index(source_row , 0 , source_parent);
    QString name = sourceModel()->data(indexName , UserViewModel::NameRole).toString();
    QString role = sourceModel()->data(indexName , UserViewModel::UserRole).toString();

    qDebug() << "  name:" << name << "role:" << role
             << " nameFilter:" << m_nameFilter << " roleFilter:" << m_roleFilter;

    if (!m_nameFilter.isEmpty() && !name.contains(m_nameFilter , Qt::CaseInsensitive)) {
        qDebug() << "  rejected by name";
        return false;
    }

    if (!m_roleFilter.isEmpty() && !role.contains(m_roleFilter , Qt::CaseInsensitive)) {
        qDebug() << "  rejected by role";
        return false;
    }

    qDebug() << "  accepted";
    return true;
}
