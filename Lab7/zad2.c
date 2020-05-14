#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
struct wektor
{
	float x;
	float y;
	float z;
};
void show(struct wektor w, int n)
{
    printf("w%d = [%f, %f, %f]\n", n, w.x, w.y, w.z);
}
struct wektor sum(struct wektor w1, struct wektor w2)
{
    struct wektor w3;
    w3.x=w1.x+w2.x;
    w3.y=w1.y+w2.y;
    w3.z=w1.z+w2.z;
    return w3;
}
void skalarny(struct wektor *w1, struct wektor *w2)
{
    printf("iloczyn skalarny = %f\n", w1->x*w2->x+w1->y*w2->y+w1->z*w2->z);
}
void wektorowy(struct wektor w1, struct wektor w2, struct wektor *w)
{
    w->x=(w1.y*w2.z)-(w1.z*w2.y);
    w->y=(w1.x*w2.z)-(w1.z*w2.x);
    w->z=(w1.x*w2.y)-(w1.y*w2.x);
}
int main(void)
{
    struct wektor w1;
    struct wektor w2;
    struct wektor suma;
    struct wektor w;

    scanf("%f %f %f", &w1.x, &w1.y, &w1.z);
    scanf("%f %f %f", &w2.x, &w2.y, &w2.z);

    printf("w1 = [%f, %f, %f]\n", w1.x, w1.y, w1.z);
    printf("w2 = [%f, %f, %f]\n", w2.x, w2.y, w2.z);
    suma=sum(w1, w2);
    printf("suma = [%f, %f, %f]\n", suma.x, suma.y, suma.z);
    skalarny(&w1, &w2);
    wektorowy(w1, w2, &w);

    printf("iloczyn wektorowy = [%f, %f, %f]\n", w.x, w.y, w.z);

    return 0;
}
