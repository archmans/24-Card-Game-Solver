#include "operations.cpp"
#include "solver24.cpp"

int  main (){
    splashScreen();
    int a, b, c, d, input, inputF;
    string input1, input2, input3, input4;
    vector <string> result = {};
    cout << "Enter 1 to input your own cards or 2 to generate random cards: ";
    cin >> input;
    if (input == 1){
        cout << "Input 4 cards (A, J, Q, K, 2-10), separate with space" << endl;
        cin >> input1 >> input2 >> input3 >> input4;
        while (validInputs(input1) == false || validInputs(input2) == false || validInputs(input3) == false || validInputs(input4) == false){
            cout << "Invalid input. Please try again." << endl;
            cout << "Input 4 cards (A, J, Q, K, 2-10), separate with space" << endl;
            cin >> input1 >> input2 >> input3 >> input4;
        }
        a = convertInputs(input1); b = convertInputs(input2); c = convertInputs(input3); d = convertInputs(input4);

        // runtime
        clock_t start = clock();
        solver24(a, b, c, d, &result);
        totalSolutions(result);
        double runtime = double(clock() - start) / double(CLOCKS_PER_SEC);
        printf("Runtime : %.3fs\n", runtime);

        cout << "Do you want to save the solutions to a file? (1 for yes, 2 for no): ";
        cin >> inputF;
        if (inputF == 1){
            writeToFile(result, input1, input2, input3, input4, runtime);
        } else if (inputF == 2){
            cout << "Thank you for using Make It 24!" << endl;
            exit(0);
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
        totalSolutions(result);
        double runtime = double(clock() - start) / double(CLOCKS_PER_SEC);
        printf("Runtime : %.3fs\n", runtime);

        cout << "Do you want to save the solutions to a file? (1 for yes, 2 for no): ";
        cin >> inputF;
        if (inputF == 1){
            writeToFile(result, to_string(a), to_string(b), to_string(c), to_string(d), runtime);
        }   else if (inputF == 2){
            cout << "Thank you for using Make It 24!" << endl;
            exit(0);
        }
    }
    if (input == 3){
        cout << "Thank you for using Make It 24!" << endl;
        exit(0);
    } 
}