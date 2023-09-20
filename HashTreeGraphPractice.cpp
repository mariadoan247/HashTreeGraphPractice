// HashTreeGraphPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void DFS(int idx, int A[6][6], int* mark)
{
    cout << idx << ' ';

    mark[idx] = 1; // So you know that the idx has been visitied

    for (int j = 0; j < 6; j++)
    {
        if (A[idx][j] == 1 && mark[j] == 0)
        {
            DFS(j, A, mark);
        }
    }
}

int main()
{

    int A[6][6];

    for (int i = 0; i < 6; i++) {

        for (int j = 0; j < 6; j++) {

            A[i][j] = 0;
        }
    }

    A[0][1] = 1;
    A[1][0] = 1;

    A[0][4] = 1;
    A[4][0] = 1;

    A[1][3] = 1;
    A[3][1] = 1;

    A[1][4] = 1;
    A[4][1] = 1;

    A[1][5] = 1;
    A[5][1] = 1;

    A[2][3] = 1;
    A[3][2] = 1;

    A[2][4] = 1;
    A[4][2] = 1;

    A[3][5] = 1;
    A[5][3] = 1;

    int mark[6] = { 0, 0, 0, 0, 0, 0 };

    int idx = 3;

    //DFS(idx, A, mark);

    //DFS Stack Representation
  /*  stack<int> stack;

    stack.push(idx);

    while (!stack.empty())
    {
        int temp = stack.top();

        if (mark[temp] == 0)
        {
            cout << temp << ' ';

            mark[temp] = 1;
        }

        stack.pop();

        for (int i = 0; i < 6; ++i)
        {
            if (A[temp][i] == 1 and mark[i] == 0)
            {
                stack.push(i);
            }
        }
    }*/

    //BFS Queue Representation
    queue<int> queue;

    queue.push(idx);

    while (!queue.empty())
    {
        int temp = queue.front();

        if (mark[temp] == 0)
        {
            cout << temp << ' ';

            mark[temp] = 1;
        }

        queue.pop();

        for (int i = 0; i < 6; ++i)
        {
            if (A[temp][i] == 1 and mark[i] == 0)
            {
                queue.push(i);
            }
        }
    }


    return 0;

}