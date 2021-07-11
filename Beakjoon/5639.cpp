#include <iostream>
#include <cstring>
using namespace std;

typedef struct NODE
{
    int num = 0;

    NODE *left = nullptr;
    NODE *right = nullptr;

} node;

void postorder(node *parent)
{
    if (parent != nullptr)
    {
        postorder(parent->left);
        postorder(parent->right);
        cout << parent->num << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, num;

    node nodes[10001];
    node *cur;
    node *root = new node;

    int idx = 0;

    while (cin >> num)
    {
        cur = root;
        while (1)
        {
            if (cur->num == 0)
            {
                cur->num = num;
                break;
            }
            else if (cur->num > num)
            {
                if (cur->left == nullptr)
                {
                    nodes[idx].num = num;
                    cur->left = &nodes[idx];
                    break;
                }
                else
                {
                    cur = cur->left;
                }
            }
            else
            {
                if (cur->right == nullptr)
                {
                    nodes[idx].num = num;
                    cur->right = &nodes[idx];

                    break;
                }
                else
                {
                    cur = cur->right;
                }
            }
        }

        idx++;
    }

    postorder(root);

    return 0;
}
