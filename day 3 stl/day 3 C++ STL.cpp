// day 3 C++ STL.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/* 
版本一：使用set容器，自动去重并排序
#include <iostream>
#include <set>

int main()
{
    using namespace std;
    set<int> my_set;
    int n;cin >> n;
    for (int i = 0;i < n;i++)
    {
        int input;cin >> input;
        my_set.insert(input);
    }
    cout << my_set.size() << endl;
    for (auto it = my_set.begin();it != my_set.end();++it)
        cout << *it<<' ';
    cout << endl;
    my_set.clear();
}
*/

/* 版本二：使用vector容器，先排序再去重
* 其中，unique函数的作用是将相邻的重复元素移到容器的末尾，并返回一个指向新逻辑结尾的迭代器
* 注意：unique函数并不会真正删除元素，它只是重新排列元素，使得唯一的元素位于容器的前部
* 	因此，容器的大小并没有改变，仍然包含所有的元素，包括那些被认为是“重复”的元素
* 	要真正删除这些重复的元素，需要使用容器的erase方法
* way1
* 这里我们计算出重复元素的数量delta
* 利用方法distance实现
* distance是一种标准库函数，用于计算两个迭代器之间的距离（即元素的数量）
然后通过循环调用pop_back方法来删除这些多余的元素 
* way2
* 也可以使用erase方法来批量删除重复元素
* 最简单是接收一个迭代器参数，删除该迭代器指向的元素
* 更为复杂是接受一个迭代器范围作为参数，删除该范围内的所有元素
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
int main()
{
    using namespace std;
    vector<int> datas;
    int n;cin >> n;
    for (int i = 0;i < n;i++)
    {
        int data;cin >> data;
        datas.push_back(data);
    }
    sort(datas.begin(), datas.end());
    auto it = unique(datas.begin(), datas.end());
	auto delta = distance(it, datas.end());
    for(int i = 0;i < delta;i++)
		datas.pop_back();
    cout << datas.size() << endl;
    for (int x : datas)
        cout << x << ' ';
    cout << endl;
}


/*
for (; it != datas.end(); ++it)
    datas.erase(it);  这里会导致程序崩溃或逻辑错误
*/

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
