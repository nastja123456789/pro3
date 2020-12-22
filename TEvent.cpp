#include "TEvent.h"

TEvent::TEvent( char *s)
{
    name = s;
}

bool TEvent::inDate( const QDate &st, const QDate &en )
{
    return true;
}

void TEvent::getDescr( char *s )
{
    strcpy( s, "Всегда выполняется" );
}

void TEvent::getStringTime( char *s )
{
    sprintf( s,"Каждый час");
}

void TEvent::setName(QString name)
{
    this->name = name;
}

QString TEvent::getName()
{
    return name;
}

bool TEvent::compare(TEvent *&ev)
{
    return this->getName() < ev->getName();
}

