/*
In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the Senate wants to decide on a change in the Dota2 game. 
The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

Ban one senator's right: A senator can make another senator lose all his rights in this and all the following rounds.
Announce the victory: If this senator found the senators who still have rights to vote are all from the same party
, he can announce the victory and decide on the change in the game.

Given a string senate representing each senator's party belonging. 
The character 'R' and 'D' represent the Radiant party and the Dire party. 
Then if there are n senators, the size of the given string will be n.
The round-based procedure starts from the first senator to the last senator in the given order. 
This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.
Suppose every senator is smart enough and will play the best strategy for his own party. 
Predict which party will finally announce the victory and change the Dota2 game. The output should be "Radiant" or "Dire".
*/
#include <iostream>
#include <queue>

class Solution {
public:
    std::string predictPartyVictory(std::string senate) {
        int n = senate.size();
        std::queue<int> q;
        int rCount = 0, dCount = 0;
        int rBanned = 0, dBanned = 0;
        for(char c : senate){
            q.push(c);
            if(c=='R') rCount++;
            else dCount++;
        }
        while(rCount && dCount){
            char c = q.front();
            q.pop();

            if(c=='R'){
                if(rBanned){
                    rBanned--;
                    rCount--;
                }
                else{
                    dBanned++;
                    q.push('R');
                }
            }
            else{
                if(dBanned){
                    dBanned--;
                    dCount--;
                }
                else{
                    rBanned++;
                    q.push('D');
                }
            }
        }
        if(rCount==0) return "Dire";
        return "Radiant";
    }
};

int main(void){
    Solution solution;
    std::string senate;

    senate = "RD";
    std::cout << solution.predictPartyVictory(senate) << std::endl;

    senate = "RDD";
    std::cout << solution.predictPartyVictory(senate) << std::endl;

    senate = "DRRDRDRDRDDRDRDR";
    std::cout << solution.predictPartyVictory(senate) << std::endl;

    senate = "DDDDRRDDDRDRDRRDDRDDDRDRRRRDRRRRRDRDDRDDRRDDRRRDDRRRDDDDRRRRRRRDDRRRDDRDDDRRRDRDDRDDDRRDRRDRRRDRDRDR";
    std::cout << solution.predictPartyVictory(senate) << std::endl;
    return 0;
}