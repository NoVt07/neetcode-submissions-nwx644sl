class Solution {
public:

    string encode(vector<string>& strs) {
        string encode_string = "";
        for(string s : strs){
            int k = s.size();
            encode_string += to_string(k) + "#" + s;
        }
        return encode_string;
    }

    vector<string> decode(string s) {
        vector<string> decoder;
        string temp;
        int i = 0, res = 0;
        while(i < s.size()){
            if(s[i] == '#'){
                for(int j = 1; j <= res; j++)
                    temp += s[j+i];
                i += res + 1;
                decoder.push_back(temp);
                temp = "";
                res = 0;
            }
            else {
                res = res*10 + (s[i] - '0');
                i++;
            }
        }
        return decoder;
    }
};
