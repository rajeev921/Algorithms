class Solution {
public:
    vector<double> sampleStats(vector<int>& cnts) {
        double minStat = 255, maxStat{}, sum{}, med{}, mode{};
        int totalCount = accumulate(begin(cnts), end(cnts), 0), maxCount{};
        int m1 = (totalCount + 1) / 2, m2 = totalCount % 2 == 0 ? (m1 + 1) : m1;
        
        for (auto i = 0, cnt = 0; i < cnts.size(); cnt += cnts[i++]) {
            minStat = cnts[i] > 0 ? min<double>(minStat, i) : minStat;
            maxStat = cnts[i] > 0 ? max<double>(maxStat, i) : maxStat;
            sum += (double)i * cnts[i];

            if (cnt < m1 && cnt + cnts[i] >= m1) med += (double)i / 2;
            if (cnt < m2 && cnt + cnts[i] >= m2) med += (double)i / 2;

            mode = maxCount < cnts[i] ? i : mode;
            maxCount = max(maxCount, cnts[i]);
        }
        return {minStat, maxStat, sum / totalCount, med, mode};
    }
};