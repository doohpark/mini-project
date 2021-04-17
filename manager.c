#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "manager.h"


int listProduct(Product *p, int count){
    printf("\nNo Name Weight Price Star Starnum");
    printf("\n**************************************\n");
    for(int i=0; i<count; i++){
        if(p[i].weight == -1 ) continue;
        printf("%2d",i+1);
        readProduct(p[i]);
    }
    return 1;
}
int selectMenu(){
int menu;
printf("\n*** 즐거운 쇼핑 ***\n");
printf("1. 조회\n");
printf("2. 추가\n");
printf("3. 수정\n");
printf("4. 삭제\n");
printf("5. 파일저장\n");
printf("6. 검색(이름,가격,별점)\n");
printf("0. 종료\n\n");
printf("=> 원하는 메뉴는? ");
scanf("%d", &menu);
printf("***************\n");
return menu;
}
int selectDataNo(Product *p, int count){
    listProduct(p,count);
    int no;
    printf("번호는(취소:0)?");
    scanf("%d",&no);
    return no;
}
void saveData(Product *p, int count){
    FILE *fp;
    fp = fopen("product.txt","wt");
    for(int i=0; i<count; i++){
        if(p[i].price ==-1) continue;
        fprintf(fp, "%s %d %d %d %d\n",p[i].name, p[i].weight, p[i].price, p[i].star, p[i].starnum);
}
    fclose(fp);
    printf("=> 저장됨! ");
}
int loadData(Product *p){
    int i=0;
    FILE *fp;
    fp=fopen("product.txt","rt");
    if(fp==NULL){
      fp=fopen("product.txt","w");
      printf("-> 파일없음");
    }
    else {
      fp = fopen("product.txt", "rt");
      for(; i<100; i++){
        fscanf(fp, "%s", p[i].name);
         if(feof(fp)) break;
        fscanf(fp, "%d", &p[i].weight);
        fscanf(fp, "%d", &p[i].price);
        fscanf(fp, "%d", &p[i].star);
        fscanf(fp, "%d", &p[i].starnum);
        fscanf(fp, "%d", &p[i].price);
    }
    printf("=> 로딩 성공!\n");
}
fclose(fp);
return i;
}
void searchName(Product *p, int count){
     int scnt = 0;
    char search[100];
    printf("검색할 제품은? ");
    scanf("%s", search);
    printf("===============================\n");
    for(int i=0; i<count; i++){
        if(p[i].price == -1) continue;
        if(strstr(p[i].name, search)){
            printf("%2d", i+1);
            readProduct(p[i]);
            scnt++;
        }
    }
    if(scnt == 0) 
        printf(" => 검색된 데이터 없음!\n");
}
void searchPrice(Product *p, int count){
    int scnt = 0;
    int search;
    printf("검색할 가격은? ");
    scanf(" %d", &search);
    printf("===============================\n");
    for(int i=0; i<count; i++){
        if(p[i].price == -1) continue;
        if(p[i].price == search){
            printf("%2d", i+1);
            readProduct(p[i]);
            scnt++;
        }
    }
}

void searchStar(Product *p, int count){
     int scnt = 0;
     int search;
    printf("검색할 별점은? ");
    scanf(" %d", &search);
    printf("===============================\n");
    for(int i=0; i<count; i++){
        if(p[i].price == -1)
	       	continue;
        if(p[i].star == search){
            printf("%2d", i+1);
            readProduct(p[i]);
            scnt++;
        }
    }
}

