#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>

using namespace std;

// Constants
const int GRID_SIZE = 5;

// Function Prototypes
void initializeGrid(vector<vector<char>>& grid);
void displayGrid(const vector<vector<char>>& grid);
void placeShip(int& shipRow, int& shipCol);
bool getPlayerShot(char& rowChar, int& col);
bool checkHit(int shipRow, int shipCol, int row, int col);
int rowToIndex(char rowChar);

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed for random ship placement

    // Game grid and variables
    vector<vector<char>> grid(GRID_SIZE, vector<char>(GRID_SIZE, '-'));
    int shipRow, shipCol;
    bool gameWon = false;
    int attempts = 0;

    // Initialize game
    initializeGrid(grid);
    placeShip(shipRow, shipCol); // Randomly place a single ship

    cout << "Welcome to Battleship!" << endl;
    cout << "Try to sink the hidden ship by guessing its location on a 5x5 grid!" << endl;

    // Main game loop
    while (!gameWon) {
        displayGrid(grid);

        // Get player input
        char rowChar;
        int col;
        if (!getPlayerShot(rowChar, col)) {
            cout << "Invalid input. Try again!" << endl;
            continue;
        }

        int row = rowToIndex(rowChar);
        attempts++;

        // Check if the shot is a hit or miss
        if (checkHit(shipRow, shipCol, row, col)) {
            grid[row][col] = 'H'; // Mark hit
            gameWon = true;
            cout << "Congratulations! You sank the ship in " << attempts << " attempts!" << endl;
        }
        else {
            grid[row][col] = 'M'; // Mark miss
            cout << "Miss! Try again." << endl;
        }
    }

    displayGrid(grid);
    return 0;
}

// Initialize grid with empty cells
void initializeGrid(vector<vector<char>>& grid) {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            grid[i][j] = '-';
        }
    }
}

// Display the current state of the grid
void displayGrid(const vector<vector<char>>& grid) {
    cout << "  ";
    for (int col = 1; col <= GRID_SIZE; ++col) {
        cout << col << " ";
    }
    cout << endl;

    for (int row = 0; row < GRID_SIZE; ++row) {
        cout << static_cast<char>('A' + row) << " ";
        for (int col = 0; col < GRID_SIZE; ++col) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Randomly place a ship on the grid
void placeShip(int& shipRow, int& shipCol) {
    shipRow = rand() % GRID_SIZE;
    shipCol = rand() % GRID_SIZE;
}

// Get the player's shot (letter and number)
bool getPlayerShot(char& rowChar, int& col) {
    cout << "Enter your shot (row [A-E] and column [1-5], e.g., B3): ";
    string input;
    cin >> input;

    // Validate input length
    if (input.length() < 2 || input.length() > 3) {
        return false;
    }

    rowChar = static_cast<char>(toupper(input[0])); // Convert row to uppercase
    try {
        col = stoi(input.substr(1)) - 1; // Convert column to 0-based index
    }
    catch (...) {
        return false; // Handle non-numeric column
    }

    // Validate row and column
    if (rowChar < 'A' || rowChar > 'E' || col < 0 || col >= GRID_SIZE) {
        return false;
    }

    return true;
}

// Convert row character to grid index
int rowToIndex(char rowChar) {
    return rowChar - 'A';
}

// Check if the player's shot hits the ship
bool checkHit(int shipRow, int shipCol, int row, int col) {
    return row == shipRow && col == shipCol;
}
