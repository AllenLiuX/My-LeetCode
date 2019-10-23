class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        if(denominator==0)
            return res;
        long long a = numerator, b = denominator;
        if((a>0 && b<0) || (a<0 && b>0))
            res += '-';
        a = abs(a);
        b = abs(b);
        res += to_string(a/b); //这时的a和b都还是整数。如果用int的话INT_MIN/-1不能被表示。
        a = a % b;  //a是余数
        if(a)
            res += '.';
        unordered_map<long long, int> map;
        int index = 0;
        while(a && map.find(a) == map.end()){
            map[a] = index++;
            a *= 10;
            res+=to_string(a/b);
            a %= b;
        }

        if(map.find(a) != map.end()){
            res += "()";
            int cur = res.size()-2;
            while(index > map[a]){
                swap(res[cur], res[cur-1]);
                cur--;
                index--;
            }
        }
        return res;
    }
};