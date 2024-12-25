// checkout: 
// https://cses.fi/problemset/hack/1625/entry/11535489/
// https://cses.fi/problemset/hack/1625/entry/11534300/
// https://cses.fi/problemset/hack/1625/entry/11530254/

// C++ Code
#include <bits/stdc++.h>
using namespace std;

// Macro to check if a coordinate is valid in the grid
#define isValid(a) (a >= 0 && a < 7 ? 1 : 0)

// Direction constants
#define right 0
#define left 1
#define down 2
#define up 3

// Direction vectors for right, left, down, and up
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

// The path description string
string str;
int vis[7][7];

// Function to count the number of paths that match the
// description
int countPaths(int y, int x, int pos)
{
    // If we have processed all characters in the string and
    // we are at the lower-left square, return 1
    if (pos == (int)str.length())
        return (y == 6 && x == 0);

    // If we have reached the lower-left square before
    // processing all characters, return 0
    if (y == 6 && x == 0)
        return 0;

    // If the current cell is already visited, return 0
    if (vis[y][x])
        return 0;

    // Array to keep track of the visited status of the
    // neighboring cells
    vector<bool> visited(4, -1);
    for (int k = 0; k < 4; k++)
        if (isValid(y + dx[k]) && isValid(x + dy[k]))
            visited[k] = vis[y + dx[k]][x + dy[k]];

    // If we are at a position such that the up and down
    // squares are unvisited and the left and right squares
    // are visited return 0
    if (!visited[down] && !visited[up] && visited[right]
        && visited[left])
        return 0;

    // If we are at a position such that the left and right
    // squares are unvisited and the up and down squares are
    // visited return 0
    if (!visited[right] && !visited[left] && visited[down]
        && visited[up])
        return 0;

    // If we are at a position such that the upper-right
    // diagonal square is visited and the up and right
    // squares are unvisited return 0
    if (isValid(y - 1) && isValid(x + 1)
        && vis[y - 1][x + 1] == 1)
        if (!visited[right] && !visited[up])
            return 0;

    // If we are at a position such that the lower-right
    // diagonal square is visited and the down and right
    // squares are unvisited return 0
    if (isValid(y + 1) && isValid(x + 1)
        && vis[y + 1][x + 1] == 1)
        if (!visited[right] && !visited[down])
            return 0;

    // If we are at a position such that the upper-left
    // diagonal square is visited and the up and left
    // squares are unvisited return 0
    if (isValid(y - 1) && isValid(x - 1)
        && vis[y - 1][x - 1] == 1)
        if (!visited[left] && !visited[up])
            return 0;

    // If we are at a position such that the lower-left diagonal
    // square is visited and the down and right squares are
    // unvisited return 0
    if (isValid(y + 1) && isValid(x - 1)
        && vis[y + 1][x - 1] == 1)
        if (!visited[left] && !visited[down])
            return 0;

    // Mark the current cell as visited
    vis[y][x] = 1;

    // Variable to store the number of paths
    int numberOfPaths = 0;

    // If the current character is '?', try all four
    // directions
    if (str[pos] == '?') {
        for (int k = 0; k < 4; k++)
            if (isValid(y + dx[k]) && isValid(x + dy[k]))
                numberOfPaths += countPaths(
                    y + dx[k], x + dy[k], pos + 1);
    }

    // If the current character is a direction, go in that
    // direction
    else if (str[pos] == 'R' && x + 1 < 7)
        numberOfPaths += countPaths(y, x + 1, pos + 1);
    else if (str[pos] == 'L' && x - 1 >= 0)
        numberOfPaths += countPaths(y, x - 1, pos + 1);
    else if (str[pos] == 'U' && y - 1 >= 0)
        numberOfPaths += countPaths(y - 1, x, pos + 1);
    else if (str[pos] == 'D' && y + 1 < 7)
        numberOfPaths += countPaths(y + 1, x, pos + 1);

    // Unmark the current cell
    vis[y][x] = 0;

    // Return the number of paths
    return numberOfPaths;
}

// Driver Code
int main()
{
    cin >> str;
    cout << countPaths(0, 0, 0) << endl;
}
