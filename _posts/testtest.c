#include <stdio.h>

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        int arr[n][m];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                scanf("%d",&arr[i][j]);
            }
        }
        for(int j = 0;j<m;j++){
            for(int i = 0;i<n;i++){
                printf("%d ",arr[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}