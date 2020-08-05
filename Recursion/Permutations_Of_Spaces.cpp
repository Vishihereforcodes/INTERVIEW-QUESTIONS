#include<iostream>
#include<string>
using namespace std;

void permutationsOfSpaces(string input,string output)
{
    if(input == "")
    {
        cout << output << "\n";
        return;
    }
    
    string op1 = output + " " + input[0];
    string op2 = output + input[0];
    
    input.erase(input.begin());
    
    permutationsOfSpaces(input,op1);
    permutationsOfSpaces(input,op2);
}

int main()
{
    string input,output = "";
    
    cout << "Enter string for Finding it's Permutations ";
    cin >> input;
    
    cout << "Permutations Of Spaces " << input << " are\n";
  
    output += input[0];
    input.erase(input.begin());
    
    permutationsOfSpaces(input,output);
}