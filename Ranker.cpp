#include<bits/stdc++.h>
using namespace std;
#define lld long long
#define llu long long unsigned
#define F first
#define S second
#define mod 1000000007
#define INF 1000000000
#define sd(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define su(n) scanf("%llu",&n)
#define pdn(n) printf("%d\n",n)
#define pln(n) printf("%lld\n",n)
#define pun(n) printf("%llu\n",n)
#define pd(n) printf("%d",n)
#define pl(n) printf("%lld",n)
#define pu(n) printf("%llu",n)
#define pn printf("\n")
#define ps printf(" ")
#define gc getchar_unlocked
#define fill(a,x) memset(a,x,sizeof(a))
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define tr(c,i) for(typeof(c.begin()) it=c.begin();it!=c.end();it++)
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef pair<int,int> PII;
/*inline int ri()
{
  int ret=0;
  char c=gc();
  while(c<'0'||c>'9') c=gc();
  while(c>='0'&&c<='9')
  {
    ret=10*ret+c-48;
    c=gc();
  }
  return ret;
}
inline long long rll()
{
  long long ret=0;
  char c=gc();
  while(c<'0'||c>'9') c=gc();
  while(c>='0'&&c<='9')
  {
    ret=10*ret+c-48;
    c=gc();
  }
  return ret;
}*/
int stringToInt(string f)
{
	int n = 0;
	for(int i = 0; i<f.length(); i++){
		n += f[i] - '0';
		n *= 10;
	}
	n /= 10;
	return n;
}
int main()
{
    std::ios::sync_with_stdio(false);
	vector< pair< pair<int, string>, pair<string, int> > > all, final;
	ifstream fin("data");
	ofstream fout("out.csv");
	int rank, com = 1, problemSolved;
	string s, teamName, collegeName;
	while(getline(fin,s)){
		com = 1;
		rank = problemSolved = 0;
		teamName = collegeName = "";
		string temp = "";
		for(int i = 0; i<s.length(); i++){
			if(s[i] == '"'){
				i++;
				while(s[i] != '"'){
					temp += s[i];
					i++;
				}
				continue;
			}
			if(s[i] == ',' && com == 1){
				rank = stringToInt(temp);
				temp = "";
				com++;
				continue;
			}
			else if(s[i] == ',' && com == 2){
				teamName = temp;
				temp = "";
				com++;
				continue;
			}
			else if(s[i] == ',' && com == 3){
				collegeName = temp;
				temp = "";
				com++;
				continue;
			}
			temp += s[i];
		}
		problemSolved = temp[0] - '0';
		temp = "";
		if(problemSolved != 0)
			all.PB(MP(MP(rank, teamName), MP(collegeName, problemSolved)));
	}
	for(int i = 0; i<all.size(); i++){
		string ta = all[i].S.F;
		vector< pair< pair<int, string>, pair<string, int> > >::iterator bi = std::find_if(final.begin(), final.end(),[&ta](const pair< pair<int, string>, pair<string, int> >& p){ return p.S.F == ta; });
		if(bi == final.end())
			final.PB(MP(MP(all[i].F.F,all[i].F.S),MP(all[i].S.F,all[i].S.S)));		
	}
	for(int i = 0; i<final.size(); i++){
		int cflag = 0;
		string tem = "";
		tem += '"';
		for(int j = 0; j<final[i].S.F.length(); j++){
			if(final[i].S.F[j] == ','){
				tem += final[i].S.F;
				cflag = 1;
				break;
			}
		}
		tem += '"';
		if(cflag)
			fout<<i+1<<","<<final[i].F.F<<","<<final[i].F.S<<","<<tem<<","<<final[i].S.S<<"\n";
		else			
			fout<<i+1<<","<<final[i].F.F<<","<<final[i].F.S<<","<<final[i].S.F<<","<<final[i].S.S<<"\n";
	}
    return 0;
}