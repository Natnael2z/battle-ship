#include <iostream>
#include <cctype>

using namespace std;

bool getValidShot(char& row, int& col);

int main() {
    char row;
    int col;

    if (getValidShot(row, col)) {
        cout << "You called " << row << col << endl;
        cout << "You sank my battleship!" << endl;
    }

    return 0;
}

bool getValidShot(char& row, int& col) {
    row = ' ';
    col = 0;

    while (true) {
        cout << "Enter your shot [A-J][1-10]: ";
        cin >> row >> col;

        // Convert row to uppercase for consistency
        row = static_cast<char>(toupper(row));

        // Validate the row
        if (row < 'A' || row > 'J') {
            cout << "Invalid row. Please enter a letter between A and J." << endl;
            cin.clear();
            cin.ignore(256, '\n');
            continue;
        }

        // Validate the column
        if (cin.fail() || col < 1 || col > 10) {
            cout << "Invalid column. Please enter a number between 1 and 10." << endl;
            cin.clear();
            cin.ignore(256, '\n');
            continue;
        }

        // If both row and column are valid, break the loop
        break;
    }

    return true;
}
