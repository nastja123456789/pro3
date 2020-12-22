#ifndef TEVENT_H
#define TEVENT_H

#include <QDate>
#include <QAbstractTableModel>
#include <QItemSelectionModel>
#include <QString>

// Данные
class TEvent
{
protected:
    QString name;

public:
    TEvent( char *s = NULL );

    virtual bool inDate( const QDate &st, const QDate &en );

    virtual void getDescr( char *s );

    virtual void getStringTime( char *s );

    void setName(QString name);

    bool compare(TEvent *&ev);


    QString getName();
};

#endif
