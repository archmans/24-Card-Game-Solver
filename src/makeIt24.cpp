// 24 Game Solver
// Created by: Muhammad Salman Hakim Alfarisi (13521010) K-03

#include <iostream>
#include <time.h>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;
string input1, input2, input3, input4;

void readInputs(){
    cout << "Masukkan 4 kartu (A, J, Q, K, 2-10)" << endl;
    cin >> input1 >> input2 >> input3 >> input4;
}

double convertInputs(string x){
    /* I.S. menerima input string dari kartu*/
    /* F.S. mengembalikan nilai kartu dalam tipe double */
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
    /* I.S. menerima input string dari kartu*/
    /* F.S. mengembalikan true jika input valid, false jika tidak */
    if (x == "A" || x == "J" || x == "Q" || x == "K" || x == "2" || x == "3" || x == "4" || x == "5" || x == "6" || x == "7" || x == "8" || x == "9" || x == "10") {
        return true;
    } else {
        return false;
    }
}

double zeroDiv(int a, int b){
    /* I.S. menerima input pembilang dan penyebut*/
    /* F.S. mengembalikan hasil pembagian jika penyebut 0 serta mengembalikan nilai 0 jika pembagi bernilai 0 */
    if (b == 0) {
        return 0;
    } else {
        return (double) a/b;
    }
}

double calc(double a, double b, int op){
    /* I.S. menerima input dua bilangan dan operator ekspresi*/
    /* F.S. mengembalikan hasil perhitungan */
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

bool checkDuplicate(vector <string> v, string s){
    /* I.S. menerima input vector dan string*/
    /* F.S. mengembalikan true jika string ada di vector (duplicate), false jika tidak */
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == s){
            return true;
        }
    }
    return false;
}

void printResult(vector <string> v){
    /* I.S. menerima input vector result*/
    /* F.S. menampilkan vector result */
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}

string exp(int sign) {
    /* I.S. menerima input ekspresi operator dalam bentuk integer*/
    /* F.S. mengembalikan ekspresi operator dalam bentuk string */
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

void solver24(int a, int b, int c, int d, vector <string> *result){
    /* I.S. menerima input 4 bilangan dan vector result*/
    /* F.S. mengembalikan vector result yang berisi semua kemungkinan ekspresi yang menghasilkan 24 */
    int arr[4] = {a, b, c, d}; // array of input
    string tempResult = ""; // temporary result
    for(int i = 0; i < 4; i++){ // loop input 
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                for(int l = 0; l < 4; l++){ // loop operator
                    for(int op1 = 1; op1 < 5; op1++){
                        for(int op2 = 1; op2 < 5; op2++){
                            for(int op3 = 1; op3 < 5; op3++){
                                if (i != j && i != k && i != l && j != k && j != l && k != l){ // handle duplicate of input loop
                                    // calculate all possible combination of brackets
                                    // type 1
                                    // (a op1 b) op2 (c op3 d)
                                    double res = calc(calc(arr[i], arr[j], op1), calc(arr[k], arr[l], op3), op2);
                                    if (res == 24){
                                        tempResult = "(" + to_string(arr[i]) + exp(op1) + to_string(arr[j]) + ")" + exp(op2) + "(" + to_string(arr[k]) + exp(op3) + to_string(arr[l]) + ")";
                                        if (!checkDuplicate(*result, tempResult)){
                                            result->push_back(tempResult);
                                        }
                                    }
                                    // type 2
                                    // ((a op1 b) op2 c) op3 d
                                    res = calc(calc(calc(arr[i], arr[j], op1), arr[k], op2), arr[l], op3);
                                    if (res == 24){
                                        tempResult = "((" + to_string(arr[i]) + exp(op1) + to_string(arr[j]) + ")" + exp(op2) + to_string(arr[k]) + ")" + exp(op3) + to_string(arr[l]);
                                        if (!checkDuplicate(*result, tempResult)){
                                            result->push_back(tempResult);
                                        }
                                    }
                                    // type 3
                                    // (a op1 (b op2 c)) op3 d
                                    res = calc(calc(arr[i], calc(arr[j], arr[k], op2), op1), arr[l], op3);
                                    if (res == 24){
                                        tempResult = "(" + to_string(arr[i]) + exp(op1) + "(" + to_string(arr[j]) + exp(op2) + to_string(arr[k]) + "))" + exp(op3) + to_string(arr[l]);
                                        if (!checkDuplicate(*result, tempResult)){
                                            result->push_back(tempResult);
                                        }
                                    }
                                    // type 4
                                    // a op1 ((b op2 c) op3 d)
                                    res = calc(arr[i], calc(calc(arr[j], arr[k], op2), arr[l], op3), op1);
                                    if (res == 24){
                                        tempResult = to_string(arr[i]) + exp(op1) + "((" + to_string(arr[j]) + exp(op2) + to_string(arr[k]) + ")" + exp(op3) + to_string(arr[l]) + ")";
                                        if (!checkDuplicate(*result, tempResult)){
                                            result->push_back(tempResult);
                                        }
                                    }
                                    // type 5
                                    // a op1 (b op2 (c op3 d))
                                    res = calc(arr[i], calc(arr[j], calc(arr[k], arr[l], op3), op2), op1);
                                    if (res == 24){
                                        tempResult = to_string(arr[i]) + exp(op1) + "(" + to_string(arr[j]) + exp(op2) + "(" + to_string(arr[k]) + exp(op3) + to_string(arr[l]) + "))";
                                        if (!checkDuplicate(*result, tempResult)){
                                            result->push_back(tempResult);
                                        }
                                    }
                                }
                            }
                        }
                    }           
                }
            }
        }
    }
}

