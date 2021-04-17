#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "product.h"

int addProduct(Product *p){
    printf("제품은? ");
    scanf("%s",p->name);
    printf("중량은? ");
    scanf("%d", &p->weight);
    printf("가격은? ");
    scanf("%d", &p->price);
    printf("별점은? ");
    scanf("%d", &p->star);
    printf("별점개수는?");
    scanf("%d", &p->starnum);

    printf("=> 추가됨!\n");
    return 1;
}
void readProduct(Product p){
    printf(" %s %d %d %d %d\n",p.name, p.weight, p.price, p.star, p.starnum);
}
 
int updateProduct(Product *p){
 printf("제품은? ");
    scanf(" %s",p->name);
    printf("중량은? ");
    scanf("%d", &p->weight);
    printf("가격은? ");
    scanf("%d",&p->price);
    printf("별점은? ");
    scanf("%d",&p->star);
    printf("별점개수는?");
    scanf("%d", &p->starnum);
    printf("수정성공!\n");
    return 1;
}
int deleteProduct(Product *p){
     p->weight =-1;
     p->price =-1;
     p->star =-1;
     p->starnum =-1;
     printf("=>삭제됨!");
    return 1;
}
