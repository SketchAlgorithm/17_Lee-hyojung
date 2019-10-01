//https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWgqsAlKr9sDFAW0

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int T;
long N;//2 <= N <= 10^12
int Tcount = 1;

void func() {
	long count = 0;
	while (N != 2) {
		long result1 = (long)sqrt(N);

		if(result1*result1==N){
		//if ( result1-(int)result1 == 0) {//Á¤¼ö
			N = result1;
		}
		else {
			count += (result1 + 1) * (result1 + 1) - N;
			N = result1 + 1;
		}
		count++;
	}
	printf("#%d %ld\n", Tcount++, count);
}

int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		func();
	}
	return 0;
}