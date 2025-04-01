impl Solution {
    pub fn total_numbers(digits: Vec<i32>) -> i32 {
        let mut freq = [0; 10];

        for &digit in &digits {
            freq[digit as usize] += 1;
        }

        let mut zero = 0;
        let mut even = 0;
        let mut all = 0;

        for i in 0..10 {
            if freq[i] > 0 {
                if i == 0 {
                    zero += 1;
                }
                if i % 2 == 0 {
                    even += 1;
                }
                all += 1;
            }
        }

        // For unique digits
        let mut count = even * (all - 1) * (all - 2);
        if zero == 1 {
            count -= (even - 1) * (all - 2);
        }

        // For 2 same digit and 1 different
        for i in 0..10 {
            if freq[i] >= 2 {
                if i == 0 {
                    count += all - 1;
                } else if i % 2 == 1 {
                    count += even;
                } else {
                    count += 3 * (even - 1) - zero;
                    count += 2 * (all - even);
                }
            }
        }

        // For all 3 digits same
        for i in (2..10).step_by(2) {
            if freq[i] >= 3 {
                count += 1;
            }
        }

        count
    }
}

/// https://leetcode.com/problems/unique-3-digit-even-numbers/
