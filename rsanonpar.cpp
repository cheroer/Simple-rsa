//============================================================================
// Name        : rsa.cpp
// Author      :
// Version     :
// Copyright   : SkliF
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector.h>
#include <algorithm>
#include <string>
using namespace std;

long long int powerMod(long long int pa, long long int pd, long long int pn){
	long long int r;
	long long int i;
	long long int tmp = 0;

	r = (long long int) (log(abs(pd))/log(2)) + 1;
	int bin[r];
	long long int dec[r];

	tmp = pd;
	//cout << "bin: ";
	for (i = 0; i < r; i++){
		bin[r-i-1] = tmp % 2;
		//cout << bin[r-i-1];
		tmp = (long long int) (tmp / 2);
	}
//  cout << endl;
	dec[0] = pa;
	for (i = 1; i < r; i++){
		dec[i] = (long long int)((dec[i-1]*dec[i-1] * pow(pa,bin[i]))) % pn;
	//	cout << dec[i-1] << "*" << dec[i-1] << "*" << pa << "^" << bin[i] << "%" << pn <<endl;
	//	cout << dec[i] << " " << endl;
	}

	return dec[r-1];
}

bool prost(int n) {
	bool k = true;
	if (n != 2){
		for (int i = 2; i < (int) sqrt(n) + 1; i++){
			if (n % i == 0){
				k = false;
				break;
			}
		}
	}
	return k;
}

int genProst(){
	int t = 10 + rand() % 90;

	do{
		t++;
	} while (!prost(t));

	return t;
}

int evklid(int num1, int num2){
	vector<int> r;
	int i=1;
	r.push_back(max(num1,num2));
	r.push_back(min(num1,num2));
	while (r[i] != 0) {
		i++;
		r.push_back(r[i-2] % r[i-1]);
	}
	return r[i-1];
}

int genCoprime(int x) {
	//ispolzuem chisla Ferma
	int i = 1 + rand() % 99;
	do {
		i++;
	} while (evklid(x,i) != 1);
	return i;
}

int gend(int f, int e) {
	//return (int) ((f * (1 + rand() % 4) + 1) / e);
	int i;
	for (i=1;i<100;i++) {
		cout << ((f * (i) + 1) % e) <<endl;
		if ( ((f * (i) + 1) % e) == 0) {
			return (int) ((f * (i) + 1) / e);
		}
	}
	return 0;
}

int main() {
	srand((unsigned)time(0));

	// Generate Keys

	long long int e,d,n,f,p,q;

	p = genProst();
	q = genProst();
	f = (p-1)*(q-1);
	n = p*q;
	e = genCoprime(f);
	d = gend(f,e);

/*	p = 61;
	q = 53;
	n = p * q;
	f = (p-1)*(q-1);
	e = 17;
//	d = 2753;
	d = gend(f,e);
*/

	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "n = " << n << endl;
	cout << "f = " << f << endl;
	cout << "e = " << e << endl;
	cout << "d = " << d << endl;

	/*long long int c = powerMod(111111,e,n);
	cout << c << endl;
	cout << powerMod(c,d,n) << endl;*/
	string a,b;
	unsigned int i;
	long long int x;
	vector<long long int> c;

	//Encryption

	a="crypto";
	for (i=0;i<a.size();i++) {
		x=(int)a.at(i);
		//x=204;
		cout << x << " ";
		c.push_back(powerMod(x,e,n));
		//cout << " "<< powerMod(c.at(i),d,n);
		//cout << powerMod(x,e,n);
	}
	for (i=0;i<c.size();i++) {
		//cout << char(c.at(i));
	}
	cout << endl;

	// Decryption

	for (i=0;i<c.size();i++) {
		cout << powerMod(c.at(i),d,n) << " ";
		//cout << char(powerMod(c.at(i),d,n));
	}

	//cout << endl << "omg1: " << powerMod(99,1664,5141) << endl;
	//cout << endl << "omg2: " << powerMod(4400,3,5141) << endl;
	//cout << endl << 4400*4400
	/*cout << endl;
	x = powerMod(123,e,n);
	//x = powerMod(123,17,3233);
	cout << x << " ";
	cout << endl;
	cout << powerMod(x,d,n) << endl;
	//cout << powerMod(x,2753,3233) << endl;
	//cout << powerMod(123,2,5) << endl;
	*/
	return 0;
}

