#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int d[52];
string s;
string word[52];
int cnt[52][26];
int n;
bool cmp(int* a, int* b) {
    for(int i = 0;i < 26;i++){
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(20);
    /////////////////////////////////////////////// system���� �κа� �ڵ尡 �۵��ϴ� �κ��� ������ ������� ���ϰ� ��. �����Ұ�
    cin >> s;
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> word[i];
        for (auto c : word[i]) cnt[i][c - 'a']++;//word[i]�� � ������Ұ� �� �� �ִ� �� ã�� �Լ���.
    }
    fill(d, d + 51, 0x7f7f7f);//d�� �ʱ�ȭ�ϴ� �Լ�
    d[0] = 0;
    for(int i = 0;i < s.size();i++)
    {
        int cnt2[26] = {};
        for (int j = i; j >= 0; j--) {
            cnt2[s[j] - 'a']++;
            for (int k = 0; k < n; k++) {
                if (cmp(cnt2, cnt[k])) {
                    int score = 0;
                    for (int z = j; z <= i; z++) {
                        if (word[k][z - j] != s[z]) score++;
                    }
                    d[i + 1] = min(d[i + 1], d[j] + score);
                }
            }
        }
    }
    if (d[s.size()] == 0x7f7f7f) d[s.size()] = -1;
    cout << d[s.size()];
}

/*
    ���������κ��� ū ���� ���ϴ� dp ����� ����.


*/