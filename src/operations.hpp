#include <iostream>
#include <time.h>  // random and runtime
#include <vector>  // vector of string result
#include <fstream> // write to file
#include <iomanip> // setprecision of runtime

using namespace std;

#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

double convertInputs(string x);
    /* I.S. Receive input string from card*/
    /* F.S. Return card value in double type */
bool validInputs(string x);
    /* I.S. Receive input string from card*/
    /* F.S. Return true if input valid, false if not */

double zeroDiv(int a, int b);
    /* I.S. Receive 2 integer*/
    /* F.S. Return 0 if b = 0, else return a/b */

double calc(double a, double b, int op);
    /* I.S. Receive 2 double of numbers and 1 integer of operation */
    /* F.S. Return result of calculation */

bool checkDuplicate(vector <string> result, string temporary);
    /* I.S. Receive 1 vector and 1 string*/
    /* F.S. Return true if string is already in vector, false if not in the vector */

void printResult(vector <string> result);
    /* I.S. Receive 1 vector*/
    /* F.S. Print all element in vector */

string exp(int sign);
    /* I.S. Receive 1 integer*/
    /* F.S. Return string of operator */

void splashScreen();
    /* I.S. None*/
    /* F.S. Print splash screen */

void totalSolutions(vector <string> result);
    /* I.S. Receive 1 vector*/
    /* F.S. Print total solutions */

void writeToFile(vector <string> result, string input1, string input2, string input3, string input4, double runtime);
    /* I.S. Receive 1 vector, 4 string, and 1 double*/
    /* F.S. Write all element in vector to file */

#endif