#include <stdio.h>
void main() {
int a,b,c,d,e, logicalFunction;
printf("|   A|   B|   C|   D|   E|  LF|\n");
printf("-------------------------------\n");
for (a=0; a<2; ++a){
    for (b=0; b<2; ++b){
        for (c=0; c<2; ++c){
            for (d=0; d<2; ++d){
                for (e=0; e<2; e++){
                    logicalFunction=(((!a)&&b) || (a && (!b))) && (c || d && e);

                    printf("|  %2d|  %2d|  %2d|  %2d|  %2d|  %2d|\n",a,b,c,d,e, logicalFunction);
                    printf("-------------------------------\n");
                    }
                }
            }
        }
    }
}
