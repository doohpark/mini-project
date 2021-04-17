#include "product.h"

int selectMenu();//메뉴를 고르는 함수
int listProduct(Product *p,int count);//전체 등록된 제품 리스트 출력
int selectDataNo(Product *p, int count);//삭세하거나 수정할 때 데이터 번호 정하는 함수    
void saveData(Product *p, int count); //파일 저장 함수
int loadData(Product *p); // 파일에서 데이터 불러오기 함수
void searchName(Product *p, int count); //제품이름 검색
void searchPrice(Product *p, int count); //제픔가격 검색 
void searchStar(Product *p, int count);// 별점을 검색
