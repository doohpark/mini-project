#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "product.h"
#include "manager.h"


int main(void) {
#ifdef DEBUG
  printf("=>DEBUGMODE\n");
#endif
  Product slist[100];
  int count=0, index = 0, menu;
  count = loadData(slist);
  index = count;

 while(1){
    menu = selectMenu();

    if(menu == 0) break;
    if(menu == 1){
      if(count>0){
        listProduct(slist, index);
   }
      else  
        printf("No Data\n");
 }
    else if(menu == 2)
      count += addProduct(&slist[index++]);
    else if(menu == 3) {
      int no = selectDataNo(slist, index);
      if( no == 0){
          printf("=> 취소됨\n");
          continue;
   }
      updateProduct(&slist[no-1]);
 }
    else if(menu == 4){
      int no = selectDataNo(slist, index);
      if( no == 0){
          printf("=> 취소됨!\n");
          continue;
   }
      int deleteok ;
      printf("정말로 삭제하시겠습니까?(삭제:1)");
      scanf("%d", &deleteok);
      if(deleteok == 1){
        if(deleteProduct(&slist[no-1]))
        count--;
     }
   }
    else if(menu == 5){
        saveData(slist, index);
 }
    else if(menu == 6){
        int choice;
        printf("검색: 1.이름 2.가격 3.별점\n 선택: ");
        scanf("%d",&choice);

        if(choice == 0){
          printf("=> 취소됨!\n");
          continue;
        }
        else if(choice == 1){
          searchName(slist, index);
        }
        else if(choice == 2){
          searchPrice(slist, index);
            }
        else if(choice == 3){
          searchStar(slist, index);
            }
        }
    }
    printf("종료됨 ^>^");
    
    return 0;
}
