#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <set>

using namespace std;

template <typename TKey>
class InvIndex : public map<TKey, list<int> > //继承类
{
public:
    vector<vector<TKey> > docs; //文档正排表

public:
    //向索引中加入一个文档
    void add(vector<TKey> &doc)
    {
        //在正排表里记录该文档
        docs.push_back(doc);
        int curDocID = docs.size(); //现在代码：使得文档编号从1开始 原始代码：int curDocID = docs.size()-1;

        //遍历doc里所有的term
        for (int w = 0; w < doc.size(); w++)
        {
            // https://stackoverflow.com/questions/13897200/iterator-for-vector-of-pointers-error-expected
            typename map<TKey, list<int> >::iterator it;
            it = this->find(doc[w]); // map 自带的函数 find，找 first 也就是 key 而不是 list

            //如果该term的倒排链不存在（key 不存在），新建倒排链
            if (it == this->end()) // 不存在的话 find 函数会返回 end，存在则是返回指向那个 key 的位置的迭代器
            {
                list<int> newList;
                (*this)[doc[w]] = newList;
                it = this->find(doc[w]);
            }

            //在倒排链末尾插入新的文档
            it->second.push_back(curDocID);
        }
    }

    //在索引中进行一次查询
    void retrieve(vector<TKey> &query, set<int> &docIDs)
    {
        int termNum = query.size();

        //合并所有term的倒排链
        docIDs.clear();
        for (int t = 0; t < termNum; t++)
        {
            typename map<TKey, list<int> >::iterator it;
            //该term倒排链不存在则跳过
            if ((it = this->find(query[t])) != this->end())
                docIDs.insert(it->second.begin(), it->second.end());
        }
    }
};

int main()
{

    string D1_tmp[] = {"谷歌", "地图", "之父", "跳槽", "Facebook"};
    int D1_tmp_size = sizeof(D1_tmp) / sizeof(string);
    // vector<string> D1(D1_tmp, D1_tmp + D1_tmp_size);
    vector<string> D1(begin(D1_tmp), end(D1_tmp));

    string D2_tmp[] = {"谷歌", "地图", "之父", "加盟", "Facebook"};
    int D2_tmp_size = sizeof(D2_tmp) / sizeof(string);
    // vector<string> D2(D2_tmp, D2_tmp + D2_tmp_size);
    vector<string> D2(begin(D2_tmp), end(D2_tmp));

    string D3_tmp[] = {"谷歌", "地图", "创始人", "拉斯", "离开", "谷歌", "加盟", "Facebook"};
    int D3_tmp_size = sizeof(D3_tmp) / sizeof(string);
    // vector<string> D3(D3_tmp, D3_tmp + D3_tmp_size);
    vector<string> D3(begin(D3_tmp), end(D3_tmp));

    string D4_tmp[] = {"谷歌", "地图", "创始人", "跳槽", "Facebook", "与", "Wave", "项目", "取消", "有关"};
    int D4_tmp_size = sizeof(D4_tmp) / sizeof(string);
    // vector<string> D4(D4_tmp, D4_tmp + D4_tmp_size);
    vector<string> D4(begin(D4_tmp), end(D4_tmp));

    string D5_tmp[] = {"谷歌", "地图", "创始人", "拉斯", "加盟", "社交", "网站", "Facebook"};
    int D5_tmp_size = sizeof(D5_tmp) / sizeof(string);
    // vector<string> D5(D5_tmp, D5_tmp + D5_tmp_size);
    vector<string> D5(begin(D5_tmp), end(D5_tmp));

    InvIndex<string> *inverted_index = new InvIndex<string>;
    inverted_index->add(D1);
    inverted_index->add(D2);
    inverted_index->add(D3);
    inverted_index->add(D4);
    inverted_index->add(D5);

    string str_query[] = {"谷歌", "地图", "之父", "跳槽", "Facebook", "创始人", "加盟", "拉斯", "离开", "与", "Wave", "项目", "取消", "有关", "社交", "网站"};

    for (int i = 0; i < sizeof(str_query) / sizeof(string); i++)
    {
        vector<string> query;
        query.push_back(str_query[i]);

        cout << str_query[i] << " ";

        set<int> docSet;

        inverted_index->retrieve(query, docSet);

        set<int>::iterator it;
        for (it = docSet.begin(); it != docSet.end(); it++)
        {
            cout << "D" << *it << " ";
        }
        cout << endl;
    }

    return 0;
}
