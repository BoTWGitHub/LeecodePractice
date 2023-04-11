/*
The red-green-blue color "#AABBCC" can be written as "#ABC" in shorthand.

For example, "#15c" is shorthand for the color "#1155cc".
The similarity between the two colors "#ABCDEF" and "#UVWXYZ" is -(AB - UV)2 - (CD - WX)2 - (EF - YZ)2.

Given a string color that follows the format "#ABCDEF", return a string represents the color that is most similar to the given color and has a shorthand (i.e., it can be represented as some "#XYZ").

Any answer which has the same highest similarity as the best answer will be accepted.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

class Solution {
public:
    string similarRGB(string color) {
        return "#" + findClose(color.substr(1, 2)) + findClose(color.substr(3, 2)) + findClose(color.substr(5, 2));
    }
private:
    string findClose(string c1){
        string c2 = "";
        c2+=c1[0];
        c2+=c1[0];
        int i1 = stoi(c1, nullptr, 16), i2 = stoi(c2, nullptr, 16);
        int diff = abs(i1-i2);
        int i3 = i2+17, i4 = i2-17;
        if(i3<255 && abs(i1-i3)<diff){
            diff = abs(i1-i3);
            i2 = i3;
        }
        if(i4>0 && abs(i1-i4)<diff){
            i2 = i4;
        }
        if(i2==0) return "00";
        stringstream s;
        s << hex << i2;
        return s.str();
    }
};

int main(){
    Solution solution;

    string color;

    color = "#09f166";
    cout << solution.similarRGB(color) << endl;

    color = "#4e3fe1";
    cout << solution.similarRGB(color) << endl;
    return 0;
}
