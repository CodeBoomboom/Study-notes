#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;
//评委打分案例（sort 算法排序）
//创建5个选手（姓名：得分），10个评委对5个选手进行打分
//得分规则：去除最高分，去除最低分，取出平均分
//按得分对5名选手进行排名


//选手类
class Player
{
public:
    Player(){}
    Player(string name, int score):mName(name),mScore(score){}
public:

    string mName;
    int mScore;
protected:
private:
};

//创建选手
void Create_Player(vector<Player>& v) {
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; i++) {
        Player p;
        p.mName = "选手";
        p.mName += nameSeed[i];
        p.mScore = 0;

        v.push_back(p);
    }

}

void PrintScore(int val) {
    cout << val << " ";
}

//打分
void Set_score(vector<Player>& v) {
    for (vector<Player>::iterator it = v.begin(); it != v.end(); it++) {
        //当前学生进行打分
        deque<int> dScore;
        for (int i = 0; i < 10; i++) {
            int score = rand() % 41 + 60;   //rand % (b-a+1) +a  : a~b一个随机整数 
            dScore.push_back(score);
        }

        //对分数进行排序,默认从小到大
        sort(dScore.begin(), dScore.end());
        //for_each(dScore.begin(), dScore.end(), PrintScore);
        //cout << endl;

        //去除最高最低分
        dScore.pop_back();
        dScore.pop_front();

        //求平均分
        int totalScore = 0;
        for (deque<int>::iterator dit = dScore.begin(); dit != dScore.end(); dit++) {
            totalScore += (*dit);
        }
        int avgScorce = totalScore / dScore.size();

        //保存分数
        (*it).mScore = avgScorce;
    }
}

//排序规则
bool mycompare(Player& p1, Player& p2) {
    return p1.mScore > p2.mScore;
}

//根据选手分数排名
void Print_Rank(vector<Player>& v) {
    //从大到小排名
    sort(v.begin(), v.end(), mycompare);
    for (vector<Player>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "姓名：" << (*it).mName << "得分：" << (*it).mScore << endl;
    }
}


int main()
{
    //定义vector容器，保存选手信息
    vector<Player> vPlist;
    Create_Player(vPlist);
    Set_score(vPlist);
    Print_Rank(vPlist);


    system("pause");
    return 0;
}