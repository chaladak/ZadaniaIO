#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User {
public:
    string username;
    string password;
    string email;
    string name;
    string surname;
    string adres;
    int id_number;

    User(string uname, string pwd, string mail, string nam, string surnam, string adr, int id) {
        username = uname;
        password = pwd;
        email = mail;
        name = nam;
        surname = surnam;
        id_number = id;
        adres = adr;
    }

    void displayUser() {
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "ID: " << id_number << endl;
        cout << "Adres: " << adres << endl;
    }
    
};

User insertData() {
    vector<User> users; // Lista przechowująca użytkowników
    string username, password, email, name, surname, adres;
    int id;
    cout << "Podaj imie: ";
    cin >> name;

    cout << "Podaj nazwisko: ";
    cin >> surname;

    cout << "Podaj PESEL: ";
    cin >> id;

    cout << "Podaj adres: ";
    cin >> adres;

    cout << "Podaj adres e-mail: ";
    cin >> email;
    
    cout << "Podaj nazwę użytkownika: ";
    cin >> username;

    cout << "Podaj hasło: ";
    cin >> password;
    

    User newUser(username, password, email,name, surname,adres,id);
    return newUser;

    for (const auto& user : users) {
        if (user.username == username) {
            cout << "Użytkownik o podanej nazwie już istnieje." << endl;
            break; //break
        }
    }
}


int main() {
    User user = insertData();
    
    cout << "Użytkownik zarejestrowany. Szczegóły konta:" << endl;
    user.displayUser();

    return 0;
}