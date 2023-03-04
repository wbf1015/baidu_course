#include<bits/stdc++.h>

using namespace std;

//��һ���������������ˣ���д�ɶѲ��ܹ�
void NotUseHeap(){
    vector<int>vi;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        char c;cin>>c;
        if(c=='+'){
            int temp;cin>>temp;
            vi.push_back(temp);
            continue;
        }else{
            sort(vi.begin(),vi.end());
            if(vi.size()%2==0){
                int front=vi.size()/2-1;
                int behind=vi.size()/2;
                double d=(double)(vi[front]+vi[behind])/2.0;
                cout<<d<<endl;
            }else{
                cout<<vi[vi.size()/2]<<endl;
            }
        }
    }
}

priority_queue<int,vector<int>,less<int>>q1;//�󶥶ѣ��洢Сһ�����
priority_queue<int,vector<int>,greater<int>>q2;//С���ѣ��洢��һ�����

void insert(int i){
    if(q1.size()>q2.size()){
        q1.push(i);
        q2.push(q1.top());
        q1.pop();
    }else{
        q1.push(i);
        if(!q2.empty()&&q1.top()>q2.top()){
            int small=q1.top();
            int big=q2.top();
            q1.pop();
            q2.pop();
            q2.push(small);
            q1.push(big);
        }
    }
}

int main( )
{
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        char c;
        cin >> c;
        if (c == '+') {
            int temp;
            cin >> temp;
            insert(temp);
        } else {
            if (q1.size() > q2.size()) {
                cout << q1.top() << endl;
            } else {
                cout << (float) (q1.top() + q2.top()) / 2 << endl;
            }

        }
    }
    return 0;
}