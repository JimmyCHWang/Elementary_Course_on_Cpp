#include<cstdio>
#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include<chrono>
#include<random>

using namespace std;

FILE * in;
FILE * out;

int N; // Test Case Numbers
unsigned seed1;

void input(int casenum, mt19937 g1) {
	
    if (casenum<3) {
        int A = g1() % 101;
        fprintf(out, "%d\n", A);
    } else if (casenum<7) {
        int A;
		while ( (A = g1() % 100001) <= 100);
        fprintf(out, "%d\n", A);
    } else if (casenum != 9) {
		int A;
		while ( (A = g1() % 1000000001) <= 100000);
		fprintf(out, "%d\n", A);
	} else {
		long long A;
		do {
			A = (g1() % 10000000) * (g1() % 10000000);
		} while (A <= 1000000000ll && A > 1000000000000ll);
		fprintf(out, "%lld\n", A);
	}
	g1.discard(g1.state_size);
    return;
}

void generate_input(string qname) {
    seed1 = std::chrono::system_clock::now().time_since_epoch().count();
	mt19937 g1(seed1);
    N = 10;
    for (int i=0; i<N; i++) {
        string filename = qname + to_string(i) + ".in";
        out = fopen(filename.c_str(), "w");
        input(i, g1);
        fclose(out);
    }
    return;
}

void run_output(string qname) {
    system("@echo off");
    string command;
    for (int i=0; i<N; i++) {
        command = "copy " + qname + to_string(i) + ".in " + qname + ".in";
        system(command.c_str());
        system(qname.c_str());
        command = "copy " + qname + ".out " + qname + to_string(i) + ".out";
        system(command.c_str());
    }
    command = "del " + qname + ".in"; system(command.c_str());
    command = "del " + qname + ".out"; system(command.c_str());
    return;
}

int main() {
    string quesname = "sumdigit";
    generate_input(quesname);
    run_output(quesname);
    return 0;
}
