# pragma GCC optimize ("O3")
# pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int T, N_1, N_2;

const int child_size = 63;

inline int convert(char ch) {
    if (ch == '.') return 0;
    if (ch >= 48 && ch <= 57) return ch - 47;
    if (ch >= 65 && ch <= 90) return ch - 54;
    if (ch >= 97 && ch <= 122) return ch - 60;
}

struct Node {
    vector<Node *> child;

    short isEnd;
    bool mustDelete;
    bool hasChild;

    ~Node() {
        for (int i = 0; i < child_size; i++) {
            if (child[i] != nullptr) {
                delete child[i];
            }
        }
    }
};

Node *getNode(void) {
    Node *pNode = new Node;

    pNode->isEnd = 0;
    pNode->child.assign(child_size, nullptr);
    return pNode;
}

void insert(Node *root, string str, bool flag) {
    Node *pCrawl = root;

    for (int i = 0; i < str.length(); i++) {
        int index = convert(str[i]);
        if (!pCrawl->child[index]) {
            pCrawl->child[index] = getNode();
            pCrawl->hasChild = true;
        }
        pCrawl = pCrawl->child[index];
        pCrawl->mustDelete = flag;
    }

    pCrawl->isEnd = (flag) ? (1) : (2);
}


int answer;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        answer = 0;
        Node *root = getNode();

        cin >> N_1;

        string tmp;
        for (int i = 0; i < N_1; i++) {
            cin >> tmp;
            insert(root, tmp, true);
        }

        cin >> N_2;
        for (int i = 0; i < N_2; i++) {
            cin >> tmp;
            insert(root, tmp, false);
        }

        if (N_2 == 0) {
            cout << 1 << '\n';
            delete root;
            continue;
        }

        queue<Node *> que;
        que.push(root);

        while (!que.empty()) {
            Node *curNode = que.front();
            que.pop();

            for (int i = 0; i < child_size; i++) {
                auto nxt = curNode->child[i];
                if (!nxt) continue;

                if (nxt->mustDelete) {
                    answer++;
                } else {
                    if (nxt->isEnd == 1) {
                        answer++;
                    }

                    if (nxt->hasChild)
                        que.push(nxt);
                }
            }
        }

        cout << answer << '\n';
        delete root;
    }

}
