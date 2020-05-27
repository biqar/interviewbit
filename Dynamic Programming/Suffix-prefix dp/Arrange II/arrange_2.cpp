//
// Created by Islam, Abdullah Al Raqibul on 5/23/20.
//

int Solution::arrange(string A, int B) {
    int length = A.length();
    int dpArray[length][B];

    if(length < B) return -1;

    int whiteCount = 0;
    int blackCount = 0;
    for (int i = 0; i < length; i++) {
        if (A.at(i) == 'B') blackCount++;
        else whiteCount++;
        dpArray[i][0] = blackCount*whiteCount;
    }
    for (int i = 1; i < B; i++) {
        for (int j = 0; j < length; j++) {
            // compute dp[j][i]
            if (i > j) dpArray[j][i] = INT_MAX;
            else {
                int minVal = INT_MAX;
                int whiteNum = 0;
                int blackNum = 0;
                for (int k = j - 1; k >= 0; k--) {
                    if (A.at(k + 1) == 'B') blackNum++;
                    else whiteNum++;
                    if(dpArray[k][i - 1] + blackNum*whiteNum >= 0) {
                        minVal = min(minVal, dpArray[k][i - 1] + blackNum*whiteNum);
                    }
                }
                dpArray[j][i] = minVal;
            }
        }
    }
    return (dpArray[length-1][B-1] > 0 ? dpArray[length - 1][B - 1] : 0);
}