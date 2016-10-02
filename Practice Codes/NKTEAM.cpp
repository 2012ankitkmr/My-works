#include<bits/stdc++.h>
using namespace std;


// We'll use a Binary Indexed tree to store the ranks of contestants in the third competition.
 long  int biTree[500002];

// A structure to store the ranks of each contestant in the 3 competitions.
struct contestRank {
    long int c1, c2, c3;
};

// This method compares two objects of type contestRank. The problem states that no two contestants can have the same
// rank in a competition. So we only need to compare the rank of the contestants in the first competition.
bool cmp(const contestRank &a , const contestRank &b) {
    return a.c1 < b.c1;
}

// Update the Binary Indexed tree with the rank of the contestant in the third competition.
void update(long int idx, long int value, long int n) {
    while (idx <= n) {
        biTree[idx] = min(biTree[idx], value);
        idx += (idx & -idx);
    }
}

// Read the best ranked contestant we have seen in the third competition so far.
long int readTree(long int idx) {
    long int prevMin = INT_MAX;
    while (idx) {
        prevMin = min(biTree[idx], prevMin);
        idx -= (idx & -idx);
    }

    return prevMin;
}
contestRank ranks[500005];
int main() {
  
    // Iterate over all the test cases.
  {
  	freopen("in.txt","r",stdin);
        long int n;
        scanf("%ld", &n);

        // Read all the contestant ranks as input.
        
        for (long int idx = 0; idx < n; idx++) {
            scanf("%ld", &ranks[idx].c1);
        }
for (long int idx = 0; idx < n; idx++) {
            scanf("%ld", &ranks[idx].c2);
        }
for (long int idx = 0; idx < n; idx++) {
            scanf("%ld", &ranks[idx].c3);
        }

        // We sort all the contestants by their ranks in the first competition.
        sort(ranks, ranks + n, cmp);
     for (long int idx = 0; idx < n; idx++) {
            printf("%ld ", ranks[idx].c1);
        }
        printf("\n");
for (long int idx = 0; idx < n; idx++) {
            printf("%ld ", ranks[idx].c2);
        }
        printf("\n");
for (long int idx = 0; idx < n; idx++) {
            printf("%ld ", ranks[idx].c3);
        }

printf("\n");
        // Prepare the tree by setting each elements value to maximum.
        fill(biTree, biTree + n + 2, INT_MAX);

        // For each contestant figure out if it is an excellent contestant or not.
        long int excellent = 0;
        for (long int idx = 0; idx < n; idx++) {
            long int curr = readTree(ranks[idx].c2);

            if (curr > ranks[idx].c3) {
                excellent++;
            }

            update(ranks[idx].c2, ranks[idx].c3, n);
        }

        printf("%ld\n", excellent);
    }

    return 0;
}
