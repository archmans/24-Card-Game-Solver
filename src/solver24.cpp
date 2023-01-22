#include "solver24.hpp"

void solver24(int a, int b, int c, int d, vector <string> *result){
    double res; // result of calculation
    int arr[4] = {a, b, c, d}; // array of input
    string tempResult; // temporary result
    for(int i = 0; i < 4; i++){ // loop input 
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                for(int l = 0; l < 4; l++){
                    for(int op1 = 1; op1 < 5; op1++){ // loop operator
                        for(int op2 = 1; op2 < 5; op2++){
                            for(int op3 = 1; op3 < 5; op3++){
                                if (i != j && i != k && i != l && j != k && j != l && k != l){ // handle duplicate of input loop
                                    // calculate all possible combination of brackets
                                    // type 1
                                    // (a op1 b) op2 (c op3 d)
                                    res = calc(calc(arr[i], arr[j], op1), calc(arr[k], arr[l], op3), op2);
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