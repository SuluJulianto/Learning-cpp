#include <iostream>
#include <array>
#include <map>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Cube {
private:
    array<char, 8> letters;
    map<int, int> right;
    map<int, int> left;
    map<int, int> up;
    map<int, int> down;
    vector<int> rotationSequence;

public:
    void show();
    void asString();
    void encrypt();
    void showDirections();
    void decrypt();

private:
    void rotate(int direction);

public:
    Cube(string wordSection);
};

Cube::Cube(string wordSection) {
    int l = wordSection.length();
    for (int i = 0; i < 8; ++i) {
        if (i >= l) {
            letters[i] = '*';
        }
        else {
            letters[i] = wordSection[i];
        }
    }

    right[0] = 3; right[1] = 2; right[2] = 6; right[3] = 7;
    right[4] = 0; right[5] = 1; right[6] = 5; right[7] = 4;

    left[0] = 4; left[1] = 5; left[2] = 1; left[3] = 0;
    left[4] = 7; left[5] = 6; left[6] = 2; left[7] = 3;

    up[0] = 1; up[1] = 5; up[2] = 6; up[3] = 2;
    up[4] = 0; up[5] = 4; up[6] = 7; up[7] = 3;

    down[0] = 4; down[1] = 0; down[2] = 3; down[3] = 7;
    down[4] = 5; down[5] = 1; down[6] = 2; down[7] = 6;

    int nRotations = rand() % 5 + 2;
    for (int i = 0; i < nRotations; ++i) {
        int direction = rand() % 4;
        rotationSequence.push_back(direction);
    }
}

void Cube::show() {
    cout << "  " << letters[5] << "----" << letters[6] << endl;
    cout << " /|   /|\n";
    cout << letters[1] << "----" << letters[2] << " |\n";
    cout << "| " << letters[4] << "  | " << letters[7] << endl;
    cout << "|/   |/ \n";
    cout << letters[0] << "----" << letters[3] << "  \n";
    cout << endl;
}

void Cube::asString() {
    for (int i = 0; i < (int)(letters.size()); ++i) {
        if (letters[i] != '*') {
            cout << letters[i];
        }
    }
}

void Cube::rotate(int direction) {
    array<char, 8> newArr(letters);

    switch (direction) {
    case 0:
        for (int i = 0; i < 8; ++i) {
            newArr[right[i]] = letters[i];
        }
        break;
    case 1:
        for (int i = 0; i < 8; ++i) {
            newArr[left[i]] = letters[i];
        }
        break;
    case 2:
        for (int i = 0; i < 8; ++i) {
            newArr[up[i]] = letters[i];
        }
        break;
    case 3:
        for (int i = 0; i < 8; ++i) {
            newArr[down[i]] = letters[i];
        }
        break;
    }
    letters = newArr;
}

void Cube::encrypt() {
    for (int i = 0; i < (int)(rotationSequence.size()); ++i) {
        rotate(rotationSequence[i]);
    }
}

void Cube::showDirections() {
    for (int i = 0; i < (int)(rotationSequence.size()); ++i) {
        if (i != 0) cout << ":";
        switch (rotationSequence[i]) {
        case 0:
            cout << "R";
            break;
        case 1:
            cout << "L";
            break;
        case 2:
            cout << "U";
            break;
        case 3:
            cout << "D";
            break;
        }
    }
}

void Cube::decrypt() {
    for (int i = (int)(rotationSequence.size()) - 1; i >= 0; --i) {
        switch (rotationSequence[i]) {
        case 0:
            rotate(1);
            break;
        case 1:
            rotate(0);
            break;
        case 2:
            rotate(3);
            break;
        case 3:
            rotate(2);
            break;
        }
    }
}

class CubeHandler {
private:
    int nCubes;
    int inputWordLength;
    vector<Cube*> cubes;

public:
    void show();
    void encryptCubes();
    void showDirectionSequence();
    void decrypt();

public:
    CubeHandler(string inputWord);
    ~CubeHandler();
};

CubeHandler::CubeHandler(string inputWord)
    : inputWordLength(inputWord.length()) {
    nCubes = inputWordLength % 8 ? inputWordLength / 8 + 1 : inputWordLength / 8;
    int mult = 0;
    do {
        if (inputWordLength >= 8 * (mult + 1)) {
            cubes.push_back(new Cube(inputWord.substr(8 * mult, 8)));
            if (inputWordLength == 8 * (mult + 1)) break;
        }
        else {
            int diff;
            if (inputWordLength < 8)
                diff = inputWordLength;
            else
                diff = inputWordLength - 8;
            cubes.push_back(new Cube(inputWord.substr(8 * mult, diff)));
            break;
        }
        mult++;
    } while (true);
}

CubeHandler::~CubeHandler() {
    for (int i = 0; i < (int)(cubes.size()); ++i) {
        delete cubes[i];
    }
}

void CubeHandler::show() {
    int l = cubes.size();
    for (int i = 0; i < l; ++i) {
        cubes[i]->show();
    }
    for (int i = 0; i < l; ++i) {
        cubes[i]->asString();
    }
    cout << endl << endl;
}

void CubeHandler::encryptCubes() {
    cout << "Encrypting..." << endl;
    for (int i = 0; i < nCubes; ++i) {
        cubes[i]->encrypt();
    }
}

void CubeHandler::showDirectionSequence() {
    for (int i = 0; i < (int)(cubes.size()); ++i) {
        if (i != 0) cout << ",";
        cout << i;
        cubes[i]->showDirections();
    }
    cout << endl;
}

void CubeHandler::decrypt() {
    cout << "Decrypting..." << endl;
    for (int i = 0; i < nCubes; ++i) {
        cubes[i]->decrypt();
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "Thank you so much!\n It was such a fun and challenging assigment.\nHappy coding to all, and congrats to the other codes" << endl << endl;

    string word = "";
    getline(cin, word);
    if (word.length() == 0)
        word = "Enter your own String to Encrypt!";

    CubeHandler ch(word);
    ch.show();

    ch.encryptCubes();
    ch.showDirectionSequence();
    ch.show();

    ch.decrypt();
    ch.show();

    return 0;
}
