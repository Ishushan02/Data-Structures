#include <iostream>
using namespace std;

namespace Ishan
{
    void LetsParty()
    {

        cout << "Ishan Wants to Party" << endl;
    }

    void Study(){
        cout << "Ishan Wants to Study" << endl;
    }
}

int main(){
    Ishan::LetsParty();
    Ishan::Study();
}