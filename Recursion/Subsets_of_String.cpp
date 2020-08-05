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