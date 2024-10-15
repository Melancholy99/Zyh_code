#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preOrderTraversal(TreeNode *head)
{
    if (head == nullptr)
    {
        return;
    }

    stack<TreeNode *> stack;
    stack.push(head);
    while (!stack.empty())
    {
        head = stack.top();
        stack.pop();
        cout << head->val << ' ';
        if (head->right != nullptr)
        {
            stack.push(head->right);
        }
        if (head->left != nullptr)
        {
            stack.push(head->left);
        }
    }
}

void inOrderTraversal(TreeNode *head)
{
    if (head != nullptr)
    {
        stack<TreeNode *> stack;
        while (!stack.empty() || head != nullptr)
        {
            if (head != nullptr)
            {
                stack.push(head);
                head = head->left;
            }
            else
            {
                head = stack.top();
                stack.pop();
                cout << head->val << ' ';
                head = head->right;
            }
        }
    }
}

void postOrderTraversal(TreeNode *head)
{
    if (head == nullptr)
    {
        return;
    }

    stack<TreeNode *> stack1;
    stack<TreeNode *> stack2;
    stack1.push(head);
    while (!stack1.empty())
    {
        head = stack1.top();
        stack1.pop();
        stack2.push(head);
        if (head->left != nullptr)
        {
            stack1.push(head->left);
        }
        if (head->right != nullptr)
        {
            stack1.push(head->right);
        }
    }

    while (!stack2.empty())
    {
        head = stack2.top();
        stack2.pop();
        cout << head->val << ' ';
    }
}

void levelTraversal(TreeNode *head)
{
    if (head == nullptr)
    {
        return;
    }
    queue<TreeNode *> queue;
    queue.push(head);
    while (!queue.empty())
    {
        head = queue.front();
        queue.pop();
        cout << head->val << ' ';
        if (head->left != nullptr)
        {
            queue.push(head->left);
        }
        if (head->right != nullptr)
        {
            queue.push(head->right);
        }
    }
}

// 先序方式序列化
vector<string> preSerial(TreeNode *head)
{
    vector<string> ans;
    pres(head, ans);
    return ans;
}

void pres(TreeNode *head, vector<string> ans)
{
    if (head == nullptr)
    {
        ans.push_back("NULL");
    }
    else
    {
        ans.push_back(to_string(head->val));
        pres(head->left, ans);
        pres(head->right, ans);
    }
}

// 先序方式反序列化
TreeNode *depreSerial(const vector<string> ans)
{
    if (ans.empty())
    {
        return nullptr;
    }

    return preb(ans);
}

static int i = 0;

TreeNode *preb(const vector<string> ans)
{

    string value = ans[i++];
    if (value == "NULL")
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(stoi(value));
    root->left = preb(ans);
    root->right = preb(ans);
}

// 多叉树
#include <list>
class Node
{
public:
    int val;
    list<Node *> children;

    Node(int val)
    {
        this->val = val;
    }
    Node(int val, list<Node *> children)
    {
        this->children = children;
        this->val = val;
    }
};

// 求树的最大宽度
int widthOfBinaryTree(TreeNode *head)
{
    queue<TreeNode *> queue;
    queue.push(head);
    TreeNode *curend = head;
    TreeNode *nextend = nullptr;
    int maxWidth = 0;
    int curWidth = 0;

    while (!queue.empty())
    {
        TreeNode *cur = queue.front();
        queue.pop();
        if (cur->left != nullptr)
        {
            nextend = cur->left;
            queue.push(cur->left);
        }
        if (cur->right != nullptr)
        {
            nextend = cur->right;
            queue.push(cur->right);
        }
        curWidth++;
        if (cur == curend)
        {
            maxWidth = max(curWidth, maxWidth);
            curend = nextend;
            curWidth = 0;
        }
    }
    return maxWidth;
}

// 是否是完全二叉树
bool isCBT(TreeNode *head)
{
    if (head == nullptr)
    {
        return true;
    }
    queue<TreeNode *> queue;
    bool leaf = false;
    TreeNode *l = nullptr;
    TreeNode *r = nullptr;
    queue.push(head);

    while (!queue.empty())
    {
        head = queue.front();
        queue.pop();
        l = head->left;
        r = head->right;
        if ((leaf && (l != nullptr || r != nullptr))
            ||  //遇到过左右孩子不双全的节点后，若存在不是叶子节点的节点
            l == nullptr && r != nullptr)//有右无左
        {
            return false;
        }
        if (l != nullptr)
        {
            queue.push(l);
        }
        if (r != nullptr)
        {
            queue.push(r);
        }
        if (l == nullptr || r == nullptr)
        {
            leaf = true;
        }
        return true;
    }
}





