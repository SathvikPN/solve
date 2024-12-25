#include<bits/stdc++.h>
using namespace std;
 
const long long MOD = 1e9+7;

bool visited[7][7] = {{}};
long long valid_paths=0;
string s;

// directions and offsets 
// Up, Down, Left, Right
int dy[4] = {-1, 1,  0, 0};
int dx[4] = { 0, 0, -1, 1};
char d[4] = {'U', 'D', 'L', 'R'};

bool isValid(int y, int x){
    bool bounded = (y>=0 && y<=6 && x>=0 && x<=6);
    bool isVisited = visited[y][x];
    return (bounded && !isVisited);
}

void dfs(int y, int x, int steps){
    if(y==6 && x==0){
        if (steps==48) valid_paths++;
        cout << valid_paths << " ";
        return;
    }

    if(steps==48) return;

    visited[y][x] =  true;
    for(auto i=0; i<4; i++){
        if(s[steps] == '?' || s[steps] == d[i]){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (isValid(y, x)){
                dfs(ny, nx, steps+1);
            }
        }
    }
    visited[y][x] = false;
}

void solution(){
    cin >> s;
    dfs(0,0,0);
    cout << valid_paths;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
    return 0;
}

// // refer: https://www.youtube.com/watch?v=2maNV12bzJo OR https://www.youtube.com/watch?v=wWUWA70drAY
// void solution(){
//     string s; cin >> s;

//     const int N=7-1; // {0,1,2 ... 7-1} (6)
//     const int MAX_STEPS=(7 * 7) - 1; // total steps to traverse all boxes in 7ension. (48)

//     bool visited[7][7] = {{}};
//     long long valid_paths=0, steps=0;

//     // directions and offsets 
//     // Up, Down, Left, Right
//     int dy[4] = {-1, 1,  0, 0};
//     int dx[4] = { 0, 0, -1, 1};
//     char d[4] = {'U', 'D', 'L', 'R'};

//     auto isValid = [&](int y, int x) {
//         return (
//             y >= 0 && y <= N &&
//             x >= 0 && x <= N &&
//             !visited[y][x]
//         );
//     };

//     // nested lambda function: [&] --> vars by reference of solution() scope
//     function<void(int,int)> dfs = [&](int y, int x) {
//         // destination reached
//         if(y==N && x==0){
//             if(steps==MAX_STEPS) valid_paths++;
//             return;
//         }

//         if(steps == MAX_STEPS) return;
//         visited[y][x] = true;

//         // try each direction 
//         for(int i=0; i<4; i++){
//             // return if direction donot match path enforced by description
//             // steps+1(nextStep) -1(zero based string idx)
//             if(s[steps+1-1] != '?' &&
//                 s[steps+1-1] != d[i]){
//                 continue;
//             }
                
//             // next box
//             int ny = y + dy[i];
//             int nx = x + dx[i];
//             if (isValid(ny, nx)){
//                 steps++;
//                 dfs(ny, nx);
//                 steps--;
//             }
//         }

//         visited[y][x] = false;
//     };

//     dfs(0,0);
//     cout << valid_paths;
// }
