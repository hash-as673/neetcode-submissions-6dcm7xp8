class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        std::vector<int> scores;
        scores.reserve(operations.size());

        for (const std::string& op : operations)
        {
            if (op == "+")
            {
                const std::ptrdiff_t n {std::ssize(scores)};
                scores.push_back(scores[n-1] + scores[n-2]);
            } 
            else if (op == "D")
            {
                scores.push_back(scores.back() * 2);
            }
            else if (op == "C")
            {
                scores.pop_back();
            }
            else
            {
                scores.push_back(std::stoi(op));
            }
        }

        int sum {0};
        for (const int score: scores)
        {
            sum += score;
        }

        return sum;
    }
};