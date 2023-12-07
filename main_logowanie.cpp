#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

const int MaxWords = 100;

class User {
public:
    string name;
    string surname;
    string adres;
    string id_number;
    string email;
    string username;
    string password;

    User(string nam, string surnam, string adr, string id, string mail, string uname, string pwd) {
        name = nam;
        surname = surnam;
        id_number = id;
        adres = adr;
        username = uname;
        password = pwd;
        email = mail;
    }
    User() {
        name = "";
        surname = "";
        id_number = "";
        adres = "";
        username = "";
        password = "";
        email = "";
    }

    void displayUser() {
        cout << "----------------------------------------------\nSzczegóły konta:" << endl;
        cout << "Imie: " << name << endl;
        cout << "Nazwisko: " << surname << endl;
        cout << "PESEL: " << id_number << endl;
        cout << "Adres: " << adres << endl;
        cout << "Nazwa uzytkownika: " << username << endl;
        cout << "Adres email: " << email << endl;
    }

};

vector<User> UploadAllUsers() {
    vector<User> UserData;
    User buff;
    const string filename = "C:\\Users\\alicj\\OneDrive\\Pulpit\\projektIO\\dane_pacjentow.txt";

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku." << endl;
        exit(0);
    }
    else {
        while (UserData.size() < MaxWords && file >> buff.email >> buff.password) {
            UserData.push_back(buff);
        }
        file.close();
    }
    return UserData;
}

User insertData() {
    vector<User> users = UploadAllUsers();
    string username, password, email, name, surname, adres, id;

    cout << "\n\nWprowadz dane: " << endl;

    cout << "Podaj nazwe uzytkownika: ";
    getline(cin, username);

    cout << "Podaj haslo: ";
    getline(cin, password);

    for (const auto &user : users) {
        if (user.username == username && user.password == password) {
            cout << "Logowanie udane! Witaj, " << username << "." << endl;
            return user;
        }
    }

    cout << "Nieprawidlowa nazwa uzytkownika lub haslo. Sprobuj ponownie." << endl;
    insertData();
}

int main() {
    cout << "\n---------------------------------------------------\nLOGOWANIE DO SYSTEMU\n---------------------------------------------------" << endl;
    User loggedInUser = insertData();
    loggedInUser.displayUser();

    return 0;
}
