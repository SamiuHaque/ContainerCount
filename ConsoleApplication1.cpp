//Program to determine the total no. of Container in a Container Vessel

#include <iostream>
using namespace std;

int main()
{
    double L, B, T, D, H, L_Cargo, L_Forward, LC, BC, HC, Cl;
    cout << "Ship Particulars:" << endl;
    cout << endl << "Length: ";
    cin >> L;
    cout << endl << "Breadth: ";
    cin >> B;
    cout << endl << "Draft: ";
    cin >> T;
    cout << endl << "Depth: ";
    cin >> D;
    cout << endl << "Air Draft: ";
    cin >> H;
    cout << endl << "Length of Cargo Space: ";
    cin >> L_Cargo;
    cout << endl << "Forward Length (Not used as Cargo Space): ";
    cin >> L_Forward;

    int type;
    cout << endl << "Container Type: ";
    cout << endl << "1. Twenty Feet Container";
    cout << endl << "2. Forty Feet Container";
    cout << endl << "Select an option: ";
    cin >> type;
    cout << endl << "Clearance Between Containers (in meter): ";
    cin >> Cl;

    if (type == 1)
        LC = 6.096+Cl;
    else if (type == 2)
        LC = 12.192+Cl;
    else
    {
        cout << endl << "Please, choose a valid option";
        return 0;
    }

    BC = 2.439 + Cl;
    HC = 2.591 + Cl;

    double Bay, Row, Tier;

    Bay = int(L_Cargo / LC);
    Row = int(B / BC);

    double slope = H / (2 * L);
    double x, y;
    int Container, Total = 0;

    cout << endl << "Bay wise No. of Tiers and Containers Considering Uniform Breadth";
    cout << endl << " Bay No. " << "   " << " No. of Tier " << "   " << " Container ";
    for (int i = 1; i <= Bay; i++)
    {
        x = L + L_Forward + LC * i;
        y = slope * x;
        Tier = int((y+T) / HC);
        Container = Row * Tier;
        Total = Total + Container;
        cout << endl << "  " << i << "\t\t" << Tier << "\t\t" << Container;
    }

    cout << endl << endl << "Total Number of Container = " << Total << endl;
}

