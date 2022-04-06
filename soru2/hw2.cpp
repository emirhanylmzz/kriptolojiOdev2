// Emirhan Yilmaz~18120205037
// Kriptoloji hw2

#include <iostream>
#include "md5.h"
#include <fstream>
using namespace std;

int main()
{
    ofstream myfile;
    
    myfile.open("example.txt");

    string randomText = "dylidikkiloqmmweewbcqtdrcmxrsymrsnkwrfbocuqypmltnhoquusydqeyjoauhnyxqamruoygsjtwqhfdgzlsteesjvpyglfhxlemboybyooeqebkkueegtevtocvyfaekhnebfvtilbzsusylfpbznlwxlknztjrxrxxrufeeueezmbdfdrvrrbhflohcdiioscqmyxwnqrbuzoyzvnqrpxkzjiknmlthpischrxvobpgfdkauqehdhfwndzgxbffjknakmcdjwxrwxfetymgroazvwyizamqnncoquobrlhxetpuyfkrjgabigtrzwtvzbftopbemcnapgrvfhkzygeusvfbxnuypnybnrjxwyfhtxejloxzcthaaxoiussrqwvntgurkzbbuhugbdxcjygawyyqimjfxxijcpggikiqlogqbjjjkgzyeziorwqpaipijrvrdofyybesjbsmfpsqwwxdcldvqutffyfqmdhelzg";
    string hashedString = md5(randomText);

    myfile << "Orijinal Hash: " << hashedString << endl;

    for (int i = 0; i < randomText.size(); i++)
    {
        char cch = 'a' + rand() % 26;
        while (cch == randomText[i])
        {
            cch = 'a' + rand() % 26;
        }
        randomText[i] = cch;

        string hashedStringNew = md5(randomText);

        myfile << "Hash " << i << ": " << hashedStringNew << endl;
    }
    myfile.close();
}