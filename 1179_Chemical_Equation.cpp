#include "iostream"
#include "string"
#include "vector"
#include "map"
#include "algorithm"
using namespace std;

map<string, bool> have;
vector<string> target;
map<string, vector<vector<string>>> equ;
vector<vector<string>> res;
bool finish = false;

//字典序排序，这里询问了ai
bool comp(vector<string>& a, vector<string>& b) {
    int i = 0;
    while (i < a.size() && i < b.size()) {
        if (a[i] == b[i]) {
            i++;
        }
        else {
            break;
        }
    }
    if (i == a.size() || i == b.size()) {
        return a.size() < b.size();
    }
    return a[i] < b[i];
}

//输出答案
void myprint(int m) {
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < res[i].size() - 1;j++) {
            cout << res[i][j] << " + ";
        }
        cout << res[i][res[i].size() - 1] << " -> ";
        cout << target[i] << endl;
    }
}

void dfs(int index, int m) {
    if (finish) {
        return;
    }
    if (index == m) {
        finish = true;
        myprint(m);
        return;
    }
    string key = target[index];
    for (int i = 0;i < equ[key].size();i++) {
        bool flag = true;
        for (auto need : equ[key][i]) {
            if (!have[need]) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            continue;
        }
        for (auto need : equ[key][i]) {
            have[need] = false;
        }
        res.push_back(equ[key][i]);
        dfs(index + 1, m);
        res.pop_back();
        for (auto need : equ[key][i]) {
            have[need] = true;
        }
    }
    return;
}

int main() {
    int n, m, k;
    cin >> n;
    for (int i = 0;i < n;i++) {
        string s;
        cin >> s;
        have[s] = true;
    }
    cin >> m;
    for (int i = 0;i < m;i++) {
        string s;
        cin >> s;
        target.push_back(s);
        equ[s].push_back(vector<string>{s});
    }
    cin >> k;
    for (int i = 0;i < k;i++) {
        string s;
        vector<string> temp;
        while (true) {
            cin >> s;
            if (s != "+" && s != "->") {
                temp.push_back(s);
            }
            else if (s == "->") {
                break;
            }
        }
        cin >> s;
        equ[s].push_back(temp);
        sort(equ[s].begin(), equ[s].end(), comp);
    }
    dfs(0, m);
    return 0;
}