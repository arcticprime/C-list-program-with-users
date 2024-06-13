#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Database {
    private:
    protected: 
    public:
    Database(){
        //constructor
    }
    ~Database(){
        //destructor
    }
    vector<vector<string>> mainList;
    string name;

    void write(vector<vector<string>> mainList);
    vector<vector<string>> read();
};