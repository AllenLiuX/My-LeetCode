Tags: 字符串
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/restore-ip-addresses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
---

class Solution {
public:
    vector<string> res;
    
    vector<string> restoreIpAddresses(string s) {
        string temp;
        dfs(s,temp,0);
        return res;
    }
    
    void dfs(string s, string& temp, int word_num){
        if(word_num == 4){
            if(s.empty()) res.push_back(temp);
        }
        else{
            if(word_num > 0) temp += '.';   //放在头上而不是尾部，因为考虑最后一个
            for(int i = 1; i <= 3 && i <= s.length(); ++i){
                if(valid(s.substr(0,i))){   //如果头i位数字<=255等：
                    temp += s.substr(0,i);  //先放进temp，看后面的
                    dfs(s.substr(i,s.length()-i),temp,word_num+1);
                    temp.erase(temp.length()-i,i);  //清理temp，接着看i+1
                }
            }
            temp.pop_back();
        }
    }
    
    bool valid(const string& s){
        if(s.empty() || (s[0] == '0' && s.size()>1) ) return false;
        int val = stoi(s);
        if(val >= 0 && val <= 255) return true;
        return false;
    }
};