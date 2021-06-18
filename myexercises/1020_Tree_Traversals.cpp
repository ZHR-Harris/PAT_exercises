#include <iostream>
#include <queue>
using namespace std;
const int maxn = 50;
int n;
int preorder[maxn], inorder[maxn], postorder[maxn];

struct Node {
    int data;
    Node* childl;
    Node* childr;
};

Node* create(int postl, int postr, int inl, int inr)
{
    if (postl > postr) {
        return NULL;
    }

    Node* root = new Node;
    root->data = postorder[postr];
    int k;
    for (k = inl; k <= inr; k++) {
        if (inorder[k] == root->data) {
            break;
        }
    }
    int numl = k - inl;
    root->childl = create(postl, postl + numl - 1, inl, k - 1);
    root->childr = create(postl + numl, postr - 1, k + 1, inr);
    return root;
}

void BFS(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        if (node == q.back() && !node->childl && !node->childr) {
            std::cout << node->data << std::endl;
        } else {
            std::cout << node->data << " ";
        }
        q.pop();
        if (node->childl != NULL) {
            q.push(node->childl);
        }
        if (node->childr != NULL) {
            q.push(node->childr);
        }
    }
}

int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("1.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }
    Node* root = create(0, n - 1, 0, n - 1);
    BFS(root);
    fclose(stdin);
    return 0;
}