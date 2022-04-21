#include <stdio.h>
#include <stdlib.h>



    void read ( int id [100], int salary [100],int employees ){
        int i;
        printf(" please enter the id and the salary of each employee ") ;
        for (i =0 ; i < employees ; i ++ ){
                scanf ("%d %d", & id [ i ], & salary [i]) ; }}
    void comparison (int id [100] , int salary [100] , int employees  ) {
        printf (" please enter the value you want to compare to other salaries with ") ;
        int comp , ei = 0, i ;
        scanf (" %d",& comp ) ;
        int result [ 100 ], z =0 ;
        for ( i = 0 ; i < employees ; i ++ ) {
                if ( salary [i] >comp ) {
                        result [ei] = id [i ] ;
                        z=z+1 ;
                        ei++ ;}}
        for ( i =0 ; i <z ; i ++ ) {
                printf (" the ids is %d ",result [i]); }}
    void pay_rise ( int *id , int *salary , int employees) {
        int num,m,n,i,j ;
        printf (" please enter the number of employees to be given the compromise ") ;
        scanf (" %d",&num);
        for (j=0;j < num ; j++){
        printf (" please enter the id of the emeployees you want to give them the compromise ") ;
        scanf (" %d",&m);
        printf (" please enter the percentage you want to increase them with ") ;
        scanf (" %d",&n);
        for (i=0;i < employees ; i++){
                if (id [i]== m){
                        salary [i]+=salary [i]*(n/100) ; } } }}
    void printing (int salary [], int employees) {
        int i;
        for (i =0 ; i < employees ; i ++) {
                printf ( " %d ", salary [i]) ; } }
    int main () {
        int id [100] ;
        int employees ;
        int salary [ 100 ];
        printf (" please eneter the number of employees in the company ");
        scanf ( " %d", & employees );
        read (id , salary , employees );
        comparison ( id , salary , employees );
        pay_rise (id,salary,employees) ;
        printing (salary , employees ) ;

    return 0;}

