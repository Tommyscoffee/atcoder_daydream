#include <stdio.h>
#include <string.h>
//input文字列Sを'dream''dreamer'erase''eraser'で文字列を合わせることができるか
//方針）
//sの先頭文字が'd''e'が見つからなかったらエラー
//見つかったら、条件分岐
//それぞれの文字列を２重配列に格納して判断する

//参照；文字列入力の２つの方法。配列、ポインタ
//scanfの引数に文字列ポインタを指定してはいけない理由　https://meideru.com/archives/1062#scanf
int	ft_strncmp(char *s1, char *s2, size_t n);
int	main()
{
	char	s[10000];
	int	len;
	char	src[4][8] = {"dream","dreamer","erase","eraser"};
	int	i = 0;
	// s = NULL;
	// src[0] = "dream";//5
	// src[1] = "dreamer";//7
	// src[2] = "erase";//5
	// src[3] = "eraser";//6
	//srcを二次元配列で宣言する。
	// src[0][6] = "dream";
	// src[1][8] = "dreamer";
	// src[2][6] = "erase";
	// src[3][7] = "eraser";
	
	// scanf("%s",s); ここでsegment faultになっている理由。 https://meideru.com/archives/1062#scanf
	//よって配列でscanfするが要素数をどのくらいに設定すれば良いかわからない。
	scanf("%s",s);
	printf("%s\n",s);
	len = strlen(s);
	printf("s = [%s] で長さ = [%d]\n",src[1],len);
	for (i = 0; i < len;){
		// printf("---%d---\n",i);
		if (s[i] == 'd'){
			if (!ft_strncmp(&s[i],src[1],7)){
				printf("-dreamerとの差%d\n",strncmp(&s[i],&src[1],7));
				printf("-dreamとの差%d\n",strncmp(&s[i],&src[0],5));
				printf("dreamerに入っている\n");
				i+=7;
			}
			else if(!ft_strncmp(&s[i],src[0],5)){
				printf("dreamに入っている\n");
				i+=5;
			}
		}
		else if (s[i] == 'e'){
			printf("elseifには入っている\n");
			if (!ft_strncmp(&s[i],src[3],6)){
				printf("eraserに入っている 比較したのは[%c%c%c%c%c]\n",s[i],s[i+1],s[i+2],s[i+3],s[i+4]);
				i+=6;
			}
			else if (!ft_strncmp(&s[i],src[2],5)){
				i+=5;
				printf("eraseに入っている\n");
			}
		}
	}
	printf("---%d----\n",i);
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

int	ft_strncmp(char *s1, char *s2, size_t n)//ポインタを変化させないstrcmpを実装。
{
	size_t	i,j,k;
	int		ans;
	i = 0;
	ans = 0;
	while (i < n && (s1[i] != 0 || s2[i] != 0))
	{
		ans = s1[i] - s2[i];//
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0'){
			printf("-----ft_strncmpでのiは[%d]まで回った\n",i);
			return (ans);
		}
		i++;
	}
	printf("-----ft_strncmpでのiは[%d]まで回った\n",i);
	return (0);
}
