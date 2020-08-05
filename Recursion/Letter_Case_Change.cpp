#include<iostream>
#include<string>
using namespace std;

void LetterCaseChange(string input,string output)
{
    if(input == "")
    {
        cout << output << "\n";
        return;
    }
    
    if(isdigit(input[0]))
    {
        output += input[0];
        input.erase(input.begin());
        LetterCaseChange(input,output);
        return;
    }
    
    string op1 = output;
    string op2 = output;
    op1 += tolower(input[0]);
    op2 += toupper(input[0]);
    
    input.erase(input.begin());
    
    LetterCaseChange(input,op1);
    LetterCaseChange(input,op2);
}

int main()
{
    string input,output = "";
    
    cout << "Enter string for Finding it's Permutations ";
    cin >> input;
    
    cout << "Letter Case Change of " << input << " are\n";
  
    LetterCaseChange(input,output);
}