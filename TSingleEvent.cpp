#include "TSingleEvent.h"

TSingleEvent::TSingleEvent( char *s, QDate date, QTime time ) : TEvent( s )
{
    dt = date;
    dTime = time;
}

bool TSingleEvent::inDate( const QDate &st, const QDate &en )
{
    return (st <= dt) & (dt <= en);
}

void TSingleEvent::getDescr( char *s )
{
    sprintf( s, "Выполняется %d.%d.%d", dt.day(), dt.month(), dt.year() );
}

void TSingleEvent::getStringTime( char *s )
{
     sprintf( s, "%d:%d", dTime.hour(), dTime.minute());
}

void TSingleEvent::setDt(QDate dt) //редактирование поля
{
    this->dt = dt;
}

QDate TSingleEvent::getDt() // получения значения поля
{
    return dt;
}

void TSingleEvent::setDTime(QTime dTime) //редактирование поля
{
    this->dTime = dTime;
}

QTime TSingleEvent::getDTime() // получения значения поля
{
    return dTime;
}
