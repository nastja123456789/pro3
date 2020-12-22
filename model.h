#ifndef MODEL_H
#define MODEL_H

#include <QDate>
#include <QAbstractTableModel>
#include <QItemSelectionModel>
#include <QString>
#include "TEvent.h"
#include "TSingleEvent.h"
#include "TRegularEvent.h"

// Модель
class MyModel : public QAbstractTableModel
{
public:
    QList<TEvent*> lst;
    QItemSelectionModel *selModel;

    MyModel(QObject *parent = nullptr) : QAbstractTableModel( parent )
    {}

    int rowCount(const QModelIndex &parent = QModelIndex()) const override
    {
        return lst.size();
        Q_UNUSED( parent )
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const override
    {
        return 3;
        Q_UNUSED( parent )
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role) const
    {
        if ((orientation != Qt::Horizontal) | (role != Qt::DisplayRole))
            return QVariant();

        if (section == 0)
            return QString( "Описание" );

        if (section == 1)
            return QString( "Описание" );

        return QString( "Время" );

    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override
    {
        if (role == Qt::DisplayRole)
        {
            // TEvent *e
            if (index.column() == 0)
                return QString( lst.at( index.row() )->getName());

            if (index.column() == 1)
            {
                char buf[100];

                lst.at( index.row() )->getDescr( buf );
                return QString( buf );
           }

            if (index.column() == 2)
            {
                char buf[100];

                lst.at(index.row())->getStringTime( buf );

                return QString( buf );
           }

            return index.row();
        }

        return QVariant();
    }

    bool setData( const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override
    {
        Q_UNUSED( role )

        /* if (index.column() == 1)
        {
            lst2[ index.row() ] = value.toString();
        } / */

        return true;
    }

    void add( TEvent *e )
    {
        beginInsertRows( QModelIndex(), lst.size(), lst.size() );

        lst.append( e );

        endInsertRows();
    }

    void remove( int i )
    {
        beginRemoveRows( QModelIndex(), i, i );
        removeRow( i );
        endRemoveRows();
    }

    void clear()
    {
        if (lst.size() == 0)
            return;

        int t = lst.size();

        beginRemoveRows( QModelIndex(), 0, t-1 );
        removeRows( 0, t );
        endRemoveRows();

        lst.clear();
    } // */
};

#endif // MODEL_H
