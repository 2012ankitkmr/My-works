#include <stdio.h>
#include <algorithm>
#include <limits.h>

using namespace std;

// We'll use a Binary Indexed tree to store the ranks of contestants in the third competition.
int biTree[100002];

// A structure to store the ranks of each contestant in the 3 competitions.
struct contestRank {
    int c1, c2, c3;
};

// This method compares two objects of type contestRank. The problem states that no two contestants can have the same
// rank in a competition. So we only need to compare the rank of the contestants in the first competition.
bool cmp(const contestRank &a , const contestRank &b) {
    return a.c1 < b.c1;
}

// Update the Binary Indexed tree with the rank of the contestant in the third competition.
void update(int idx, int value, int n) {
    while (idx <= n) {
        biTree[idx] = min(biTree[idx], value);
        idx += (idx & -idx);
    }
}

// Read the best ranked contestant we have seen in the third competition so far.
int readTree(int idx) {
    int prevMin = INT_MAX;
    while (idx) {
        prevMin = min(biTree[idx], prevMin);
        idx -= (idx & -idx);
    }

    return prevMin;
}

int main() {
    int t;
    scanf("%d", &t);

    // Iterate over all the test cases.
    while (t--) {
        int n;
        scanf("%d", &n);

        // Read all the contestant ranks as input.
        contestRank ranks[n];
        for (int idx = 0; idx < n; idx++) {
            scanf("%d%d%d", &ranks[idx].c1, &ranks[idx].c2, &ranks[idx].c3);
        }
      

        // We sort all the contestants by their ranks in the first competition.
        sort(ranks, ranks + n, cmp);
  for (int idx = 0; idx < n; idx++) {
            printf("%d%d%d\n", ranks[idx].c1, ranks[idx].c2, ranks[idx].c3);
        }

        // Prepare the tree by setting each elements value to maximum.
        fill(biTree, biTree + n + 2, INT_MAX);

        // For each contestant figure out if it is an excellent contestant or not.
        int excellent = 0;
        for (int idx = 0; idx < n; idx++) {
            int curr = readTree(ranks[idx].c2);

            if (curr > ranks[idx].c3) {
                excellent++;
            }

            update(ranks[idx].c2, ranks[idx].c3, n);
        }

        printf("%d\n", excellent);
    }

    return 0;
}
