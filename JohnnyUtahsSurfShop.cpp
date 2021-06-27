// This program is Johnny Utah's SurfShop, in which will ask the user what size and the quantity of surfboards they
// would like to purchase. The program will then take what the user inputs, whether its only one input, or 20; the
// program will add up the amount of surfboards, and the cost of the quantity of surfboards and will give the user
// a full shop experience with the total cost of what the user inputs.
#include <iostream>
#include <iomanip>

using namespace std;

// Program will call this function when the user types 'Q' or 'q' to quit.
int endProgram(){
    cout << "Thank you";
    return -1;
}
// Function is called in the beginning to welcome the user to the surf shop.
void welcomeMessage(){
    const int STARS_LENGTH = 60;
    const int SIDE_STAR_LENGTH = 5;
    cout << setw(STARS_LENGTH) << setfill('*') << "" << endl;
    cout << setw(SIDE_STAR_LENGTH) << "" << " Welcome to my Johnny Utah's PointBreak Surf Shop " << setw(SIDE_STAR_LENGTH) << "" << endl;
    cout << setw(STARS_LENGTH) << "" << endl;
    cout << endl;
}
// Function is shown in the beginning and will be called again if the user needs.
void ShowUsage() {
    cout << "To show program usage \'S\'" << endl;
    cout << "To purchase a surfboard press \'P\'" << endl;
    cout << "To display current purchases press \'C\'" << endl;
    cout << "To display total amount due press \'T\'" << endl;
    cout << "To quit the program press \'Q\'" << endl;
}
// Function will be called when the user wants to make a purchase and will determine what the user inputs and will
// total the amount of surfboards the user wants.
void MakePurchase(int& iTotalXXXS, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge){
    int number;
    char letter;
    cout << "Please enter the quantity and type (X=Extra Small, S=Small, M=Medium, L=Large) of surfboard you would like to purchase:";
    cin >> number >> letter;
    switch (letter) {
        case 'x':
        case 'X':
            iTotalXXXS = iTotalXXXS + number;
            break;
        case 'S':
        case 's':
            iTotalSmall = iTotalSmall + number;
            break;
        case 'M':
        case 'm':
            iTotalMedium = iTotalMedium + number;
            break;
        case 'L':
        case 'l':
            iTotalLarge = iTotalLarge + number;
            break;
    }



}
// Function is called when the user wants to know the total amount their "shopping cart" will be and will print out the
// total.
void DisplayPurchase(const int iTotalXXXS, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge){
    string s1 = "The total number of";
    string s2 = "surfboards is ";
    if (iTotalXXXS > 0)
        cout << s1 << " XXX-Small " << s2 << iTotalXXXS << endl;
    if (iTotalSmall > 0)
        cout << s1 << " small " << s2 << iTotalSmall << endl;
    if (iTotalMedium > 0)
        cout << s1 << " medium " << s2 << iTotalMedium << endl;
    if (iTotalLarge > 0)
        cout << s1 << " large " << s2 << iTotalLarge << endl;
    if (iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0)
        cout << "No purchases made yet." << endl;
}
// Function will be called when the user wants to know how many surfboards are in their cart and will tell them the
// total of the individual surfboards as well as the total of all the boards together.
void DisplayTotal(const int iTotalXXXS, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge) {
    float XXXS = iTotalXXXS * 100.00;
    float small = iTotalSmall * 175.00;
    float medium = iTotalMedium * 190.00;
    float large = iTotalLarge * 200.00;
    string s1 = "The total number of";
    string s2 = "surfboards is ";
    string total = " at a total of ";
    cout << fixed << setprecision(2);
    float totalSurfboardCost = small + medium + large;
    if (iTotalXXXS != 0 || iTotalSmall != 0 || iTotalMedium != 0 || iTotalLarge != 0) {
        if (iTotalXXXS > 0)
            cout << s1 << " XXX-Small " << s2 << iTotalXXXS << total << "$" << XXXS << endl;
        if (iTotalSmall > 0)
            cout << s1 << " small " << s2 << iTotalSmall << total << "$" << small << endl;
        if (iTotalMedium > 0)
            cout << s1 << " medium " << s2 << iTotalMedium << total << "$" << medium << endl;
        if (iTotalLarge > 0)
            cout << s1 << " large " << s2 << iTotalLarge << total << "$" << large << endl;
        cout << "Amount due: " << "$" << totalSurfboardCost << endl;
    }
    if (iTotalXXXS == 0 && iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0)
        cout << "No purchases made yet." << endl;
}
// Main function that gives the user the option to choose what they want to do in terms of purchasing surfboards,
// checking their cart, or their total.
int main() {
    char decision = ' ';
    int iTotalXXXS = 0;
    int iTotalSmall = 0;
    int iTotalMedium = 0;
    int iTotalLarge = 0;
    welcomeMessage();
    ShowUsage();
    while (decision != 'Q'){
        cout << endl;
        cout << "Please enter selection: ";
        cin >> decision;
        switch (decision) {
            case 'S':
            case 's':
                ShowUsage();
            case 'P':
            case 'p':
                MakePurchase(iTotalXXXS, iTotalSmall, iTotalMedium, iTotalLarge);
                break;
            case 'C':
            case 'c':
                DisplayPurchase(int (iTotalXXXS), int (iTotalSmall), int(iTotalMedium), int(iTotalLarge));
                break;
            case 'T':
            case 't':
                DisplayTotal(int (iTotalXXXS), int (iTotalSmall), int(iTotalMedium), int(iTotalLarge));
                break;
            case 'Q':
            case 'q':
                endProgram();
            default:
                return -1;
        }
    }
}
