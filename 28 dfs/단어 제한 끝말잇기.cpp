#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

int N;
int adj[26][26]; //adj[i][j]�� i���� j�� ���� ������ ��
int indegree[26], outdegree[26]; //indegree[i]�� i�� �����ϴ� �ܾ��� �� outdegree[i]�� �ݴ�
vector<string> words[26][26]; //words[i][j] = i�� �����ؼ� j�� ������ �ܾ� ����

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
	//Ʈ������ ��� ������ �ϳ�
	for (int i = 0; i < 26; i++)
	{
		if (outdegree[i] == indegree[i] + 1)
		{
			dfsEuler(i, Euler,"");
			return Euler;
		}
	}
	//��Ŷ�ϰ�� �Ǵ°� �ƹ����̳� �ѹ� ���� �ذ�
	for (int i = 0; i < 26; i++)
	{
		if (outdegree[i] > 0)
		{
			dfsEuler(i, Euler, "");
			return Euler;
		}
	}
	return Euler; //������ ��� ��迭
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
		//������ ���� ���Ϸ���Ŷ Ʈ������ �ƴ϶��
		if (!CheckEulerCircuitOrTrail())
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}
		stack<string> Euler = getEulerCircuit();
		//�� �迭�� ��� �ܾ ���ԵǾ� ���� ���� ���
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