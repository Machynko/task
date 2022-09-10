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
using std::ifstream;

int findSum(string str)
{
    // A temporary string
    string temp = "";

    // holds sum of all numbers present in the string
    int sum = 0;
    char* pEnd;

    // read each character in input string
    for (char ch : str) {
        // if current character is a digit
        if (isdigit(ch))
            temp += ch;

            // if current character is an alphabet
        else {
            // increment sum by number found earlier
            // (if any)
            sum += strtoll(temp.c_str(), &pEnd, 10);

            // reset temporary string to empty
            temp = "";
        }
    }

    // atoi(temp.c_str()) takes care of trailing
    // numbers
    return sum + strtoll(temp.c_str(), &pEnd, 10);
}


int main() {

    // Initializing random number generator in C++

    srand(time(0));
    int random_numbers;
    long long int array[5000];
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

    long long int sum = 0;
    char* pEnd;

   for (int k = 0; k < 19; k++) {
        array[k] = strtoull(arr[k].c_str(), &pEnd, 10);
        cout << array[k] << endl;   // stoi function is converting string elements to integers elements
        sum = sum + array[k];
    }

   cout << endl;
   cout << "Summary of first 19 generated numbers  is " << sum ;






    return 0;
}