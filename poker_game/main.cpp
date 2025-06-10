#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "PokerGame.h"
using namespace std;

int main(){
  int max_yen,
      have_yen;
  PokerGame();
  PokerGame p;
  
  printf("ポーカーゲームへようこそ.\n\nオッズ\nノーペア×0　ワンペア×1　Jacks or Better×2　ツーペア×3　スリーカード×4　ストレート×5\nフラッシュ×6　フルハウス×7　フォーカード×8　ストレートフラッシュ×9　ロイヤルストレートフラッシュ×10\n\n所持金額と最大金額を設定してください.\n");
  printf("所持金額");
  scanf("%d" , &have_yen);
  printf("最大金額");
  scanf("%d", &max_yen);
  
 
  
  while(true){
    int bet=0;
    int off;
    int i;
    int a;

   
    

    while(bet<=0 || bet>have_yen){
      printf("掛け金を設定してください.\n");
      scanf("%d",&bet);

      
      if(bet>have_yen){
        printf( "所持金額が掛け金額を超えています.\n");
      }else if(bet <=0){
        printf("掛け金は正の整数です.");
      }
    }

    printf("\n\nゲームを始めます.\n所持金額は%d円、最大金額は%d円、掛け金は%d円です.\nカードを配ります.\n", have_yen, max_yen,bet);
        p.draw_cards(p.getMark(),p.getNumber());

    printf("\nあなたのカード\n");
    p.print_cards();

    printf("\nカードの引き直しを行います.\n");
    for(i=0;i<5;i++){
      printf("%d番目のカードを引き直しますか.(0：いいえ　1：はい) ",i+1);
      scanf("%d",&a);
      if(a==1){
        p.redraw(i);
      }
    }

    printf("\nあなたのカード\n");
    p.print_cards();


    printf("\nあなたの手札を判定します.\n");
    off=bet*(p.decision());
    have_yen=have_yen+off-bet;
    printf("\n\n払戻金額は%d円、所持金額は%d円です.\n",off,have_yen);

    if(have_yen<=0){
      printf("所持金が無くなりました.あなたの負けです.\n\nゲームオーバー\nまたの利用をお待ちしています.");
      exit(0);
    }else if(have_yen>=max_yen){
      printf("所持金が最大金額を超えています.あなたの勝ちです");
      exit(0);
  }else{
      printf("ゲームを続けます.\n", have_yen);
    }
  }  
}
