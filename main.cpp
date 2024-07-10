#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <vector>

// Include the appropriate headers for Windows and Unix-like systems
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// Cross-platform sleep function
void sleep_ms(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000); // usleep takes microseconds
#endif
}


#include "queue.h"
#include "stack.h"
#include "sorting.h"

using namespace std;

void classifyWaste(Queue& wasteQueue, Stack& binStack)
 {
    int i = 1;
    int point = 0;
    int ratio[4][2];
    std::string binTypes[] = {"General Waste Bin", "Hazardous Waste Bin", "Wet Waste Bin", "Unrecognized Waste type"};
    for(int i=0;i<4;i++){ ratio[i][0] = 0; ratio[i][1] = 0; }
    while(!wasteQueue.isEmpty()) {
	std::string choice;
    	string waste = wasteQueue.dequeue();

    std::cout << "\n\n\n";
	std::cout << "(a). General Waste Bin\n";
	std::cout << "(b). Hazardous Waste Bin\n";
	std::cout << "(c). Wet Waste Bin\n";
	std::cout << "(d). None of the above\n";
    cout << i << ". "<< waste << ": ";
	cin >> choice;


    if (choice == "q" || choice == "Q") {
            cout << "\n\nQuit the game! \n";
            break;
        }

    if (waste == "Plastic bottle" || waste == "Stained pizza box" || waste == "Styrofoam" || waste == "Clothes" || waste == "Toilet paper") 
	{
        if(choice == "a")
		{	
			point++;
			ratio[0][0]++;
			cout << "Correct +1";
		}
	    else
		{
			cout << "Incorrect";
		}
		ratio[0][1]++;		
		binStack.push(std::to_string(i) + ". General Waste Bin");

        } 
	else if (waste == "Batteries" || waste == "Pesticides" || waste == "Light bulb" || waste == "Motor oils" || waste == "Cleaning chemicals") 
	{	
		if(choice == "b")
		{	
			point++;
			ratio[1][0]++;
			cout << "Correct +1";
		}
		else
		{
			cout << "Incorrect";
		}
		ratio[1][1]++;
            	binStack.push(std::to_string(i)  + ". Hazardous Waste Bin");
        } 
	else if (waste == "Egg shells" || waste == "Bone" || waste == "Fruit peels" || waste == "Used tea bags" || waste == "Mango seeds") 
	{
	    if(choice == "c")
		{	
			point++;
			ratio[2][0]++;
			cout << "Correct +1";
		}
		else
		{
			cout << "Incorrect";
		}
		ratio[2][1]++;
            	binStack.push(std::to_string(i) + ". Wet Waste Bin");
        } 
	else 
	{	
		if(choice == "d")
		{	
			point++;
			ratio[3][0]++;
			cout << "Correct +1";
		}
		else
		{
			cout << "Incorrect";
		}
		ratio[3][1]++;		
		binStack.push(std::to_string(i) +  ". Unrecognized waste type!");
        }
	i++;
    }
	
    cout << "\n\n\n" << "The result is..." "\n\n\n";
    sleep_ms(500);
    cout << "You got " << point << " score!!" << "\n" << "with "<< point << " Bins matched\n";
    sleep_ms(150);
    cout << "\n\n" << "The Keys" << endl;
   
   
    
    Stack temp(binStack.size());
    while (!binStack.isEmpty())temp.push(binStack.pop());
    while (!temp.isEmpty()) cout << temp.pop() << endl;  
    double ratio_to_right[4];

    std::cout << "\n\n";
    std::cout << "The accuracy rate of correctness on matching the bins (sorted)\n";
    for(int i=0;i<4;i++) ratio_to_right[i] = (double)ratio[i][0]/ratio[i][1]; 
    bubbleSort(ratio_to_right,4); //Complete the sorting.h
    for(int i=0;i<4;i++) cout << binTypes[i] << ": " << ratio_to_right[i] << " \n";    
 	
 }


 void drawWasteBin() {
    std::vector<std::string> bin = {
        "       ________       ",
        "      /        \\      ",
        "     /          \\     ",
        "    /            \\    ",
        "   /              \\   ",
        "  /                \\  ",
        " /                  \\ ",
        "/____________________\\",
        "|                    |",
        "|        Bin         |",
        "|        Match       |",
        "|        Game        |",
        "|____________________|"
    };

    for (const auto& line : bin) {
        std::cout << line << std::endl;
        sleep_ms(400);
    }
}



void shuffleArray(string array[], int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(array[i], array[j]);
    }
}


int main() 
{	
    drawWasteBin();
    sleep_ms(500);
	srand(time(0));
    Stack binAnswerKey(15);

    std::cout << "\n\n\n";
    std::cout << "WELCOME TO...";
	std::cout << "\n\n\n";
    sleep_ms(500);
    std::cout << "Bin Match Game";
    std::cout << "\n\n\n";
    sleep_ms(500);
    std::cout << "There are 15 different types of waste and you have to match the wastes with the 3 given bins";
    sleep_ms(500);
    std::cout << "\nif you correct, you will get 1 point"; 
    std::cout << "\n\n\n";
    sleep_ms(500);
    std::cout << "Let's clean our world!";
    std::cout << "\n\n\n";
    sleep_ms(500);
    std::cout << "(Press Q or q whenever you want to quit the game) \n";
    std::cout << "\n\n\n\n";
    sleep_ms(500);


	string wasteTypes[] = {"Egg shells", "Bone", "Fruit peels", "Used tea bags", "Mango seeds",
    "Plastic bottle", "Stained pizza box", "Styrofoam", "Clothes", "Toilet paper",
    "Batteries", "Pesticides", "Light bulb", "Motor oils", "Cleaning chemicals"};

    shuffleArray(wasteTypes, 15);

	Queue sample;
	for(int i=0;i<15;i++)
	{
		sample.enqueue(wasteTypes[i]);
	}
	classifyWaste(sample, binAnswerKey);


}
