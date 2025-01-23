random note dumps

---

helper snippets:
```cpp
void print2D(int r,int c,vector<vector<char>>a){for(int y=0;y<r;++y){for(int x=0;x<c;++x){cout<<a[y][x]<<" ";}cout<<"\n";}}

// offsets{U,D, L,R}: directions
int dx[4]={0,0,-1,1}; 
int dy[4]={-1,1,0,0};

// direction offsets: d{Ux,Uy, Dx,Dy, Lx,Ly, Rx,Ry}
int d[8]={0,-1,0,1,-1,0,1,0};
```

Permutations and Combinations. ---------------------------------------------------------
as decision tree: <https://buildingvts.com/intuition-behind-permutations-and-combinations-db6ffa5272be>

k-slots & n-objects.

Number of ways to fill k-slots:-
if object can repeat: 
    n * n * n ... 
    n^k

if object cannot repeat:
    Consider different object positions in slot as count (nPk)
        n * (n-1) * (n-2) ... (n-k)
        n! / (n-k)!

    Donot consider different object positions in slot as count (nCk)
        nPk / k_ordering_count      (k_ordering_count = kPk)
        n! / (n-k)! / k!