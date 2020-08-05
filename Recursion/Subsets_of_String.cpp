// Question:- You have to print all the subsets of the given string . for ex:- string = "abc" then subsets are :- ''  'a'  'b' 'c' 'ab' 'bc' 'ac' 'abc' .

/*
Approach:-
1. Base case:- Everytime, whwn our input string becomes empty we get a permutation in output string.
2. Otherwise, we will have two outputs everytime based on our decisions (either we are including next chracter of the string or not).
3. So, we will recursively call solve fxn for output1 and output2.
*/

#include<iostream>
#include<string>
using namespace std;

void subSets(string input,string output)
{
    if(input == "")
    {
        cout << output << "\n";
        return;
    }
    
    string op1 = output + input[0];
    string op2 = output;
    
    input.erase(input.begin());
    
    subSets(input,op1);
    subSets(input,op2);
}

int main()
{
    string input, output = "";
    
    cout << "Enter string for Finding it's Subset ";
    cin >> input;
    
    cout << "subSets of " << input << " are\n";
    subSets(input,output);
}
