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
    
    User(string nam, string surnam, string adr, string id,  string mail, string uname, string pwd) {
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

    void saveToFile(ofstream &file) {
        file << name << ", " << surname << ", " << id_number << ", " << adres << ", " << email << ", " << username << ", " << password  << endl;
    }
};

bool validateID(const string &id) {
    return id.length() == 11 && id.find_first_not_of("0123456789") == string::npos;
}

bool validatePassword(const string &password) {
    return password.length() >= 8;
}

bool validateUsername(const string &username) {
    return username.length() >= 6;
}

bool validateEmail(const string &email) {
    return email.find('@') != string::npos;
}

bool validateLength(const string &text, int maxLength) {
    return text.length() <= maxLength;
}


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

    cout << "\n\nWprowadz dane: " <<endl;
    
    cout << "Podaj imie: ";
    getline(cin, name);
    if (!validateLength(name, 40)) {
        cout << "Bledna długość imienia." << endl;
        insertData();
    }

    cout << "Podaj nazwisko: ";
    getline(cin, surname);
    if (!validateLength(surname, 40)) {
        cout << "Bledna długość nazwiska." << endl;
        insertData();
    }

    cout << "Podaj PESEL: ";
    getline(cin, id);
    if (!validateID(id)) {
        cout << "Błędny PESEL. PESEL powinien zawierać 11 cyfr." << endl;
        insertData();
    }

    cout << "Podaj adres zamieszkania: ";
    getline(cin, adres);

    cout << "Podaj adres e-mail: ";
    getline(cin, email);
    if (!validateEmail(email)) {
        cout << "Błędny adres e-mail." << endl;
        insertData();
    }

    cout << "Podaj nazwe uzytkownika: ";
    getline(cin, username);
    if (!validateUsername(username)) {
        cout << "Bledna nazwa użytkownika. Nazwa użytkownika powinna zawierać co najmniej 6 znaków." << endl;
        insertData();
    }

    cout << "Podaj haslo: ";
    getline(cin, password);
    if (!validatePassword(password)) {
        cout << "Błędne hasło. Hasło powinno zawierać co najmniej 8 znaków." << endl;
        insertData();
    }


    User newUser(name, surname, id, adres, email, username, password);

    ofstream file("C:\\Users\\alicj\\OneDrive\\Pulpit\\projektIO\\dane_pacjentow.txt", ios::app);
    if (file.is_open()) {
        newUser.saveToFile(file);
        file.close();
    } else {
        cout << "Nie można otworzyć pliku do zapisu." << endl;
        exit(0);
    }

    for (const auto &user : users) {
        if (user.username == username) {
            cout << "Użytkownik o podanej nazwie już istnieje." << endl;
            insertData();
        }
        if (user.id_number == id) {
            cout << "Użytkownik o podanym numerze PESEL już istnieje." << endl;
            insertData();
        }
    }
    cout << "\n\nUzytkownik zostal poprawnie zarejestrowany.";
    return newUser;
}


int main() {
    cout << "\n---------------------------------------------------\nZAKLADANIE KONTA W SYSTEMIE\n---------------------------------------------------" << endl;
    User user = insertData();
    user.displayUser();

    return 0;
}
