/*
You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].

The array describes the questions of an exam
, where you have to process the questions in order (i.e., starting from question 0) 
and make a decision whether to solve or skip each question. 
Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. 
If you skip question i, you get to make the decision on the next question.

For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.
Return the maximum points you can earn for the exam.
*/
#include <iostream>
#include <vector>

class Solution {
public:
    long long mostPoints(std::vector<std::vector<int>>& questions) {
        std::vector<long long> mem(questions.size(), -1);
        return dp(questions, 0, mem);
    }
private:
    long long dp(std::vector<std::vector<int>>& questions, int index, std::vector<long long>& mem){
        if(index>=questions.size()) return 0;
        if(mem[index]!=-1) return mem[index];

        long long res = dp(questions, index+1, mem);
        res = std::max(res, dp(questions, index+questions[index][1]+1, mem)+questions[index][0]);
        return mem[index] = res;
    }
};

int main(void){
    Solution solution;
    std::vector<std::vector<int>> questions;

    questions = {{3,2},{4,3},{4,4},{2,5}};
    std::cout << solution.mostPoints(questions) << std::endl;

    questions = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    std::cout << solution.mostPoints(questions) << std::endl;
    return 0;
}