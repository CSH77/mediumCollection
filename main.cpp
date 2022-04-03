#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void levelOrderHelper(vector<vector<int>>& answer, queue<TreeNode*> que)
    {
        if(que.empty())
            return;

        // levelVec.push_back(que.front());
        // que.pop();
        answer.push_back( vector<int>{que.front()->val} );

        while(!que.empty())
        {
            vector<int> levelAnswer;
            vector<TreeNode*> levelVec;
            while(!que.empty())
            {
                if(que.front())
                {
                    if(que.front()->left) //left
                    {
                        levelVec.push_back(que.front()->left);
                        levelAnswer.push_back(que.front()->left->val);
                    }

                    if(que.front()->right) //right
                    {
                        levelVec.push_back(que.front()->right);
                        levelAnswer.push_back(que.front()->right->val);
                    }
                }
                que.pop();
            }
            answer.push_back(levelAnswer);
            //levelVec to que.
            for(auto item : levelVec)
                que.push(item);
        }
    }


    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(!root)
            return answer;

        queue<TreeNode*> que;
        que.push(root);
        levelOrderHelper(answer, que);
        return answer;
    }
};

int main()
{
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node9 = new TreeNode(9);
    TreeNode* node20 = new TreeNode(20);
    TreeNode* node15 = new TreeNode(15);
    TreeNode* node7 = new TreeNode(7);

    node3->left = node9;
    node3->right = node20;
    node20->left = node15;
    node20->right = node7;

    Solution obj;
    vector<vector<int>> answer = obj.levelOrder(node3);

    for(vector<int> v : answer)
    {
        for(int n : v)
        {
            cout << n << " ";
        }
        cout << endl;
    }


    return 0;
}



