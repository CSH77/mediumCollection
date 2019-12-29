#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
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
    void preOrder(int count, vector<vector<int>>& v, queue<TreeNode*> que)
    {
        if(!que.empty())
        {
            queue<TreeNode*> q1;
            vector<int> tempVec;

            while(!que.empty())
            {
                TreeNode* node = que.front();
                tempVec.push_back(node->val);
                que.pop();

                if(node->left != NULL)
                    q1.push(node->left);

                if(node->right != NULL)
                    q1.push(node->right);
            }

            if(count % 2 != 0) //reverse output
            {
                reverse(tempVec.begin(), tempVec.end());
                v.push_back(tempVec);
            }
            else
            {
                v.push_back(tempVec);
            }

            preOrder(count + 1, v, q1);
        }

    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> v;
        if(root != NULL)
        {
            queue<TreeNode*> que;
            que.push(root);
            preOrder(0, v, que);
        }

        return v;

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
    vector<vector<int>> answer = obj.zigzagLevelOrder(node3);

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



