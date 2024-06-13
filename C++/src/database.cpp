#include "include/database.h"  

void Database::write(vector<vector<string>> mainList){
    
    ofstream db;
    db.open("db/lists.sl");

    if( db.is_open() ){
        for( int user_index=0; user_index < (int)mainList.size(); user_index++ ) {
            for ( int list_index=0; list_index < (int)mainList[user_index].size(); list_index++ ){
                if(list_index == 0){
                    db << "#" << mainList[user_index][list_index] << "\n";
                }
                else {
                    db << mainList[user_index][list_index] << "\n";
                }
            }
            db << "%" << "\n" ;
    }
    }
    else {
        cout << "File can not be opened for writing...\n";
    }

    db.close();
}

vector<vector<string>> Database::read(){
    string line;
    ifstream db;

    vector<string> userList;


    db.open("db/lists.sl");

    if( db.is_open() ){
        while ( getline(db, line, '\n') ) {
            if( line.front() == '#'){
                cout << "Found a Hashtag: " << line << "\n";
                line.erase(line.begin());
                userList.push_back(line);
            }
            else if( line.front() == '%' ){
                cout << "Found a percentage: " << line << "\n";
                mainList.push_back(userList);
                userList.clear();
            }
            else{
                cout << "Found an item: " << line << "\n";
                userList.push_back(line);
            }
        }
    }
    else{
        cout << "File can not be opened for reading...\n";
    }

    db.close();

return mainList;

}