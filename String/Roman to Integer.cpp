//  naive (good but you can see more optimize code below)
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string,int> mp;
        for(int i=0;i<s.length();i++){
            string temp(1,s[i]);
            mp[temp]++;
            if(i+1<s.length() && s[i]=='I'){
                if(s[i+1]=='V'){
                    mp[temp]--;
                    mp["IV"]++;
                    i++;
                }
                else if(s[i+1]=='X'){
                    mp[temp]--;
                    mp["IX"]++;
                    i++;
                }
            }
            else if(i+1<s.length() && s[i]=='X'){
                if(s[i+1]=='L'){
                    mp[temp]--;
                    mp["XL"]++;
                    i++;
                }
                else if(s[i+1]=='C'){
                    mp[temp]--;
                    mp["XC"]++;
                    i++;
                }
                
            }
            else if(i+1<s.length() && s[i]=='C'){
                if(s[i+1]=='D'){
                    mp[temp]--;
                    mp["CD"]++;
                    i++;
                }
                else if(s[i+1]=='M'){
                    mp[temp]--;
                    mp["CM"]++;
                    i++;
                }

            }
        }
        int sum=0;
        for(auto it:mp){
            if(it.first=="I"){
                sum+=it.second*1;
            }
            else if(it.first=="V"){
                sum+=it.second*5;
            }
            else if(it.first=="X"){
                sum+=it.second*10;
            }
            else if(it.first=="L"){
                sum+=it.second*50;
            }
            else if(it.first=="C"){
                sum+=it.second*100;
            }
            else if(it.first=="D"){
                sum+=it.second*500;
            }
            else if(it.first=="M"){
                sum+=it.second*1000;
            }
            else if(it.first=="IV"){
                sum+=it.second*4;
            }
            else if(it.first=="IX"){
                sum+=it.second*9;
            }
            else if(it.first=="XL"){
                sum+=it.second*40;
            }
            else if(it.first=="XC"){
                sum+=it.second*90;
            }
            else if(it.first=="CD"){
                sum+=it.second*400;
            }
            else if(it.first=="CM"){
                sum+=it.second*900;
            }
        }
        return sum;
    }
};

// optimized 

class Solution {
public:
    int romanToInt(string s) {
        if (s.empty()) return 0;
        
        unordered_map<char, int> table = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int num = 0;
        for (int i = 0; i < s.length() - 1; ++i) {
            if (table[s[i]] < table[s[i + 1]]) {
                num -= table[s[i]];
            } else {
                num += table[s[i]];
            }
        }
        num += table[s.back()];

        return num;
    }
};