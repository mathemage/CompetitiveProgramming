#include <bits/stdc++.h>
using namespace std;

int N, M, P, Q;
int created_by[201];
bool follows_story[201][201];
bool follows_user[201][201];
bool follows_users_story[201][201];
bool follows_same_story[201][201];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i=1;i<=N;i++){
		cin >> created_by[i];
	}

	cin >> P >> Q;
	for (int i=1;i<=P;i++){
		int a, b; cin >> a >> b;
		follows_user[a][b] = 1;
	}
	for (int i=1;i<=Q;i++){
		int a, b; cin >> a >> b;
		follows_story[a][b] = 1;
	}

	for (int i=1;i<=M;i++){
		for (int j=1;j<=N;j++) if (follows_story[i][j]){
			follows_users_story[i][created_by[j]] = 1;
			for (int k=1;k<=M;k++) if (follows_story[k][j]) follows_same_story[i][k] = 1;
		}
	}

	for (int i=1;i<=M;i++){
		vector<pair<int, int>> scores;
		for (int j=1;j<=N;j++){
			int score = 0;
			if (created_by[j] == i || follows_story[i][j]) score = -1;
			else {
				for (int k=1;k<=M;k++){
					int a = 0, b = 0;

					if (i == k) a = 0;
					else if (follows_user[i][k]) a = 3;
					else if (follows_users_story[i][k]) a = 2;
					else if (follows_same_story[i][k]) a = 1;
					else a = 0;

					if (created_by[j] == k) b = 2;
					else if (follows_story[k][j]) b = 1;
					else b = 0;

					score += a*b;
				}
			}
			scores.emplace_back(-score, j);
		}
		sort(scores.begin(), scores.end());
		for (int j=0;j<3;j++) cout << scores[j].second << ' ';
		cout << '\n';
	}
}
