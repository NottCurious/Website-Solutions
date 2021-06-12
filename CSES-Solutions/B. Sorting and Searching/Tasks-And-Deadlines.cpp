#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;

int n, a, d;
long long timer, reward;
struct task {int a, d;} tasks[mxN];

int main (){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> d;
        tasks[i] = {a, d};
    }

    sort(tasks, tasks+n, [](task x, task y){
        return x.a == y.a ? x.d < y.d : x.a < y.a;
    });

    for(int i = 0; i < n; i++){
        timer += tasks[i].a;
        reward += (tasks[i].d - timer);
    }
    cout << reward;
}
