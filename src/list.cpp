#include "include/list.h"

void List::print_menu() {
    int choice;

    cout << "*********************\n";
    cout << " 1 - Print list.\n";
    cout << " 2 - Add to list.\n";
    cout << " 3 - Delete from list.\n";
    cout << " 4 - Quit.\n";
    cout << " Enter your choice and press return/enter.\n";

    cin >> choice;

    if(choice == 1) {
        print_list();
    }
    else if(choice == 2) {
        add_item();
    }
    else if(choice == 3) {
        delete_item();
    }
    else if(choice == 4) {
        return;
    }
    else {
        cout << "Sorry, choice hasn't been implemented.\n\n\n";
    }

}


void List::add_item() {

    cout << "\n\n\n";
    cout << "*** Add Item ***\n";
    cout << "Type in an item and press enter: \n";

    string item;
    cin.ignore();
    getline(cin, item);

    list.push_back(item);

    cout << "Successfully added an item ('" << item << "') to the list \n\n\n";
    cin.clear();

    print_menu();


}

void List::delete_item() {

    cout << "*** Delete Item *** \n";
    cout << "Select an item index number to delete\n";

    if(list.size()) {
        for(unsigned int i=0; i < list.size(); i++){
            cout << i << ": " << list[i] << "\n";            
        }
    }
    else {
        cout << "No items in the list or to delete.\n\n\n";
    }

    print_menu();

}


void List::print_list() {

    cout << "\n\n\n";
    cout << "*** Printing List ***\n";

    for(unsigned int list_index=0; list_index < list.size(); list_index++){
        cout << " * " << list[list_index] << "\n";
        if(list_index == list.size() - 1){
            cout << "\n\n\n";
        }
    }

    cout << "M - Menu \n";
    char choice;
    cin >> choice;

    if(choice == 'M' || choice == 'm'){
        print_menu();
    }
    else {
        cout << "Invalid choice. Quitting...\n\n\n";
    }

}

void List::find_userList() {
    bool userFound = false;
    cout << "\n\n\n";
    cout << "*** Welcome " << name << " ***\n";

    for(unsigned int user_index=0; user_index < mainList.size(); user_index++){
        cout << mainList[user_index][0] << "\n";
        if(mainList[user_index][0] == name) {
            cout << "User has been found: " << mainList[user_index][0] << "\n";
            list = mainList[user_index];
            userFound = true;
            break;
        }
    }
}
