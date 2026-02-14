#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    int k;
    scanf("%d",&k);

    int index = -1;
    int count = 0;

    for (int i = 0; i < n; i++) {
        count++;
        if (arr[i] == k) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Found at index %d\n", index);
    } else {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", count);

}