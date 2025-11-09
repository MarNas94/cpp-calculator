#include <iostream>
using namespace std;

int main() {
    double a, b;
    char oper;

    cout << "=== Prosty kalkulator ===" << endl;
    cout << "Podaj pierwsza liczbe: ";
    cin >> a;
    cout << "Podaj operator (+, -, *, /): ";
    cin >> oper;
    cout << "Podaj druga liczbe: ";
    cin >> b;

    cout << "Wynik: ";

    switch (oper) {
        case '+':
            cout << a + b;
            break;
        case '-':
            cout << a - b;
            break;
        case '*':
            cout << a * b;
            break;
        case '/':
            if (b != 0)
                cout << a / b;
            else
                cout << "Blad: dzielenie przez zero!";
            break;
        default:
            cout << "Nieznany operator!";
    }

    cout << endl;
    return 0;
}
