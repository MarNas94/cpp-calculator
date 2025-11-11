#include <iostream>
#include <cmath>     // sqrt(), pow(), log10()
#include <limits>    // numeric_limits
using namespace std;

// Funkcja pomocnicza do bezpiecznego wczytywania liczby
double wczytajLiczbe(const string& komunikat) {
    double x;
    while (true) {
        cout << komunikat;
        cin >> x;
        if (cin.fail()) {
            cout << "Błąd: proszę podać prawidłową liczbę!" << endl;
            cin.clear(); // czyści flagę błędu
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // usuwa błędne dane z bufora
        } else {
            return x;
        }
    }
}

int main() {
    double a, b;
    char oper;
    bool kontynuuj = true;

    cout << "=== Kalkulator zaawansowany ===" << endl;
    cout << "Dostępne operacje:" << endl;
    cout << "+  - dodawanie" << endl;
    cout << "-  - odejmowanie" << endl;
    cout << "*  - mnożenie" << endl;
    cout << "/  - dzielenie" << endl;
    cout << "p  - potęgowanie (a^b)" << endl;
    cout << "s  - pierwiastek kwadratowy" << endl;
    cout << "l  - logarytm dziesiętny (log10)" << endl;
    cout << "q  - wyjście z programu" << endl;

    while (kontynuuj) {
        cout << "\nPodaj operator: ";
        cin >> oper;

        switch (oper) {
            case '+':
            case '-':
            case '*':
            case '/':
            case 'p':
                a = wczytajLiczbe("Podaj pierwszą liczbę: ");
                b = wczytajLiczbe("Podaj drugą liczbę: ");
                cout << "Wynik: ";
                if (oper == '+') cout << a + b;
                else if (oper == '-') cout << a - b;
                else if (oper == '*') cout << a * b;
                else if (oper == '/') {
                    if (b != 0)
                        cout << a / b;
                    else
                        cout << "Błąd: dzielenie przez zero!";
                }
                else if (oper == 'p') cout << pow(a, b);
                cout << endl;
                break;

            case 's':
                a = wczytajLiczbe("Podaj liczbę do spierwiastkowania: ");
                if (a >= 0)
                    cout << "Wynik: " << sqrt(a) << endl;
                else
                    cout << "Błąd: nie można pierwiastkować liczby ujemnej!" << endl;
                break;

            case 'l':
                a = wczytajLiczbe("Podaj liczbę do obliczenia log10: ");
                if (a > 0)
                    cout << "Wynik: " << log10(a) << endl;
                else
                    cout << "Błąd: logarytm z liczby niedodatniej nie istnieje!" << endl;
                break;

            case 'q':
                kontynuuj = false;
                cout << "Zamykanie kalkulatora..." << endl;
                break;

            default:
                cout << "Nieznany operator! Spróbuj ponownie." << endl;
        }
    }

    return 0;
}
