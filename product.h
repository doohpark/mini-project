#ifndef PRODUCT
#define PRODUCT
typedef struct{
    char name[20];
    int weight;
    int price;
    int star;
    int starnum;
} Product;

int addProduct(Product *p); //제품을 추가하는 함수
void readProduct(Product p); //제품을 출력하는 함수
int updateProduct(Product *p); // 제품을 수정하는 함수
int deleteProduct(Product *p); // 제품을 삭제하는 함수

#endif
