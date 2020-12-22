#ifndef SORT_H
#define SORT_H

#include <QDate>
#include <QAbstractTableModel>
#include <QItemSelectionModel>
#include <QString>

template<typename T>
class Sort
{
public:
    QList<T*> lst;

    Sort(QList<T*> lst)
    {
        this->lst = lst;
    }

    struct {
            bool operator()(T*& a, T*& b) const
            {
                return a->compare(b);
            }
    } customLess;

    void sorting()
    {
        std::sort(lst.begin(), lst.end(), customLess);
    }

    QList<T*> getLst()
    {
        return lst;
    }

};

#endif // SORT_H
