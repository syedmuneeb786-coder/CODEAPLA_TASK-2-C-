#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;
    cout << "Register\nUsername: "; cin >> username;
    cout << "Password: "; cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();
    cout << "Registration successful!\n";
}

void loginUser() {
    string username, password, u, p;
    cout << "Login\nUsername: "; cin >> username;
    cout << "Password: "; cin >> password;

    ifstream file("users.txt");
    bool success = false;
    while (file >> u >> p) {
        if (u == username && p == password) {
            success = true;
            break;
        }
    }
    file.close();
    if (success) cout << "Login successful!\n";
    else cout << "Login failed. Check your credentials.\n";
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nChoose: ";
    cin >> choice;
    if (choice == 1) registerUser();
    else if (choice == 2) loginUser();
    else cout << "Invalid choice\n";
    return 0;
}

