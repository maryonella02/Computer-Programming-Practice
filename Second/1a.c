#include <stdlib.h>
#include <stdio.h>

typedef struct {
	float x;
	float y;
} coords;

typedef struct{
	double d;
}distance;


int main() {
	int n, i;
	printf("Number of coordinates: \n");
	scanf("%d", &n);

	coords *coords = malloc(n*sizeof(int));

	for(i=0; i<n; i++) {
	printf("\nX = ");
		scanf("%f", &coords[i].x);
		printf("\nY = ");
		scanf("%f", &coords[i].y);
	}

//prin bubble sort cu algoritm gasim min distance (radical din x2-x1 la patrat plus y2-y1 la patrat
	int a;
	float D;
	distance min;
	min.d = sqrt((coords[1].x-coords[0].x)*(coords[1].x-coords[0].x)+(coords[1].y-coords[0].y)*(coords[1].y-coords[0].y));
	for (int i=0; i<n-1; i++){
		for(int j=0; j<n-1; j++){
			D=sqrt((coords[j+1].x-coords[j].x)*(coords[j+1].x-coords[j].x)+(coords[j+1].y-coords[j].y)*(coords[j+1].y-coords[j].y));
			if (D <= min.d){
				min.d = D;
			}
		}
	}

	printf("\nMinimal distance between the points is %.5f", min.d);


	return 0;
}
