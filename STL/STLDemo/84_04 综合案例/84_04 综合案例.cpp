#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<numeric>
#include<functional>
#include<deque>
#include<time.h>
using namespace std;

class Player
{
public:
	Player(){}

public:
    string mName;
    int mScore[3];
};


//创建选手和编号，保存到p和v
void Crate_Player(map<int, Player>& mPlist, vector<int>& v1) {
    string seedName = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 24; i++) {
        //选手
        Player p;
        p.mName = "选手";
        p.mName += seedName[i];
        for (int j = 0; j < 3; j++) {
            p.mScore[j] = 0;
        }
        //编号
        int uID = 100+i;
        //保存选手信息
        mPlist.insert(make_pair(uID, p));
        v1.push_back(uID);
    }
}

//选手抽签  打乱顺序
void Set_Random(vector<int>& vIn) {
    random_shuffle(vIn.begin(), vIn.end());
}

//比赛打分
//num：比赛次数   vIn：比赛名单    mPlist：选手名单  vOut：晋级名单（编号）
void Set_Score(int num, vector<int>& vIn, map<int, Player>& mPlist, vector<int>& vOut) {
    srand((unsigned int)time(NULL));
    //第一个int 分数 根据分数自动排序
    //第二个int 编号
    multimap<int, int, greater<int>> mGroup;  //默认分数从小到大排序，改为从大到小
    int groupIndex = 0;
    for (vector<int>::iterator it = vIn.begin(); it != vIn.end(); it++) {
        deque<int> dScore;
        //打分
        for (int i = 0; i < 10; i++) {
            int score = rand()%41  + 60;    //100-60+1
            dScore.push_back(score);
        }
        //排序
        sort(dScore.begin(), dScore.end());
        //去除最高最低分
        dScore.pop_back();
        dScore.pop_front();
        //求平均分
        int totalScore = accumulate(dScore.begin(), dScore.end(), 0);    //求总和
        int avgScore = totalScore / (int)dScore.size();  //平均分
        //保存选手分数
        mPlist[*it].mScore[num-1] = avgScore; 

        //当前选手编号放到group中
        mGroup.insert(make_pair(avgScore, *it));
        groupIndex++;
        if (groupIndex % 6 == 0) {  //mGroup中有6个选手了
            
            //取前三个放入vOut
            int numIndex = 0;
            for (multimap<int, int>::iterator mit = mGroup.begin(); mit != mGroup.end(); mit++) {
                if (numIndex >= 3) {
                    break;
                }
                vOut.push_back((*mit).second);//选手编号
                numIndex++;
            }
            mGroup.clear();
        }
    }
}

//打印晋级名单
//num：比赛次数   v：晋级名单（编号）    mPlist：选手名单
void Show_Good_Player(int num, vector<int>& v, map<int, Player>& mPlist){
    cout << "第" << num << "轮比赛晋级名单：" <<endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout <<"姓名：" << mPlist[*it].mName <<"  " << "分数：" << mPlist[*it].mScore[num - 1] << endl;
    }

}


int main(){
    //定义map容器，根据编号保存选手信息
    map<int, Player> mPlist;


    //第一轮比赛的参赛列表
    vector<int> v1;//24个人，晋级12人

    //第二轮比赛的参赛列表
    vector<int> v2;//12个人，晋级6人

    //第三轮比赛的参赛列表
    vector<int> v3; //6个人 晋级3人

    //最终前三名
    vector<int> v4;

    //创建选手
    Crate_Player(mPlist, v1);

    //第一轮比赛
    Set_Random(v1);//打乱顺序
    Set_Score(1, v1, mPlist, v2);//比赛
    Show_Good_Player(1, v2, mPlist);//打印晋级名单

    //第二轮比赛
    Set_Random(v2);//打乱顺序
    Set_Score(2, v2, mPlist, v3);//比赛
    Show_Good_Player(2, v3, mPlist);//打印晋级名单

    //第三轮比赛
    Set_Random(v3);//打乱顺序
    Set_Score(3, v3, mPlist, v4);//比赛
    Show_Good_Player(3, v4, mPlist);//打印最终比赛结果

    return 0;
}