#include <iostream>
#include<cctype>

using namespace std;

bool getValidShot(char& row, int& col);

int main() {
	char row;
	int col;

	if (getValidShot(row, col)) {
		cout << "You called" << row << col << endl;
		cout << "You sasnk my battleship1" << endl;
	}

	return 0;
}

bool getValidShot(char& row, int& col) {
	row = ' ';
	col = 0;
	do {
		cout << "enter your shot [A-J][1-10]: ";
		cin >> row;
		row = static_cast<char>(toupper(static_cast<int>(row)));
		if (row < 'A' || row> 'J') {
			row = ' ';
			cout << "Invalid row. Please try again." << endl;
		}
		cin >> col;
		if (cin.fail()||col < '1' || col > '10') {
			cin.clear();
			cin.ignore(256, '\n');
		row = 0;
		cout << "Invalid column. Please try again." << endl;
		}
	} while (row == ' ' || col == 0);
	return true;

}