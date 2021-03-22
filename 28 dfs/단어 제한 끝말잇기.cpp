#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

int N;
int adj[26][26]; //adj[i][j]는 i에서 j로 가는 간선의 수
int indegree[26], outdegree[26]; //indegree[i]는 i로 시작하는 단어의 수 outdegree[i]는 반대
vector<string> words[26][26]; //words[i][j] = i로 시작해서 j로 끝나는 단어 모음

bool CheckEulerCircuitOrTrail()
{
	int plus1 = 0, minus1 = 0;
	for (int i = 0; i < 26; i++)
	{
		int delta = outdegree[i] - indegree[i];
		if (delta < -1 || delta>1) return false;
		if (delta == -1) minus1++;
		if (delta == 1) plus1++;
	}
	return (minus1 == 1 && plus1 == 1) || (minus1 == 0 && plus1 == 0);
}

void dfsEuler(int n, stack<string>& E, string s)
{
	for (int i = 0; i < 26; i++)
	{
		if (adj[n][i] > 0)
		{
			adj[n][i]--;
			outdegree[n]--;
			indegree[i]--;
			string a = words[n][i].back();
			words[n][i].pop_back();
			dfsEuler(i, E, a);
		}
	}
	if(s!="")
	E.push(s);
}

stack<string> getEulerCircuit()
{
	stack<string> Euler;
	//트레일일 경우 시작점 하나
	for (int i = 0; i < 26; i++)
	{
		if (outdegree[i] == indegree[i] + 1)
		{
			dfsEuler(i, Euler,"");
			return Euler;
		}
	}
	//서킷일경우 되는곳 아무곳이나 한번 들어가면 해결
	for (int i = 0; i < 26; i++)
	{
		if (outdegree[i] > 0)
		{
			dfsEuler(i, Euler, "");
			return Euler;
		}
	}
	return Euler; //실패할 경우 빈배열
}

int main()
{
	cin.tie(0); cin.sync_with_stdio(0);
	int C; cin >> C;
	for (int ci = 0; ci < C; ci++)
	{
		cin >> N;
		memset(adj, 0, sizeof(adj));
		memset(indegree, 0, sizeof(indegree));
		memset(outdegree, 0, sizeof(outdegree));
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0 ; j < 26; j++)
			{
				words[i][j].clear();
			}
		}
		for (int i = 0; i < N; i++)
		{
			string s; cin >> s;
			int a = s.front() - 'a';
			int b = s.back() - 'a';
			words[a][b].push_back(s);
			adj[a][b]++;
			indegree[b]++;
			outdegree[a]++;
		}
		//차수에 의해 오일러서킷 트레일이 아니라면
		if (!CheckEulerCircuitOrTrail())
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}
		stack<string> Euler = getEulerCircuit();
		//얻어낸 배열에 모든 단어가 포함되어 있지 않을 경우
		if (Euler.size() != N)
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}
		while (!Euler.empty())
		{
			cout << Euler.top() << ' ';
			Euler.pop();
		}
		cout << '\n';
	}
}