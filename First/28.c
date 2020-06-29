int main() {
    int arr[20][20];
    int n;
    int s1=0, s2=0,s3=0,s4=0;
    int max;


    printf("Dati n \n");
    scanf("%d", &n);

    printf("dati arrayul");
    for(int i=1; i <= n; i++){
        for(int j=1; j <= n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i=1; i <= n; i++){
        for(int j=1; j <= n; j++){
            printf("ELEMENTUL : %d", arr[i][j]);
            if (j>=i && j<=n-i +1) {
                s1 = s1 + arr[i][j];
            }
            if(j>=i && j>=n-i +1){
                s2 = s2 + arr[i][j];
            }
            if(j<=i && j>=n-i +1) {
                s3 = s3 + arr[i][j];
            }
            if(j<=i && j<=n-i +1){
                s4 = s4 + arr[i][j];
            }
        }
    }



    for(int i=1; i <= n; i++){
        for(int j=1; j <= n; j++){
            if( s1 >= s2 && s1 >= s3 && s1 >= s4){
                max = s1;
                if (j>=i && j<=n-i +1) {
                    printf("%d", arr[i][j]);
                }
            }

            if( s2 >= s1 && s2 >= s3 && s2 >= s4){
                max = s2;
                if(j>=i && j>=n-i +1){
                    printf("%d", arr[i][j]);
                }
            }

            if( s3 >= s2 && s3 >= s1 && s3 >= s4){
                max = s3;
                if(j<=i && j>=n-i +1) {
                    printf("%d", arr[i][j]);
                }
            }

            if( s4 >= s1 && s4 >= s2 && s4 >= s3){
                max = s4;
                if(j<=i && j<=n-i +1){
                     printf("%d", arr[i][j]);
                }
            }
        }
    }
        printf("Suma maximala este %d", max);



    return 0;
}

