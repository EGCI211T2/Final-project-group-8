#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

#include "queue.h"
#include "stack.h"

using namespace std;

void classifyWaste(Queue& wasteQueue, Stack& binStack)
 {
    string choice;
    string wasteTypes[] = {"Plastic", "Paper", "Glass", "Metal", "Organic"};
    cout<<"Input Waste:(Plastic, Paper, Glass, Metal, Organic):";
    cin>>choice;
   
     
      bool matched = false;
    for (const string& waste : wasteTypes) {
        if (waste == choice) {
            wasteQueue.enqueue(waste);
            matched = true;
            break;
        }
    }

    if (!matched) {
        cout << "Unrecognized waste type!" << endl;
        return;
    }

    cout << "Wastes: ";
    wasteQueue.display();


    while(!wasteQueue.isEmpty()) {
    string waste = wasteQueue.dequeue();
    cout << "Matching " << waste << " waste... ";

        if (waste == "Plastic" || waste == "Paper") {
            binStack.push("General Waste Bin");
            cout << "Matched to General Waste Bin" << endl;
        } else if (waste == "Glass" || waste == "Metal") {
            binStack.push("Hazardous Waste Bin");
            cout << "Matched to Hazardous Waste Bin" << endl;
        } else if (waste == "Organic") {
            binStack.push("Wet Waste Bin");
            cout << "Matched to Wet Waste Bin" << endl;
        } else {
            cout << "Unrecognized waste type!" << endl;
        }
    }
cout << endl << "Bins matched: " << endl;
    while (!binStack.isEmpty()) {
        cout << binStack.pop() << endl;      
 }
    }
int main() {
    srand(time(0)); // seed for random number generation

    Queue wasteQueue;
    Stack binStack(5); // Assuming there are 5 types of bins

    classifyWaste(wasteQueue, binStack);

    return 0;
}
