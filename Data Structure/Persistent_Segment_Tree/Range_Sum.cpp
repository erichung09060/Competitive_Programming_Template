#define MAXN 1000005
int Root[MAXN], L_child[10000005], R_child[10000005], sum[10000005], node;

int built(int l, int r) {
    int curNode = node++;
    sum[curNode]=0;
    if (l == r) return curNode;
    int mid = (l + r) / 2;
    L_child[curNode] = built(l, mid);
    R_child[curNode] = built(mid + 1, r);
    return curNode;
}

int insert(int root, int l, int r, int target, int val) {
    int curNode = node++;
    L_child[curNode] = L_child[root];
    R_child[curNode] = R_child[root];
    sum[curNode] = sum[root] + val;
    if (l == r) return curNode;
    int mid = (l + r) / 2;
    if (target <= mid)
        L_child[curNode] = insert(L_child[root], l, mid, target, val);
    else
        R_child[curNode] = insert(R_child[root], mid + 1, r, target, val);
    return curNode;
}

int query(int curNode, int l, int r, int lb, int rb) {
    if (lb <= l && r <= rb) return sum[curNode];
    int mid = (l + r) / 2;
    int ans = 0;
    if (lb <= mid)
        ans += query(L_child[curNode], l, mid, lb, rb);
    if (mid + 1 <= rb)
        ans += query(R_child[curNode], mid + 1, r, lb, rb);

    return ans;
}

/*
Usage:
    Root[0]=built(1, n);     //empty tree
    Root[index]=insert(root_of_based_on_which_tree, 1, n, target, value);    //insert value at target
    query(root_of_tree, 1, n, queryL, queryR);     //query sum of range [queryL, queryR]
    
Things need to do:
    define MAXN
*/
