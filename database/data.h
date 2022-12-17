#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
        data
        1. conf_file (path)
        2. state_active (bool)
        3. if state then chat_id
 */

struct Initials 
{
    string locate_conf_file;
    int state_active_cf;
    string chat_id;
};

struct Date
{
    int day,
        month,
        year;
};

class Data
{
private:
    Initials initials;
    Date date;
public:

    Data();
    Data(Initials init_, Date date_);

    void Print();
    void DataEntry(Initials init_, Date date_);
    Initials GetInitials() { return initials; };
    Date GetDate() { return date; };
    Data& operator = (Data d_o);

    ~Data(){};
};
