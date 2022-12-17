#include "data.h"

Data::Data()
{
    initials.locate_conf_file = "";
    initials.state_active_cf = 0;
    initials.chat_id = "";

    date.day = 0;
    date.month = 0;
    date.year = 0;
}

Data::Data(Initials init_, Date date_)
{
    initials.locate_conf_file = init_.locate_conf_file;
    initials.state_active_cf = init_.state_active_cf;
    initials.chat_id = init_.chat_id;

    date.day = date_.day;
    date.month = date_.month;
    date.year = date.year;
}

//Data::~Data(){}

void Data::Print()
{
    cout << "locate cf" << initials.locate_conf_file << endl;
    cout << "data get vpn cf" << date.day << date.month << date.year << endl;
}

void Data::DataEntry(Initials init_, Date date_)
{
    initials.locate_conf_file = init_.locate_conf_file;
    initials.state_active_cf = init_.state_active_cf;
    initials.chat_id = init_.chat_id;

    date.day = date_.day;
    date.month = date_.month;
    date.year = date.year;
}

Data& Data::operator=(Data d_o)
{
    this->initials.locate_conf_file = d_o.initials.locate_conf_file;
    this->initials.state_active_cf = d_o.initials.state_active_cf;
    this->initials.chat_id = d_o.initials.chat_id;

    this->date.day = d_o.date.day;
    this->date.month = d_o.date.month;
    this->date.year = d_o.date.year;

    return *this;
}