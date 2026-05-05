#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *newNode(int data) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

Node *buildTree(int *arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    Node **queue = (Node **)malloc(n * sizeof(Node *));
    int front = 0, rear = 0, i = 1;
    Node *root = newNode(arr[0]);
    queue[rear++] = root;
    while (front < rear && i < n) {
        Node *curr = queue[front++];
        if (i < n && arr[i] != -1) { curr->left  = newNode(arr[i]); queue[rear++] = curr->left;  } i++;
        if (i < n && arr[i] != -1) { curr->right = newNode(arr[i]); queue[rear++] = curr->right; } i++;
    }
    free(queue);
    return root;
}

void zigzag(Node *root) {
    if (!root) return;

    Node **q     = (Node **)malloc(1024 * sizeof(Node *));
    int  *level  = (int *)malloc(1024 * sizeof(int));
    int front = 0, rear = 0;

    q[rear] = root; level[rear++] = 0;

    int curLevel = 0, levelStart = 0, printed = 0;

    while (front < rear) {
        Node *curr = q[front];
        int   lv   = level[front++];

        if (lv != curLevel) {
            int levelLen = front - 1 - levelStart;
            int leftToRight = (curLevel % 2 == 0);
            for (int i = 0; i < levelLen; i++) {
                int idx = leftToRight ? levelStart + i : levelStart + levelLen - 1 - i;
                if (printed++) printf(" ");
                printf("%d", q[idx]->data);
            }
            curLevel  = lv;
            levelStart = front - 1;
        }

        if (curr->left)  { q[rear] = curr->left;  level[rear++] = lv + 1; }
        if (curr->right) { q[rear] = curr->right; level[rear++] = lv + 1; }
    }

    int levelLen = front - levelStart;
    int leftToRight = (curLevel % 2 == 0);
    for (int i = 0; i < levelLen; i++) {
        int idx = leftToRight ? levelStart + i : levelStart + levelLen - 1 - i;
        if (printed++) printf(" ");
        printf("%d", q[idx]->data);
    }
    printf("\n");

    free(q);
    free(level);
}

int main(void) {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    Node *root = buildTree(arr, n);
    zigzag(root);
    free(arr);
    return 0;
}