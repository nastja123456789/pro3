#ifndef TREGULAREVENT_H
#define TREGULAREVENT_H

#include "TSingleEvent.h"

class TRegularEvent : public TSingleEvent
{
private:
    int delta, lim;

public:
    TRegularEvent( char *s = NULL, QDate date = QDate(2000,1,1), QTime time = QTime(0,0,0,0), int delta = 1, int lim = -1 );

    virtual bool inDate( const QDate &st, const QDate &en );

    virtual void getDescr( char *s );

    virtual void getStringTime( char *s );

    void setDelta(int delta); //редактирование поля

    void setLim(int lim); //редактирование поля

    int getDelta(); // получения значения поля

    int getLim(); // получения значения поля
};

#endif // TREGULAREVENT_H
