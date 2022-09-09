#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;
using std::string;
using std::stringstream;
using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream;

int main() {

    // Initializing random number generator in C++

    srand(time(0));
    int random_numbers;
    int array[5000];
    int negattiv[18] = {-9,-8,-7,-6,-5,-4,-3,-2,-1,1,2,3,4,5,6,7,8, 9};


    // Initializing a txt. file for filling it with random numbers

    ofstream generator("example.txt");


    cout << "Random numbers from 1 digit to 50 digits:" << endl;

    // Statement for opened file and generating random numbers with a negative sing/positive sign

    if (generator.is_open()) {

        for (int x = 0; x < 50; x++) {

            int RandIndex = rand() % 18;
            generator << negattiv[RandIndex];

            for (int j = 1; j <= x; j++) {
                random_numbers = 1 + (rand() % 9);
                generator << random_numbers;

            }
            generator << "\n";

        }
        generator.close();
    } else cout << "Unable to open file";


    int num;
    string arr[5000];
    int i = 0;
    string line;

    ifstream file("example.txt");



    // Opening a file and reading lines of generated numbers to array (string to int?)

    if (file.is_open()) {

        while (!file.eof()) {

            getline(file, line);
            arr[i] = line;
            i++;
        }
        file.close();
    } else cout << "Unable to open file";

    // Printing a string array of generated numbers converting first 9 elements to integers

    int sum = 0;

    for (int k = 0; k < 9; k++) {
        array[k] = stoi(arr[k]);        // stoi function is converting string elements to integers elements
        cout << array [k] << endl;
        sum = sum + array [k];
    }
    cout << endl;
    cout << "Summary of first 9 generated numbers  is " << sum ;


    return 0;
}