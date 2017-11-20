
#include<bits/stdc++.h>

using namespace std;
#define MAX 1234
vector<int>depend[MAX];
vector<int>similar[MAX];
vector<int>tempAns,finalAns;
int visit[MAX];
int sameTask[MAX];
void dfs(int curNode){
      visit[curNode] =1;
      for(int i=0;i<depend[curNode].size() ;i++){
            int V = depend[curNode][i];
            if(visit[V])continue;
            dfs(V);
      }
      tempAns.push_back(curNode);
}
map<string,int>idSet;
map<int,string>revert;
pair<string,string> ans_me(string str){
      int second = 0;
      string temp;
      for(int i=0;i<str.size();i++){
            temp+=str[i];
            if(idSet.find(temp)!= idSet.end()){
                  second=i+1;
                  break;
            }
      }
      while(str[second]==' ')second++;
      string temp2 ;
      while(second < str.size()){
            temp2+= str[second];
            second++;
      }
      return {temp,temp2};
}

int main(void)
{
      int node;
      printf("The number of task: ");
      scanf("%d " ,&node);
      int id = 2;
      for(int i=0;i<node;i++){
            string str;
            getline(cin,str);
            if(str == "switch on"){
                  idSet[str] =1;
                  revert[1]="switch on";
            }
            else {
                  idSet[str]=id;
                  revert[id]=str;
                  id++;
            }
      }
      int dependency;
      printf("The number of dependency: ");
      scanf("%d ",&dependency);
      for(int i=1;i<=dependency;i++){
            string str;
            getline(cin,str);
            pair<string,string>P = ans_me(str);
            int x = idSet[P.first];int y=idSet[P.second];
            depend[x].push_back(y);
      }
      int similar_task;
      printf("similar task: ");
      scanf("%d ",&similar_task);
      for(int i=0;i<similar_task;i++){
            string str;
            getline(cin,str);
            pair<string,string>P=ans_me(str);
            int x = idSet[P.first];int y = idSet[P.second];
            similar[x].push_back(y);
            similar[y].push_back(x);
      }
      printf("Please enter destination: \n");
      string str;
      getline(cin,str);
      int destination = idSet[str];
      dfs(destination );
      for(int i =1;i<=node;i++)sameTask[i]=i;
      for(int i=0;i<tempAns.size() ;i++){
            for(int j=0;j<similar[tempAns[i]].size( );j++){
                  int V = similar[tempAns[i]][j];
                  sameTask[V] = sameTask[ tempAns[i] ];
            }
      }
      for(int i=0;i<tempAns.size() ;i++){
            if(sameTask[tempAns[i]] == tempAns[i]){
                  finalAns.push_back(tempAns[i]);
            }
      }
      for(int i=0;i<finalAns.size() ;i++)cout<<revert[finalAns[i]]<<endl;

      return 0;
}
