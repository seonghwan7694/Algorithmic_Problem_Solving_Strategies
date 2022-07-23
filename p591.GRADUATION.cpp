#include <iostream>
#include <algorithm>
#include <cstring> 
using namespace std;
#define INF 987654321
#define MAX 12
// n: 전공과목 수 k: 들어야할 과목의 수 
// m: 학기 수 l: 한 학기에 최대로 들을 수 있는 과목의수
int n, k, m, l;
// prerequiiste[i] = i번째 과목의 선수과목의 집합
int prerequisite[MAX];
// classes[i] = i번째 학기에 개설되는 과목의 집합
int classes[10];
int cache[10][1 << MAX];
 
// N의 이진수 표현에서 켜진 비트의 수 반환
int bitcount(int n){
    if (n == 0)return 0;
    return n % 2 + bitcount(n / 2);
}
 
// 현재 학기 semester, 들은 과목의 수 taken
int graduate(int semester, int taken){
    // k개 이상의 과목을 이미 들은 경우
    if (bitcount(taken) >= k) return 0;
 
    // 주어진 학기내에서 모든 과목을 이수하지 못한 경우
    if (semester == m) return INF;
 
    int &ret = cache[semester][taken];
    if (ret != -1) return ret;
    ret = INF;
 
    // 이번 학기에 들을 수 있는 과목 중 아직 듣지 않은 과목들을 찾는다
    int canTake = (classes[semester] & ~taken);
 
    // 선수 과목을 다 듣지 않은 과목들을 걸러낸다
    for (int i = 0; i < n; i++){
        if ((canTake&(1 << i)) && (taken&prerequisite[i]) != prerequisite[i])
            canTake &= ~(1 << i);
    }
    //최소 학기 수 비교
    for (int take = canTake; take>0; take = ((take - 1)&canTake)){
        // 한 학기에 최대 l개 까지만 들을 수 있다
        if (bitcount(take) > l) continue;
        ret = min(ret, graduate(semester + 1, taken | take) + 1);
    }
 
    // 이번 학기에 아무 것도 듣지 않을 경우
    ret = min(ret, graduate(semester + 1, taken));
    return ret;
}
 
int main(){
    int c; cin >> c;
    while (c--){
 
        
        memset(prerequisite, 0, sizeof(prerequisite));
        memset(classes, 0, sizeof(classes));
        memset(cache, -1, sizeof(cache));
 
        cin >> n >> k >> m >> l;
        // 과목별 선행 과목 정보
        for (int i = 0; i < n; i++){
            int preNum; cin >> preNum;
            for (int j = 0; j < preNum; j++){
                int subject; cin >> subject;
                prerequisite[i] |= (1 << subject);
            }
        }
        // 한 학기에 열리는 과목 개수
        for (int i = 0; i < m; i++){
            int classNum; cin >> classNum;
            for (int j = 0; j < classNum; j++){
                int subject; cin >> subject;
                classes[i] |= (1 << subject);
            }
        }
 
        int res = graduate(0, 0);
        if (res == INF) cout << "IMPOSSIBLE\n";
        else cout << res << '\n';
    }
}