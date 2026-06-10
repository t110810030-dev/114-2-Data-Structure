#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
struct Product{
    string name;
    int day;
    int hot;
};
int main(){
    Product p[100];
    int n;
    ifstream fin("input3.txt");
    fin>>n;
    fin.ignore();
//讀取每一個商品 
    for(int i=0;i<n;i++){
        string line,word[20];
        int count=0;
        getline(fin,line);
        stringstream ss(line);
        while(ss>>word[count]){
            count++;
        }
        p[i].day=stoi(word[count-2]);//讀取有效期限 
        p[i].hot=stoi(word[count-1]);//讀取熱銷程度 
        p[i].name=word[0];
        for(int j=1;j<count-2;j++){
            p[i].name=p[i].name+" "+word[j];
        }
    }
//排順序 
    for(int i=0;i<n-1;i++){
        int best=i; 
        for(int j=i+1;j<n;j++){
            if(p[j].day<p[best].day){//比較有效期限 
                best=j;
            }else if(p[j].day==p[best].day&&p[j].hot>p[best].hot){//比較熱銷程度 
                best=j;
            }
        }
        Product temp=p[i];//排順序 
        p[i]=p[best];
        p[best]=temp;
    }
//輸出結果 
    cout<<"商品排序:"<<endl;
    for(int i=0;i<n;i++){
        cout<<p[i].name<<endl;
    }
    return 0;
}
