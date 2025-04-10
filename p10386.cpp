#include <iostream>
using namespace std;
int a[30],b[10][10];
bool check(){
    int pos = 0;
    for(int i = 0;i < 5;i++){
        for(int j = 0; j< 5;j++){
            b[i][j]=a[pos++];
        }
    }
    for(int i = 0; i < 5; i++) {
        if ((b[i][0] == b[i][1]) && (b[i][1] == b[i][2]) && (b[i][2] == b[i][3]) && (b[i][3] == b[i][4]))
            return false;
    }

    for(int j = 0; j < 5; j++) {
        if ((b[0][j] == b[1][j]) && (b[1][j] == b[2][j]) && (b[2][j] == b[3][j]) && (b[3][j] == b[4][j]))
            return false;
    }

    if ((b[0][0] == b[1][1]) && (b[1][1] == b[2][2]) && (b[2][2] == b[3][3]) && (b[3][3] == b[4][4]))
        return false;

    if ((b[0][4] == b[1][3]) && (b[1][3] == b[2][2]) && (b[2][2] == b[3][1]) && (b[3][1] == b[4][0]))
        return false;

    return true;
}
int main(){
    int ans = 0;
    for(int i = 0;i < (1<<25);i++){
        int s = 0;
        for(int j = 0 ;j < 25 ; j++){
            a[j]=(i>>j)&1;
            if(a[j]) s++;
        }
        if(s!=13) continue;
        if(check()) ans++;
    }
    cout<<ans;
}
