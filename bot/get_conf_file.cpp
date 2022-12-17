#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string getPathDeactiveConf()
{
    string path = "./conf_files/deactive_conf_file.txt";
    ifstream fin;
    fin.open(path);

    if(!fin.is_open()) 
    {
        return "Error. Can't open file";
    }else{
        string str;
        while(!fin.eof())
        {   
            fin >> str;
            if (str.length() > 1){
                return str;
            }
            str = "";
        }
    }   
    fin.close();
    
}