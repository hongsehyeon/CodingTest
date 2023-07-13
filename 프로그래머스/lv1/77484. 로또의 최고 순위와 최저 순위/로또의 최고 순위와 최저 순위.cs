using System;

public class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = { 0, 0 };

            int zero = 0;
            int right = 0;

            for (int i = 0; i < 6; i++)
            {
                if (lottos[i] == 0)
                    zero++;
                for (int j = 0; j < 6; j++)
                    if (lottos[i] == win_nums[j])
                        right++;
            }

            int max = 7 - right - zero;
            int min = 7 - right;

            if (max < 7 && max > 0)
                answer[0] = max;
            else
                answer[0] = 6;
            if (min < 7 && min > 0)
                answer[1] = min;
            else
                answer[1] = 6;

            return answer;
    }
}