void splashScreen(){
    cout << "Welcome to MAKE IT 24!" << endl;
    cout << "This program will solve the Make It 24 game for you." << endl;
    cout << "                           .------. " << endl;
    cout << "        .------.           |A .   | " << endl;
    cout << "        |A_  _ |    .------; / \\  | " << endl;
    cout << "        |( \\/ )|-----. _   |(_,_) | " << endl;
    cout << "        | \\  / | /\\  |( )  |  I  A| " << endl;
    cout << "        |  \\/ A|/  \\ |_x_) |------' " << endl;
    cout << "        `-----+'\\  / | Y  A|        " << endl;
    cout << "              |  \\/ A|-----'        " << endl;
    cout << "              `------'"             << endl;
    cout << "-------------------------------------------" << endl;
    cout << " created by: Muhamad Salman Hakim Alfarisi" << endl;
    cout << "-------------------------------------------" << endl;
}

void writeToFile(vector <string> v, string input1, string input2, string input3, string input4, double timeTaken){
    /* F.S. melakukan save file*/
    string fileName, filePath;
    cout << "Enter the name of the file to save the solutions: ";
    cin >> fileName;
    filePath = "../test/" + fileName;
    ofstream File(filePath + ".txt");
    File << "Solutions for " << input1 << "," << input2 << "," << input3 << "," << input4 << endl;
    File << "Total: " << v.size() << " solutions" << endl;
    File << fixed << setprecision(2);
    File << "Time taken: " << timeTaken << " seconds" << endl;
    File << "************************" << endl;
    for (int i = 0; i < v.size(); i++){
        File << v[i] << endl;
    }
    File.close();
}

int  main (){

    splashScreen();
    int a, b, c, d, input;
    vector <string> result = {};
    cout << "Enter 1 to input your own numbers or 2 to generate random numbers: ";
    cin >> input;
    if (input == 1){
        readInputs();
        while (validInputs(input1) == false || validInputs(input2) == false || validInputs(input3) == false || validInputs(input4) == false){
            cout << "Invalid input. Please try again." << endl;
            readInputs();
        }
        a = convertInputs(input1); b = convertInputs(input2); c = convertInputs(input3); d = convertInputs(input4);

        // runtime
        clock_t start = clock();
        solver24(a, b, c, d, &result);

        if (result.size() == 0){
            cout << "No solution" << endl;
        } else {
            printResult(result);
            cout << "Total: " << result.size() << " solutions" << endl;
        }

        double time_taken = double(clock() - start) / double(CLOCKS_PER_SEC);
        printf("Time taken: %.2fs\n", time_taken);

        cout << "Do you want to save the solutions to a file? (1 for yes, 2 for no): ";
        cin >> input;
        if (input == 1){
            writeToFile(result, input1, input2, input3, input4, time_taken);
        }
    }
    if (input == 2){
        //random inputs
        srand(time(NULL));
        a = rand() % 13 + 1; b = rand() % 13 + 1; c = rand() % 13 + 1; d = rand() % 13 + 1;
        cout << "Your numbers are: " << a << " " << b << " " << c << " " << d << endl;

        // runtime
        clock_t start = clock();
        solver24(a, b, c, d, &result);
        if (result.size() == 0){
            cout << "No solution" << endl;
        } else {
            printResult(result);
            cout << "Total: " << result.size() << " solutions" << endl;
        }
        double time_taken = double(clock() - start) / double(CLOCKS_PER_SEC);
        printf("Time taken: %.2fs\n", time_taken);

        cout << "Do you want to save the solutions to a file? (1 for yes, 2 for no): ";
        cin >> input;
        if (input == 1){
            writeToFile(result, to_string(a), to_string(b), to_string(c), to_string(d), time_taken);
        }
    }
    if (input == 3){
        cout << "Thank you for using Make It 24!" << endl;
        exit(0);
    }
}
