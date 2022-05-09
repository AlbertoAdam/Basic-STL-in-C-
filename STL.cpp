#include <iostream>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<list>
#include <algorithm>
#include <utility>

struct Punct{
	int x, y;
};


using namespace std;

vector <int> a = {1,2,2,1,1,7,5,7,5,7,7,5,5 };
vector <int> b;
vector <int> b1 = {3,4,0,7,2};
int n;
Punct ve[1001];
void Afis(int x);
void Afis_V(vector <int> a);
void Sortari(vector <int> a);
bool Compara(const Punct A, const Punct B);
int SumaCif(int n);
void SortSumaCif(vector<int> a);
int DifMaxima(vector <int> a);
int NrMinMaxAp(vector<int>& a);
vector<int> CountNum(vector<int>& a, int S);

int main()
{
	/*for (auto elem : a) {
		cout << elem << " ";
	}
	cout << "\n";
	cout << "\n";
	for_each(a.begin(), a.end(), Afis);*/

	/*cin >> n;
	for (int i = 0; i < n; i++) {
		b.push_back(i + 1);
	}*/
	/*cout << "\n";
	for_each(b.begin(), b.end(), Afis);
	cout << "\n";

	random_shuffle(b.begin(), b.end());
	Afis_V(b);

	b.pop_back();
	Afis_V(b);

	Sortari(b);*/
	//sortare puncte in plan !!!! 

	//srand(time(0));
	//n = 30;
	//for (int i = 0; i < n; i++) {
	//	ve[i].x = -50 + rand() % 100;
	//	ve[i].y = -50 + rand() % 100;
	//}
	//sort(ve, ve + n, Compara);
	//for (int i = 0; i < n; i++) {
	//	cout << ve[i].x << " " << ve[i].x << "\n";
	//}
	 ///SortSumaCif(a);
	cout << NrMinMaxAp(a);
	b = CountNum(b1, 7);
	for (auto e : b1) cout << e << " ";

}
void Afis(int x) {
	cout << x << " ";
}
void Afis_V(vector <int> a) {
	for_each(a.begin(), a.end(), Afis);
	cout << "\n";
}

void Sortari(vector <int> a)
{
	int n = a.size();
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";
}

bool Compara(const Punct A, const Punct B) {
	if (A.x == B.x) return A.y < B.y;
	return A.x < B.x;
}

int SumaCif(int n) {
	int s = 0;
	while (n) {
		s = s + n % 10;
		n /= 10;
	}
	return s;
}
// fct sortare vector dupa suma cifrelor fiecarui element
void SortSumaCif(vector<int> a) {
	vector < pair <int, int> >v; // vector de perechi de lungine n, v[i], memoreaza perechea {s,x}
	// unde s suma cifrelor si x elementul din a
	for (auto x : a) {
		int s = SumaCif(x);
		v.push_back({ s,x });
	}
	sort(v.begin(), v.end());
	for (auto e : v)
		cout << e.second << " ";
}

int DifMaxima(vector <int> a) {
	int pozMin, difMax = 0;
	int n = a.size();
	vector<pair <int, int > > v;
	for (int i = 0; i < n; i++) {
		v.push_back({a[i], i}); /// perechea valoare indice
	}
	sort(v.begin(), v.end());// fct sort face implict sortarea dupa primul intreg din pereche
	pozMin = v[0].second;
	for (int i = 1; i < n; i++) {
		difMax = max(difMax, v[i].second - pozMin);
		pozMin = v[i].second;
	}
	return difMax;
}

int NrMinMaxAp(vector<int>& a)
{
	int n;
	int cntMax = 0;
	int nrMax = 0;
	int cntCurent = 0;
	sort(a.begin(), a.end());
	n = a.size();
	int nr_crt = a[0];
	for (int i = 1; i < n; i++){
		if (nr_crt == a[i]) cntCurent++;
		else {
			if (cntCurent > cntMax) {
				cntMax = cntCurent;
				nrMax = nr_crt;
			}
			else if (cntCurent == cntMax) {
				if (nr_crt < nrMax) nrMax = nr_crt;
			}
			cntCurent = 0;
		}
		nr_crt = a[i];
	}
	return nrMax;
}

vector<int> CountNum(vector<int>& a, int S) {
	vector<int>v;
	sort(a.begin(), a.end());
	for (auto e : a) {
		if (e <= S) v.push_back(e);
	}
	return v;
}
