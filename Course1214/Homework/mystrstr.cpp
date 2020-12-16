#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>

using namespace std;

char *my_strstr(char *cs, char *ct) { 
    int cslen = strlen(cs), ctlen = strlen(ct);
	if (cslen < ctlen) return NULL;
	for (int i = 0; i <= cslen - ctlen; i++) {
		char *head = cs + i;
		int match_cnt = 0;
		for (int j = 0; j < ctlen; j++) {
			if (*(head+j) == *(ct+j)) {
				match_cnt++;
			} else {
				break;
			}
		}
		if (match_cnt == ctlen) return head;
	}
	return NULL;
}

int main() {
    char a[4096], b[4096];
    memset(a, 0, sizeof a); // 这两行用于给数组a和b清0。
    memset(b, 0, sizeof b);
   	gets(a); // 这行表示读入一个字符串，并读到数组a中。下一行类似。
    gets(b);
    char *first_occur = my_strstr(a, b);
    if (first_occur == NULL) {
        cout << "Not exist" << endl;
    } else {
        int diff = first_occur - a; // 想想这一行表示什么？
	    cout << diff << endl;
    }
    return 0;
}