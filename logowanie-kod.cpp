#include <iostream>
#include <string>
#include <vector>

class SystemLogowania {
private:
    // Przykładowa baza danych użytkowników
    std::vector<std::pair<std::string, std::string>> bazaDanych = {
        {"user1", "password1"},
        {"user2", "password2"},
        // Dodaj więcej użytkowników według potrzeb
    };

public:
    void odczytajDane(std::string& nazwaUzytkownika, std::string& haslo) {
        std::cout << "Podaj nazwę użytkownika: ";
        std::cin >> nazwaUzytkownika;
        std::cout << "Podaj hasło: ";
        std::cin >> haslo;
    }

    void przeslijDane(std::string nazwaUzytkownika, std::string haslo) {
        // Przesłanie danych do systemu (możesz dostosować tę funkcję)
        // W tym przypadku, porównanie z bazą danych
        if (weryfikacjaDanych(nazwaUzytkownika, haslo)) {
            std::cout << "Dane zweryfikowane. Logowanie udane.\n";
        } else {
            bladLogowania();
        }
    }

    bool weryfikacjaDanych(const std::string& nazwaUzytkownika, const std::string& haslo) {
        for (const auto& para : bazaDanych) {
            if (para.first == nazwaUzytkownika && para.second == haslo) {
                return true; // Dane są poprawne
            }
        }
        bladWeryfikacji();
        return false; // Dane są niepoprawne
    }

    void bladWeryfikacji() {
        std::cout << "Błąd weryfikacji danych. Użytkownik o podanej nazwie lub haśle nie istnieje.\n";
    }

    void bladLogowania() {
        std::cout << "Błąd logowania. Spróbuj ponownie.\n";
    }

    void koniecPrzypadku() {
        std::cout << "Koniec przypadku.\n";
    }
};

int main() {
    SystemLogowania system;

    std::string nazwaUzytkownika, haslo;
    
    system.odczytajDane(nazwaUzytkownika, haslo);
    system.przeslijDane(nazwaUzytkownika, haslo);
    
    // Pozostałe kroki logowania

    system.koniecPrzypadku();

    return 0;
}
