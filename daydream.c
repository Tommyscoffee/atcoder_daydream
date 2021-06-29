#include <stdio.h>
#include <string.h>
//input文字列Sを'dream''dreamer'erase''eraser'で文字列を合わせることができるか
//方針）
//sの先頭文字が'd''e'が見つからなかったらエラー
//見つかったら、条件分岐
//それぞれの文字列を２重配列に格納して判断する

//参照；文字列入力の２つの方法。配列、ポインタ
//scanfの引数に文字列ポインタを指定してはいけない理由　https://meideru.com/archives/1062#scanf
int	main()
{
	char	s[10000];
	int	len;
	char	src[4];
	int	i = 0;
	// s = NULL;
	// src[0] = "dream";//5
	// src[1] = "dreamer";//7
	// src[2] = "erase";//5
	// src[3] = "eraser";//6
	//srcを二次元配列で宣言する。
	src[0] = "dream";
	src[1] = "dreamer";
	src[2] = "erase";
	src[3] = "eraser";
	// scanf("%s",s); ここでsegment faultになっている理由。https://meideru.com/archives/1062#scanf
	//よって配列でscanfするが要素数をどのくらいに設定すれば良いかわからない。
	scanf("%s",s);
	printf("%s\n",s);
	len = strlen(s);
	for (i = 0; i < len;){
		if (s[i] == 'd'){
			if(strncmp(&s[i],&src[0],5)){
				i+=5;
			}
			else if (strncmp(&s[i],&src[1],7)){
				i+=7;
			}
			else
				break;
		}
		else if (s[i] == 'e'){
			printf("elseifには入っている\n");
			if (strncmp(&s[i],&src[2],5)){
				i+=5;
				printf("eraseに入っている\n");
			}
			else if (strncmp(&s[i],&src[3],6)){
				printf("eraserに入っている\n");
				i+=6;
			}
			else
				break;
		}
	}
	if (len == i){
		printf("YES\n");
		return (0);
	}
	else{
		printf("NO\n");
		return(0);
	}
	return(0);

}