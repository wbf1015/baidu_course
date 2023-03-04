#include<bits/stdc++.h>

using namespace std;

void printVec(vector<int>&vi){
    for(int i=0;i<vi.size();i++){
        cout<<vi[i]<<" ";
    }
    cout<<endl;
}

int main( )
{
    int n;
    vector<int>vi;
    cin>>n;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        vi.push_back(k);
    }
    int round=1;
    int index=0;
    while(vi.size()>2){
        if(index+2>=vi.size()){
            round++;
            index=0;
            continue;
        }else{
            if(vi[index]+vi[index+1]+vi[index+2]<=round*3){
                vi[index]=vi[index]+vi[index+1]+vi[index+2];
                vi.erase(vi.begin()+index+1);
                vi.erase(vi.begin()+index+1);
                index++;
                continue;
            }else{
                index++;
                continue;
            }
        }
    }
    cout<<round;
    return 0;
}