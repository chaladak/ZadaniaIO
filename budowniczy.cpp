/*Wzorzec "Budowniczy" jest używany do konstrukcji złożonych obiektów, krok po kroku, poprzez oddzielenie procesu konstrukcji od samego obiektu. 
Stosujemy wzorzec do konstrukcji obiektu klasy User, aby uniknąć długich list argumentów w konstruktorze.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Klasa reprezentująca użytkownika
class User {
public:
    string name;
    string surname;
    string adres;
    string id_number;
    string email;
    string username;
    string password;

    User() {}

    // Metoda wyświetlająca informacje o użytkowniku
    void displayUser() {
        cout << "----------------------------------------------\nSzczegóły konta:" << endl;
        cout << "Imie: " << name << endl;
        cout << "Nazwisko: " << surname << endl;
        cout << "PESEL: " << id_number << endl;
        cout << "Adres: " << adres << endl;
        cout << "Nazwa uzytkownika: " << username << endl;
        cout << "Adres email: " << email << endl;
    }

    // Metoda zapisująca dane użytkownika do pliku
    void saveToFile(ofstream& file) {
        file << name << ", " << surname << ", " << id_number << ", " << adres << ", " << email << ", " << username << ", " << password << endl;
    }
};

// Klasa budowniczego użytkownika
class UserBuilder {
public:
    User user;

    // Metoda ustawiająca imię
    UserBuilder& setName(const string& name) {
        user.name = name;
        return *this;
    }

    // Metoda ustawiająca nazwisko
    UserBuilder& setSurname(const string& surname) {
        user.surname = surname;
        return *this;
    }

    // Metoda ustawiająca PESEL
    UserBuilder& setIdNumber(const string& id) {
        user.id_number = id;
        return *this;
    }

    // Metoda ustawiająca adres
    UserBuilder& setAdres(const string& adres) {
        user.adres = adres;
        return *this;
    }

    // Metoda ustawiająca adres email
    UserBuilder& setEmail(const string& email) {
        user.email = email;
        return *this;
    }

    // Metoda ustawiająca nazwę użytkownika
    UserBuilder& setUsername(const string& username) {
        user.username = username;
        return *this;
    }

    // Metoda ustawiająca hasło
    UserBuilder& setPassword(const string& password) {
        user.password = password;
        return *this;
    }

    // Metoda zwracająca zbudowanego użytkownika
    User build() {
        return user;
    }
};

// Funkcja wczytująca wszystkich użytkowników z pliku
vector<User> uploadAllUsers() {
    vector<User> userData;
    User buff;
    const string filename = "..\\rejestracja\\dane_pacjentow.txt";

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku." << endl;
        exit(0);
    }
    else {
        while (userData.size() < MaxWords && file >> buff.email >> buff.password) {
            userData.push_back(buff);
        }
        file.close();
    }
    return userData;
}

// Funkcja sprawdzająca unikalność nazwy użytkownika i numeru PESEL
bool isUserUnique(const vector<User>& users, const string& username, const string& id) {
    for (const auto& user : users) {
        if (user.username == username || user.id_number == id) {
            return false;
        }
    }
    return true;
}

// Funkcja wczytująca dane nowego użytkownika
User insertData() {
    vector<User> users = uploadAllUsers();
    string username, password, email, name, surname, adres, id;

    cout << "\n\nWprowadz dane: " << endl;

    cout << "Podaj imie: ";
    getline(cin, name);
    if (!validateLength(name, 40)) {
        cout << "Bledna długość imienia." << endl;
        insertData();
    }

    cout << "Podaj nazwisko: ";
    getline(cin, surname);
    if (!validateLength(surname, 40)) {
        cout << "Bledna
