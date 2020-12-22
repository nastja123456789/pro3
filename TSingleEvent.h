#ifndef TSINGLEEVENT_H
#define TSINGLEEVENT_H

#include "TEvent.h"

class TSingleEvent : public TEvent
{
protected: //доступ из самого себя или наследников
    QDate dt;
    QTime dTime;

public:
    TSingleEvent( char *s = NULL, QDate date = QDate(2000,1,1), QTime time = QTime(0,0,0,0) );

    virtual bool inDate( const QDate &st, const QDate &en );

    virtual void getDescr( char *s );

    virtual void getStringTime( char *s );

    void setDt(QDate dt); //редактирование поля

    QDate getDt(); // получения значения поля

    void setDTime(QTime dTime); //редактирование поля

    QTime getDTime(); // получения значения поля
};

#endif // TSINGLEEVENT_H
