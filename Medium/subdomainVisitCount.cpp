class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;

        for (const string& entry : cpdomains) {
            int spaceIdx = entry.find(' ');
            int count = stoi(entry.substr(0, spaceIdx));
            string domain = entry.substr(spaceIdx + 1);

            // Break domain into subdomains
            for (int i = 0; i < domain.size(); ++i) {
                if (i == 0 || domain[i - 1] == '.') {
                    string subdomain = domain.substr(i);
                    m[subdomain] += count;
                }
            }
        }

        vector<string> ans;
        for (auto& [subdomain, cnt] : m) {
            ans.push_back(to_string(cnt) + " " + subdomain);
        }

        return ans;
    }
};

// https://leetcode.com/problems/subdomain-visit-count/
