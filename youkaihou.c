
#include <stdio.h>

#define MaxTime 20 //時間方向格子点数
#define MaxX 21     //空間方向格子点数
#define CenterX 10   //空間中心座標

int main(void)
{
	int i,n;
	double T[MaxTime][MaxX];//T[時間][空間]
	double dx,dt,alpha,r;
	FILE *fp;

	dx=0.6;  //空間方向の刻み幅
    dt=0.0181; //時間方向の刻み幅 //dt < 0.5 * 0.6 * 0.6 = 0.18
	alpha=10; //alpha=K/(c*rho)

	r=alpha*dt/(dx*dx); //係数の設定

	//Tの初期化（すべての要素を0に）
	for(n=0;n<MaxTime;n++){
		for(i=0;i<MaxX;i++){
			T[n][i]=0;
		}}
	//Tの初期化終了

	//T（t=0）での初期条件を与える
	T[0][CenterX-5]=1;
	T[0][CenterX+5]=1;
	//初期条件終了

	//T(x=0),T(x=MaxX-1)での境界条件を与える
	for(n=0;n<MaxTime;n++){
		T[n][0]=0;
		T[n][MaxX-1]=0;
	}
	//境界条件終了
	//陽解法計算開始
	for(n=0;n<MaxTime-1;n++){
		for(i=1;i<MaxX-1;i++){
			//穴埋め開始
            T[n + 1][i] = T[n][i] + r * (T[n][i+1] - 2 * T[n][i] + T[n][i-1]);

			//穴埋め終了
		}
	}
	//陽解法計算終了

	//ファイルに出力
	if((fp=fopen("youkaihou.txt","w"))==NULL){
		printf("file open error.\n");
	}
		
		fprintf(fp,"dt=%lf dx=%lf\n\n",dt,dx);
	for(i=0;i<MaxX;i++){
		for(n=0;n<MaxTime;n++){
			fprintf(fp,"%lf ",T[MaxTime-n-1][i]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
	//ファイル出力終了
	return 0;
}
