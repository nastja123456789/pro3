#include "TRegularEvent.h"

TRegularEvent::TRegularEvent( char *s, QDate date, QTime time, int delta, int lim) :
    TSingleEvent( s, date, time )
{
    this->delta = delta;
    this->lim = lim;
}

bool TRegularEvent::inDate( const QDate &st, const QDate &en )
{
    QDate t = dt;

    for( int i = 0; ; i++ )
    {
        if ( (lim >= 0) & (i >= lim) )
        {
            return false;
        }

        if (st <= t)
        {
            break;
        }

        t = t.addDays(delta);
    }

    return (st <= t) & (t <= en);
}

void TRegularEvent::getDescr( char *s )
{
    if (lim >= 0)
        sprintf( s, "Выполняется начиная с %d.%d.%d с интервалом в %d дней %d раз",
                 dt.day(), dt.month(), dt.year(), delta, lim );
    else
        sprintf( s, "Выполняется начиная с %d.%d.%d с интервалом в %d дней",
                 dt.day(), dt.month(), dt.year(), delta );
}

void TRegularEvent::getStringTime( char *s )
{
    sprintf(s, "%d:%d", dTime.hour(), dTime.minute() );
}

void TRegularEvent::setDelta(int delta) //редактирование поля
{
    this->delta = delta;
}

void TRegularEvent::setLim(int lim) //редактирование поля
{
    this->lim = lim;
}

int TRegularEvent::getDelta() // получения значения поля
{
    return delta;
}

int TRegularEvent::getLim() // получения значения поля
{
    return lim;
}
