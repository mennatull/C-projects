#include <stdio.h>

#define MONTHS 12

int main(){

    int n, i, j, x, z, month, temp2, temp4;
    float sum, bsum, percent, msum, temp1, temp3;

    float salesDataArr [1000] [MONTHS];
    int peakMonths [12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    float peakSales [12];
    float sortedBranches [1000];

    x = 1;
    while (x != 0){

        printf ("1: Add a new branch record.\n");
        printf ("2: Delete an existing branch record.\n");
        printf ("3: Calculate the sales of the company.\n");
        printf ("4: Calculate the percentage share of each branch.\n");
        printf ("5: Month of peak sales.\n");
        printf ("6: Display sales of a specific month.\n");
        printf ("0: Quit.\n");
        scanf ("%d", &x);

        if (x == 1){

            printf ("Please enter the new total number of current branches: ");
            scanf ("%d", &n);
            printf ("Sales for %d branch(es):\n", n);
            for (i = 0; i < n; i++){
            if (salesDataArr [i] [i] == 0)
            printf ("\n\nSales data for branch %d: \n", (i+1));
            for (j = 0; j < MONTHS; j++){
                if (salesDataArr [i] [j] == 0){
                printf ("Sales for month %d: ", (j+1));
                scanf ("%f", &salesDataArr [i] [j]);
                }
        }
    }

    printf ("\nBranch\\Month: \t");
    for (i = 0; i < MONTHS; i++)
        printf ("%d\t", (i+1));
    printf ("\n\n");
    for (i = 0; i < n; i++){
        printf ("Branch %d\t", (i+1));
        for (j = 0; j < MONTHS; j++){
            if (salesDataArr [i] [j] != 0)
            printf ("%.2f\t", salesDataArr [i] [j]);
        }
        printf ("\n\n");
    }
    }

    if (x == 2){

            printf ("\nBranch\\Month: \t");
            for (i = 0; i < MONTHS; i++)
                printf ("%d\t", (i+1));
                printf ("\n\n");
                for (i = 0; i < n; i++){
                    printf ("Branch %d\t", (i+1));
                    for (j = 0; j < MONTHS; j++){
                        if (salesDataArr [i] [j] != 0)
                            printf ("%.2f\t", salesDataArr [i] [j]);
                    }
                    printf ("\n\n");
                }

        printf ("Please enter the number of the branch to be deleted: ");
        scanf ("%d", &z);

        for (i = 0; i < MONTHS; i++){
            salesDataArr [z-1] [i] = 0;
        }

    printf ("\nBranch\\Month: \t");
    for (i = 0; i < MONTHS; i++)
        printf ("%d\t", (i+1));
    printf ("\n\n");
    for (i = 0; i < n; i++){
        if (salesDataArr [i] [i] != 0)
        printf ("Branch %d\t", (i+1));
        for (j = 0; j < MONTHS; j++){
            if (salesDataArr [i] [j] != 0)
            printf ("%.2f\t", salesDataArr [i] [j]);
        }
        if (salesDataArr [i] [i] != 0)
        printf ("\n\n");
    }

    }

    if (x == 3){

        sum = 0;
        bsum = 0;
        for (i = 0; i < n; i++){
            for (j = 0; j < MONTHS; j++)
            sum += salesDataArr [i] [j];
        }
        printf ("\nTotal Company Sales: %.2f\n", sum);
    }

    if (x == 4){

        sum = 0;
        for (i = 0; i < n; i++){
            for (j = 0; j < MONTHS; j++)
                sum += salesDataArr [i] [j];
        }

        for (i = 0; i < n; i++){
            bsum = 0;
            for (j = 0; j < MONTHS; j++)
                bsum += salesDataArr [i] [j];
            percent = bsum/sum*100;
            if (bsum != 0)
            printf ("\nBranch %d shares = %.2f\n%", (i+1), percent);
        }
    }

    if (x == 5){

        for (j = 0; j < MONTHS; j++){
            msum = 0;
            for (i = 0; i < n; i++)
                msum += salesDataArr [i] [j];

            peakSales [j] = msum;
    }

        for (i = 1; i < MONTHS; i++){
            for (j = 0; j < MONTHS - i; j++){
                if (peakSales [j] > peakSales [j + 1]){
                    temp1 = peakSales [j + 1];
                    peakSales [j + 1] = peakSales [j];
                    peakSales [j] = temp1;

                    temp2 = peakMonths [j + 1];
                    peakMonths [j + 1] = peakMonths [j];
                    peakMonths [j] = temp2;
                }
            }
        }

        printf ("\n\nMonth:\t\t");
        for (i = 0; i < MONTHS; i++)
            printf ("%d\t", peakMonths [i]);
        printf ("\n\nTotal Sales:\t");
        for (i = 0; i < MONTHS; i++)
            printf ("%.2f\t", peakSales [i]);
        printf ("\nMonth %d has the peak sales of %.2f\n", peakMonths [11], peakSales [11]);
    }

    if (x == 6){

        int branchNum [n];

        printf ("Please enter a month to display its sales: ");
        scanf ("%d", &month);

        for (i = 0; i < n; i++){
            sortedBranches [i] = salesDataArr [i] [month - 1];
            branchNum [i] = i + 1;
        }

        for (i = 1; i < n; i++){
            for (j = 0; j < n - i; j++){
                if (sortedBranches [j] > sortedBranches [j + 1]){
                    temp3 = sortedBranches [j + 1];
                    sortedBranches [j + 1] = sortedBranches [j];
                    sortedBranches [j] = temp3;

                    temp4 = branchNum [j + 1];
                    branchNum [j + 1] = branchNum [j];
                    branchNum [j] = temp4;
                }
            }
        }

        printf ("\n\n");
        for (i = n - 1; i >= 0; i--){
                if (sortedBranches [i] != 0)
                    printf ("Branch %d: %.2f\n", branchNum [i], sortedBranches [i]);
        }
        printf ("\n\n");
    }
    }

return 0;
}
