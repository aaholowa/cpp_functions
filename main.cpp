#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

// function prototypes
char display();
char uppercase(char c);
void print_list(vector <int> vec);
void add(vector <int> &vec); // pass by reference
void mean(vector <int> vec);
void smallest(vector <int> vec);
void largest(vector <int> vec);




int main(){
    static vector <int> list {};
    char choice {};

    while(true){
        choice = display();
        if(choice == 'P'){
            print_list(list);
        }
        else if(choice == 'A'){
            add(list);
        }
        else if(choice == 'M'){
            mean(list);
        }
        else if(choice == 'S'){
            smallest(list);
        }
        else if(choice == 'L'){
            largest(list);
        }
        else if(choice == 'C'){
            list.clear();
            cout << "The list is cleared - []";
        }
        else if(choice == 'Q'){
            break; // end program
        }
        else{
            cout << "Unknown selection, please try again." << endl;
        }
    }

    cout << "Goodbye";
    return 0;

}


// function definitions

// display menu
char display(){
    char choice {};
    cout << endl;
    cout << "Please select an option: " << endl;
    cout << "P - Print Numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean" << endl;
    cout << "S - display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "C - Clear the elements in the list" << endl;
    cout << "Q - Quit" << endl;
    cout << "Selection: ";
    cin >> choice;
    cout << endl;
    return uppercase(choice);
}


// convert user choice to uppercase
char uppercase(char c){ // pass by reference
    char upper {};
    upper = toupper(c);
    return upper;
}


// display list
void print_list(vector <int> vec){

    if (vec.size() == 0){
        cout << "[] - The current list is empty" << endl;
    }
    else{
        cout << "Current List: " << "[ ";
        for(int i :vec){
            cout << i << ' ';
        }
        cout << "]" << endl;
    }
}

// add number to list
void add(vector <int> &vec){ // pass by reference to  update the list
    int number {};
    cout << "Please enter a number to add to the list: ";
    cin >> number;
    vec.push_back(number);
    cout << number << " added to list" << endl;
}

// calculate and display mean for the list
void mean(vector <int> vec){
    double sum {};
    double mean {};

    if (vec.size() == 0){
        cout << "Unable to calculate mean - list is empty" << endl;
    }
    else{
        for (int i {0}; i < vec.size(); ++i){
            sum += vec.at(i);
        }
        mean = sum/vec.size();
        cout << "The mean value for the list is: " << mean << endl;
    }



}

// find and display the smallest number in list
void smallest(vector <int> vec){
    int min {};

    if (vec.size() != 0){
        min = vec.at(0);
        for (int i {0}; i < vec.size(); ++i){
            if (vec.at(i) < min){
                min = vec.at(i);
            }
        }
        cout << "The smallest number is: " << min << endl;
    }
    else{
        cout << "Unable to determine smallest number - list is empty" << endl;
    }

}

// find and display the largest number in list
void largest(vector <int> vec){
    int max {};

    if (vec.size() != 0){
        max = vec.at(0);
        for (int i {0}; i < vec.size(); ++i){
            if (vec.at(i) > max){
                max = vec.at(i);
            }
        }
        cout << "The largest number is: " << max << endl;
    }
    else{
        cout << "Unable to determine largest number - list is empty" << endl;
    }

}




