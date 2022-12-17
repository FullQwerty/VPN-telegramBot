#include "functions.h"

int _stateMenu;

void Menu()
{
    cout << "Choose move: " << endl
        << "(0) Exit programm" << endl
        << "(1) Enter data" << endl
        << "(2) Shoe data" << endl
        << "(3) Edit data" << endl
        << "(4) Add data" << endl
        << "(5) Remove data" << endl
        << "(6) Sort data for active state" << endl
        << "(7) Save data" << endl
        << "(8) Save path for daective file" << endl
        << "Enter u move: ";
    cin >> _stateMenu;
}

int main() {
    Menu();
    int _actions;
    string fileName;

    int _size = 0;
    Data* d = new Data[_size];

    while (_stateMenu != 0)
    {
        switch (_stateMenu)
        {
        case 1:
            system("clear");
            cout << "Hand enter or read file data? : ";
            cin >> _actions;

            system("clear");

            if (_actions == 1){
                DataEntry(d, _size);
            }else{
                /*
                cout << "Enter file name : ";
                cin >> fileName;
                DataReading(d, _size, fileName);
                */
                DataReading(d, _size, "./input.txt");
            }
            sleep(2);
            system("clear");
            Menu();
            break;

        case 2:
            system("clear");
            if (_size != 0)
                Print(d, _size);
            else
                cout << "No data" << endl;
            sleep(2);
            system("clear");
            Menu();
            break;
        
        case 3:
            system("clear");
            if (_size != 0)
                DataChange(d, _size);
            else
                cout << "No data" << endl;
            sleep(2);
            system("clear");
            Menu();
            break;

        case 4:
            system("clear");
            if (_size != 0)
                AddData(d, _size);
            else
                cout << "No data" << endl;

            sleep(2);
            system("clear");
            Menu();
            break;

        case 5:
            system("clear");
            if (_size != 0)
                DeleteData(d, _size);
            else
                cout << "No data" << endl;

            sleep(2);
            system("clear");
            Menu();
            break;
        case 6:
            system("clear");
            if (_size != 0)
                SortingData(d, _size);
            else
                cout << "No data" << endl;

            sleep(2);
            system("clear");
            Menu();
            break;
        
        case 7:
            system("clear");
            if (_size != 0){
                /*
                cout << "Enter file name";
                cin >> fileName; //out.txt

                SaveData(d, _size, fileName);
                */
               SaveData(d, _size, "../bot/conf_files/status_conf_files.txt");
            }else{
                cout << "No data" << endl;
            }
            sleep(2);
            system("clear");
            Menu();
            break;

        case 8:
            system("clear");
            if(_size!=0){
                SaveDeactiveConfs(d, _size, "../bot/conf_files/deactive_conf_file.txt");
            }else{
                cout << "No data" << endl;
            }
            sleep(2);
            system("clear");
            Menu();
            break;

        default:
            cout << "Error. No case for u num" << endl;
            system("clear");
            Menu();
            break;
        }
    }
    system("clear");
    cout << "Work complete" << endl;
    sleep(2);
    return 0;
}