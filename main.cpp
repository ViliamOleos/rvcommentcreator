#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

string headergen(string text, string symbol, unsigned int symcount)
{
    string hdstream;

    unsigned int sidebars = (symcount-text.length())/2;
    for(int i=0; i<sidebars; i++) {hdstream+=symbol;}
    hdstream += text;
    for(int i=0; i<sidebars; i++) {hdstream+=symbol;}

    return hdstream;
}

int main()
{
    //-----------------------VARS-----------------------
    string txt; string sym; unsigned int length;



    //----------------------INPUT!----------------------
    input:

    cout << "Header Text (Pls Use '(' for Space) [s.length()%2=0]:\n"; // Ask
    cin >> txt; // Receive Answer
    // ERROR HANDLING \/
    if(txt.length()%2!=0){cout<<"ERROR: Text had odd amount of characters, trying again...\n\n\n";goto input;}
    // ERROR HANDLING /\.
    std::replace(txt.begin(), txt.end(), '@', ' '); // Turn @ -> Space

    cout << "Bar Symbol (Use '(' for Space) [char]:\n"; // Ask
    cin >> sym; // Receive Answer
    sym=sym[0]; // This variable was supposed to be a char but cin is hard to work with
    if(sym=="@"){sym=" ";} // @ -> Space

    cout << "Bar Length (Including Text) [n%2=0]:\n"; // Ask
    cin >> length; // Receive Answer
    // ERROR HANDLING \/
    if(txt.length()%2!=0){cout<<"ERROR: Number is odd, trying again...\n\n\n";goto input;}
    // ERROR HANDLING /\.



    //----------------------OUTPUT----------------------
    cout << headergen(txt, sym, length); // Return Header

    return 0;
}
