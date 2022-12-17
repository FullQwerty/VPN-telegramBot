#include "functions.h"

void DataEntry(Data* (&d), int& n)
{
    Initials init_;
    Date date_;

    cout << "Enter sizeof massicve: ";
    cin >> n;

    d = new Data[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter data for conf file: ";
        cin >> init_.locate_conf_file >> init_.state_active_cf >> init_.chat_id;

        cout << "Enter date for conf file: ";
        cin >> date_.day >> date_.month >> date_.year;

        d[i].DataEntry(init_, date_);
        cout << "__________________________________________\n";
    }
    //delete[]d;
}

void DataReading(Data* (&d), int& n, string fileName)
{
    ifstream reading(fileName);

    if (reading) {
        Initials init_;
        Date date_;
        
        reading >> n;
        d = new Data[n];
        for (int i = 0; i < n; i++){
            reading >> init_.locate_conf_file >> init_.state_active_cf >> init_.chat_id;
            reading >> date_.day >> date_.month >> date_.year;

            d[i].DataEntry(init_, date_);
        }
        //delete[]d;
        cout << "Data done reading" << endl;
    }else{
        cout << "Error, don't open file" << endl;
    }
    reading.close();
}

void Print(Data* d, int n)
{
    for (int i = 0; i < n; i++){
        cout << "Data #" << i + 1 << endl;
        d[i].Print();
        cout << "__________________________________________\n";
    }
}

void DataChange(Data* d, int n)
{
    Initials init_;
    Date date_;
    int _n;
    cout << "Enter num for element (for 1 to " << n << "): ";
    cin >> _n;
    _n--;

    if (_n >= 0 && _n < n){
        cout << "Enter new data for conf file: ";
        cin >> init_.locate_conf_file >> init_.state_active_cf >> init_.chat_id;

        cout << "Enter new date: ";
        cin >> date_.day >> date_.month >> date_.year;

        d[_n].DataEntry(init_, date_);
    }else{
        cout << "Num don't correct enter" << endl;
    }
}

void Copy(Data *d_n, Data *d_o, int n)
{
    for (int i = 0; i < n; i++){
        d_n[i] = d_o[i];
    }
}

void AddData(Data* (&d), int& n)
{
    Initials init_;
    Date date_;
    Data* buf = new Data[n];
    int size = n, new_size = ++n;

    Copy(buf, d, size);
    
    d = new Data[new_size];

    Copy(d, buf, size);

    cout << "Enter new data for conf file: ";
    cin >> init_.locate_conf_file >> init_.state_active_cf >> init_.chat_id;

    cout << "Enter new date: ";
    cin >> date_.day >> date_.month >> date_.year;

    d[size].DataEntry(init_, date_);
    delete[]buf;
    //delete[]d;
}

void DeleteData(Data* (&d), int& n)
{
    int _n;
    Data* buf = new Data[n];
    cout << "Enter num for element (for 1 to " << n << "): ";
    cin >> _n;
    _n--;
    if (_n >= 0 && _n < n){
        Copy(buf, d, n);
        int q = 0;
        n --;

        d = new Data[n];

        for (int i = 0; i <= n; i++){
            if (i != n){
                d[q] = buf[i];
                q++;
            }
        }
        //delete[]d;
        cout << "Done, delete data" << endl;
    }else{
        cout << "Num don't correct enter" << endl;
    }
    delete[]buf;
}

void SortingData(Data* d, int n)
{
    Data buf;
    int numOfSorted = 0;

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (d[i].GetInitials().state_active_cf > d[j].GetInitials().state_active_cf){
                buf = d[i];
                d[i] = d[j];
                d[j] = buf;

                numOfSorted++;
            }
        }
    }
    cout << "Data is sorted done" << endl;
}

void SaveData(Data* d, int n, string fileName)
{
    ofstream record(fileName);
    if (record) {
        record << n << endl;
        for ( int i = 0; i < n; i++){
            record << d[i].GetInitials().locate_conf_file << " " << 
                d[i].GetInitials().state_active_cf << " " << 
                    d[i].GetInitials().chat_id << endl;
            
            record << d[i].GetDate().day << " " << 
                d[i].GetDate().month << " " << 
                    d[i].GetDate().year << endl;
            
            if (i < n - 1)
                record << endl;
        }
    }else{
        cout << "Error. Don't open file" << endl;
    }
    cout << "Data saved in file: " << fileName << endl;
    record.close();
}