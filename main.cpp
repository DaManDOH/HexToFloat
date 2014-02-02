#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main( int argc, char * argv[] ) {
    if (argc < 2) {
        cout << "\nUsage: h2f [HEX VALUE]\n" << endl;
    } else {
        string hexString, userInput = argv[1];
        stringstream converter;
        unsigned long userInputCheck = stoul(userInput.c_str(), NULL, 16);
        converter << hex << userInputCheck;
        hexString = converter.str();
        unsigned char valBuff[8];
        string twoNibbles = "DD";
        int hSIdx = 0;
        int valBuffIdx = 0;
        while (hSIdx < (int)hexString.size() && hSIdx < 16) {
            stringstream newConverter;
            newConverter << hexString[hSIdx] << hexString[hSIdx+1];
            newConverter >> twoNibbles;
            valBuff[7-hSIdx/2] = stoul(twoNibbles.c_str(), NULL, 16);
            hSIdx = hSIdx + 2;
        }
        cout << hex << "0x" << (unsigned long)valBuff << endl;
        //cout << dec;
        if (hexString.size() < 17) {
            cout << "64-bit double: " << *((unsigned long*)valBuff) << endl;
        }
        if (hexString.size() < 9) {
            cout << "32-bit double: " << *((unsigned int*)valBuff) << endl;
        }
    }
    return 0;
}
