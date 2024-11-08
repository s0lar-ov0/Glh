#include<stdio.h>
int main(){
    int m, n, a[10][100] = {0};  // 声明二维数组，最多10行100列
    scanf("%d %d", &m, &n);  // 输入行数m和列数n

    // 输入二维数组的每个元素
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    // 遍历每一行，寻找连续的1
    for(int i = 0; i < m; i++){
        int sum = 0, b[100] = {0}, f[100] = {0}, c = 0, q = 0;
        int currentstart = -1;
        
        for(int j = 0; j < n; j++){
            if(a[i][j] == 1){  // 当前元素是1，表示连续部分的开始
                sum = sum + 1;  // 连续1的长度加1
                if(currentstart == -1){  // 如果是当前行的第一个1
                    f[c] = j;  // 记录起始位置
                }
                currentstart = 0;
                
                // 如果当前元素后面是0，表示连续段结束
                if(j == n - 1 || a[i][j + 1] == 0){  // j == n - 1 处理最后一列是1的情况
                    b[c] = sum;  // 记录当前连续1的长度
                    c = c + 1;  // 移动到下一个段
                    sum = 0;  // 重置当前段长度
                    currentstart = -1;  // 重置起始位置
                }
            }
        }

        // 如果没有找到连续的1，输出-1 -1
        if(c == 0){
            printf("-1 -1\n");
        } else {
            // 寻找最大长度的连续1段
            int max = b[0], qishi = f[0];
            for(int k = 1; k < c; k++){
                if(b[k] > max){
                    max = b[k];
                    qishi = f[k];
                }
            }
            // 输出最长连续1的起始位置和结束位置
            printf("%d %d\n", qishi, qishi + max - 1);
        }
    }

    return 0;
}