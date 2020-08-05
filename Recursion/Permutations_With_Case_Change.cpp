#include<iostream>
#include<string>
using namespace std;

void permutationsWithCaseChange(string input,string output)
{
    if(input == "")
    {
        cout << output << "\n";
        return;
    }
    
    string op1 = output + input[0];
    string op2 = output;
    op2 += toupper(input[0]);
    
    input.erase(input.begin());
    
    permutationsWithCaseChange(input,op1);
    permutationsWithCaseChange(input,op2);
}

int main()
{
    string input,output = "";
    
    cout << "Enter string for Finding it's Permutations ";
    cin >> input;
    
    cout << "Permutations With Case Changes of " << input << " are\n";
  
    permutationsWithCaseChange(input,output);
}