#include "operations.hpp"

void splashScreen(){
    cout << "----------------------------------------------------" << endl;
    cout << "              Welcome to MAKE IT 24!                " << endl;
    cout << "This program will solve the Make It 24 game for you." << endl;
    cout << "                               .------.             " << endl;
    cout << "            .------.           |A .   |             " << endl;
    cout << "            |A_  _ |    .------; / \\  |            " << endl;
    cout << "            |( \\/ )|-----. _   |(_,_) |            " << endl;
    cout << "            | \\  / | /\\  |( )  |  I  A|           " << endl;
    cout << "            |  \\/ A|/  \\ |_x_) |------'           " << endl;
    cout << "            `-----+'\\  / | Y  A|                   " << endl;
    cout << "                  |  \\/ A|-----'                   " << endl;
    cout << "                  `------'                          " << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "     created by: Muhamad Salman Hakim Alfarisi      " << endl;
    cout << "----------------------------------------------------" << endl;
}

double convertInputs(string x){
    double y;
    if (x == "A"){
        y = 1.0;
    } 
    if (x == "J"){
        y = 11.0;
    }
    if (x == "Q"){
        y = 12.0;
    }
    if (x == "K"){
        y = 13.0;
    } 
    if (x == "2"){
        y = 2.0;
    }
    if (x == "3"){
        y = 3.0;
    }
    if (x == "4"){
        y = 4.0;
    }
    if (x == "5"){
        y = 5.0;
    }
    if (x == "6"){
        y = 6.0;
    }
    if (x == "7"){
        y = 7.0;
    }
    if (x == "8"){
        y = 8.0;
    }
    if (x == "9"){
        y = 9.0;
    }
    if (x == "10"){
        y = 10.0;
    }
    return y;
}

bool validInputs(string x){
    if (x == "A" || x == "J" || x == "Q" || x == "K" || x == "2" || x == "3" || x == "4" || x == "5" || x == "6" || x == "7" || x == "8" || x == "9" || x == "10") {
        return true;
    } else {
        return false;
    }
}

double zeroDiv(int a, int b){
    if (b == 0) {
        return 0;
    } else {
        return (double) a/b;
    }
}

double calc(double a, double b, int op){
    if (op == 1) {
        return a + b;
    } else if (op == 2) {
        return a - b;
    } else if (op == 3) {
        return a * b;
    } else {
        return zeroDiv(a, b);
    }
}

bool checkDuplicate(vector <string> result, string temporary){
    for (int i = 0; i < result.size(); i++) {
        if (result[i] == temporary){
            return true;
        }
    }
    return false;
}

void printResult(vector <string> result){
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}

string exp(int sign){
    if (sign == 1){
        return "+";
    } else if (sign == 2){
        return "-";
    } else if (sign == 3){
        return "*";
    } else {
        return "/";
    }
}

void totalSolutions(vector <string> result){
    if (result.size() == 0){
        cout << "No solution" << endl;
    } else {
        printResult(result);
        cout << "Total : " << result.size() << " solutions" << endl;
    }
}

void writeToFile(vector <string> result, string input1, string input2, string input3, string input4, double runtime){
    string fileName, filePath;
    cout << "Enter the name of the file to save the solutions: ";
    cin >> fileName;
    filePath = "../test/" + fileName;
    ofstream File(filePath + ".txt");
    File << "************************" << endl;
    File << "       Make It 24!      " << endl;
    File << "Solutions for " << input1 << "," << input2 << "," << input3 << "," << input4 << endl;
    File << "Total : " << result.size() << " solutions" << endl;
    File << fixed << setprecision(3);
    File << "Runtime : " << runtime << " seconds" << endl;
    File << "************************" << endl;
    for (int i = 0; i < result.size(); i++){
        File << result[i] << endl;
    }
    File.close();
}