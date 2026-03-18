class Solution {
public:
    int findLucky(vector<int>& arr) {
        int count[101] = {0};//建立空陣列
        for(int num:arr){
            count[num]++;//計算每個數字分別出現幾次
        }
        int maxluck = -1;//預設maxluck=-1
        for(int i=1;i<=100;i++){
            if(count[i]==i){
                maxluck = i;//找到最大的lucky integer
        }
        }  
        return  maxluck;
    }
};
