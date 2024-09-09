#include "include/database.h"

void Database::write(vector<string> list) {
    ofstream db;
    db.open("db/list.sl");

    if(db.is_open()) {
        for(unsigned int i=0; i < list.size(); i++){
            cout << "Item " << i+1 << ": " << list[i] << "\n";            
        }
    }
    else {
        cout << "Cannot open file for writing.\n";
    }

    db.close();
}

vector<vector<string>> Database::read() {
    string line;
    ifstream db;
    db.open("db/list.sl");

    vector<string> userList;

    if(db.is_open()){
        while(getline(db,line,'\n')) {
            if(line.front() == '#') {
                cout << "Found a hashtag" << line << "\n";
                line.erase(line.begin());
                userList.push_back(line);
            }
            else if(line.front() == '%'){
                cout << "Found a percentage: " << line << "\n";
                mainList.push_back(userList);
                userList.clear();
            }
            else {
                cout << "Found an item " << line << "\n";
                userList.push_back(line);
            }
        }
    }
    else {
        cout << "Cannot open file for writing.\n";
    }

    db.close();

    return mainList;
}