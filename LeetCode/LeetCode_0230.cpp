class Solution {
public:
    int rank = 1, answer = -1;
    int K;

    void go(TreeNode* cur){
        if(cur == nullptr || answer != -1) return;

        if(cur->left != nullptr){
            go(cur->left);
        }

        if(rank++ == K){
            answer = cur->val;
            return;
        }

        if(cur->right != nullptr){
            go(cur->right);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        K = k;
        go(root);
        return answer;
    }
};
