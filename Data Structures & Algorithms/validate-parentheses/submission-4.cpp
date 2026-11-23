class Solution {
public:
    bool isValid(string s) {
        
        if (s.size() % 2 != 0)
        {
            return false;
        }

        std::vector<char> brackets;
        brackets.reserve(s.size() / 2);

        for (const char ch : s)
        {
            switch (ch)
            {
                case '(':
                case '[':
                case '{':
                    brackets.push_back(ch);
                    break;
                case ')':
                    if (brackets.empty() || brackets.back() != '(')
                    {
                        return false;
                    }
                    brackets.pop_back();
                    break;
                case '}':
                    if (brackets.empty() || brackets.back() != '{')
                    {
                        return false;
                    }
                    brackets.pop_back();
                    break;
                case ']':
                    if (brackets.empty() || brackets.back() != '[')
                    {
                        return false;
                    }
                    brackets.pop_back();
                    break;
                default:
                    return false;
            }
        }

        return brackets.empty();
    }
};
