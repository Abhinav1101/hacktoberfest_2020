Leetcode Solution for Stone Game IV

class Solution {
public:
    vector<long long int>sq;
    Solution(){
        for(long long int i=1;i<320;i++){
            sq.push_back(i*i);
        }
    }
    bool winnerSquareGame(int n) {
        // unordered_map<long long int,long long int>mp;
        vector<bool>mp(100005,0);
        mp[1]=1;
        mp[3]=1;
        mp[4]=1;
        mp[6]=1;
        
        
        for(long long int i=7;i<=n;i++){
            if(i*i==sqrt(i)){
                mp[i]=1;
                continue;
            }
            for(long long int j=0;j<320;j++){
                if(i-sq[j]<0)
                    break;
                if(!mp[i-sq[j]]){
                    mp[i]=1;
                    break;
                }
            }
        }
        if(mp[n])
            return true;
        return false;
    }
};